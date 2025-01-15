#include "Queen.h"


ChessmanType Queen::GetType() {
    return ChessmanType::QUEEN;
}

bool Queen::AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8])
{
    int flag_posX = (end_posX - start_posX > 0) ? 1 : -1;
    int flag_posY = (end_posY - start_posY > 0) ? 1 : -1;
    if(abs(start_posX - end_posX) == abs(start_posY - end_posY)){
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
    if (start_posX == end_posX) {
        int CheckY;
        for (CheckY = start_posY + flag_posY; CheckY != end_posY; CheckY += flag_posY) {
            if (board[CheckY][start_posX] != nullptr) {
                return false;
            }
        }
        return true;
    }
    else if (end_posY == start_posY) {
        int CheckX;
        for (CheckX = start_posX + flag_posX; CheckX != end_posX; CheckX += flag_posX) {
            if (board[start_posY][CheckX] != nullptr) {
                return false;
            }
        }
        return true;
    }
    return false;
}