#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void free_matrix(double **matrix, int n) {
    if (matrix == NULL) return;
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;

    printf("Введите размерность квадратной матрицы: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Ошибка: неверный размер матрицы.\n");
        return 1;
    }

    double **matrix = (double **)malloc(n * sizeof(double *));
    if (!matrix) return 1; 

    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
        if (!matrix[i]) {
            free_matrix(matrix, i); 
            return 1;
        }
    }

    printf("Введите элементы матрицы (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                fprintf(stderr, "Ошибка: некорректный ввод в строке %d, столбце %d.\n", i + 1, j + 1);
                free_matrix(matrix, n);
                return 1;
            }
        }
    }

    double result = calculate_determinant(matrix, n);
    
    printf("\nОпределитель матрицы: %.4f\n", result);
 
    free_matrix(matrix, n);

    return 0;
}
