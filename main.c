#include <stdio.h>
#include "matrixc.h"

int main() {
    // Define A
    Matrix* A = create_matrix(2, 2);
    set_element(A, 0, 0, 6);
    set_element(A, 0, 1, 4);
    set_element(A, 1, 0, 8);
    set_element(A, 1, 1, 3);

    // Define B
    Matrix* B = create_matrix(2, 3);
    set_element(B, 0, 0, 1);
    set_element(B, 0, 1, 2);
    set_element(B, 0, 2, 3);
    set_element(B, 1, 0, 4);
    set_element(B, 1, 1, 5);
    set_element(B, 1, 2, 6);

    // Define C
    Matrix* C = create_matrix(2, 3);
    set_element(C, 0, 0, 2);
    set_element(C, 0, 1, 4);
    set_element(C, 0, 2, 6);
    set_element(C, 1, 0, 1);
    set_element(C, 1, 1, 3);
    set_element(C, 1, 2, 5);

    // Step 1: 3 * B
    Matrix* threeB = ScalarMultiplication(B, 3);

    // Step 2: C^T
    Matrix* C_T = transpose_matrix(C); // 3x2

    // Step 3: (3 * B) × C^T
    Matrix* mult = multiply_matrices(threeB, C_T); // 2x3 * 3x2 = 2x2

    // Step 4: A + result
    Matrix* D = add_matrices(A, mult);

    // Print result
    printf("Resulting matrix D = A + (3 * B) x C^T:\n");
    for (int i = 0; i < D->rows; i++) {
        for (int j = 0; j < D->columns; j++) {
            printf("%d ", get_element(D, i, j));
        }
        printf("\n");
    }

    // Free memory
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    free_matrix(threeB);
    free_matrix(C_T);
    free_matrix(mult);
    free_matrix(D);

    return 0;
}