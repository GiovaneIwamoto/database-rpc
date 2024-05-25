/* rbd_sif.c - initialize_1_svc, insert_1_svc, remove_1_svc, search_1_svc */ 
#include <rpc/rpc.h> 
#include "rbd.h" 
#include "rbd_srp.h"

static int retcode; 

int *initialize_1_svc(i,req)
void *i;
struct svc_req *req; 
{ 
  retcode = initialize(); 
  return &retcode; 
} 

int *insert_1_svc(i,req) 
char **i; 
struct svc_req *req;
{ 
  retcode = insert(*i); 
  return &retcode; 
}

int *remove_1_svc(i,req) 
char **i; 
struct svc_req *req;
{ 
      retcode = remove(*i); 
  return &retcode; 
} 

int *search_1_svc(i,req) 
char **i; 
struct svc_req *req;
{ 
  retcode = search(*i); 
  return &retcode; 
}
