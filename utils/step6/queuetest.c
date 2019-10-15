#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fn(void* element){
  char* string=(char*)element;
  if (strcmp(string,"Hello")==0){
    printf("found it\n"); 
  }
  else{
    printf("Not it\n");
  }
}

bool searchfn(void* elementp,const void* keyp){
  if (strcmp(elementp,keyp) == 0){
    printf("Match in searchfunction\n");
    return true;
  }
  return false;

}
int main(){
  printf("testing opening and closing queue\n");
  queue_t* queue=qopen();
  if (queue == NULL){
    exit(EXIT_FAILURE);
  }
  qclose(queue);
  exit(EXIT_SUCCESS);
}
