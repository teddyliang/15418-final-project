#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <cstdint>
#include "move.h"


// Declare the global bitboard variables
extern uint64_t whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKing;
extern uint64_t blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKing;
extern uint64_t allPieces;

// Utility functions
uint64_t setBit(uint64_t bitboard, int position);
uint64_t clearBit(uint64_t bitboard, int position);
int popCount(uint64_t bitboard);
int getLSB(uint64_t bitboard);
void printBitboard(uint64_t bitboard);
void printWholeBoard();
// Initialize the chessboard to the starting position
void initializeBoard();

// Make a move on the board
void makeMove(const Move& move);

// Unmake the last move (for backtracking during search)
void undoMove(const Move& move);

#endif // BITBOARDS_H