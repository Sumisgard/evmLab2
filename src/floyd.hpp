#pragma once

#include "matrix.hpp"
#include <vector>
#include <string>

namespace sumisgard
{

class FloydMethod
{
public:
    FloydMethod() = default;
    FloydMethod(const SpecialMatrix& L1, const SpecialMatrix& D);

    void computeDelta();
    void printDelta() const;

    std::vector<char> reconstructPath(char from, char to) const;

private:
    Matrix L1;
    Matrix D;
    Matrix Gamma;
    std::vector<std::vector<char>> Delta;
    Labels labels;
    int N;

    int labelToIndex(char label) const;
    char indexToLabel(int idx) const;
};

}