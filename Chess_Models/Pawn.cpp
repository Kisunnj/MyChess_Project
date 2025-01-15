#include "Pawn.h"

ChessmanType Pawn::GetType() {
    return ChessmanType::PAWN;
}

bool Pawn::AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8])
{
    Chessman* chessman = board[end_posY][end_posX];
    if (chessman == nullptr) {
        if (start_posX == end_posX) {
            //было
//            if (GetColor() == ChessmanColor::WHITE) {
//                if ((end_posY == start_posY + 1) || ((end_posY == start_posY + 2) && (end_posY == 3))) {
//                    return true;
//                }
//            }
//            else {
//                if ((end_posY == start_posY - 1) || ((end_posY == start_posY - 2) && (end_posY == 4))) {
//                    return true;
//                }
//            }
            //стало
            if ((end_posY == start_posY + 1) || ((end_posY == start_posY + 2) && (end_posY == 3))) {
                    return true;
            }



        }
    }
    else {
        if ((start_posX == end_posX + 1) || (start_posX == end_posX - 1)) {
            //было
//            if (GetColor() == ChessmanColor::WHITE) {
//                if (end_posY == start_posY + 1) {
//                    return true;
//                }
//            }
//            else {
//                if (end_posY == start_posY - 1) {
//                    return true;
//                }
//            }
            //стало
            if (end_posY == start_posY + 1) {
                    return true;
            }


        }
    }
    return false;
}
