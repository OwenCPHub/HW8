#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>

typedef struct {
    int rows;
    int columns;
    int* data;
} Matrix;

Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* m);

int get_element(const Matrix* m, size_t row, size_t col);
void set_element(Matrix* m, size_t row, size_t col, int value);

Matrix* ScalarMultiplication(const Matrix* a, int scalar);
Matrix* add_matrices(const Matrix* a, const Matrix* b);
Matrix* multiply_matrices(const Matrix* a, const Matrix* b);
Matrix* transpose_matrix(const Matrix* m);

#endif