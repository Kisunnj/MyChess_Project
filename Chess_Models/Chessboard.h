//
// Created by Михаил on 08.04.2023.
//

#ifndef CHESS_CHESSBOARD_H
#define CHESS_CHESSBOARD_H
#include "Chessman.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"


class ChessBoard
{
public:
    ChessBoard();
    ~ChessBoard();
    bool IsInCheck(ChessmanColor color);
    bool CanMove(ChessmanColor color);
    Chessman *chessman[8][8];
};


#endif //CHESS_CHESSBOARD_H
