#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return (n * factorial(n - 1));
}

double power(double x, int n) {
    double result = 1;

    for (int i = 0 ; i < n ; i ++ ) {
        result *= x;
    }
    return result;
}

double sinus(double x) {
    double sum = 0;

    for (int i = 0 ; i <= 20 ; i ++ ) {
        int degree = 2 * i + 1;

        if (i % 2 == 0) {
            sum += power(x, degree) / factorial(degree);
        }
        else {
            sum -= power(x, degree) / factorial(degree);
        }
    }

    return sum;

}


int main() {
    FILE *file = fopen("input.txt", "r");

    int n = 0;
    fscanf(file, "%d", &n);

    for (int i = 0 ; i < n ; i ++ ) {
        double x = 0;
        fscanf(file, "%lf", &x);
        printf("%0.15lf\n", sinus(x));
    }

    fclose(file);
    return 0;
}