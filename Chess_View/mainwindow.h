//
// Created by Михаил on 08.04.2023.
//

#ifndef CHESS_MAINWINDOW_H
#define CHESS_MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "GraphicView.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = 0);
    virtual ~MainWindow(){};

private:
    Ui::MainWindow  *ui;
    GraphicView   *myPicture;
};


#endif //CHESS_MAINWINDOW_H
