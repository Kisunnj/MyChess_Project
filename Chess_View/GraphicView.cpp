#include "GraphicView.h"

GraphicView::GraphicView(QMainWindow *parent)
        : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(700);
    this->setMinimumWidth(700);

    scene = new QGraphicsScene();
    this->setScene(scene);


    group_1 = new QGraphicsItemGroup();
    group_2 = new QGraphicsItemGroup();
    myFigures = new ChessmanView(this->width(), this->height());
    scene->addItem(group_2);
    scene->addItem(group_1);

    timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
}

void GraphicView::slotAlarmTimer()
{
    this->deleteItemsFromGroup(group_2);
    this->deleteItemsFromGroup(group_1);

    scene->setSceneRect(0, 0, this->width(), this->height());

    //group_2
    paintBoard();

    //group_1
    myFigures->SetNewSize(this->width(), this->height());
    group_1->addToGroup(myFigures);
}


void GraphicView::resizeEvent(QResizeEvent *event)
{
    timer->start(10);
    int width = this->width();
    int height = this->height();
    int sideOfSquare = (height > width) ? (width - 60) : (height - 60);
    int centerOfMainWindow_X = width/2;
    int centerOfMainWindow_Y = height/2;
    double sideOfLittelSquare = sideOfSquare/8.;

    double one_fieldX = 0, one_fieldY = sideOfLittelSquare;
    for(int j = 0; j < 8; ++j){
        for(int i = 0; i < 8; ++i){
            boardFields[j][i] = QRectF(centerOfMainWindow_X - (sideOfSquare / 2) + one_fieldX,
                                       centerOfMainWindow_Y + (sideOfSquare / 2) - one_fieldY,
                                       sideOfLittelSquare,
                                       sideOfLittelSquare);
            one_fieldX += sideOfLittelSquare;
        }
        one_fieldY += sideOfLittelSquare;
        one_fieldX = 0;
    }

    myFigures->clearPressMouse();
    QGraphicsView::resizeEvent(event);
}

void GraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    if (group == group_1){
        group_1->removeFromGroup(myFigures);
    }
    else {
        foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
            if(item->group() == group ) {
                delete item;
            }
        }
    }
}

void GraphicView::mousePressEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton) {
        int pressFieldX = -1, pressFieldY = -1;
        bool flag = false;
        QPen penBlack(Qt::black);
        QBrush brush(QColor(252, 251, 204));

//TODO: OUT OF THE BOARD CLICK
        for (int j = 0; j < 8; ++j) {
            for (int i = 0; i < 8; ++i) {
                if(abs(boardFields[j][i].center().x() - event->position().x()) <= boardFields[j][i].height()/2 &&
                   abs(boardFields[j][i].center().y() - event->position().y()) <= boardFields[j][i].height()/2){
                    pressFieldX = i;
                    pressFieldY = j;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }

        if (myFigures->IsNeedDraw(pressFieldX, pressFieldY)) {
            myFigures->SetFirstPress(pressFieldX, pressFieldY);
            slotAlarmTimer();
            for (int j = 0; j < 8; ++j) {
                for (int i = 0; i < 8; ++i) {
                    if (myFigures->isLegalField(pressFieldX, pressFieldY, i, j)) {
                        group_2->addToGroup(scene->addRect(boardFields[j][i],
                                                           penBlack, brush));

                    }
                }
            }
        }
        else if(myFigures->isSecondPress()){
            myFigures->SetSecondPress(pressFieldX, pressFieldY);
            if(myFigures->move()){
                if(myFigures->isGameOver()){
                    QMessageBox::critical(this,"Конец игры","Шах и мат");
                }
            }
            slotAlarmTimer();
        }
    }
//    else if(event->buttons() & Qt::RightButton){
//        myFigures->TurnBoard();
//        slotAlarmTimer();
//    }
}

void GraphicView::paintBoard() {
    QBrush brushBlack(QColor(67, 152, 209));
    QBrush brushWhite(QColor(220, 245, 247));
    QPen penBlack(Qt::black);
    for(int j = 0; j < 8; ++j){
        for(int i = 0; i < 8; ++i){
            if((i + j) % 2 == 0) {
                group_2->addToGroup(scene->addRect(boardFields[j][i],
                                                   penBlack, brushWhite));
            }
            else {
                group_2->addToGroup(scene->addRect(boardFields[j][i],
                                                   penBlack, brushBlack));
            }
        }
    }
}



