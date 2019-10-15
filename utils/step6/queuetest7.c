#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

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
  printf("testing removing from queue at different parts\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  printf("putting in 3 char*, Tom, Bob, Gill into queue in this order\n");
  char* tom="Tom";
  char* bob="Bob";
  char* gill="Gill";
  qput(queue,tom);
  qput(queue,bob);
  qput(queue,gill);
  printf("applying finction to print queue\n");
  qapply(queue,&fn);
  printf("getting first person in the queue\n");
  char* firstperson=qget(queue);
  printf("first person is %s\n",firstperson);
  char* secondperson=qget(queue);
  printf("getting second person in the queue\n");
  printf("Second person is %s\n",secondperson);
  printf("adding more people to this queue\n");
  printf("adding Mike,TJ,Rachel in this order to queue\n");
  char* mike="Mike";
  char* tj="TJ";
  char* rachel="Rachel";
  qput(queue,mike);
  qput(queue,tj);
  qput(queue,rachel);
  printf("printing the queue again we have\n");
  qapply(queue,&fn);
  printf("removing from middle of queue\n");
  char* midkey="TJ";
  char* middleperson=qremove(queue,&searchfn,midkey);
  if (strcmp(middleperson,midkey)!= 0){
    exit(EXIT_FAILURE);
  }
  printf("%s was in the middle\n",middleperson);
  printf("removing from end of list");
  char* endkey="Rachel";
  char* lastitem=qremove(queue,&searchfn,endkey);
  if (strcmp(lastitem,endkey)!= 0){
    exit(EXIT_FAILURE);
  }
  printf("last person in queue was %s\n",lastitem);
  printf("removing from beginning of queue\n");
  char* firstkey="Gill";
  char* firstitem=qremove(queue,&searchfn,firstkey);
  if (strcmp(firstitem,firstkey)!=0){
    exit(EXIT_FAILURE);
  }
  qapply(queue,&fn);
  qclose(queue);
  exit(EXIT_SUCCESS);
}
