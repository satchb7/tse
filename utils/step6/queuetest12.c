#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fn(void* element){
  char* str=(char*)element;
  printf("%s\n",str);
}

bool searchfn(void* elementp,const void* keyp){
  if (strcmp(elementp,keyp) == 0){
    return true;
  }
  return false;
}

int main(){
  printf("Testing concatenating two queues\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  qput(queue,"Hello");
  qput(queue,"Bob");
  qput(queue,"Sam");
  queue_t* queue2=qopen();
  qconcat(queue,queue2);
  qput(queue,"David");
  qput(queue,"Irene");
  qget(queue);
  qget(queue);
  qget(queue);
  qget(queue);
  qget(queue);
  qget(queue);
  qput(queue,"David");
  qapply(queue,&fn);
  qclose(queue);
}
