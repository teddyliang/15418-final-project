#ifndef MOVE_H
#define MOVE_H

#include <cstdint>

enum MoveType {
    NORMAL,
    CASTLE,
    EN_PASSANT,
    PROMOTION
};

enum PieceType {
    NO_PIECE = 0,  // for captured and promotion fields of Move struct
    WHITE_PAWN, BLACK_PAWN,
    WHITE_KNIGHT, BLACK_KNIGHT,
    WHITE_BISHOP, BLACK_BISHOP,
    WHITE_ROOK, BLACK_ROOK,
    WHITE_QUEEN, BLACK_QUEEN,
    WHITE_KING, BLACK_KING
};

struct Move {
    uint8_t from;       // Starting square (0 to 63)
    uint8_t to;         // Ending square (0 to 63)
    PieceType piece;    // Piece being moved
    PieceType captured; // Piece being captured, if any
    MoveType type;      // Type of move
    PieceType promotion;// Piece to promote to, if applicable

    Move(uint8_t from, uint8_t to, PieceType piece, PieceType captured = NO_PIECE,
         MoveType type = NORMAL, PieceType promotion = NO_PIECE)
        : from(from), to(to), piece(piece), captured(captured), type(type), promotion(promotion) {}
};

#endif
