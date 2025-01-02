#include "sec.h"

void matrix_init(int rows, int cols, int matrix[rows][cols]) {
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
            if (value > 100) value = 1;
        }
    }
}

void matrix_d_init(int rows, int cols, double matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double angle = (i * cols + j) * M_PI / 180.0;
            matrix[i][j] = sin(angle);
        }
    }
}

void mul_int(int rows, int cols, int result[rows][cols], int mat1[rows][cols], int mat2[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void mul_d(int rows, int cols, double result[rows][cols], double mat1[rows][cols], double mat2[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void mul_int_neon(int rows, int cols, int result[rows][cols], int mat1[rows][cols], int mat2[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int32x4_t sum_vec = vdupq_n_s32(0);
            for (int k = 0; k < cols; k += 4) {
                int32x4_t mat1_vec = vld1q_s32(&mat1[i][k]);
                int32x4_t mat2_vec = vld1q_s32(&mat2[k][j]);
                sum_vec = vmlaq_s32(sum_vec, mat1_vec, mat2_vec);
            }
            int32_t sum_array[4];
            vst1q_s32(sum_array, sum_vec);
            result[i][j] = sum_array[0] + sum_array[1] + sum_array[2] + sum_array[3];
        }
    }
}

void mul_d_neon(int rows, int cols, double result[rows][cols], double mat1[rows][cols], double mat2[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            float64x2_t sum_vec = vdupq_n_f64(0.0);
            for (int k = 0; k < cols; k += 2) {
                float64x2_t mat1_vec = vld1q_f64(&mat1[i][k]);
                float64x2_t mat2_vec = vld1q_f64(&mat2[k][j]);
                sum_vec = vfmaq_f64(sum_vec, mat1_vec, mat2_vec);
            }
            double sum_array[2];
            vst1q_f64(sum_array, sum_vec);
            result[i][j] = sum_array[0] + sum_array[1];
        }
    }
}
