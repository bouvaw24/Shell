#include "header.h"
void
change_directory(char *dir) {
    if (chdir(dir) != 0) {
        perror("cd");
    }
}
