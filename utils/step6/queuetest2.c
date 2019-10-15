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
  printf("Testing all functions in one long testfile\n");
  printf("Making a queue\n");
  queue_t* queue=qopen();
  if (queue == NULL){
    exit(EXIT_FAILURE);
  }
  printf("removing from empty list\n");
  char* key="Ashton";
  char* removefromempty=qremove(queue,&searchfn,key);
  if (removefromempty == NULL){
    printf("got NULL back, queue is empty\n");
  }
  printf("applying function that prints all names to empty queue\n");
  qapply(queue,&fn);
  printf("Getting from an empty list\n");
  char* getfromempty=qget(queue);
  if (getfromempty == NULL){
    printf("queue is empty\n");
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
  printf("printing the queue again we have\n");
  qapply(queue,&fn);
  printf("removing from middle of queue\n");
  char* midkey="TJ";
  char* middleperson=qremove(queue,&searchfn,midkey);
  printf("%s was in the middle\n",middleperson);
  printf("removing from end of list");
  char* endkey="Rachel";
  char* lastitem=qremove(queue,&searchfn,endkey);
  printf("last person in queue was %s\n",lastitem);
  printf("removing from beginning of queue\n");
  char* firstkey="Gill";
  char* firstitem=qremove(queue,&searchfn,firstkey);
  printf("%s was at beginning\n",firstitem);
  printf("printing new queue\n");
  printf("Searching if Gill is in queue\n");
  void* isgill=qsearch(queue,&searchfn,firstkey);
  if (isgill == NULL){
    printf("We got NULL back gill is not in the queue\n");
  }
  qapply(queue,&fn);
  queue_t* queue2=qopen();
  printf("Making another queue\n");
  printf("This queue will hold int pointers\n");
  int one=1;
  int two=2;
  int three=3;
  qput(queue2,&one);
  qput(queue2,&two);
  qput(queue2,&three);
  printf("printing this new list\n");
  qapply(queue2,&fn2);
  printf("Making a third queue with people\n");
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
  printf("Printing the new combined queue\n");
  qapply(queue3,&fn);
  qclose(queue2);
  qclose(queue3);
  return 0;
}
