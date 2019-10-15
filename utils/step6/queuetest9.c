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
  printf("testing having multiple queues open at same time and doing operations\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  if (queue == NULL){
    exit(EXIT_FAILURE);
  }
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
  printf("Making another queue");
  queue_t* queue2=qopen();
  if (queue2 == NULL){
    exit(EXIT_FAILURE);
  }
  printf("Making another queue\n");
  printf("This queue will hold int pointers\n");
  int one=1;
  int two=2;
  int three=3;
  int32_t returncodequeue2=qput(queue2,&one);
  if (returncodequeue2 != 0){
    exit(EXIT_FAILURE);
  }
  qput(queue2,&two);
  qput(queue2,&three);
  printf("printing this new list\n");
  qapply(queue2,&fn2);
  printf("Making a third queue with people\n");
  printf("Putting in Tina, Patt and Rick into a new queue\n");
  queue_t* queue3=qopen();
  if (queue3 == NULL){
    exit(EXIT_FAILURE);
  }
  char* tina="Tina";
  char* patt="Patt";
  char* rick="Rick";
  qput(queue3,tina);
  qput(queue3,patt);
  qput(queue3,rick);
  qclose(queue);
  qclose(queue2);
  qclose(queue3);
  exit(EXIT_SUCCESS);
}
