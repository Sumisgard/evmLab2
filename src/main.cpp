#include <iostream>

#include "matrix.hpp"

// N = 5, j = 7
/*
      |  A  |  B  |  C  |  D  |  E
    A | 0   | i   | i   | 60  | 5
    B | i   | 0   | i   | i   | 80
    C | i   | 20  | 0   | i   | 35
    D | 60  | i   | i   | 0   | 40
    E | i   | 80  | 35  | 40  | 0
*/

int main(void) {
    sumisgard::SpecialMatrix network(
    {
        {  0, INF, INF,  60,  5}, // A
        {INF,   0, INF, INF, 80}, // B
        {INF,  20,   0, INF, 35}, // C
        { 60, INF, INF,   0, 40}, // D
        {INF,  80,  35,  40,  0}  // E
    },  {'A', 'B', 'C', 'D', 'E'});

    network.printMatrix();

    return 0;
}