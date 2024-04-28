/* rbd_cif.h - inicializar, insere, remove, busca */ 
#include <rpc/rpc.h> 
#include "rbd.h"

#define MAXWORD  32

CLIENT *handle;  /* handle para procedimento remoto */ 

int inicializar();

int insere(char *);

int remover(char *);

int busca(char *);

void cli_error();


