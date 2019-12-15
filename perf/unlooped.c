#include <time.h>
#include <stdio.h> 
int main(void) 
{ 
  clock_t start_t,end_t,total_t;
  start_t=clock();
  
  int fact[5] = { 1, 1, 2, 6, 24 }; 

 // Here the same work is done 
 // without counter overhead
  end_t=clock();
  printf("Took : %g clocks.\n", (double)(end_t-start_t));
  return 0; 
} 
