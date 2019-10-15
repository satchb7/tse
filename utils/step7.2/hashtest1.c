#include "hash.h"
#include "../step6/queue.h"
#include "../step3/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  printf("testing opening hashtable with size 500 and closing\n");
  hashtable_t* hash=hopen(500);
  if (hash == NULL){
    exit(EXIT_FAILURE);
  }
  hclose(hash);
  exit(EXIT_SUCCESS);
}
