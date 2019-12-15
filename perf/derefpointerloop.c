#include <time.h>
#include <stdio.h> 
int main(void) 
{ 
  clock_t start_t,end_t,total_t;
  start_t=clock();
  
  int a = 0; 
  int* iptr = &a; 
  
  // Dereferencing pointer outside loop 
  // and saving its value in a temp variable 
  int temp = *iptr; 
  
  for (int i = 1; i < 1e6; ++i) { 
    
    // performing calculations on temp variable 
    temp = temp + i; 
  } 
  
  // Updating pointer using final value of temp 
  *iptr = temp; 
  
  printf("Value of a : %d", a); 
  
  end_t=clock();
  printf("Took : %g clocks.\n", (double)(end_t-start_t));
  
  return 0; 
} 
