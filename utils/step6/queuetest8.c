#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fn(void* element){
  char* str=(char*)element;
  printf("%s\n",str);
}

void fn2(void* element){
  int* num=(int*)element;
  printf("%d\n",*num);
}

bool searchfn(void* elementp,const void* keyp){
  if (strcmp(elementp,keyp) == 0){
    return true;
  }
  return false;
}

int main(){
  printf("testing whether a removed element is out of queue\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  printf("adding Mike,TJ,Rachel in this order to queue\n");
  char* mike="Mike";
  char* tj="TJ";
  char* rachel="Rachel";
  qput(queue,mike);
  qput(queue,tj);
  qput(queue,rachel);
  printf("printing the queue again we have\n");
  qapply(queue,&fn);
  char* firstkey="Mike";
  printf("removing mike from queue\n");
  char* firstitem=qremove(queue,&searchfn,firstkey);
  printf("%s was at beginning\n",firstitem);
  printf("Searching if Mike is in queue\n");
  void* isgill=qsearch(queue,&searchfn,firstkey);
  if (isgill == NULL){
    printf("We got NULL back Mike is not in the queue\n");
  }
  if (isgill != NULL){
    exit(EXIT_FAILURE);
  }
  qclose(queue);
  exit(EXIT_SUCCESS);
}
