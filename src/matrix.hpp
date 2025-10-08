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
    SpecialMatrix(Matrix matrix);

    operator const Matrix() const;

    void printMatrix() const;

    static Matrix matrixMultiply(const Matrix& A, const Matrix& B);
    static bool matrixEqual(const Matrix& A, const Matrix& B);

    Matrix get_matrix() const;
    Labels get_labels() const;
    int get_size() const;
    
private:
    Matrix matrix;
    Labels labels;

    static std::string formatValue(double val);
};

class SolvingWithMatrix
{
public:
    SolvingWithMatrix() = default;
    SolvingWithMatrix(SpecialMatrix L1);
    void solve();

    SpecialMatrix get_LD() const;

private:
    SpecialMatrix L1;
    SpecialMatrix L_prev;
    SpecialMatrix L_curr;
    SpecialMatrix LD;
};

}