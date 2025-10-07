#pragma once

#include <vector>
#include <iostream>
#include <iomanip>
#include <limits>

using Matrix = std::vector<std::vector<double>>;
using Labels = std::vector<char>;

const double INF = std::numeric_limits<double>::infinity();

namespace sumisgard
{

class SpecialMatrix 
{
public:
    SpecialMatrix() = default;
    SpecialMatrix(Matrix matrix, Labels labels);

    operator const Matrix() const;

    void printMatrix() const;

    static Matrix matrixMultiply(const Matrix& A, const Matrix& B);
    static bool matrixEqual(const Matrix& A, const Matrix& B);

    Matrix get_matrix() const;
    int get_size() const;
    
private:
    Matrix matrix;
    Labels labels;

    static std::string formatValue(double val);
};

class SolvingWithMatrix
{
public:
    SolvingWithMatrix(SpecialMatrix L1);
    void solve();

private:
    SpecialMatrix L1;
    SpecialMatrix L_prev;
    SpecialMatrix L_curr;
    SpecialMatrix LD;
};

}