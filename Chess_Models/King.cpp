#include "King.h"

King::King(ChessmanColor color) : Chessman(color) {
    this->move = ChessmanIsMakeMove::FALSE;
}

ChessmanType King::GetType() {
    return ChessmanType::KING;
}

bool King::AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8])
{
    int delta_posX = end_posX - start_posX;
    int delta_posY = end_posY - start_posY;
    if(((delta_posX >= -1) && (delta_posX <= 1)) &&
       ((delta_posY >= -1) && (delta_posY <= 1))){

        return true;
    }
    if((delta_posX == 2 || delta_posX == -2) && delta_posY == 0) {
        if (this->move == ChessmanIsMakeMove::FALSE) {
            for(int rookX = 0; rookX < 8; ++rookX) {
                if(board[start_posY][rookX] != nullptr){
                    if (board[start_posY][rookX]->GetType() == ChessmanType::ROOK){
                        if(board[start_posY][rookX]->GetMove() == ChessmanIsMakeMove::FALSE) {
                            int flag_posX = (rookX - start_posX > 0) ? 1 : -1;
                            if ((rookX - start_posX < 0) && (delta_posX == -2)) {
                                for (int CheckX = rookX - flag_posX;
                                     CheckX != start_posX;
                                     CheckX -= flag_posX) {
                                    if (board[start_posY][CheckX] != nullptr) {
                                        return false;
                                    }
                                }
                                return true;
                            }
                            else if ((rookX - start_posX > 0) && (delta_posX == 2)) {
                                for (int CheckX = rookX - flag_posX;
                                     CheckX != start_posX;
                                     CheckX -= flag_posX) {
                                    if (board[start_posY][CheckX] != nullptr) {
                                        return false;
                                    }
                                }
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
//    if(this->move == ChessmanIsMakeMove::FALSE){
//        for(int rookX = 0; rookX < 7; ++rookX){
//            if(board[start_posY][rookX] != nullptr && board[start_posY][rookX]->GetType() == ChessmanType::ROOK){
//                int flag_posX = (rookX - start_posX > 0) ? 1 : -1;
//                if(board[start_posY][rookX]->GetMove() == ChessmanIsMakeMove::FALSE) {
//                    if ((rookX - start_posX < 0) && (delta_posX == -2) && (delta_posY == 0)) {
//                        for (int CheckX = start_posX + flag_posX;
//                             CheckX != end_posX;
//                             CheckX += flag_posX) {
//                            if (board[start_posY][CheckX] != nullptr) {
//                                return false;
//                            }
//                        }
//                        return true;
//                    }
//                    else if ((rookX - start_posX > 0) && (delta_posX == 2) && (delta_posY == 0)) {
//                        for (int CheckX = start_posX + flag_posX;
//                             CheckX != end_posX;
//                             CheckX += flag_posX) {
//                            if (board[start_posY][CheckX] != nullptr) {
//                                return false;
//                            }
//                        }
//                        return true;
//                    }
//                }
//            }
//        }
//    }
    return false;

}

bool King::AreCastleLegal(int start_posX, int start_posY, int end_posX, int end_posY, Chessman *(*board)[8]) {
    int delta_posX = end_posX - start_posX;
    int delta_posY = end_posY - start_posY;
    if((delta_posX == 2 || delta_posX == -2) && delta_posY == 0) {
        if (this->move == ChessmanIsMakeMove::FALSE) {
            for(int rookX = 0; rookX < 8; ++rookX) {
                if(board[start_posY][rookX] != nullptr){
                    if (board[start_posY][rookX]->GetType() == ChessmanType::ROOK){
                        if(board[start_posY][rookX]->GetMove() == ChessmanIsMakeMove::FALSE) {
                            int flag_posX = (rookX - start_posX > 0) ? 1 : -1;
                            if ((rookX - start_posX < 0) && (delta_posX == -2)) {
                                for (int CheckX = rookX - flag_posX;
                                     CheckX != start_posX;
                                     CheckX -= flag_posX) {
                                    if (board[start_posY][CheckX] != nullptr) {
                                        return false;
                                    }
                                }
                                return true;
                            }
                            else if ((rookX - start_posX > 0) && (delta_posX == 2)) {
                                for (int CheckX = rookX - flag_posX;
                                     CheckX != start_posX;
                                     CheckX -= flag_posX) {
                                    if (board[start_posY][CheckX] != nullptr) {
                                        return false;
                                    }
                                }
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;








//    if(this->move == ChessmanIsMakeMove::FALSE){
//        for(int rookX = 0; rookX < 7; ++rookX){
//            if(board[start_posY][rookX]->GetType() == ChessmanType::ROOK){
//                int flag_posX = (rookX - start_posX > 0) ? 1 : -1;
//                if(board[start_posY][rookX]->GetMove() == ChessmanIsMakeMove::FALSE){
//                    if((rookX - start_posX < 0) && (delta_posX == -2) && (delta_posY == 0)){
//                        for(int CheckX = start_posX + flag_posX;
//                            CheckX != end_posX;
//                            CheckX += flag_posX) {
//                            if (board[start_posY][CheckX] != nullptr) {
//                                return false;
//                            }
//                        }
//                        return true;
//
//                    }
//                    else if((rookX - start_posX > 0) && (delta_posX == 2) && (delta_posY == 0)){
//                        for(int CheckX = start_posX + flag_posX;
//                            CheckX != end_posX;
//                            CheckX += flag_posX) {
//                            if (board[start_posY][CheckX] != nullptr) {
//                                return false;
//                            }
//                        }
//                        return true;
//
//                    }
//                }
//            }
//        }
//    }







    //    int delta_posX = end_posX - start_posX;
//    if(this->move == ChessmanIsMakeMove::FALSE){
//        int flag_posX = (end_posX - start_posX > 0) ? 1 : -1;
//        if(board[start_posY][7]->GetMove() == ChessmanIsMakeMove::FALSE){
//            if((7 - start_posX == -3) || (7 - start_posX == 3)){
//                if((delta_posX == -2) || (delta_posX == 2)){
//                    for(int CheckX = start_posX + flag_posX;
//                        CheckX != end_posX;
//                        CheckX += flag_posX){
//                        if(board[start_posY][CheckX] != nullptr){
//                            return false;
//                        }
//                    }
////                    SetMoveTrue();
//                    return true;
//                }
//            }
//            else if((7 - start_posX == -4) || (7 - start_posX == 4)){
//                if((delta_posX == -3) || (delta_posX == 3)){
//                    for(int CheckX = start_posX + flag_posX;
//                        CheckX != end_posX;
//                        CheckX += flag_posX){
//                        if(board[start_posY][CheckX] != nullptr){
//                            return false;
//                        }
//                    }
//                    SetMoveTrue();
//                    return true;
//                }
//            }
//        }
//        else if(board[start_posY][0]->GetMove() == ChessmanIsMakeMove::FALSE){
//            if((0 - start_posX == -3) || (0 - start_posX == 3)){
//                if((delta_posX == -2) || (delta_posX == 2)){
//                    for(int CheckX = start_posX + flag_posX;
//                        CheckX != end_posX;
//                        CheckX += flag_posX){
//                        if(board[start_posY][CheckX] != nullptr){
//                            return false;
//                        }
//                    }
//                    return true;
//                }
//            }
//            else if((7 - start_posX == -4) || (7 - start_posX == 4)){
//                if((delta_posX == -3) || (delta_posX == 3)){
//                    for(int CheckX = start_posX + flag_posX;
//                        CheckX != end_posX;
//                        CheckX += flag_posX){
//                        if(board[start_posY][CheckX] != nullptr){
//                            return false;
//                        }
//                    }
//                    SetMoveTrue();
//                    return true;
//                }
//            }
//        }
//    }
}

void King::SetMoveTrue() {
    this->move = ChessmanIsMakeMove::TRUE;
}
