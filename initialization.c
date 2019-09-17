#include <stdio.h>

int f(int a){
  return a+1;
}

int g(int a){
  return 2*a;
}

int a = 1;
static int b = 2;
extern int c = 3;


int main(int arc, char *arv){
  printf("Hello World\n");

  printf("a = %d \n",a);
  printf("b = %d \n",b);
  printf("c = %d \n",c);

  a=5;
  b=4;
  c=2;
  
  printf("a = %d \n",a);
  printf("b = %d \n",b);
  printf("c = %d \n",c);

  
  return(0);
}
  
