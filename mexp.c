#include <stdio.h>
#include <stdlib.h>

int dim, **matrix, **product;

void print() {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            printf("%d", matrix[i][j]);
            if (j < dim - 1)
                printf(" ");
        }
        printf("\n");
    }
}

void multiply(int **a, int **b) {
    product = malloc(dim * sizeof(int *));
    product[0] = malloc(dim * dim * sizeof(int));
    for (int i = 1; i < dim; ++i)
        product[i] = product[i - 1] + dim;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < dim; ++k)
                product[i][j] += a[i][k] * b[k][j];
        }
    }
}

void exponentiate(int exp) {
    if (exp <= 1) 
        return;
    int **result = matrix;
    int c = exp;
    while (c > 1) {
        int **temp = result;
        multiply(matrix, result);
        result = product;
        if (c < exp) {
            free(temp[0]);
            free(temp);
        }
        --c;
    }
    int **temp = matrix;
    matrix = result;
    free(temp[0]);
    free(temp);
}

int main(int argc, char **argv) {
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL)
        return 0;
    int num, exp;
    fscanf(fp, "%d", &dim);
    matrix = malloc(dim * sizeof(int *));
    matrix[0] = malloc(dim * dim * sizeof(int));
    for (int i = 1; i < dim; ++i)
        matrix[i] = matrix[i - 1] + dim;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            if (fscanf(fp, "%d", &num) > 0)
                matrix[i][j] = num;
        }
    }
    fscanf(fp, "%d", &exp);
    exponentiate(exp);
    print();
    free(matrix[0]);
    free(matrix);
    return EXIT_SUCCESS;
}