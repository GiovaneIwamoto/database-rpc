#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbd.h"

#define MAX_WORD_LENGTH 100

void print_menu() {
    printf("\n1. Insert word\n");
    printf("2. Search word\n");
    printf("3. Remove word\n");
    printf("4. Exit\n");
    printf("\nChoose an option: ");
}

int main(int argc, char *argv[]) {
    CLIENT *clnt; // Client handle
    char *server; // Server adress
    
    char *word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char)); 
    int *result;
    int option;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server>\n", argv[0]);
        exit(1);
    }
    server = argv[1];

    // Create client handle
    clnt = clnt_create(server, RBDPROG, RDBVERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(server);
        exit(1);
    }

    // Initialize remote database    
    result = initialize_1(NULL, clnt);
    if (result == 0) {
        fprintf(stderr, "Error initializing remote database\n");
        clnt_perror(clnt, server);
        exit(1);
    } else {
        printf("Remote database initialized successfully\n");
    }

    while (1) {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1: // Insert word
                printf("Enter the word to be inserted: ");
                scanf("%s", word);
                result = insert_1(&word, clnt);
                if (result == 0) {
                    fprintf(stderr, "Error inserting word into remote database\n");
                    clnt_perror(clnt, server);
                    exit(1);
                } else {
                    printf("Word inserted into remote database\n");
                }
                break;

            case 2: // Search word
                printf("Enter the word to be searched: ");
                scanf("%s", word);
                result = search_1(&word, clnt);
                if (result == 0) {
                    printf("Word not found in remote database\n");
                } else {
                    printf("Word found in remote database\n");
                }
                break;

            case 3: // Remove word
                printf("Enter the word to be removed: ");
                scanf("%s", word);
                result = remove_1(&word, clnt);
                if (result == 0) {
                    fprintf(stderr, "Error removing word from remote database\n");
                    clnt_perror(clnt, server);
                } else {
                    printf("Word removed from remote database\n");
                }
                break;

            case 4: // Exit
                printf("Exiting the program.\n");
                clnt_destroy(clnt);
                exit(0);
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}