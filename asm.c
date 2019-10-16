#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define BIT(x) (1ULL << (x))

#if defined(__i386__)

static __inline__ unsigned long long rdtsc(void)
{
    unsigned long long int x;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
    return x;
}

#elif defined(__x86_64__)

static __inline__ unsigned long long rdtsc(void)
{
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

#endif


typedef unsigned long long ticks;

static __inline__ ticks start (void) {
  unsigned cycles_low, cycles_high;
  asm volatile ("CPUID\n\t"
		"RDTSC\n\t"
		"mov %%edx, %0\n\t"
		"mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
		"%rax", "%rbx", "%rcx", "%rdx");
  return ((ticks)cycles_high << 32) | cycles_low;
}

static __inline__ ticks stop (void) {
  unsigned cycles_low, cycles_high;
  asm volatile("RDTSCP\n\t"
	       "mov %%edx, %0\n\t"
	       "mov %%eax, %1\n\t"
	       "CPUID\n\t": "=r" (cycles_high), "=r" (cycles_low):: "%rax",
	       "%rbx", "%rcx", "%rdx");
  return ((ticks)cycles_high << 32) | cycles_low;
}


int main(int arc, char **arv){
  u_int64_t istart,istop;
  ticks tstart,tstop;

  
  istart=0;
  istop=0;

  istart=rdtsc();
  sleep(2);
  istop=rdtsc();

  tstart=start();
  sleep(2);
  tstop=stop();
  
  printf("Classic\t %llu\t %llu\t %llu\n", istart,istop,istop-istart);
  printf("Newer\t\ %llu\t %llu\t %llu\n", tstart,tstop,tstop-tstart);
  

  int a = 0x7, b, c = 0, d;
  asm ("cpuid\n\t"
       : "=a" (a), "=b" (b), "=c" (c), "=d" (d)
       : "0" (a), "2" (c));
  
  if ((b & BIT(25)) == 0)
    printf("Intel PT not supported\n");
  else
    printf("Intel PT supported\n");
  
  return(1);
  
}

