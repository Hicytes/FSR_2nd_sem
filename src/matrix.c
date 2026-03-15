#include "matrix.h"
#include <math.h>
#include <stdlib.h>

double calculate_determinant(double **matrix, int n) {
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) > fabs(matrix[pivot][i])) {
                pivot = j;
            }
        }

        if (fabs(matrix[pivot][i]) < 1e-15) {
            return 0.0;
        }

        if (i != pivot) {
            double *temp = matrix[i];
            matrix[i] = matrix[pivot];
            matrix[pivot] = temp;
            det *= -1.0;
        }

        det *= matrix[i][i];

        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i + 1; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    return det;
}
