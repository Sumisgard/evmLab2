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

}