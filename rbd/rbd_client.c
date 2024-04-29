#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbd.h"

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    CLIENT *cl; // Handle do cliente
    char *server; // Endereço do servidor
    char *word; // Palavra a ser manipulada no banco de dados remoto
    int result; // Resultado das operações remotas

    if (argc < 2) {
        fprintf(stderr, "Uso: %s servidor\n", argv[0]);
        exit(1);
    }
    server = argv[1];

    // Criar handle do cliente
    cl = clnt_create(server, RBDPROG, RDBVERS, "tcp");
    if (cl == NULL) {
        clnt_pcreateerror(server);
        exit(1);
    }

    // Inicializar o banco de dados remoto
    result = inicializar_1(NULL, cl);
    if (result == 0) {
        fprintf(stderr, "Erro ao inicializar o banco de dados remoto\n");
        clnt_perror(cl, server);
        exit(1);
    } else {
        printf("Banco de dados remoto inicializado com sucesso\n");
    }

    // Exemplo de inserção de uma palavra no banco de dados remoto
    word = "exemplo";
    result = insere_1(&word, cl);
    if (result == 0) {
        fprintf(stderr, "Erro ao inserir a palavra no banco de dados remoto\n");
        clnt_perror(cl, server);
        exit(1);
    } else {
        printf("Palavra inserida no banco de dados remoto\n");
    }

    // Exemplo de busca de uma palavra no banco de dados remoto
    word = "exemplo";
    result = busca_1(&word, cl);
    if (result == 0) {
        printf("Palavra não encontrada no banco de dados remoto\n");
    } else {
        printf("Palavra encontrada no banco de dados remoto\n");
    }

    // Exemplo de remoção de uma palavra do banco de dados remoto
    word = "exemplo";
    result = remove_1(&word, cl);
    if (result == 0) {
        fprintf(stderr, "Erro ao remover a palavra do banco de dados remoto\n");
        clnt_perror(cl, server);
        exit(1);
    } else {
        printf("Palavra removida do banco de dados remoto\n");
    }

    // Destruir handle do cliente
    clnt_destroy(cl);

    return 0;
}
