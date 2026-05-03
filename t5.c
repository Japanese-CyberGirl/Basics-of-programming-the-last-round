#include <stdio.h>
#include <stdlib.h>

void scan_array_long_long(long long *array, int n, FILE *file) {
    for (int i = 0; i < n; i++) {
        fscanf(file, "%lld", &array[i]);
    }
}

int find_min_index(long long *array, int n, long long C) {
    if (n == 1) {
        return 0;
    }

    int left = 0;
    int right = n - 2;
    int answer = n - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        long long difference = array[middle + 1] - array[middle] + C;

        if (difference >= 0) {
            answer = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return answer;
}

int main() {

    FILE *input = fopen("input.txt", "r");

    int n = 0;
    fscanf(input, "%d", &n);

    long long *array = calloc(n, sizeof(long long));

    scan_array_long_long(array, n, input);

    int q = 0;
    fscanf(input, "%d", &q);

    long long C = 0;

    for (int i = 0; i < q; i++) {
        fscanf(input, "%lld", &C);

        int result = find_min_index(array, n, C);

        printf("%d\n", result);
    }

    free(array);

    fclose(input);

    return 0;
}