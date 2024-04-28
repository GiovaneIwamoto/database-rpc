/* rbd_sif.c - inicializar_1_svc, insere_1_svc, remove_1_svc, busca_1_svc */ 
#include <rpc/rpc.h> 
#include "rbd.h" 
#include "rbd_srp.h"

static int retcode; 

int *inicializar_1_svc(i,req)
void *i;
struct svc_req *req; 
{ 
  retcode = inicializar(); 
  return &retcode; 
} 

int *insere_1_svc(i,req) 
char **i; 
struct svc_req *req;
{ 
  retcode = insere(*i); 
  return &retcode; 
}

int *remove_1_svc(i,req) 
char **i; 
struct svc_req *req;
{ 
      retcode = remover(*i); 
  return &retcode; 
} 

int *busca_1_svc(i,req) 
char **i; 
struct svc_req *req;
{ 
  retcode = busca(*i); 
  return &retcode; 
}
