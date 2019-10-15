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
  printf("Testing all function in one long test file\n");
  printf("opening hashtable with size 500\n");
  hashtable_t* hash=hopen(500);
  if (hash == NULL){
    printf("NULL hashtable");
  }
  printf("trying to remove from empty hashtable\n");
  char* removekey="key";
  car_t* removefromempty=hremove(hash,&searchfn,removekey,strlen(removekey));
  if (removefromempty == NULL){
    printf("got back NULL,hashtable is empty\n");
  }
  printf("Putting car data structure in hashtable with key as it's plate\n");
  char* two="2Z9";
  car_t secondcar={NULL,"2Z9",3000,2011};
  char* three="91G";
  car_t thirdcar={NULL,"91G",1600,2019};
  hput(hash,&secondcar,two,strlen(two));
  hput(hash,&thirdcar,three,strlen(three));
  printf("Putting in cars with plate 2Z9,91G,9XL\n");
  char* one="9XL";
  car_t firstcar={NULL,"9XL",2000,1998};
  hput(hash,&firstcar,one,strlen(one));
  printf("Applying func to print plates of all cars in table\n");
  happly(hash,&printcar);
  printf("searching for car with plate-9XL\n");
  car_t* car=hsearch(hash,&searchfn,one,strlen(one));
  printf("Printing plate of car we got from search\n");
  printf("Plate=%s\n",car->plate);
  printf("Applying function to print plates of all cars in list\n");
  happly(hash,&printcar);
  printf("Removing car with plate 9XL\n");
  printf("Using remove function and using key=9XL\n");
  car_t* carremove=hremove(hash,&searchfn,one,strlen(one));
  printf("Printing plate of car we got from remove\n");
  printf("Plate=%s\n",carremove->plate);
  printf("Applying function to print plates of all cars in list\n");
  happly(hash,&printcar);
  printf("Removing car with plate 2Z9\n");
  printf("Using remove function and using key=2Z9\n");
  car_t* carremove2=hremove(hash,&searchfn,two,strlen(two));
  printf("Printing plate of car we got from remove\n");
  printf("Plate=%s\n",carremove2->plate);
  printf("Applying function to print plates of all cars in list\n");
  happly(hash,&printcar);
  hclose(hash);
}
