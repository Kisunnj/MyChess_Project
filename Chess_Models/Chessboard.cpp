#include "Chessboard.h"


ChessBoard::ChessBoard()
{
    for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            chessman[row][col] = nullptr;
        }
    }
    for(int col = 0; col < 8; ++col) {
        chessman[6][col] = new Pawn(ChessmanColor::BLACK);
    }
    chessman[7][0] = new Rook(ChessmanColor::BLACK);
    chessman[7][1] = new Knight(ChessmanColor::BLACK);
    chessman[7][2] = new Bishop(ChessmanColor::BLACK);
    chessman[7][3] = new Queen(ChessmanColor::BLACK);
    chessman[7][4] = new King(ChessmanColor::BLACK);
    chessman[7][5] = new Bishop(ChessmanColor::BLACK);
    chessman[7][6] = new Knight(ChessmanColor::BLACK);
    chessman[7][7] = new Rook(ChessmanColor::BLACK);
    for(int col = 0; col < 8; ++col) {
        chessman[1][col] = new Pawn(ChessmanColor::WHITE);
    }
    chessman[0][0] = new Rook(ChessmanColor::WHITE);
    chessman[0][1] = new Knight(ChessmanColor::WHITE);
    chessman[0][2] = new Bishop(ChessmanColor::WHITE);
    chessman[0][3] = new Queen(ChessmanColor::WHITE);
    chessman[0][4] = new King(ChessmanColor::WHITE);
    chessman[0][5] = new Bishop(ChessmanColor::WHITE);
    chessman[0][6] = new Knight(ChessmanColor::WHITE);
    chessman[0][7] = new Rook(ChessmanColor::WHITE);
}

ChessBoard::~ChessBoard() {
    for (int iRow = 0; iRow < 8; ++iRow) {
        for (int iCol = 0; iCol < 8; ++iCol) {
            delete chessman[iRow][iCol];
            chessman[iRow][iCol] = 0;
        }
    }
}

bool ChessBoard::IsInCheck(ChessmanColor color) {
    int iKingRow;
    int iKingCol;
    for (int iRow = 0; iRow < 8; ++iRow) {
        for (int iCol = 0; iCol < 8; ++iCol) {
            if (chessman[iRow][iCol] != nullptr) {
                if (chessman[iRow][iCol]->GetType() == ChessmanType::KING) {
                    if (chessman[iRow][iCol]->GetColor() == color) {
                        iKingRow = iRow;
                        iKingCol = iCol;
                    }
                }
            }
        }
    }
    for (int iRow = 0; iRow < 8; ++iRow) {
        for (int iCol = 0; iCol < 8; ++iCol) {
            if (chessman[iRow][iCol] != nullptr) {
                if (chessman[iRow][iCol]->GetColor() != color) {
                    if (chessman[iRow][iCol]->IsMoveLegal(iCol, iRow, iKingCol, iKingRow, chessman)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool ChessBoard::CanMove(ChessmanColor color) {
    for (int iRow = 0; iRow < 8; ++iRow) {
        for (int iCol = 0; iCol < 8; ++iCol) {
            if (chessman[iRow][iCol] != nullptr) {
                if (chessman[iRow][iCol]->GetColor() == color) {
                    for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow) {
                        for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol) {
                            if (chessman[iRow][iCol]->IsMoveLegal(iCol, iRow, iMoveCol, iMoveRow, chessman)) {
                                //  whether king is in check
                                Chessman* qpTemp = chessman[iMoveRow][iMoveCol];
                                chessman[iMoveRow][iMoveCol] = chessman[iRow][iCol];
                                chessman[iRow][iCol] = nullptr;
                                bool bCanMove = !IsInCheck(color);
                                chessman[iRow][iCol] = chessman[iMoveRow][iMoveCol];
                                chessman[iMoveRow][iMoveCol] = qpTemp;
                                if (bCanMove) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
