#include <stdio.h>
#include <stdlib.h>

int haszero = 0;

int exponentiate(int num, int exp) {
    int result = num;
    if (exp == 0)
        return 1;
    while (exp > 1) {
        result *= num;
        --exp;
    }
    return result;
}

int numdigits(int num) {
    int digits = 0;
    for (int n = num; n > 0; n /= 10)
        ++digits;
    return digits;
}

void fill(int sudoku[9][9], int row, int col) {
    int missing = 0, twoBlanks = 0;
    for (int i = 1; i <= 9; ++i) {
        int found = 0;
        for (int j = 0; j < 9; ++j) {
            if (i == sudoku[row][j])
                found = 1;
        }
        if (!found) {
            if (missing)
                twoBlanks = 1;
            else
                missing = i;
        }
    }
    if (twoBlanks) {
        for (int i = 1; i <= 9; ++i) {
            int found = 0;
            for (int j = 0; j < 9; ++j) {
                if (i == sudoku[j][col])
                    found = 1;
            }
            if (!found)
                missing = i;
        }
    }
    sudoku[row][col] = missing;
}

int validate(int arr[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (arr[i] == arr[j])
                return 0;
        }
    }
    return 1;
}

int validateRows(int sudoku[9][9]) {
    for (int i = 0; i < 9; ++i) {
        int n = 0;
        int arr[9];
        for (int j = 0; j < 9; ++j) {
            if (!sudoku[i][j]) {
                haszero = 1;
                fill(sudoku, i, j);
            }
            arr[n++] = sudoku[i][j];
        }
        if (!validate(arr))
            return 0;
    }
    return 1;
}

int validateColumns(int sudoku[9][9]) {
    for (int j = 0; j < 9; ++j) {
        int n = 0;
        int arr[9];
        for (int i = 0; i < 9; ++i) {
            if (!sudoku[i][j]) {
                haszero = 1;
                fill(sudoku, i, j);
            }
            arr[n++] = sudoku[i][j];
        }
        if (!validate(arr))
            return 0;
    }
    return 1;
}

int validateBoxes(int sudoku[9][9]) {
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            int n = 0;
            int arr[9];
            for (int i = row; i < row + 3; ++i) {
                for (int j = col; j < col + 3; ++j) {
                    if (!sudoku[i][j]) {
                        haszero = 1;
                        fill(sudoku, i, j);
                    }
                    arr[n++] = sudoku[i][j];
                }
            }
            if (!validate(arr))
                return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("error\n");
        return 0;
    }
    int num, num2;
    int sudoku[9][9] = {0};
    for (int i = 0; i < 9 && fscanf(fp, "%d", &num) > 0; ++i) {
        while (num < exponentiate(10, 8)) {
            fscanf(fp, "%d", &num2);
            num *= exponentiate(10, 9 - numdigits(num));
            num += num2 * exponentiate(10, 9 - numdigits(num));
        }
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = num / exponentiate(10, 8 - j);
            num %= exponentiate(10, 8 - j);
        }
    }
    if (validateRows(sudoku) && validateColumns(sudoku) && validateBoxes(sudoku)) {
        if (haszero)
            printf("solvable\n");
        else
            printf("correct\n");
    }
    else {
        if (haszero)
            printf("unsolvable\n");
        else
            printf("incorrect\n");
    }
    return EXIT_SUCCESS;
}