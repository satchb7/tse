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
  printf("testing that queue is agnostic\n");
  printf("Making a queue\n");
  queue_t* queue2=qopen();
  printf("This queue will hold int pointers\n");
  int one=1;
  int two=2;
  int three=3;
  int32_t returncode=qput(queue2,&one);
  if (returncode != 0){
    exit(EXIT_FAILURE);
  }
  int32_t returncode2=qput(queue2,&two);
  if (returncode2 != 0){
    exit(EXIT_FAILURE);
  }
  qput(queue2,&three);
  printf("printing this new list\n");
  qapply(queue2,&fn2);
  qclose(queue2);
  exit(EXIT_SUCCESS);
}
