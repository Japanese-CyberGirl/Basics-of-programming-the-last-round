#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int commonality_function(char *answer, char *student) {
    int record = 0;
    int counter = 0;

    int len = strlen(answer);
    for (int i = 0 ; i < len ; i ++ ) {
        if (answer[i] != student[i]) {
            counter += 1;
        }
        else {
            record = record > counter ? record : counter;
            counter = 0;
        }
    }
    record = record > counter ? record : counter;
    return record;
}

int main() {

    FILE *file = fopen("input.txt", "r");

    int N = 0;
    int M = 0;
    int R = 0;
    
    fscanf(file, "%d %d %d", &N, &M, &R);

    char *answer = calloc(N + 1, sizeof(char));
    fscanf(file, "%s", answer);

    char *temp = calloc(N + 1, sizeof(char));

    int flag = 0;

    for (int i = 0 ; i < M ; i ++ ) {
        fscanf(file, "%s", temp);
        printf("%d\n", commonality_function(answer, temp));
        if (commonality_function(answer, temp) >= R) {
            flag += 1;
        }
    }

    fclose(file);

    if (flag) {
        printf("YES");
        return 0;
    }

    printf("NO\n");

    return 0;
}