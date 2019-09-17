#include <stdio.h>

int f(int a){
  return a+1;
}

int g(int a){
  return 2*a;
}


int main(int argc, char **argv){
  printf("Hello World\n");


  int *foo, *bar;
  int singleint=5;
  int *sobb[10];
  int (*bob)[10];
	     
  int grobb[2]={21,42};
  
  printf("Size of sobb = %ld \n",sizeof(sobb));
  printf("Size of bob = %ld \n",sizeof(bob));
  printf("Size of foo = %ld \n",sizeof(foo));
  printf("Size of singleint = %ld \n",sizeof(singleint));
  
  int (*p)(int) = f;
  int b = (*p)(4);
  printf("b = %d \n",b);

  foo=&grobb;
  bar=&grobb[0];

  printf("foo pointer location-> %p foo pointer value-> %d \n", (void *)foo, *foo);
  printf("bar pointer location-> %p bar pointer value-> %d \n", (void *)bar, *bar);
  printf("increment foo++\n");
  foo++;
  printf("foo pointer location-> %p foo pointer value-> %d \n", (void *)foo, *foo);
  printf("bar pointer location-> %p bar pointer value-> %d \n", (void *)bar, *bar);

  printf("Difference = %ld \n", ((void*)foo-(void*)bar));
  printf("Difference = %ld \n", (foo-bar));

  
  p = g;
  b = (*p)(4);
  printf("b = %d \n",b);
  printf("grobb[1] = %d\ngrobb[2] = %d\ngrobb[3] = %d\n",grobb[0],grobb[1],grobb[2]);

  int dArray[10][10];
  int eArray[10][10][10];
  int myInt;

  printf("Size of myInt  = %ld \n", sizeof(myInt));

  printf("Size of dArray = %ld \n", sizeof(dArray));
  printf("Size of eArray = %ld \n", sizeof(eArray));
  

  
  return(0);
}
  
