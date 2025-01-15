#include "Chessman.h"

bool Chessman::IsMoveLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]) {
    Chessman* chessman = board[end_posY][end_posX];
    if(chessman == nullptr || color != chessman->GetColor()){
        return AreFieldLegal(start_posX, start_posY, end_posX, end_posY, board);
    }
    return false;
}

ChessmanColor Chessman::GetColor() {
    return color;
}

ChessmanIsMakeMove Chessman::GetMove() {
    return move;
}

ChessmanIsMakeMove Chessman::SetMove(ChessmanIsMakeMove move) {
    this->move = move;
}

//bool Chessman::IsCastleLegal(int start_posX, int start_posY, int end_posX, int end_posY, Chessman* board[8][8]) {
//    Q_UNUSED(start_posX);
//    Q_UNUSED(start_posY);
//    Q_UNUSED(end_posX);
//    Q_UNUSED(end_posY);
//    Q_UNUSED(board);
//    return false;
//}

