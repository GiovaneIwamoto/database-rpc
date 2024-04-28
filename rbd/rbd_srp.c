/* rbd_srp.c - inicializar, insere, remove, busca*/ 

#include "rbd_srp.h"



/* Procedimentos remotos do servidor e dados globais */ 


char bd[BDSIZE][MAXWORD]; /* armazena o dicionário de palavras */ 
int  npalavras = 0;   /* número de palavras no dicionário */ 

int inicializar() 
{ 
    printf("Inicializando o banco. BD com zero palavras.\n");
    npalavras = 0; 
     return 1; 
} 

int insere(palavra) 
char *palavra; 
{ 
     printf("Inserindo BD[%d]=%s\n", npalavras, palavra);
     strcpy(bd[npalavras], palavra); 
     npalavras++; 
     return npalavras; 
}

int remover(palavra) 
char *palavra; 
{ 
  int i; 
  for (i=0; i<npalavras; i++) 
   if (strcmp(palavra, bd[i]) == 0) { 
        printf("Removendo BD[%d]=%s\n", i, palavra);
        npalavras--; 
        strcpy(bd[i], bd[npalavras]); 
        return 1; 
   } 
  return 0; 
} 

int busca(palavra) 
char *palavra; 
{ 
  int i; 
  for (i=0; i<npalavras; i++) 
   if (strcmp(palavra, bd[i]) == 0 ) {
       printf("Palavra %s encontrada em BD[%d]\n", palavra, i);
       return 1; 
   }
  return 0; 
} 

