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
    SpecialMatrix(Matrix matrix, Labels labels);

    void printMatrix() const;

private:
    Matrix matrix;
    Labels labels;

    static std::string formatValue(double val);
};

class SolvingWithMatrix
{
public:
    SolvingWithMatrix(Matrix L1);

private:
    Matrix L1;
    Matrix L_curr;
};

}