#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.txt", "r");

    int q = 0;
    fscanf(file, "%d", &q);

    char line[205];

    fgets(line, sizeof(line), file);

    for (int test = 0; test < q; test ++) {
        fgets(line, sizeof(line), file);

        unsigned long long mask = 0;

        char *token = strtok(line, "(), \n");

        while (token != NULL) {
            int number = atoi(token);

            mask = mask | (1ULL << number);

            token = strtok(NULL, "(), \n");
        }

        printf("%016llX\n", mask);

    }        

    fclose(file);
    return 0;
}