#include <time.h>
#include <stdio.h> 
int main(void) 
{ 
  clock_t start_t,end_t,total_t;
  start_t=clock();
  int a = 0; 
  int* iptr = &a; 
  
  // Dereferencing pointer inside loop 
  // is costly 
  for (int i = 1; i < 1e6; ++i) { 
    *iptr = *iptr + i; 
  } 
  printf("Value of a : %d", a); 

  end_t=clock();
  printf("Took : %g clocks.\n", (double)(end_t-start_t));
  
  return 0; 
} 
