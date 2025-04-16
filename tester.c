#include <stdio.h>
#include "matrixc.h"

// Utility function to print matrix
void print_matrix(const Matrix* m, const char* name) {
    if (!m) {
        printf("%s is NULL\n", name);
        return;
    }
    printf("Matrix %s (%dx%d):\n", name, m->rows, m->columns);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j) {
            printf("%4d ", get_element(m, i, j));
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // 1. Create two 2x2 matrices A and B
    Matrix* A = create_matrix(2, 2);
    Matrix* B = create_matrix(2, 2);

    // 2. Fill matrices
    set_element(A, 0, 0, 1); set_element(A, 0, 1, 2);
    set_element(A, 1, 0, 3); set_element(A, 1, 1, 4);

    set_element(B, 0, 0, 5); set_element(B, 0, 1, 6);
    set_element(B, 1, 0, 7); set_element(B, 1, 1, 8);

    print_matrix(A, "A");
    print_matrix(B, "B");

    // 3. Scalar multiplication
    Matrix* S = ScalarMultiplication(B, 3);
    print_matrix(S, "3 * B");

    // 4. Matrix addition: A + B
    Matrix* Add = add_matrices(A, B);
    print_matrix(Add, "A + B");

    Matrix* Wrongadd = create_matrix(3, 2);
    Matrix* FailAdd = multiply_matrices(A, Wrongadd);
    if (!FailAdd) {
        printf("Correctly handled invalid matrix addition dimensions.\n\n");
    }

    // 5. Transpose B
    Matrix* T = transpose_matrix(B);
    print_matrix(T, "B Transposed");

    // 6. Matrix multiplication: A x T
    Matrix* Mul = multiply_matrices(A, T);
    print_matrix(Mul, "A * B^T");

    // 7. Try multiplication with wrong dimensions (2x2 * 2x3 → should fail)
    Matrix* Wrongmult = create_matrix(3, 2);
    Matrix* FailMul = multiply_matrices(A, Wrongmult);
    if (!FailMul) {
        printf("Correctly handled invalid matrix multiplication dimensions.\n\n");
    }

    // 8. Clean up
    free_matrix(A);
    free_matrix(B);
    free_matrix(S);
    free_matrix(Add);
    free_matrix(T);
    free_matrix(Mul);
    free_matrix(Wrongadd);
    free_matrix(Wrongmult);
    // No need to free FailMul because it's NULL

    return 0;
}