/* rbd_cif.h - initialize, insert, remove, search */ 
#include <rpc/rpc.h> 
#include "rbd.h"

#define MAXWORD  32

CLIENT *handle;

int initialize();

int insert(char *);

int remove(char *);

int search(char *);

void cli_error();


