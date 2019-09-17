#include <stdio.h>

typedef struct {
  int a;
  int b;
} node_t;

node_t f(int a, int b){
  node_t myN;
  myN.a=a;
  myN.b=b;
  return myN;
}

 
node_t *g(node_t *myN,int a, int b){
  myN->a=a;
  myN->b=b;
  return myN;
}


int main(int arc, char *arv){
  printf("Hello World\n");

  node_t bob;
  node_t *bar;
  bar=g(&bob,1,2);
  bar->a=3;

  printf("bob.a = %d \n",bob.a);
  printf("bar.a = %d \n",bar->a);
  printf("bob = %p, \n",&bob);
  printf("bar = %p, \n",bar);

  int q=10;
  printf("q = % d\n",q);
  ++q;
  printf("q = % d\n",q);
  
  return(0);
}
  
