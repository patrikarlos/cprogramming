#include <stdio.h>
#include <stdlib.h>


/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 
 */
char* itoa(int value, char* result, int base) {
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }
  
  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;
  

  int digits=0;
  do {
    tmp_value = value;
    value /= base;

    *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    digits++;
  } while ( value );


  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
  *ptr-- = '\0';
  while(ptr1 < ptr) {
    tmp_char = *ptr;
    *ptr--= *ptr1;
    *ptr1++ = tmp_char;
  }
  return result;
}

void bit_set(char bit, char *byte) { 
  bit = 1 << bit;
  *byte = *byte & bit; 
}

void bit_reset(char bit, char *byte) { 
  bit = 1 << bit;
  bit ^= 0xff; 
  *byte = *byte & bit; 
} 


int bit_test(char bit, char byte) { 
  bit = 1 << bit; 
  return  (bit & byte)?1:0; 
} 


int main(int arc, char **arv){

  char buffer[33];
  char buffer2[33];
  char buffer3[33];
  char buffer4[33];
  char buffer5[33];

  int foo=0b10101;
  int bar=0b00010;
  int qtip=foo+bar;
  itoa(foo,buffer2,2);
  printf("foo = %s (%d)\n", buffer2,foo);
  
  
  itoa(bar,buffer3,2);
  printf("bar = %s (%d)\n", buffer3,bar);
 
  
  itoa(qtip,buffer,2);  
  printf("qtip (foo+bar)= %s (%d) \n", buffer,qtip);



  
  qtip=foo-bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo-bar)= %s (%d) \n", buffer,qtip);

  qtip=foo*bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo*bar)= %s (%d)\n", buffer,qtip);

  qtip=foo/bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo/bar)= %s (%d)\n", buffer,qtip);



  qtip=foo&&bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo&&bar)= %s (%d)\n", buffer,qtip);

  qtip=foo||bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo||bar)= %s (%d)\n", buffer,qtip);


  qtip=foo&bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo&bar)= %s (%d)\n", buffer,qtip);

  qtip=foo|bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo|bar)= %s (%d)\n", buffer,qtip);

  qtip=foo^bar;
  itoa(qtip,buffer,2);
  printf("qtip (foo^bar)= %s (%d)\n", buffer,qtip);

  int bart=0b00011;
  itoa(bart,buffer4,2);

  printf("foo = %s (%d)\n", buffer2,foo);
  printf("bart= %s (%d)\n", buffer4,bart);
  
  qtip=foo&bart;
  itoa(qtip,buffer,2);
  printf("qtip (foo&bart)= %s (%d)\n", buffer,qtip);

  qtip=foo|bart;
  itoa(qtip,buffer,2);
  printf("qtip (foo|bart)= %s (%d)\n", buffer,qtip);

  qtip=foo^bart;
  itoa(qtip,buffer,2);
  printf("qtip (foo^bart)= %s (%d)\n", buffer,qtip);


  unsigned short moff=0b10101;
  unsigned short uqtip;

  
  itoa(moff,buffer5,2);

  printf("moff = %s (%ud)\n", buffer5,moff);
  
  uqtip=~moff;
  itoa(uqtip,buffer,2);
  printf("uqtip (~moff)= %s (%u)\n", buffer,uqtip);

  uqtip=moff<<2;
  itoa(uqtip,buffer,2);
  printf("uqtip (moff<<2)= %s (%u)\n", buffer,uqtip);

  uqtip=moff>>2;
  itoa(uqtip,buffer,2);
  printf("uqtip (moff>>2)= %s (%u)\n", buffer,uqtip);


  printf("----------------------------------------------\n");


  printf("setbit \n");
  moff= 0b10101;
  uqtip=0b01000;
 
  itoa(moff,buffer2,2);
  itoa(uqtip,buffer,2);

  
  unsigned short SetABit=moff|uqtip;
  itoa(SetABit,buffer3,2);


  printf("moff     = %s (%u)\n",buffer2,moff);
  printf("uqtip   = %s (%u)\n", buffer,uqtip);
  printf("SetABit = %s (%u)\n", buffer3,SetABit);


  printf("clearbit \n");
  moff= 0b10101;
  uqtip=0b00100;
 
  itoa(moff,buffer2,2);
  itoa(uqtip,buffer,2);

  SetABit=moff&(uqtip^0xff);
  itoa(SetABit,buffer3,2);



  printf("moff     = %s (%u)\n",buffer2,moff);
  printf("uqtip   = %s (%u)\n", buffer,uqtip);
  printf("SetABit = %s (%u)\n", buffer3,SetABit);



  printf("read bit \n");  
  moff= 0b10101;
  uqtip=0b00100;
 
  itoa(moff,buffer2,2);
  itoa(uqtip,buffer,2);

  
  SetABit= (moff&uqtip)>>2;
  
  itoa(SetABit,buffer3,2);

    
  printf("moff     = %s (%u)\n",buffer2,moff);
  printf("uqtip    = %s (%u)\n", buffer,uqtip);
  printf("ReadABit = %s (%u)\n", buffer3,SetABit);


  printf("----------------------------------\n");

  char myBit=3;
  char theByte=0b10101;

  itoa(theByte,buffer,2);
  printf("theByte     = %s (%u)\n",buffer2,theByte);


  printf("Is bit 5 set?: %d\n", bit_test(5,theByte));
  printf("Is bit 4 set?: %d\n", bit_test(4,theByte));
  printf("Is bit 3 set?: %d\n", bit_test(3,theByte));
  printf("Is bit 2 set?: %d\n", bit_test(2,theByte));
  printf("Is bit 1 set?: %d\n", bit_test(1,theByte));
  printf("Is bit 0 set?: %d\n", bit_test(0,theByte));


  unsigned short ipfrag=0;
  unsigned short ipflag=2;
  unsigned short ipfrfl=0;
  
  itoa(ipfrag,buffer3,2);
  printf("ipfrag     = %s (%u)\n",buffer3,ipfrag);
  itoa(ipflag,buffer2,2);
  printf("ipflag     = %s (%u)\n",buffer2,ipflag);

  ipfrfl=ipflag<<13;
  itoa(ipfrfl,buffer2,2);
  printf("ipfrfl (shift)    = %s (%u)\n",buffer2,ipfrfl);

  ipfrfl=ipfrfl|ipfrag;
  itoa(ipfrfl,buffer2,2);
  printf("ipfrfl (or)       = %s (%u)\n",buffer2,ipfrfl);
  


  return 1;
}
