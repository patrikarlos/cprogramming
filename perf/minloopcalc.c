#include <time.h>
#include <stdio.h> 
int main(void) 
{ 
  clock_t start_t,end_t,total_t;
  start_t=clock();

  int arr[1000]; 
  int a = 1, b = 5, c = 25, d = 7; 
  
  // pre calculating the constant expression 
  int temp = (((c % d) * a / b) % d); 
  
  for (int i = 0; i < 1000; ++i) { 
    arr[i] = temp * i; 
  } 
  
  end_t=clock();
  printf("Took : %g clocks.\n", (double)(end_t-start_t));

  return 0; 
} 
