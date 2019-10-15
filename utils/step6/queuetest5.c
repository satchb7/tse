#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fn(void* element){
  char* str=(char*)element;
  printf("%s\n",str);
}
int main(){
  printf("Testing putting into empty and nonempty queue\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  printf("putting in 3 char*, Tom, Bob, Gill into queue in this order\n");
  char* tom="Tom";
  char* bob="Bob";
  char* gill="Gill";
  int32_t returncode1=qput(queue,tom);
  if (returncode1 != 0){
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
