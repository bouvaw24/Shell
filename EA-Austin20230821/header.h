#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_TOKENS 64
char *read_input(void);
char **tokenize_input(char *input);
void free_tokens(char **tokens);
void change_directory(char *dir);
