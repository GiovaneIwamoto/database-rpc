/* rbd_srp.h - server: initialize, insert, remove, search */ 

#include <rpc/rpc.h> 
#include "rbd.h"

#define BDSIZE  100
#define MAXWORD  32


int initialize();

int insert(char *);

int remove(char *);

int search(char *);




