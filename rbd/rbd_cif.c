/* rbd_cif.c - inicializar, insere, remove, busca */ 

#include "rbd_cif.h"

int inicializar() 
{ 
     int * result;
  
     result = inicializar_1(NULL,handle); 
     if (result == (int *)NULL) 
         cli_error();
     
     return *result; 
} 

int insere(char *item) 
{ 
     char **arg; 
     int * result;
     
     arg = &item; 
     result =  insere_1(arg, handle); 
     
     if (result == (int *)NULL) 
         cli_error();
     
      return *result; 
} 

int remover(char *item) 
{ 
  char **arg; 
  int * result;

  arg = &item; 

  result = remove_1(arg, handle); 
  if (result == (int *)NULL) 
      cli_error();

  return *result;
} 

int busca(char *item) 
{ 
  char **arg; 
  int * result;
  arg = &item; 

  result = busca_1(arg, handle); 
  if (result == (int *)NULL) 
      cli_error();

  return *result;
}


void cli_error()
{
   /* An error occurred while calling the server. */
   /* Print error message and die. */
   printf("RPC falhou\n");
   clnt_perror(handle, "RPC error");
   clnt_destroy( handle );
   exit(1);
}
