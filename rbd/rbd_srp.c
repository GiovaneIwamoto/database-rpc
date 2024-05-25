/* rbd_srp.c - initialize, insert, remove, search*/ 

#include "rbd_srp.h"

char bd[BDSIZE][MAXWORD];
int  nwords = 0;

int initialize() 
{ 
    printf("Initializing database.\n");
    nwords = 0; 
     return 1; 
} 

int insere(word) 
char *word; 
{ 
     printf("Inserting at database [%d] = %s\n", nwords, word);
     strcpy(bd[nwords], word); 
     nwords++; 
     return nwords; 
}

int remove(word) 
char *word; 
{ 
  int i; 
  for (i=0; i<nwords; i++) 
   if (strcmp(word, bd[i]) == 0) { 
        printf("Removing from database [%d] = %s\n", i, word);
        nwords--; 
        strcpy(bd[i], bd[nwords]); 
        return 1; 
   } 
  return 0; 
} 

int search(word) 
char *word; 
{ 
  int i; 
  for (i=0; i<nwords; i++) 
   if (strcmp(word, bd[i]) == 0 ) {
       printf("Word %s not found\n", word);
       return 1; 
   }
  return 0; 
} 

