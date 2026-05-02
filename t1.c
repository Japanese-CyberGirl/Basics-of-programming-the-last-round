#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int **matrix, int n, int m) {
    for (int i = 0 ; i < n; i ++ ) {
        for (int j = 0 ; j < m ; j ++ ) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_array(int *array, int n) {
    for (int i = 0 ; i < n ; i ++ ) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void addition(char *a, char *b, int **matrix, int *prefix, int *suffix) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char *answer = calloc(max_len + 1, sizeof(char));

    if (len_a == len_b) {
        for (int i = 0 ; i < len_a ; i ++ ) {
            int a_digit = a[i] - '0';
            int b_digit = b[i] - '0';

            answer[i] = matrix[a_digit][b_digit] + '0';
        }
    }

    if (len_a < len_b) {
        int diff = len_b - len_a;
        for (int i = 0 ; i < diff ; i ++ ) {
            int b_digit = b[i] - '0';

            answer[i] = prefix[b_digit] + '0';
        }

        for (int i = diff ; i < len_b ; i ++ ) {
            int a_digit = a[i - diff] - '0';
            int b_digit = b[i] - '0';

            answer[i] = matrix[a_digit][b_digit] + '0';
        }
    }

    if (len_a > len_b) {
        int diff = len_a - len_b;
        for (int i = 0 ; i < diff ; i ++ ) {
            int a_digit = a[i] - '0';

            answer[i] = suffix[a_digit] + '0';
        }

        for (int i = diff; i < len_a ; i ++ ) {
            int a_digit = a[i] - '0';
            int b_digit = b[i - diff] - '0';

            answer[i] = matrix[a_digit][b_digit] + '0';
        }
    }

    printf("%s\n", answer);
    free(answer);
}

int main(void) {

    FILE *file = fopen("input.txt", "r");

    int n = 10;

    int **matrix = calloc(n, sizeof(int*));
    for (int i = 0; i < n; i ++ ) {
        matrix[i] = calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }


    // первая таблица : @ + 0, @ + 1, ... , @ + 9
    // вторая таблица: 0 + @, 1 + @, ... , 9 + @

    int *special_prefix_array = calloc(n, sizeof(int));
    for (int i = 0 ; i < n ; i ++ ) {
        fscanf(file, "%d", &special_prefix_array[i]);
    }

    int *special_suffix_array = calloc(n, sizeof(int));
    for (int i = 0 ; i < n ; i ++ ) {
        fscanf(file, "%d", &special_suffix_array[i]);
    }


    int amount_of_tasks = 0;
    fscanf(file, "%d", &amount_of_tasks);

    for (int i = 0 ; i < amount_of_tasks ; i ++ ) {
        char a[1005];
        char b[1005];
        fscanf(file, "%s %s", a, b);

        addition(a, b, matrix, special_prefix_array, special_suffix_array);
    }

    fclose(file);
    for (int i = 0; i < n; i ++ ) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}