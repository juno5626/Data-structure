#include <stdio.h>
#include <stdlib.h>

float **make2dArray(int a, int b) {
    float **arr = (float **)malloc(a * sizeof(float *));
    for (int i = 0; i < a; i++) {
        arr[i] = (float *)malloc(b * sizeof(float));
    }
    return arr;
}

void free2dArray(float **arr, int a) {
    for (int i = 0; i < a; i++) {
        free(arr[i]);
    }
    free(arr);
}

float **add_matrix(float **a, int ah, int aw, float **b, int bh, int bw) {
    if (ah != bh || aw != bw) {
        printf("Matrix dimensions mismatch\n");
        return 0;
    }

    float **result = make2dArray(ah, aw);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < aw; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

float **mul_matrix(float **a, int ah, int aw, float **b, int bh, int bw) {
    if (aw != bh) {
        printf("Matrix dimensions mismatch\n");
        return 0;
    }

    float **result = make2dArray(ah, bw);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < bw; j++) {
            result[i][j] = 0;
            for (int k = 0; k < aw; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}
float **transpose_matrix(float **a, int ah, int aw) {
    float **result = make2dArray(aw, ah);
    for (int i = 0; i < ah; i++) {
        for (int j = 0; j < aw; j++) {
            result[j][i] = a[i][j];
        }
    }
    return result;
}

int main() {
    char op;
    printf("What operation do you want? (‘a’, ‘m’, ‘t’)\n");
    scanf(" %c", &op);

    char filename1[10], filename2[10];
    printf("Input file names:\n");
    scanf("%s", filename1);
    scanf("%s", filename2);

    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");

    int a1, b1, a2, b2;
    fscanf(file1, "%d %d", &a1, &b1);
    fscanf(file2, "%d %d", &a2, &b2);

    float **mat1 = make2dArray(a1, b1);
    float **mat2 = make2dArray(a2, b2);

    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < b1; j++) {
            fscanf(file1, "%f", &mat1[i][j]);
        }
    }

    for (int i = 0; i < b1; i++) {
        for (int j = 0; j < b2; j++) {
            fscanf(file2, "%f", &mat2[i][j]);
        }
    }

    fclose(file1);
    fclose(file2);

    float **result;
    int arr1, arr2;

    switch (op) {
        case 'a':
            result = add_matrix(mat1, a1 , b1, mat2, a2, b2);
            result_rows = a1;
            result_cols = b1;
            break;

        case 'm':
            result = mul_matrix(mat1, rows1, cols1, matrix2, rows2, cols2);
            result_rows = rows1;
            result_cols = cols2;
            break;
        case 't':
            result = transpose_matrix(matrix1, rows1, cols1);
            result_rows = cols1;
            result_cols = rows1;
            break;
        default:
            printf("Invalid operation\n");
            free2dArray(matrix1, rows1);
            free2dArray(matrix2, rows2);
            return 1;
    }

    if (result != NULL) {
        printf("The output is:\n");
        printf("%d %d\n", result_rows, result_cols);
        for (int i = 0; i < result_rows; i++) {
            for (int j = 0; j < result_cols; j++) {
                printf("%.2f ", result[i][j]);
            }
            printf("\n");
        }
        free2dArray(result, result_rows);
    }

    free2dArray(matrix1, rows1);
    free2dArray(matrix2, rows2);

    return 0;
}
