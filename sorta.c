#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int i, j, min;
    for (i = 1; i < argc - 1; ++i) {
        min = i;
        for (j = i + 1; j < argc; ++j) {
            if (strcmp(argv[j], argv[min]) < 0)
                min = j;
        }
        char *temp = argv[min];
        argv[min] = argv[i];
        argv[i] = temp;
    }
    for (int i = 1; argv[i] != NULL; ++i)
        printf("%s\n", argv[i]);
    return EXIT_SUCCESS;
}