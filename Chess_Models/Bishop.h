#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Chessman.h"

class Bishop: public Chessman
{
public:
    explicit Bishop(ChessmanColor color) : Chessman(color){}
    virtual ChessmanType GetType();
    bool AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]);
    bool AreCastleLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]){return false;}
};



#endif //CHESS_BISHOP_H
