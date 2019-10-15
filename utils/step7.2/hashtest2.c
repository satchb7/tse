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
  printf("Testing doing operations on empty hashtable\n");
  printf("opening hashtable with size 500\n");
  hashtable_t* hash=hopen(500);
  if (hash == NULL){
    printf("NULL hashtable");
  }
  printf("trying to remove from empty hashtable\n");
  char* removekey="key";
  car_t* removefromempty=hremove(hash,&searchfn,removekey,strlen(removekey));
  if (removefromempty != NULL){
    exit(EXIT_FAILURE);
  }
  printf("searching in empty hashtable\n");
  car_t* searchfromempty=hsearch(hash,&searchfn,removekey,strlen(removekey));
  if (searchfromempty != NULL){
    exit(EXIT_FAILURE);
  }
  printf("Closing hashtable\n");
  hclose(hash);
  exit(EXIT_SUCCESS);
}
