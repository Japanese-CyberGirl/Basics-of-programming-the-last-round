#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    FILE *file = fopen("input.txt", "r");

    fclose(file);
    return 0;
}