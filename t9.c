#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.txt", "r");

    char a[1005];
    char b[1005];

    fscanf(file, "%s", a);
    fscanf(file, "%s", b);

    int len_a = strlen(a);
    int len_b = strlen(b);

    int result_len = len_a + len_b;

    int *result = calloc(result_len, sizeof(int));

    for (int i = len_a - 1 ; i >= 0 ; i -- ) {
        for (int j = len_b - 1 ; j >= 0 ; j -- ) {
            int digit_a = a[i] - '0';
            int digit_b = b[j] - '0';

            int product = digit_a * digit_b;

            int position = i + j + 1;

            result[position] += product;
        }
    }

    for (int i = result_len - 1; i > 0 ; i -- ) {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }

    int start = 0;

    while (start < result_len - 1 && result[start] == 0) {
        start ++ ;
    }

    for (int i = start ; i < result_len ; i ++ ) {
        printf("%d", result[i]);
    }

    printf("\n");

    fclose(file);

    return 0;
}