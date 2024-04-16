#include "bitboards.h"
#include "move.h"
#include <string>
#include <cstdint>
#include <iostream>

uint64_t whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKing;
uint64_t blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKing;
uint64_t allPieces;


// Function to set a bit in a bitboard
uint64_t setBit(uint64_t bitboard, int position) {
    return bitboard | (1ULL << position);
}

uint64_t clearBit(uint64_t bitboard, int position) {
    return bitboard & ~(1ULL << position);
}

// Debugging
void printWholeBoard() {
    std::cout << "   a b c d e f g h" << std::endl;
    for (int rank = 7; rank >= 0; rank--) {
        std::cout << (rank + 1) << " ";
        for (int file = 0; file < 8; file++) {
            int square = (rank * 8) + file;
            if (whitePawns & (1ULL << square)) {
                std::cout << "P ";
            } else if (whiteKnights & (1ULL << square)) {
                std::cout << "N ";
            } else if (whiteBishops & (1ULL << square)) {
                std::cout << "B ";
            } else if (whiteRooks & (1ULL << square)) {
                std::cout << "R ";
            } else if (whiteQueens & (1ULL << square)) {
                std::cout << "Q ";
            } else if (whiteKing & (1ULL << square)) {
                std::cout << "K ";
            } else if (blackPawns & (1ULL << square)) {
                std::cout << "p ";
            } else if (blackKnights & (1ULL << square)) {
                std::cout << "n ";
            } else if (blackBishops & (1ULL << square)) {
                std::cout << "b ";
            } else if (blackRooks & (1ULL << square)) {
                std::cout << "r ";
            } else if (blackQueens & (1ULL << square)) {
                std::cout << "q ";
            } else if (blackKing & (1ULL << square)) {
                std::cout << "k ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << (rank + 1) << std::endl;
    }
    std::cout << "   a b c d e f g h" << std::endl;
}

void printBitboard(uint64_t bitboard) {
    for (int rank = 7; rank >= 0; rank--) {
        std::cout << (rank + 1) << " "; // Print the rank number
        for (int file = 0; file < 8; file++) {
            int square = (rank * 8) + file;
            if (bitboard & (1ULL << square)) {
                std::cout << "X "; // Print 'X' if the bit is set
            } else {
                std::cout << "- "; // Print '-' if the bit is clear
            }
        }
        std::cout << std::endl; // Move to the next rank
    }
    std::cout << "  a b c d e f g h" << std::endl; // Print the file names
}

// Initialize the chessboard to the starting position
void initializeBoard() {
    // Clear all bitboards
    whitePawns = whiteKnights = whiteBishops = whiteRooks = whiteQueens = whiteKing = 0;
    blackPawns = blackKnights = blackBishops = blackRooks = blackQueens = blackKing = 0;

    // Set up the white pieces
    whitePawns = 0xFF00; // Pawns on the second rank
    whiteKnights = setBit(whiteKnights, 1) | setBit(whiteKnights, 6); // Knights
    whiteBishops = setBit(whiteBishops, 2) | setBit(whiteBishops, 5); // Bishops
    whiteRooks = setBit(whiteRooks, 0) | setBit(whiteRooks, 7); // Rooks
    whiteQueens = setBit(whiteQueens, 3); // Queen
    whiteKing = setBit(whiteKing, 4); // King

    // Set up the black pieces (adjust the positions for black pieces)
    blackPawns = 0xFF000000000000; // Pawns on the seventh rank
    blackKnights = setBit(blackKnights, 57) | setBit(blackKnights, 62); // Knights
    blackBishops = setBit(blackBishops, 58) | setBit(blackBishops, 61); // Bishops
    blackRooks = setBit(blackRooks, 56) | setBit(blackRooks, 63); // Rooks
    blackQueens = setBit(blackQueens, 59); // Queen
    blackKing = setBit(blackKing, 60); // King
    allPieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing |
                blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
}

// Make a move on the board
void makeMove(const Move& move) {
    uint64_t* movingPieceBitboard = nullptr;
    uint64_t* capturedPieceBitboard = nullptr;

    // Identify the moving piece's bitboard
    switch (move.piece) {
        case WHITE_PAWN: movingPieceBitboard = &whitePawns; break;
        case WHITE_KNIGHT: movingPieceBitboard = &whiteKnights; break;
        case WHITE_BISHOP: movingPieceBitboard = &whiteBishops; break;
        case WHITE_ROOK: movingPieceBitboard = &whiteRooks; break;
        case WHITE_QUEEN: movingPieceBitboard = &whiteQueens; break;
        case WHITE_KING: movingPieceBitboard = &whiteKing; break;
        case BLACK_PAWN: movingPieceBitboard = &blackPawns; break;
        case BLACK_KNIGHT: movingPieceBitboard = &blackKnights; break;
        case BLACK_BISHOP: movingPieceBitboard = &blackBishops; break;
        case BLACK_ROOK: movingPieceBitboard = &blackRooks; break;
        case BLACK_QUEEN: movingPieceBitboard = &blackQueens; break;
        case BLACK_KING: movingPieceBitboard = &blackKing; break;
        default: break;  // Optionally handle unknown piece type
    }

    // Identify the captured piece's bitboard, if any
    if (move.captured != NO_PIECE) {  // Assuming NO_PIECE is a defined constant indicating no piece captured
        switch (move.captured) {
            case WHITE_PAWN: capturedPieceBitboard = &whitePawns; break;
            case WHITE_KNIGHT: capturedPieceBitboard = &whiteKnights; break;
            case WHITE_BISHOP: capturedPieceBitboard = &whiteBishops; break;
            case WHITE_ROOK: capturedPieceBitboard = &whiteRooks; break;
            case WHITE_QUEEN: capturedPieceBitboard = &whiteQueens; break;
            case WHITE_KING: capturedPieceBitboard = &whiteKing; break;
            case BLACK_PAWN: capturedPieceBitboard = &blackPawns; break;
            case BLACK_KNIGHT: capturedPieceBitboard = &blackKnights; break;
            case BLACK_BISHOP: capturedPieceBitboard = &blackBishops; break;
            case BLACK_ROOK: capturedPieceBitboard = &blackRooks; break;
            case BLACK_QUEEN: capturedPieceBitboard = &blackQueens; break;
            case BLACK_KING: capturedPieceBitboard = &blackKing; break;
            default: break;  // Optionally handle unknown piece type
        }
    }


    // Move the piece
    if (movingPieceBitboard != nullptr) {
        *movingPieceBitboard = clearBit(*movingPieceBitboard, move.from);
        *movingPieceBitboard = setBit(*movingPieceBitboard, move.to);
    }

    // Capture the opponent's piece, if any
    if (capturedPieceBitboard != nullptr) {
        *capturedPieceBitboard = clearBit(*capturedPieceBitboard, move.to);
    }

    // Special moves handling (castling, en passant, promotion)
    switch (move.type) {
        case CASTLE:
            // Clear the original king position
            *movingPieceBitboard = clearBit(*movingPieceBitboard, move.from);
            // Set the new king position
            *movingPieceBitboard = setBit(*movingPieceBitboard, move.to);

            // Assuming movingPieceBitboard points to the king's bitboard,
            // you will need to update the correct rook's bitboard as well:
            if (move.piece == WHITE_KING || move.piece == BLACK_KING) {
                uint64_t* rookBitboard = (move.piece == WHITE_KING) ? &whiteRooks : &blackRooks;
                if (move.to > move.from) { // King-side castling
                    *rookBitboard = clearBit(*rookBitboard, move.piece == WHITE_KING ? 7 : 63);
                    *rookBitboard = setBit(*rookBitboard, move.piece == WHITE_KING ? 5 : 61);
                } else { // Queen-side castling
                    *rookBitboard = clearBit(*rookBitboard, move.piece == WHITE_KING ? 0 : 56);
                    *rookBitboard = setBit(*rookBitboard, move.piece == WHITE_KING ? 3 : 59);
                }
            }
            break;

        case EN_PASSANT:
            // Move the pawn
            *movingPieceBitboard = clearBit(*movingPieceBitboard, move.from);
            *movingPieceBitboard = setBit(*movingPieceBitboard, move.to);

            // Capture the opponent's pawn
            if (move.piece == WHITE_PAWN) {
                *capturedPieceBitboard = clearBit(*capturedPieceBitboard, move.to - 8);
            } else {
                *capturedPieceBitboard = clearBit(*capturedPieceBitboard, move.to + 8);
            }
            break;

        case PROMOTION:
            // Remove the pawn
            *movingPieceBitboard = clearBit(*movingPieceBitboard, move.from);

            // Add the promoted piece
            switch (move.promotion) {
                case WHITE_KNIGHT:
                    whiteKnights = setBit(whiteKnights, move.to);
                    break;
                case WHITE_BISHOP:
                    whiteBishops = setBit(whiteBishops, move.to);
                    break;
                case WHITE_ROOK:
                    whiteRooks = setBit(whiteRooks, move.to);
                    break;
                case WHITE_QUEEN:
                    whiteQueens = setBit(whiteQueens, move.to);
                    break;
                case BLACK_KNIGHT:
                    blackKnights = setBit(blackKnights, move.to);
                    break;
                case BLACK_BISHOP:
                    blackBishops = setBit(blackBishops, move.to);
                    break;
                case BLACK_ROOK:
                    blackRooks = setBit(blackRooks, move.to);
                    break;
                case BLACK_QUEEN:
                    blackQueens = setBit(blackQueens, move.to);
                    break;
                default:
                    if (move.piece == WHITE_PAWN) {
                        whiteQueens = setBit(whiteQueens, move.to);
                    }
                    else if (move.piece == BLACK_PAWN) {
                        blackQueens = setBit(blackQueens, move.to);
                    }
                    break;
            }
            break;
        default:
            // Normal move
            break;
    }

    // Update the combined allPieces bitboard
    allPieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing |
                blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
}

// Unmake the last move (for backtracking during search)
void undoMove(const Move& move) {
    // Identify the moving piece's bitboard
    uint64_t* movingPieceBitboard = nullptr;
    uint64_t* capturedPieceBitboard = nullptr;

    // Restore the moving piece's position
    switch (move.piece) {
        case WHITE_PAWN: movingPieceBitboard = &whitePawns; break;
        case WHITE_KNIGHT: movingPieceBitboard = &whiteKnights; break;
        case WHITE_BISHOP: movingPieceBitboard = &whiteBishops; break;
        case WHITE_ROOK: movingPieceBitboard = &whiteRooks; break;
        case WHITE_QUEEN: movingPieceBitboard = &whiteQueens; break;
        case WHITE_KING: movingPieceBitboard = &whiteKing; break;
        case BLACK_PAWN: movingPieceBitboard = &blackPawns; break;
        case BLACK_KNIGHT: movingPieceBitboard = &blackKnights; break;
        case BLACK_BISHOP: movingPieceBitboard = &blackBishops; break;
        case BLACK_ROOK: movingPieceBitboard = &blackRooks; break;
        case BLACK_QUEEN: movingPieceBitboard = &blackQueens; break;
        case BLACK_KING: movingPieceBitboard = &blackKing; break;
        default: break;
    }

    // Restore the captured piece's position, if any
    if (move.captured != NO_PIECE) {
        switch (move.captured) {
            case WHITE_PAWN: capturedPieceBitboard = &whitePawns; break;
            case WHITE_KNIGHT: capturedPieceBitboard = &whiteKnights; break;
            case WHITE_BISHOP: capturedPieceBitboard = &whiteBishops; break;
            case WHITE_ROOK: capturedPieceBitboard = &whiteRooks; break;
            case WHITE_QUEEN: capturedPieceBitboard = &whiteQueens; break;
            case WHITE_KING: capturedPieceBitboard = &whiteKing; break;
            case BLACK_PAWN: capturedPieceBitboard = &blackPawns; break;
            case BLACK_KNIGHT: capturedPieceBitboard = &blackKnights; break;
            case BLACK_BISHOP: capturedPieceBitboard = &blackBishops; break;
            case BLACK_ROOK: capturedPieceBitboard = &blackRooks; break;
            case BLACK_QUEEN: capturedPieceBitboard = &blackQueens; break;
            case BLACK_KING: capturedPieceBitboard = &blackKing; break;
            default: break;
        }
    }

    // Undo the move
    if (movingPieceBitboard != nullptr) {
        *movingPieceBitboard = clearBit(*movingPieceBitboard, move.to);
        *movingPieceBitboard = setBit(*movingPieceBitboard, move.from);
    }

    // Restore the captured piece, if any
    if (capturedPieceBitboard != nullptr) {
        *capturedPieceBitboard = setBit(*capturedPieceBitboard, move.to);
    }

    // Undo special moves
    switch (move.type) {
        case CASTLE:
            // Undo the rook move
            if (move.to > move.from) { // King-side castling
                *movingPieceBitboard = clearBit(*movingPieceBitboard, 5);
                *movingPieceBitboard = setBit(*movingPieceBitboard, 7);
            } else { // Queen-side castling
                *movingPieceBitboard = clearBit(*movingPieceBitboard, 3);
                *movingPieceBitboard = setBit(*movingPieceBitboard, 0);
            }
            break;
        case EN_PASSANT:
            // Restore the captured pawn
            if (move.piece == WHITE_PAWN) {
                *capturedPieceBitboard = setBit(*capturedPieceBitboard, move.to - 8);
            } else {
                *capturedPieceBitboard = setBit(*capturedPieceBitboard, move.to + 8);
            }
            break;
        case PROMOTION:
            // Restore the pawn and remove the promoted piece
            *movingPieceBitboard = setBit(*movingPieceBitboard, move.from);
            switch (move.promotion) {
                case WHITE_KNIGHT: whiteKnights = clearBit(whiteKnights, move.to); break;
                case WHITE_BISHOP: whiteBishops = clearBit(whiteBishops, move.to); break;
                case WHITE_ROOK: whiteRooks = clearBit(whiteRooks, move.to); break;
                case WHITE_QUEEN: whiteQueens = clearBit(whiteQueens, move.to); break;
                case BLACK_KNIGHT: blackKnights = clearBit(blackKnights, move.to); break;
                case BLACK_BISHOP: blackBishops = clearBit(blackBishops, move.to); break;
                case BLACK_ROOK: blackRooks = clearBit(blackRooks, move.to); break;
                case BLACK_QUEEN: blackQueens = clearBit(blackQueens, move.to); break;
                default: break;
            }
            break;
        default:
            // Normal move
            break;
    }

    // Update the combined allPieces bitboard
    allPieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing |
                blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
}