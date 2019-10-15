#include "list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("Getting from empty list\n");
  car_t* getfromempty=lget();
  if (getfromempty == NULL){
    printf("listisempty\n");
  }
  car_t firstcar={NULL,"9XL",2000,1998};
  car_t secondcar={NULL,"D9Z",999,2011};
  printf("Putting in firstcar with year 1998 and secondcar with year 2011\n");
  int32_t returncode=lput(&firstcar);
  if (returncode != 0){
    exit(EXIT_FAILURE);
  }
  lput(&secondcar);
  printf("Getting from list\n"); 
  car_t* getfromnonempty=lget();
  if (getfromnonempty == NULL){
    exit(EXIT_FAILURE);
  }
  int yearofcar=getfromnonempty->year;
  if (yearofcar !=2011){
    exit(EXIT_FAILURE);
  }
  printf("Year of car we got back is %d\n",yearofcar);
  exit(EXIT_SUCCESS);
}
