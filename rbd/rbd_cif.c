/* rbd_cif.c - initialize, insert, remove, search */ 

#include "rbd_cif.h"

int initialize() 
{ 
     int * result;
  
     result = initialize_1(NULL,handle); 
     if (result == (int *)NULL) 
         cli_error();
     
     return *result; 
} 

int insert(char *item) 
{ 
     char **arg; 
     int * result;
     
     arg = &item; 
     result =  insert_1(arg, handle); 
     
     if (result == (int *)NULL) 
         cli_error();
     
      return *result; 
} 

int remove(char *item) 
{ 
  char **arg; 
  int * result;

  arg = &item; 

  result = remove_1(arg, handle); 
  if (result == (int *)NULL) 
      cli_error();

  return *result;
} 

int search(char *item) 
{ 
  char **arg; 
  int * result;
  arg = &item; 

  result = search_1(arg, handle); 
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
