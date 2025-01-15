#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Chessman.h"

class Queen: public Chessman
{
public:
    explicit Queen(ChessmanColor color) : Chessman(color){}
    virtual ChessmanType GetType();
    bool AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]);
    bool AreCastleLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]){return false;}

};

#endif //CHESS_QUEEN_H
