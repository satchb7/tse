#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool searchfn(void* elementp,const void* keyp){
  if (strcmp(elementp,keyp) == 0){
    return true;
  }
  return false;
}

int main(){
  printf("Testing functions on empty queue\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  printf("removing from empty list\n");
  char* key="Ashton";
  char* removefromempty=qremove(queue,&searchfn,key);
  if (removefromempty == NULL){
    printf("got NULL back, queue is empty\n");
  }
  if (removefromempty != NULL){
    exit(EXIT_FAILURE);
  }
  printf("getting from empty list");
  char* fromempty=qget(queue);
  if (fromempty !=NULL){
    exit(EXIT_FAILURE);
  }
  qclose(queue);
  exit(EXIT_SUCCESS);
}
