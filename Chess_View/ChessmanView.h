#ifndef CHP_CHESSMANVIEW_H
#define CHP_CHESSMANVIEW_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QMessageBox>
#include "../Chess_Models/Chessboard.h"
#include "../Chess_Models/Chessman.h"


class ChessmanView: public QGraphicsItem {

public:
    ChessmanView(int width_, int height_);

    void AlternateTurn();

    bool isLegalField(int x1, int y1, int x2, int y2);
    bool IsNeedDraw(int x, int y);
    void SetFirstPress(int x, int y);
    void SetSecondPress(int x, int y);
    void TurnBoard();
    void SetNewSize(int width_, int height_);
    void clearPressMouse();
    bool move();
    bool isSecondPress() const;

    bool isGameOver();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* Widget) override;
    ~ChessmanView() override = default;
private:
    QRectF boundingRect() const override;
    QPixmap *image;
    ChessBoard *board;
    ChessmanColor playerTurn;


    int centerOfMainWindow_X, centerOfMainWindow_Y, sideOfBoard;
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
};

#endif //CHP_CHESSMANVIEW_H
