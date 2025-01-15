#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Chessman.h"



class King: public Chessman
{
public:
    explicit King(ChessmanColor color);
    virtual ChessmanType GetType();
    bool AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]);
    bool AreCastleLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]);
    void SetMoveTrue();

};


#endif //CHESS_KING_H
