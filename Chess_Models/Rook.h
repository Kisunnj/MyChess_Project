#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Chessman.h"

class Rook: public Chessman
{
public:
    explicit Rook(ChessmanColor color);
    virtual ChessmanType GetType();
    bool AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]);
    void SetMoveTrue();
    bool AreCastleLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]){return false;}

};

#endif //CHESS_ROOK_H
