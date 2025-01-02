#include <stdio.h>
#include "sec.h"

double czas(clock_t start, clock_t end) {
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int mat1[N][N], mat2[N][N], result_int[N][N];
    double mat1_d[N][N], mat2_d[N][N], result_double[N][N];

    matrix_init(N, N, mat1);
    matrix_init(N, N, mat2);
    matrix_d_init(N, N, mat1_d);
    matrix_d_init(N, N, mat2_d);

    clock_t start = clock();
    mul_int(N, N, result_int, mat1, mat2);
    clock_t end = clock();
    printf("czas mnożenia calkowitych: %.6f s\n", czas(start, end));

    start = clock();
    mul_int_neon(N, N, result_int, mat1, mat2);
    end = clock();
    printf("czas mnożenia calkowitych z neon: %.6f s\n", czas(start, end));

    start = clock();
    mul_d(N, N, result_double, mat1_d, mat2_d);
    end = clock();
    printf("czas mnożenia zmiennoprzecinkowych: %.6f s\n", czas(start, end));

    start = clock();
    mul_d_neon(N, N, result_double, mat1_d, mat2_d);
    end = clock();
    printf("czas mnożenia zmiennoprzecinkowych z neon: %.6f s\n", czas(start, end));

    return 0;
}
