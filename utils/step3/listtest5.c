
#include "list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("applying function to empty list\n");
  car_t* firstget=lget();
  if (firstget != NULL){
    exit(EXIT_FAILURE);
  }
}
