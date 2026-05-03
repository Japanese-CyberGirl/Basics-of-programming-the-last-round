#include <stdio.h>
#include <stdlib.h>

int n;

int target[20][20];
int field[20][20];
int clicked[20][20];

void clear_arrays() {
    for (int i = 0; i < n ; i ++ ) {
        for (int j = 0 ; j < n ; j ++ ) {
            field[i][j] = 0;
            clicked[i][j] = 0;
        }
    }
}

void toggle_cell(int r, int c) {
    if (r >= 0 && r < n && c >= 0 && c < n) {
        field[r][c] = 1 - field[r][c];
    }
}

void click_cell(int r, int c) {
    clicked[r][c] = 1;

    toggle_cell(r,c);
    toggle_cell(r - 1, c);
    toggle_cell(r + 1, c);
    toggle_cell(r, c - 1);
    toggle_cell(r, c + 1);
}

int is_equal_to_target() {
    for (int i = 0 ; i < n ; i ++ ) {
        for (int j = 0 ; j < n ; j ++ ) {
            if (field[i][j] != target[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    FILE *file = fopen("input.txt", "r");

    fscanf(file, "%d", &n);

    for (int i = 0 ; i < n ; i ++ ) {
        char s[25];
        fscanf(file, "%s", s);

        for (int j = 0 ; j < n ; j ++ ) {
            if (s[j] == '*') {
                target[i][j] = 1;
            }
            else {
                target[i][j] = 0;
            }
        }
    }

    int total_variants = 1 << n; //всего вариантов

    for (int mask = 0; mask < total_variants; mask ++ ) {
        clear_arrays();

        for (int j = 0 ; j < n ; j ++ ) {
            if (mask & (1 << j)) {
                click_cell(0, j);
            }
        }

        for (int i = 1; i < n ; i ++ ) {
            for (int j = 0 ; j < n ; j ++ ) {
                if (field[i-1][j] != target[i - 1][j]) {
                    click_cell(i, j);
                }
            }
        }

        if (is_equal_to_target()) {
            int count = 0;

            for (int i = 0 ; i < n ; i ++ ) {
                for (int j = 0 ; j < n ; j ++ ) {
                    if (clicked[i][j]) {
                        count++;
                    }
                }
            }

            printf("%d\n", count);

            for (int i = 0 ; i < n ; i ++ ) {
                for (int j = 0 ; j < n ; j ++ ) {
                    if (clicked[i][j]) {
                        printf("%d %d\n", i + 1, j + 1);
                    }
                }
            }
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 0;
}