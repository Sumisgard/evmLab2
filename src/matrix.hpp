#include <vector>

using Matrix = std::vector<std::vector<double>>;
using Labels = std::vector<char>;

namespace sumisgard
{

class SpecialMatrix 
{
public:
    SpecialMatrix(Matrix matrix);
private:
    Matrix matrix;
    Labels labels;
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