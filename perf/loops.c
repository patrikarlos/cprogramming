#include <time.h>x
#include <stdio.h> 
int main(void) 
{ 
  clock_t start_t,end_t,total_t;
  start_t=clock();

  int fact[5]; 
  fact[0] = 1; 

  // Overhead of managing a counter 
  // just for 4 iterations 
  // is not a good idea 
  for (int i = 1; i < 5; ++i) { 
  fact[i] = fact[i - 1] * i; 
  }
  end_t=clock();
  printf("Took : %g clocks.\n", (double)(end_t-start_t));

  return 0; 
} 
