#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    for (int i = 0; argv[1][i] != '\0'; ++i) {
        if ((argv[1][i] >= 'A' && argv[1][i] <= 'M') || (argv[1][i] >= 'a' && argv[1][i] <= 'm'))
            putchar(argv[1][i] + 13);
        else if ((argv[1][i] >= 'N' && argv[1][i] <= 'Z') || (argv[1][i] >= 'n' && argv[1][i] <= 'z'))
            putchar(argv[1][i] - 13);
        else
            putchar(argv[1][i]);
    }
    return EXIT_SUCCESS;
}