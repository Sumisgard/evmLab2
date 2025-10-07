#include "matrix.hpp"

namespace sumisgard
{

SpecialMatrix::SpecialMatrix(Matrix matrix, Labels labels) {
    this->matrix = matrix;
    this->labels = labels;
}

std::string SpecialMatrix::formatValue(double val)
{
    if (val == INF)
        return "inf";
    else
        return std::to_string(static_cast<int>(val)); // или используйте stringstream для форматирования
}

void SpecialMatrix::printMatrix() const
{
    int n = matrix.size();
    if (n == 0) return;

    // Печать заголовка (имена столбцов)
    std::cout << "  ";
    for (char label : labels)
    {
        std::cout << std::setw(7) << label;
    }
    std::cout << "\n";

    // Печать строк
    for (int i = 0; i < n; ++i)
    {
        std::cout << labels[i] << " ";
        for (int j = 0; j < n; ++j)
        {
            std::cout << std::setw(7) << formatValue(matrix[i][j]);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

Matrix SpecialMatrix::matrixMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    std::vector<std::vector<double>> C(n, std::vector<double>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double minVal = INF;
            for (int k = 0; k < n; ++k) {
                if (A[i][k] == INF || B[k][j] == INF) continue;
                double sum = A[i][k] + B[k][j];
                if (sum < minVal) minVal = sum;
            }
            C[i][j] = minVal;
        }
    }
    return C;
}

bool SpecialMatrix::matrixEqual(const Matrix& A, const Matrix& B) {
    int n = A.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != B[i][j]) return false;
    return true;
}

}