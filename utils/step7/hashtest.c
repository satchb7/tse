#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fn(void* element){
  char* string=(char*)element;
  if (strcmp(string,"Hello")==0){
    printf("found it\n"); 
  }
  else{
    printf("Not it\n");
  }
}

bool searchfn(void* elementp, const void* searchkeyp) {
  if (strcmp(elementp,searchkeyp)==0){
    return true;
  }
  printf("%s\n",(char*)elementp);
  return false;
}

int main(){
  hashtable_t* hash=hopen(500);
  if (hash == NULL){
    printf("NULL hashtable");
  }
  const char* key="Hello";
  char* word="Value";
  int32_t index=hput(hash,word,key,strlen(key));
  printf("index=%d\n",index);
  char* regetword=hsearch(hash,&searchfn,key,strlen(key));
  printf("regetword=%s\n",regetword);
  happly(hash,fn);
  hclose(hash);
}
