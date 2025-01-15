#ifndef CHESS_GRAPHICVIEW_H
#define CHESS_GRAPHICVIEW_H

#include <QPixmap>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QPainter>
#include <QLabel>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include "ChessmanView.h"


class GraphicView : public QGraphicsView
{
Q_OBJECT
public:
    explicit GraphicView(QMainWindow *parent = 0);
    virtual ~GraphicView(){};
signals:

private slots:
    void slotAlarmTimer();
private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *group_1;
    QGraphicsItemGroup *group_2;
    QTimer *timer;
    ChessmanView *myFigures;

    QRectF boardFields[8][8];


    void paintBoard();
    void resizeEvent(QResizeEvent *event) override;
    void deleteItemsFromGroup(QGraphicsItemGroup *group);
    void mousePressEvent(QMouseEvent *event) override;

};

#endif //CHESS_GRAPHICVIEW_H
