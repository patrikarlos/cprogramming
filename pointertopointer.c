#include <stdio.h>



int main(int argc, char **argv){
  printf("Hello World\n");

  int thePointer=5;
  
  int *tp=&thePointer;
  int **ptp=&tp;
  
  
  printf("ptp pointer location-> %p ptp 2x dereferencing value-> %d \n", (void *)ptp, **ptp);
  printf(" tp pointer location-> %p tp     dereferencing value-> %d \n", (void *)tp, *tp);
 
  printf("Updating value, from ptp, **ptp=50.\n");
  **ptp=50;
  
  printf("ptp pointer location-> %p ptp 2x dereferencing value-> %d \n", (void *)ptp, **ptp);
  printf(" tp pointer location-> %p tp     dereferencing value-> %d \n", (void *)tp, *tp);

  printf("Updating value, from tp, *tp=500.\n");
  *tp=500;
  
  printf("ptp pointer location-> %p ptp 2x dereferencing value-> %d \n", (void *)ptp, **ptp);
  printf(" tp pointer location-> %p tp     dereferencing value-> %d \n", (void *)tp, *tp);
  printf(" thePointer =========================================  %d \n",thePointer);

  int anotherInt=6;
  tp=&anotherInt;
  printf("ptp pointer location-> %p ptp 2x dereferencing value-> %d \n", (void *)ptp, **ptp);
  printf(" tp pointer location-> %p tp     dereferencing value-> %d \n", (void *)tp, *tp);
  printf(" thePointer =========================================  %d \n",thePointer);



  int ***pptp=&ptp;

  printf("pptp pointer location-> %p pptp 3x dereferencing value-> %d \n", (void *)pptp, ***pptp);
  printf("ptp pointer location-> %p ptp 2x dereferencing value-> %d \n", (void *)ptp, **ptp);



  int *Stuff[10];

  printf("Stuff[0] is at %p, \n",&Stuff);
  printf("Stuff[1] is at %p, \n",&Stuff[1]);

  for(int i=0;i<10;i++){
    printf("Stuff[%d] @ %p  -> %p\n",i,&Stuff[i],(void*)Stuff[i]);
  }

  Stuff[0]=&thePointer;
  Stuff[1]=&anotherInt;
  Stuff[2]=tp;
  
  for(int i=0;i<10;i++){
    printf("Stuff[%d] @ %p  -> %p\n",i,&Stuff[i],(void*)Stuff[i]);
  }


  /* A bit dangerous  */

  int *rougePointer=(int*)0xffffcbb0;
  *rougePointer=0x0;


  for(int i=0;i<10;i++){
    printf("Stuff[%d] @ %p  -> %p\n",i,&Stuff[i],(void*)Stuff[i]);
  }
  Stuff[4]=0x0;
  int i=4;
  printf("Stuff[%d] @ %p  -> %p\n",i,&Stuff[i],(void*)Stuff[i]);
}
