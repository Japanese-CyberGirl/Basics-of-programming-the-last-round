#include <stdio.h>
#include <stdlib.h>

int index_k_row_finding(double **matrix, int n, int start_line) { //функция определения ненулевого элемента в строке start_line
        int k = -1;
        for (int i = start_line; i < n ; i ++ ) {
            if (matrix[i][start_line] != 0.0) {
                k = i;
                break;
            }
        }
        return k; 
    }

void first_line_elementary_transformation(double **matrix, int n, int k, int start_line) { //функция прибавления к строке start_line строки r
        for (int i = 0; i <= n; i ++) {
            matrix[start_line][i] += matrix[k][i];
        }
    }

void elementary_transforamtions(double **matrix, int n, int start_line) { //функция элементарных преобразований сверху вниз
    for  (int i = start_line + 1 ; i < n ; i ++ ) {
        double x = -(matrix[i][start_line]/matrix[start_line][start_line]);
        for (int j = 0 ; j <= n ; j ++ ) {
            matrix[i][j] += x*matrix[start_line][j];
        }
    }
}

double determinant(double **matrix, int n) { //функция поиска диагонального определителя
    double det = 1.0;
    for (int i = 0; i < n; i ++ ) {
        det *= matrix[i][i];
    }
    return det;
}

void matrix_out(double **matrix, int n) { //функция вывода матрицы в консоль
    for (int i = 0 ; i < n ; i ++ ) {
        printf("\n");
        for (int j = 0 ; j < n ; j ++ ) {
            printf("%lf\t", matrix[i][j]);
        }
    }
    printf("\n");
}


int main()
{
    int n; //инициализация перменной размерности матрицы
    scanf("%d",&n); //ввод значения размерности матрицы

    // выделение памяти на двухмерный массив

    double **matrix = (double **)calloc(n, sizeof(double*)); //создания массива указателей длины n с указателями на строки

    for (int i = 0; i < n ; i ++ ) {
        matrix[i] = (double *)calloc(n + 1, sizeof(double)); //создание одномерных массивов для каждой строки
    } 


    //заполнение матрицы
    for (int i = 0 ; i < n ; i ++ ) {
        for (int j = 0; j <= n ; j ++ ) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    //printf("\n");
    //matrix_out(matrix, n);

    int start_line = 0;
    while(start_line < n-1) {
        int k = index_k_row_finding(matrix,n,start_line);
        if (k == -1) {
            {printf("%0.2lf",0.00); return 0;}
        }
        if (k!=start_line) {
            first_line_elementary_transformation(matrix, n, k , start_line); /*matrix_out(matrix,n)*/; 
        }
        elementary_transforamtions(matrix,n,start_line);
        //matrix_out(matrix,n);
        start_line += 1;
        //printf("%d\n",start_line);

    }

    double *x = calloc(n, sizeof(double));

    for (int i = n - 1; i >= 0; i--) {
        double sum = matrix[i][n];

        for (int j = i + 1; j < n; j++) {
            sum -= matrix[i][j] * x[j];
        }

        x[i] = sum / matrix[i][i];
    }

    for (int i = 0; i < n; i++) {
        printf("%.10lf\n", x[i]);
    }

    return 0;
}