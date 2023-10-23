#include "header.h"

char **
tokenize_input(char *input) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    if (!tokens) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    int token_count = 0;
    char *token = strtok(input, " \t\n");
    while (token != NULL) {
        tokens[token_count] = strdup(token);
        if (!tokens[token_count]) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        token_count++;
        token = strtok(NULL, " \t\n");
    }

    tokens[token_count] = NULL;
    return tokens;
}
