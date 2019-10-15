#include <stdint.h>
#include "list.h"
#include <string.h>

static car_t *front=NULL;

int32_t lput(car_t *cp){
  if (cp == NULL){
    return 1;
  }
  cp->next=front;
  front=cp;
  return 0;
}

car_t *lget(){
  if (front == NULL){
    return NULL;
  }
  else{
    car_t* toreturn=front;
    front=front->next;
    return toreturn;
  }
}

void lapply(void (*fn)(car_t *cp)){
  car_t* curr;
  for(curr=front;curr != NULL;curr=curr->next){
    fn(curr);
  }
}

car_t *lremove(char *platep){
  car_t* curr;
  car_t* currprev;
  for(curr=front;curr != NULL;curr=curr->next){
    if (strcmp(platep,front->plate)==0){
      car_t* toreturn=front;
      front=front->next;
      return toreturn;
    }
    if (strcmp(platep,curr->plate)==0){
      car_t* returnitem=curr;
      currprev->next=curr->next;
      return returnitem;
    }
    currprev=curr;
  }
  return NULL;
}
