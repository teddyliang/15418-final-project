#ifndef BITBOARDS_H
#define BITBOARDS_H

#include <cstdint>
#include <vector>
#include "move.h"
#include "evaluation.h"

extern uint64_t whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKing;
extern uint64_t blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKing;
extern uint64_t allPieces;

uint64_t setBit(uint64_t bitboard, int position);
uint64_t clearBit(uint64_t bitboard, int position);
int popCount(uint64_t bitboard);
int getLSB(uint64_t bitboard);
void printBitboard(uint64_t bitboard);
void printWholeBoard();
void initializeBoard();
void makeMove(const Move& move);
void undoMove(const Move& move);

std::vector<Move> generateLegalMoves(bool isWhite);  // Generate legal moves for the current player
int evaluateBoard();  // Evaluate the board for minimax

int alphaBeta(int depth, int alpha, int beta, bool isMaximizingPlayer);
Move findBestMove(int depth, bool isWhite);  // Find the best move using alpha-beta pruning
bool gameOver();
bool isCheck(bool isWhite);
bool isSquareAttacked(int square, bool byWhite);

#endif // BITBOARDS_H
