#include "matrixc.h"
#include <stdlib.h>
#include <stdio.h>

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix* mat = malloc(sizeof(Matrix));
    if (!mat) return NULL;
    mat->rows = rows;
    mat->columns = cols;
    mat->data = calloc(rows * cols, sizeof(int));
    if (!mat->data) {
        free(mat);
        return NULL;
    }
    return mat;
}
void free_matrix(Matrix* m){
    if (m) {
        free(m->data);
        free(m);
    }
}

int get_element(const Matrix* m, size_t row, size_t col){
    if (row < m->rows && col < m->columns){    
        return m->data[row * m->columns + col];
    }
    return 0;
}
void set_element(Matrix* m, size_t row, size_t col, int value){
    if (row >= m->rows || col >= m->columns) return;
    m->data[row * m->columns + col] = value;
}

Matrix* ScalarMultiplication(const Matrix* a, int scalar) {
    Matrix* result = create_matrix(a->rows, a->columns);
        for (int i = 0; i < a->rows; i++)
            for (int j = 0; j < a->columns; j++)
                set_element(result, i, j, get_element(a, i, j) * scalar);
    return result;
}
Matrix* add_matrices(const Matrix* a, const Matrix* b){
    if (!a || !b) return NULL;

    if (a->rows != b->rows || a->columns != b->columns) {
        return NULL;
    }

    Matrix* result = create_matrix(a->rows, a->columns);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j< a->columns; j++) {
            int sum = get_element(a, i, j) + get_element(b, i, j);
            set_element(result, i, j, sum);
        }
    }
    return result;
}

Matrix* multiply_matrices(const Matrix* a, const Matrix* b){
    if (a->columns == b->rows) {
        Matrix* result = create_matrix(a->rows, b->columns);
        for (size_t i = 0; i < a->rows; i++) {
            for (size_t j = 0; j < b->columns; j++) {
                int sum = 0;
                for (size_t k = 0; k < a->columns; k++) {
                    sum += get_element(a, i, k) * get_element(b, k, j);
                }
                set_element(result, i, j, sum);
            }
        }
        return result;
    }
    return NULL;
}
Matrix* transpose_matrix(const Matrix* m){
    if (!m) return NULL;

    Matrix* result= create_matrix(m->columns, m->rows);
        for (int i = 0; i < m->rows; i++)
            for (int j = 0; j < m->columns; j++)
                    set_element(result, j, i, get_element(m, i, j));
        return result;
}