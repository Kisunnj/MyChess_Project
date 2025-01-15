#include "Bishop.h"

ChessmanType Bishop::GetType() {
    return ChessmanType::BISHOP;
}

bool Bishop::AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8])
{
    if(abs(start_posX - end_posX) == abs(start_posY - end_posY)){
        int flag_posX = (end_posX - start_posX > 0) ? 1 : -1;
        int flag_posY = (end_posY - start_posY > 0) ? 1 : -1;
        int CheckX;
        int CheckY;
        for(CheckX = start_posX + flag_posX, CheckY = start_posY + flag_posY;
            CheckX != end_posX;
            CheckX += flag_posX, CheckY += flag_posY){
            if(board[CheckY][CheckX] != nullptr){
                return false;
            }
        }
        return true;
    }
    return false;
}
