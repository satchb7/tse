#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void fn(void* element){
  char* str=(char*)element;
  printf("%s\n",str);
}

int main(){
  printf("Testing getting from queue\n");
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
  if (strcmp(firstperson,tom) != 0){
    exit(EXIT_FAILURE);
  }
  printf("first person is %s\n",firstperson);
  char* secondperson=qget(queue);
  if (strcmp(secondperson,bob) != 0){
    exit(EXIT_FAILURE);
  }
  printf("getting second person in the queue\n");
  printf("Second person is %s\n",secondperson);
  qclose(queue);
  exit(EXIT_SUCCESS);
}
