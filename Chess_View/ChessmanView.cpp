#include "ChessmanView.h"
ChessmanView::ChessmanView(int width_, int height_) : playerTurn(ChessmanColor::WHITE){
    this->centerOfMainWindow_X = width_/2;
    this->centerOfMainWindow_Y = height_/2;
    this->sideOfBoard = (height_ > width_) ? (width_ - 60) : (height_ - 60);
    board = new ChessBoard();
}

void ChessmanView::SetNewSize(int width_, int height_) {
    this->centerOfMainWindow_X = width_/2;
    this->centerOfMainWindow_Y = height_/2;
    this->sideOfBoard = (height_ > width_) ? (width_ - 60) : (height_ - 60);
}

void ChessmanView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *Widget) {
    double one_field = sideOfBoard/8.;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board->chessman[i][j] == nullptr) {
                image = nullptr;
                continue;
            }
            if (board->chessman[i][j]->GetColor() == ChessmanColor::WHITE) {
                if (board->chessman[i][j]->GetType() == ChessmanType::PAWN) {
                    image = new QPixmap("../resources/W_pawn.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::ROOK) {
                    image = new QPixmap("../resources/W_rook.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::KNIGHT) {
                    image = new QPixmap("../resources/W_knight.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::BISHOP) {
                    image = new QPixmap("../resources/W_bishop.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::KING) {
                    image = new QPixmap("../resources/W_king.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::QUEEN) {
                    image = new QPixmap("../resources/W_queen.png");\
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);
                }
            }
            else {
                if (board->chessman[i][j]->GetType() == ChessmanType::PAWN) {
                    image = new QPixmap("../resources/B_pawn.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::ROOK) {
                    image = new QPixmap("../resources/B_rook.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::KNIGHT) {
                    image = new QPixmap("../resources/B_knight.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::BISHOP) {
                    image = new QPixmap("../resources/B_bishop.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::KING) {
                    image = new QPixmap("../resources/B_king.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);

                } else if (board->chessman[i][j]->GetType() == ChessmanType::QUEEN) {
                    image = new QPixmap("../resources/B_queen.png");
                    painter->drawPixmap(centerOfMainWindow_X - (sideOfBoard / 2) + one_field * j,
                                        centerOfMainWindow_Y + (sideOfBoard / 2) - i * one_field - one_field,
                                        sideOfBoard / 8., sideOfBoard / 8., *image);
                }
            }
        }
    }
    Q_UNUSED(option);
    Q_UNUSED(Widget);
}

QRectF ChessmanView::boundingRect() const {
    return QRectF(centerOfMainWindow_X - sideOfBoard/2, centerOfMainWindow_Y - sideOfBoard/2, sideOfBoard, sideOfBoard);
}

bool ChessmanView::IsNeedDraw(int x, int y) {
    if (board->chessman[y][x] != nullptr && board->chessman[y][x]->GetColor() == playerTurn) {
            return true;
    }
    return false;
}

bool ChessmanView::move() {
    if (board->chessman[y1][x1]->GetType() == ChessmanType::KING){
        if (board->chessman[y1][x1]->IsMoveLegal(x1, y1, x2, y2, board->chessman)) {
            if(board->chessman[y1][x1]->AreCastleLegal(x1, y1, x2, y2, board->chessman)) {
                if(!board->IsInCheck(playerTurn)) {
                    int flag_posX = (x2 - x1 > 0) ? 1 : -1;
                    int CheckX = x1 + flag_posX;
                    board->chessman[y1][CheckX] = board->chessman[y1][x1];
                    board->chessman[y1][x1] = nullptr;
                    if(board->IsInCheck(playerTurn)) {
                        board->chessman[y1][x1] = board->chessman[y1][CheckX];
                        board->chessman[y1][CheckX] = nullptr;
                        clearPressMouse();
                        return false;
                    }
                    CheckX += flag_posX;
                    board->chessman[y1][CheckX] = board->chessman[y1][CheckX - flag_posX];
                    board->chessman[y1][CheckX - flag_posX] = nullptr;
                    if(board->IsInCheck(playerTurn)) {
                        board->chessman[y1][x1] = board->chessman[y1][CheckX];
                        board->chessman[y1][CheckX] = nullptr;
                        clearPressMouse();
                        return false;
                    }
//                        for (int CheckX = x1 + flag_posX; !board->IsInCheck(playerTurn) && CheckX != x2; CheckX += flag_posX) {
//                        board->chessman[y1][CheckX] = board->chessman[y1][CheckX - flag_posX];
//                        board->chessman[y1][CheckX - flag_posX] = nullptr;
//                        if (board->IsInCheck(playerTurn)) {
//                            board->chessman[y1][x1] = board->chessman[y1][CheckX];
//                            board->chessman[y1][CheckX] = nullptr;
//                            clearPressMouse();
//                            return false;
//                        }
//                        else {
//                            board->chessman[y1][CheckX + flag_posX] = board->chessman[y1][CheckX];
//                            board->chessman[y1][CheckX] = nullptr;
//                        }
//                    }
                    if (x2 - x1 > 0) {
                        board->chessman[y1][x1 + flag_posX] = board->chessman[y1][7];
                        board->chessman[y1][7] = nullptr;
                        AlternateTurn();
                        clearPressMouse();
                        return true;
                    }
                    else {
                        board->chessman[y1][x1 + flag_posX] = board->chessman[y1][0];
                        board->chessman[y1][0] = nullptr;
                        AlternateTurn();
                        clearPressMouse();
                        return true;
                    }
                }
                else{
                    clearPressMouse();
                    return false;
                }
            }
        }
    }

    if (board->chessman[y1][x1]->IsMoveLegal(x1, y1, x2, y2, board->chessman)) {
        Chessman* buf = board->chessman[y2][x2];
        board->chessman[y2][x2] = board->chessman[y1][x1];
        board->chessman[y1][x1] = nullptr;
        if(board->IsInCheck(playerTurn)){
            board->chessman[y1][x1] = board->chessman[y2][x2];
            board->chessman[y2][x2] = buf;
            clearPressMouse();
            return false;
        }
        else{
            board->chessman[y2][x2]->SetMove(ChessmanIsMakeMove::TRUE);
            AlternateTurn();
            delete buf;
            clearPressMouse();
            return true;
        }
    }
    clearPressMouse();
    return false;
}

void ChessmanView::clearPressMouse() {
    x1 = -1;
    y1 = -1;
    x2 = -1;
    y2 = -1;
}

void ChessmanView::AlternateTurn() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            Chessman* buf = board->chessman[i][j];
            board->chessman[i][j] = board->chessman[7 - i][7 - j];
            board->chessman[7 - i][7 - j] = buf;
        }
    }
    playerTurn = (playerTurn == ChessmanColor::WHITE) ? ChessmanColor::BLACK : ChessmanColor::WHITE;
}

bool ChessmanView::isSecondPress() const {
    if(x1 != -1 && y1 != -1){
        return true;
    }
    return false;
}

bool ChessmanView::isGameOver() {
    bool bCanMove(false);
    bCanMove = board->CanMove(playerTurn);
    if (!bCanMove) {
        if (board->IsInCheck(playerTurn)) {
            AlternateTurn();
            qDebug() << "Checkmate!";
        }

    }
    return !bCanMove;
}

void ChessmanView::SetFirstPress(int x, int y) {
    this->x1 = x;
    this->y1 = y;
}

void ChessmanView::SetSecondPress(int x, int y) {
    this->x2 = x;
    this->y2 = y;
}

bool ChessmanView::isLegalField(int x1, int y1, int x2, int y2) {
    if(board->chessman[y1][x1]->IsMoveLegal(x1, y1, x2, y2, board->chessman)){
        return true;
    }
    else{
        return false;
    }
}

void ChessmanView::TurnBoard() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            Chessman* buf = board->chessman[i][j];
            board->chessman[i][j] = board->chessman[7 - i][7 - j];
            board->chessman[7 - i][7 - j] = buf;
        }
    }
}



