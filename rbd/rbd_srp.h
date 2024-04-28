/* rbd_srp.h - funções do servidor: inicializar, insere, remove, busca */ 

#include <rpc/rpc.h> 
#include "rbd.h"

#define BDSIZE  100
#define MAXWORD  32


int inicializar();

int insere(char *);

int remover(char *);

int busca(char *);




