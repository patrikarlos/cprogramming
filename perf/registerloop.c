#include <stdio.h>
#include <time.h>
int main(void) 
{
  clock_t start_t,end_t,total_t;
  start_t=clock();

  register int i = 0; 
  register int j = 0;
  //7int i = 0; 
  //int j = 0; 
  int n = 5; 
  
  // using register variables 
  // as counters make the loop faster 
  for (i = 0; i < n; ++i) { 
    for (j = 0; j <= i; ++j) { 
      printf("* "); 
    } 
    printf("\n"); 
	} 

  end_t=clock();
  printf("Took : %g clocks.\n", (double)(end_t-start_t));
  return 0; 

} 
