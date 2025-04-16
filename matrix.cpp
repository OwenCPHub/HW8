#include <iostream>
#include <vector>
using namespace std;


class Matrix {
    private:
        vector<vector<double>> data;
        int rows, cols;

    public:
        // Constructor
        Matrix(int r, int c) : rows(r), cols(c) {
            data.resize(r, vector<double>(c, 0));
        }

        // Set an element
        void set(int r, int c, double val) {
            data[r][c] = val;
        }

        // Get an element
        double get(int r, int c) const {
            return data[r][c];
        }

        // Print the matrix
        void print() const {
            for (const auto& row : data) {
                for (double val : row) cout << val << " ";
                cout << "\n";
            }
        }

        // Scalar multiplication
        Matrix scalarMultiply(double scalar) const {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    result.set(i, j, data[i][j] * scalar);
            return result;
        }

        // Transpose
        Matrix transpose() const {
            Matrix result(cols, rows);
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    result.set(j, i, data[i][j]);
            return result;
        }

        // Matrix multiplication
        Matrix multiply(const Matrix& other) const {
            if (cols != other.rows) throw invalid_argument("Matrix dimensions incompatible for multiplication.");
            Matrix result(rows, other.cols);
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < other.cols; ++j)
                    for (int k = 0; k < cols; ++k)
                        result.data[i][j] += data[i][k] * other.data[k][j];
            return result;
        }

        // Matrix addition
        Matrix add(const Matrix& other) const {
            if (rows != other.rows || cols != other.cols) throw invalid_argument("Matrix dimensions must match for addition.");
            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    result.set(i, j, data[i][j] + other.data[i][j]);
            return result;
        }
};

int main() {
    // A (2x2)
    Matrix A(2, 2);
    A.set(0, 0, 6); A.set(0, 1, 4);
    A.set(1, 0, 8); A.set(1, 1, 3);

    // B (2x3)
    Matrix B(2, 3);
    B.set(0, 0, 1); B.set(0, 1, 2); B.set(0, 2, 3);
    B.set(1, 0, 4); B.set(1, 1, 5); B.set(1, 2, 6);

    // C (2x3)
    Matrix C(2, 3);
    C.set(0, 0, 2); C.set(0, 1, 4); C.set(0, 2, 6);
    C.set(1, 0, 1); C.set(1, 1, 3); C.set(1, 2, 5);

    // D = A + (3 * B) * C^T
    Matrix result = A.add(B.scalarMultiply(3).multiply(C.transpose()));

    cout << "Result D = \n";
    result.print();

    return 0;
}
