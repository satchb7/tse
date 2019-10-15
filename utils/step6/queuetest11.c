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
  printf("Testing concatenating two queues\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  printf("putting in 3 char*, Tom, Bob, Gill into queue in this order\n");
  char* tom="Tom";
  char* bob="Bob";
  char* gill="Gill";
  qput(queue,tom);
  qput(queue,bob);
  qput(queue,gill);
  printf("Making a new queue with people\n");
  printf("Putting in Tina, Patt and Rick into a new queue\n");
  queue_t* queue3=qopen();
  char* tina="Tina";
  char* patt="Patt";
  char* rick="Rick";
  qput(queue3,tina);
  qput(queue3,patt);
  qput(queue3,rick);
  printf("now we will combine this new queue and the first queue\n");
  qconcat(queue3,queue);
  printf("searching for tom from first queue in other queue, tom should be in this queue now\n");
  char* istom=qsearch(queue3,&searchfn,tom);
  if (istom == NULL){
    exit(EXIT_FAILURE);
  }
  printf("searching for gill from first queue in other queue, gill should be in this queue now\n");
  char* isgill=qsearch(queue3,&searchfn,gill);
  if (isgill == NULL){
    exit(EXIT_FAILURE);
  }
  printf("Printing the new combined queue\n");
  qapply(queue3,&fn);
  qclose(queue3);
  exit(EXIT_SUCCESS);
}
