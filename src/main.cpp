#include <iostream>

#include "matrix.hpp"
#include "floyd.hpp"

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
    std::cout << "Матрица L^2: \n";
    network.printMatrix();

    sumisgard::SolvingWithMatrix firstMethod(network);
    firstMethod.solve();

    sumisgard::FloydMethod floyd(network, firstMethod.get_LD()); // вам нужно добавить getLD()
    floyd.computeDelta();
    floyd.printDelta();

    // Пример восстановления пути от A к E:
    auto path = floyd.reconstructPath('A', 'E');
    std::cout << "Путь от A к E: ";
    for (char node : path) {
        std::cout << node << " ";
    }
    std::cout << "\n";

    return 0;
}