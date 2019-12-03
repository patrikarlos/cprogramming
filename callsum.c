/*
 * callsum.c
 *
 * Illustrates how to call the sum function we wrote in assembly language.
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

static inline uint64_t get_cycles()
{
  uint64_t t;
  __asm volatile ("rdtsc" : "=A"(t));
  return t;
}


double sum(double[], unsigned);
double csum(double [],unsigned int );
double absum(double, double);



#define elements 1000

int main() {
  double test[elements];
  for (int i=0;i<elements;i++){
    test[i]=rand();
  }
  

    
    printf("ASM - \n");
    uint64_t astsc = __builtin_ia32_rdtsc();
    printf("%20.7f\n", sum(test, elements));
    uint64_t aetsc = __builtin_ia32_rdtsc();

    printf("C Style - \n");

    uint64_t cstsc = __builtin_ia32_rdtsc();
    printf("%20.7f\n", csum(test, elements));
    uint64_t cetsc = __builtin_ia32_rdtsc();

    uint64_t adiff,cdiff;
    adiff=aetsc-astsc;
    cdiff=cetsc-cstsc;

    printf("Asm : %" PRIu64 "\n",adiff);
    printf(" C  : %" PRIu64 "\n",cdiff);
    
    printf("A+B = %20.7f \n", absum(1.5,2));
    
    return 0;
}

double csum(double array[],unsigned int len){
  double result=0;
  for(int i=0;i<len;i++){
    result+=array[i];
  }
  return result;
}
  

