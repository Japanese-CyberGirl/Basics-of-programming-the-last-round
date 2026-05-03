#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *file = fopen("input.txt", "r");

    int q = 0;
    fscanf(file, "%d", &q);

    long double pi = 3.141592653589793238462643383279502884197169399375105820974944;

    for (int i = 0 ; i < q ; i ++ ) {
        long double ax, ay, bx, by, cx, cy;

        fscanf(file, "%Lf %Lf %Lf %Lf %Lf %Lf", 
        &ax, &ay, &bx, &by, &cx, &cy);

        long double ab_x = bx - ax;
        long double ab_y = by - ay;

        long double ac_x = cx - ax;
        long double ac_y = cy - ay;

        long double dot = ab_x * ac_x + ab_y * ac_y;
        long double cross = ab_x * ac_y - ab_y * ac_x;

        long double angle_rad = atan2l(fabsl(cross), dot);
        long double angle_deg = angle_rad * 180.0L / pi;

        printf("%0.20Lg\n", angle_deg);
    }

    fclose(file);
    
    return 0;
}
