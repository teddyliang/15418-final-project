#ifndef EVALUATION_H
#define EVALUATION_H

#include <array>

extern const std::array<int, 64> PAWN_TABLE;
extern const std::array<int, 64> KNIGHTS_TABLE;
extern const std::array<int, 64> BISHOPS_TABLE;
extern const std::array<int, 64> ROOKS_TABLE;
extern const std::array<int, 64> QUEENS_TABLE;
extern const std::array<int, 64> KINGS_TABLE;

int evaluateBoard();

#endif // EVALUATION_H
