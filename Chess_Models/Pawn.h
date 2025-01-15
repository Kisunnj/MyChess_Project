//
// Created by Михаил on 12.04.2023.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Chessman.h"
#include <cmath>

class Pawn: public Chessman
{
public:
    explicit Pawn(ChessmanColor color) : Chessman(color){}
    virtual ChessmanType GetType();
    bool AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]);
    bool AreCastleLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]){return false;}

};


#endif //CHESS_PAWN_H
