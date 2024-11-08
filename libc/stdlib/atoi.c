#include <stdlib.h>

int atoi(const char* a){
  int apoint=0, acc=0;
  while (*(a+(apoint++))){
    acc = acc*10 + (*a - 0x30);
  }

  return acc;
}
