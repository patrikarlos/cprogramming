#include <stdio.h>
#include <myLib.h>

int main(int argc, char **argv){
  printf("Hello World\n");


  print_version;

  int b=10;
  int c=5;

  int response=addition(b,c);
  int response2=mult(b,c);
  
  printf("b+c=%d\n",response);
  printf("b*c=%d\n",response2);

  return 1;
}
