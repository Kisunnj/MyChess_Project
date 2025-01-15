#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QMainWindow *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myPicture = new GraphicView();
    ui->gridLayout->addWidget(myPicture);
}


