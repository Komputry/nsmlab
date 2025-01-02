#ifndef SEC_H
#define SEC_H

#include <math.h>
#include <time.h>
#include <arm_neon.h>

#define N 50

void matrix_init(int rows, int cols, int matrix[rows][cols]);
void matrix_d_init(int rows, int cols, double matrix[rows][cols]);

void mul_int(int rows, int cols, int result[rows][cols], int mat1[rows][cols], int mat2[rows][cols]);
void mul_d(int rows, int cols, double result[rows][cols], double mat1[rows][cols], double mat2[rows][cols]);
void mul_int_neon(int rows, int cols, int result[rows][cols], int mat1[rows][cols], int mat2[rows][cols]);
void mul_d_neon(int rows, int cols, double result[rows][cols], double mat1[rows][cols], double mat2[rows][cols]);

#endif
