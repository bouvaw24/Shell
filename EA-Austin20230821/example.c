
//Function to read a line of input


// Function to tokenize the input


// Function to free the token array


// Function to change the current directory
#include "header.h"

int
main(void) {
    char *input;
    char **tokens;
    int status;

    while (1) {
        input = read_input();
        if (input == NULL) {
            
            break;
        }

        tokens = tokenize_input(input);

        if (tokens[0] == NULL) {
            
            free_tokens(tokens);
            free(input);
            continue;
        }

        if (strcmp(tokens[0], "cd") == 0) {
            // Change directory
            if (tokens[1] == NULL) {
                fprintf(stderr, "cd: expected argument\n");
            } else {
                change_directory(tokens[1]);
            }
        } else if (strcmp(tokens[0], "exit") == 0) {
            // Exit the shell
            free_tokens(tokens);
            free(input);
            break;
        } else {
            // Fork a child process and execute the command
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execvp(tokens[0], tokens);
                perror("Command execution error");
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                // Parent process
                waitpid(pid, &status, 0);
            } else {
                // Fork error
                perror("Fork error");
            }
        }

        free_tokens(tokens);
        free(input);
    }

    return 0;
}
