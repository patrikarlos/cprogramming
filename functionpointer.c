#include <stdio.h>

void fun(int a){
  printf("a=%d\n",a);
}


void bun(int a){
  printf("b=%d\n",a);
}

void fun2(){
  printf("Fun2\n");
}

void fun3(){
  printf("Fun3\n");
}


void wrapper(void (*funny)()){
  funny();
}


int main(int argc, char **argv){
  printf("Hello World\n");

  void (*fun_ptr)(int)=&fun;

  void (*fun_ptr2)(int)=fun;

  fun_ptr(5);
  fun_ptr2(10);
  

  wrapper(fun2);
  wrapper(fun3);
  
  
  return 0;
}
