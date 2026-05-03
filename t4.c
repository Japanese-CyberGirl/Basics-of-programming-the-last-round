#include <stdio.h>
#include <stdlib.h>

double expo_small(double x) {
    double sum = 1.0;
    double term = 1.0;

    for (int i = 1; i <= 40; i++) {
        term *= x / i;
        sum += term;
    }

    return sum;
}

double expo(double x) {
    double y = x / 128.0;

    double result = expo_small(y);

    for (int i = 0; i < 7; i++) {
        result *= result;
    }

    return result;
}

int main() {
    FILE *file = fopen("input.txt", "r");

    int n = 0;
    fscanf(file, "%d", &n);

    for (int i = 0; i < n; i++) {
        double x = 0;
        fscanf(file, "%lf", &x);

        printf("%0.15g\n", expo(x));
    }

    fclose(file);

    return 0;
}