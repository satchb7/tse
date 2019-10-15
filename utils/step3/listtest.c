#include "list.h"
#include <stdint.h>
#include <stdio.h>

/* Prints if price of car is higher than set number */
void fn(car_t* cp){
  if ((cp->price) > 200.1){
    printf("Match-price=%lf car=%s\n",cp->price,cp->plate);
  }
}
int main(){
  printf("Applying function to empty list\n");
  lapply(&fn);
  car_t* itemfromget1=lget();
  if (itemfromget1 == NULL){
    printf("Empty list\n");
  }
  car_t* itemfromremove1=lremove("Hello");
  if (itemfromremove1 == NULL){
    printf("licence plate Hello not in list\n");
  }
  car_t car1={NULL,"9XL",100.01,2000};
  int32_t successornot=lput(&car1);
  printf("successornot lput-%d\n",successornot);
  car_t car2={NULL,"DYZ",500.2,4000};
  int32_t successornot2=lput(&car2);
  printf("successornot lput-%d\n",successornot2);
  printf("applying function to nonempty list to find car with price higher than 200.1\n");
  lapply(&fn);
  car_t* itemfromremove2=lremove("DYZ");
  if (itemfromremove2 == NULL){
    printf("licence plate  not in list\n");
  }
  printf("itemfromremove - item we got is %s\n",itemfromremove2->plate);
  car_t* itemfromremove3=lremove("9XL");
  if (itemfromremove3 == NULL){
    printf("licence plate not in list\n");
  }
  printf("itemfromremove - item we got is %s\n",itemfromremove3->plate);
  car_t* itemfromget=lget();
  if (itemfromget == NULL){
    printf("Empty list\n");
  }
  else{
     printf("item we got is %s\n",itemfromget->plate);
  }
  car_t car3={NULL,"A1",1000.01,2019};
  lput(&car3);
  car_t car4={NULL,"B2",1210.01,2010};
  lput(&car4);
  car_t car5={NULL,"B3",500.01,2010};
  lput(&car5);
  car_t car6={NULL,"B4",4055,2016};
  lput(&car6);
  car_t* itemfromremove4=lremove("B2");
  printf("itemfromremove - item we got is %s\n",itemfromremove4->plate);
  car_t* get1=lget();
  car_t* get2=lget();
  car_t* get3=lget();
  printf("getitem - item we got is %s\n",get1->plate);
  printf("getitem - item we got is %s\n",get2->plate);
  printf("getitem - item we got is %s\n",get3->plate);
  car_t* get4=lget();
  if (get4 == NULL){
    printf("empty list");
  }
  
}
