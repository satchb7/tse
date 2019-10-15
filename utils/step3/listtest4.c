#include "list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  printf("removing from empty list\n");
  car_t* getfromempty=lremove("9XL");
  if (getfromempty == NULL){
    printf("Got NULL back, list is empty\n");
  }
  printf("putting in five cars with plates 9XL,88L,2XL,22L,33L\n");
  car_t car1={NULL,"9XL",2000.0,2000};
  car_t car2={NULL,"88L",3000.0,2000};
  car_t car3={NULL,"2XL",799.0,2000};
  car_t car4={NULL,"22L",3000.0,2000};
  car_t car5={NULL,"33L",799.0,2000};
  lput(&car1);
  lput(&car2);
  lput(&car3);
  lput(&car4);
  lput(&car5);
  printf("getting from end of list car-33L\n");
  car_t* carback=lremove("33L");
  printf("Got car %s\n",carback->plate);
  if (strcmp(carback->plate,"33L")!= 0){
    exit(EXIT_FAILURE);
  }
  printf("getting from front of list car-9XL\n");
  car_t* carback2=lremove("9XL");
  printf("Got car %s\n",carback2->plate);
  if (strcmp(carback2->plate,"9XL")!= 0){
    exit(EXIT_FAILURE);
  }
  printf("getting from middle of list car-2XL\n");
  car_t* carback3=lremove("2XL");
  printf("Got car %s\n",carback3->plate);
  if (strcmp(carback3->plate,"2XL")!= 0){
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
  

}
