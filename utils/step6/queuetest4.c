#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void fn(void* element){
  char* str=(char*)element;
  printf("%s\n",str);
}
int main(){
  printf("Testing applying function to queue when empty and non empty\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  printf("applying function that prints all names to empty queue\n");
  qapply(queue,&fn);
  printf("putting in 3 char*, Tom, Bob, Gill into queue in this order\n");
  char* tom="Tom";
  char* bob="Bob";
  char* gill="Gill";
  int32_t returncode=qput(queue,tom);
  if (returncode != 0){
    exit(EXIT_FAILURE);
  }
  int32_t returncode2=qput(queue,bob);
  if (returncode2 != 0){
    exit(EXIT_FAILURE);
  }
  qput(queue,gill);
  printf("applying finction to print queue\n");
  qapply(queue,&fn);
  qclose(queue);
  exit(EXIT_SUCCESS);
}
