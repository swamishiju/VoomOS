#include <stdlib.h>

char* itoa(int integer, char* buffer, int base){
  int fbp=0, rem=0;
  char buff[16];
  bool neg=false;
  char *ERROR_MSG = "ITOA ERROR";

  if (base<=1){
    while (*ERROR_MSG){
      buffer[fbp++] = *ERROR_MSG;
      ERROR_MSG++;
    }
    return buffer;
  }
  
  buff[fbp++] = '\0';

  if (integer<0){
    integer = -integer;
    neg=true;
  }

  while(integer){
    rem = integer%base;
    if (rem<10)
      buff[fbp++] = 48 + rem;
    else 
      buff[fbp++] = 55 + rem;


    integer = (int)integer/base;
  }

  if (neg)
    buff[fbp++]='-';


  for (int i=1;i<=fbp;i++){
    buffer[fbp-i] = buff[i-1];
  }

  return buffer;
}
