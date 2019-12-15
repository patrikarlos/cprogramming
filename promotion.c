#include <stdio.h>


#define get_type(expr)                \
  _Generic((expr),		      \
	   int: "int",		      \
	   char: "char",	      \
	   double: "double",	      \
	   char*: "string"	      \
	   )

void u(double a, int b);
void v(float a, short b);

int main(int argc, char** argv){
  printf("Hello world.\n");
  u(1.12,44);
  v(1.12,44);
  printf("This is a %s", get_type("a"));


  int i;
  int a[8];

  i[a]=2;
}  

void u(double a, int b){
  printf("double = %g , int = %d \n",a,b);
  return;
}

void v(float a, short b){
  printf("float = %f , short = %i \n",a,b);
  return;
}

