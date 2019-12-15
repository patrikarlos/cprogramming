#include <time.h>
#include <stdio.h> 
int main(void) 
{ 
  clock_t start_t,end_t,total_t;
  start_t=clock();
  
  int arr[1000]; 
  int a = 1, b = 5, c = 25, d = 7; 
  
  // Calculating a constant expression 
  // for each iteration is not good. 
  for (int i = 0; i < 1000; ++i) { 
    arr[i] = (((c % d) * a / b) % d) * i; 
  } 
  
  end_t=clock();
  printf("Took : %g clocks.\n", (double)(end_t-start_t));
  return 0; 
} 
