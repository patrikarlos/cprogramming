#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <stdalign.h>
#include <stdatomic.h>

int main(int arc, char **arv){

  char myChar;

  short myShort;
  int myInt;
  long myLong;
  float myFloat;
  double myDouble;
  long double myQD;

  _Atomic int counter = ATOMIC_VAR_INIT(1);

  _Bool myBoolean;

  
  double _Complex z=4+2*I;

  int qube[10][10][10];

  
  printf("Sizeof(short) = %d \n", sizeof(myShort));
  printf("Sizeof(int) = %d \n", sizeof(myInt));
  printf("Sizeof(long) = %d \n", sizeof(myLong));
  printf("Sizeof(float) = %d \n", sizeof(myFloat));
  printf("Sizeof(double) = %d \n", sizeof(myDouble));
  printf("Sizeof(myBoolean) = %d \n", sizeof(myBoolean));
  printf("Sizeof(myQD) = %d \n", sizeof(myQD));

  printf("Sizeof(qube) = %d \n", sizeof(qube));
  


  enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun}; 

  printf("1/3.0i = %.1f%+.1fi\n",creal(z),cimag(z));

  enum week day;
  day = Wed; 
  printf("day=%d\n",day); 



  typedef enum { foo,bar,brother} bobby;
  bobby Brown;

  printf("brown=%d\n", Brown);

  Brown=foo;
  printf("brown=%d\n", Brown);
  printf("foo=%d\n", foo);
  printf("bar=%d\n", bar);
  printf("brother=%d\n", brother);


  struct Q {
    unsigned int x: 4;
    unsigned int y: 2;
    unsigned int z: 2;
    
  };


  struct Q myQ;

  myQ.x=1;
  printf("sizeof(myQ) = %d , x = %d \n", sizeof(myQ), myQ.x);


  struct __attribute__((packed)) Q2 {
    unsigned int x: 4;
    unsigned int y: 2;
    unsigned int z: 3;
  };


  struct __attribute__((aligned(1),packed)) Q3 {
    unsigned int x: 4;
    unsigned int y: 2;
    unsigned int z: 2;
  } ;

  struct Q2 myQ2;
  struct Q3 myQ3;
  
  myQ2.x=1;
  myQ3.x=1;

  
  printf("sizeof(myQ2) = %d , x = %d \n", sizeof(myQ2), myQ2.x);
  printf("sizeof(myQ3) = %d , x = %d \n", sizeof(myQ3), myQ3.x);
  

  printf("Q ->   %p \n", (void*)&myQ);

  printf("Q2 ->   %p \n", (void*)&myQ2);



 
  
  return 1;
}

