// floyd.cpp
#include "floyd.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

namespace sumisgard
{

int FloydMethod::labelToIndex(char label) const {
    auto it = std::find(labels.begin(), labels.end(), label);
    if (it == labels.end())
        throw std::invalid_argument("Unknown node label");
    return std::distance(labels.begin(), it);
}

char FloydMethod::indexToLabel(int idx) const {
    if (idx < 0 || idx >= N)
        throw std::out_of_range("Index out of range");
    return labels[idx];
}

FloydMethod::FloydMethod(const SpecialMatrix& L1, const SpecialMatrix& D)
    : L1(L1), D(D), labels(L1.get_labels()), N(L1.get_size())
{
    // Построим Gamma из L1: копируем L1, но ставим INF на диагональ
    Gamma = L1.get_matrix();
    for (int i = 0; i < N; ++i) {
        Gamma[i][i] = INF;
    }

    // Инициализируем Delta пустой матрицей нужного размера
    Delta = std::vector<std::vector<char>>(N, std::vector<char>(N, 0));
}

void FloydMethod::computeDelta()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double minDist = INF;
            char bestNext = 0;

            // Перебираем все возможные первые шаги k
            for (int k = 0; k < N; ++k) {
                if (Gamma[i][k] == INF || D[k][j] == INF)
                    continue;

                double candidate = Gamma[i][k] + D[k][j];
                if (candidate < minDist) {
                    minDist = candidate;
                    bestNext = indexToLabel(k);
                }
            }

            // Если не нашли пути — оставляем как есть (но по логике D всегда содержит путь)
            if (bestNext == 0) {
                // fallback: если прямой путь существует, то следующий узел — j
                if (L1[i][j] < INF) {
                    bestNext = indexToLabel(j);
                } else {
                    bestNext = '?'; // или оставить как есть
                }
            }

            Delta[i][j] = bestNext;
        }
    }
}

void FloydMethod::printDelta() const
{
    std::cout << "Матрица кратчайших путей Δ:\n";
    std::cout << "  ";
    for (char label : labels) {
        std::cout << std::setw(7) << label;
    }
    std::cout << "\n";

    for (int i = 0; i < N; ++i) {
        std::cout << labels[i] << " ";
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(7) << Delta[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

std::vector<char> FloydMethod::reconstructPath(char from, char to) const
{
    int i = labelToIndex(from);
    int j = labelToIndex(to);

    std::vector<char> path;
    path.push_back(from);

    while (from != to) {
        char next = Delta[labelToIndex(from)][labelToIndex(to)];
        if (next == '?' || next == 0 || next == from) {
            // Нет пути или зацикливание
            break;
        }
        path.push_back(next);
        from = next;
    }

    return path;
}

}