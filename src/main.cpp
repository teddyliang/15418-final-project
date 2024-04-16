#include "bitboards.h"
#include "move.h"
#include <iostream>

int main() {
    // Initialize the chessboard to the starting position
    initializeBoard();
    std::cout << "initial board" << std::endl;
    printWholeBoard();


    // std::string userInput;
    // bool isGameOver = false;

    // while (!isGameOver) {
    //     std::cout << "Enter your move (e.g., e2 e4): ";
    //     std::getline(std::cin, userInput);

    //     // Convert user input to Move object
    //     Move userMove = parseMove(userInput);  // You need to implement parseMove

    //     makeMove(userMove);
    //     printWholeBoard();

    //     if (isCheckmate()) {
    //         std::cout << "Checkmate! You win!" << std::endl;
    //         break;
    //     } else if (isStalemate()) {
    //         std::cout << "Stalemate! It's a draw!" << std::endl;
    //         break;
    //     }

    //     // Engine makes a move
    //     Move engineMove = engineDecideMove();  // You need an engine decision-making function
    //     makeMove(engineMove);
    //     std::cout << "Engine's move: " << moveToString(engineMove) << std::endl;  // Implement moveToString
    //     printWholeBoard();

    //     if (isCheckmate()) {
    //         std::cout << "Checkmate! Engine wins!" << std::endl;
    //         break;
    //     } else if (isStalemate()) {
    //         std::cout << "Stalemate! It's a draw!" << std::endl;
    //         break;
    //     }
    // }

    // return 0;
    std::cout << "first move" << std::endl;
    Move move = Move(8,16,WHITE_PAWN);
    makeMove(move);
    printWholeBoard();
    std::cout << "undo first move" << std::endl;
    undoMove(move);
    printWholeBoard();
    std::cout << "castle king side move (not legal but just checking bitboards)" << std::endl;
    Move castleKing = Move(4,6,WHITE_KING, NO_PIECE, CASTLE, NO_PIECE);
    makeMove(castleKing);
    printWholeBoard();
    std::cout << "king position:" << std::endl;
    printBitboard(whiteKing);
    std::cout << "rook positions:" << std::endl;
    printBitboard(whiteRooks);
    return 0;
}