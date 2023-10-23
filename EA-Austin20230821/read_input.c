#include "header.h"

char
*read_input(void) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    if (!buffer) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    printf(">> ");
    if (fgets(buffer, MAX_BUFFER_SIZE, stdin) == NULL) {
        free(buffer);
        return NULL; 
    }

    return buffer;
}
