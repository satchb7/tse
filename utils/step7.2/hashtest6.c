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
  printf("Testing having multiple hashtables open\n");
  printf("opening hashtable with size 500\n");
  hashtable_t* hash=hopen(500);
  if (hash == NULL){
    printf("NULL hashtable");
    exit(EXIT_FAILURE);
  }
  printf("opening another hashtable with size 400\n");
  hashtable_t* hash2=hopen(400);
  if (hash2== NULL){
    exit(EXIT_FAILURE);
  }
  printf("opening another hashtable with size 20\n");
  hashtable_t* hash3=hopen(20);
  if (hash3 == NULL){
    exit(EXIT_FAILURE);
  }
  hclose(hash);
  hclose(hash2);
  hclose(hash3);
  exit(EXIT_SUCCESS);
}
