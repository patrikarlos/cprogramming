#include <stdio.h>



int main(int argc, char **argv){
  printf("Hello World\n");

  int thePointer=5;

  int *tp=&thePointer;

  printf("tp pointer location-> %p tp pointer value-> %d \n", (void *)tp, *tp);
  tp++;
  printf("tp pointer location-> %p tp pointer value-> %d \n", (void *)tp, *tp);
  tp++;
  printf("tp pointer location-> %p tp pointer value-> %d \n", (void *)tp, *tp);
  

  int myArray[4]={1,2,3,4};

  tp=&myArray;
  printf("tp pointer location-> %p tp pointer value-> %d \n", (void *)tp, *tp);
  tp++;
  printf("tp pointer location-> %p tp pointer value-> %d \n", (void *)tp, *tp);
  tp++;
  printf("tp pointer location-> %p tp pointer value-> %d \n", (void *)tp, *tp);
  tp++;
  printf("tp pointer location-> %p tp pointer value-> %d \n", (void *)tp, *tp);


  double myDoubleArray[4]={1.1,2.2,3.3,4.4};
  double *tpd; 
  
  tpd=&myDoubleArray;
  printf("tp pointer location-> %p tp pointer value-> %g \n", (void *)tpd, *tpd);  tpd++;
  printf("tp pointer location-> %p tp pointer value-> %g \n", (void *)tpd, *tpd);  tpd++;
  printf("tp pointer location-> %p tp pointer value-> %g \n", (void *)tpd, *tpd);  tpd++;
  printf("tp pointer location-> %p tp pointer value-> %g \n", (void *)tpd, *tpd);











  
  
}
