#include "list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void fn(car_t* cp){
  if ((cp->price) > 800){
    printf("Match-price=%lf car=%s\n",cp->price,cp->plate);
  }
}

int main(){
  printf("applying function to empty list\n");
  lapply(&fn);
  printf("putting in 3 cars with prices 2000,3000,799\n");
  car_t car1={NULL,"9XL",2000.0,2000};
  car_t car2={NULL,"88L",3000.0,2000};
  car_t car3={NULL,"2XL",799.0,2000};
  int32_t returncode=lput(&car1);
  if (returncode != 0){
    exit(EXIT_FAILURE);
  }
  int32_t returncode2=lput(&car2);
  if (returncode2 != 0){
    exit(EXIT_FAILURE);
  }
  lput(&car3);
  printf("putting in 3 cars with prices 2000,3000,799\n");
  printf("applying function to print cars with prices greater than 800\n");
  lapply(&fn);
  exit(EXIT_SUCCESS);
}
