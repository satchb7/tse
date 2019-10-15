#include "hash.h"
#include "../step6/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fn(void* element){
  char* string=(char*)element;
  if (strcmp(string,"hey2")==0){
    printf("found it\n"); 
  }
  else{
    printf("Not it\n");
  }
  printf("%s\n",string);
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
  const char* key="key1";
  queue_t* queue=qopen();
  qput(queue,(void*)key);
  int returncode=hput(hash,queue,key,strlen(key));
  printf("%d\n",returncode);
  const char* key2="hey2";
  queue_t* queue2=qopen();
  qput(queue,(void*)key2);
  int returncode2=hput(hash,queue2,key2,strlen(key2));
  printf("%d\n",returncode2);
  char* returned=hsearch(hash,&searchfn,key2,strlen(key2));
  printf("returned = %s\n",returned);
  char* returned2=hremove(hash,&searchfn,key2,strlen(key2));
  printf("remove returned =%s\n",returned2);
  char* searchnotinlist=hsearch(hash,&searchfn,key2,strlen(key2));
  printf("searchnotinlist = %s\n",searchnotinlist);
  hclose(hash);
}
