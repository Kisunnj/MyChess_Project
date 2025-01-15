#include "Knight.h"

ChessmanType Knight::GetType() {
    return ChessmanType::KNIGHT;
}

bool Knight::AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8])
{
    int difX = abs(end_posX - start_posX);
    int difY = abs(end_posY - start_posY);
    if((difX == 2 && difY == 1) || (difX == 1 && difY == 2)){
        return true;
    }
    return false;
}
