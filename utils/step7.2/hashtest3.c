#include "hash.h"
#include "../step6/queue.h"
#include "../step3/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

bool searchfn(void* elementp, const void* searchkeyp) {
  car_t* car=elementp;
  char* plate=car->plate;
  const char* str=searchkeyp;
  if (strcmp(plate,str) == 0){
    return true;
  }
  return false;
}

void printcar(void* ep){
  car_t* car=ep;
  printf("plate=%s\n",car->plate);
}

int main(){
  printf("Testing putting car data structures in hashtable\n");
  printf("opening hashtable with size 500\n");
  hashtable_t* hash=hopen(500);
  printf("Putting car data structure in hashtable with key as it's plate\n");
  char* two="2Z9";
  car_t secondcar={NULL,"2Z9",3000,2011};
  char* three="91G";
  car_t thirdcar={NULL,"91G",1600,2019};
  int32_t returncode=hput(hash,&secondcar,two,strlen(two));
  if (returncode != 0){
    exit(EXIT_FAILURE);
  }
  int32_t returncode2=hput(hash,&thirdcar,three,strlen(three));
  if (returncode2 != 0){
    exit(EXIT_FAILURE);
  }
  printf("Putting in cars with plate 2Z9,91G,9XL\n");
  char* one="9XL";
  car_t firstcar={NULL,"9XL",2000,1998};
  int32_t returncode3=hput(hash,&firstcar,one,strlen(one));
  if (returncode3 != 0){
    exit(EXIT_FAILURE);
  }
  printf("Applying func to print plates of all cars in table\n");
  happly(hash,&printcar);
  hclose(hash);
  exit(EXIT_SUCCESS);
}
