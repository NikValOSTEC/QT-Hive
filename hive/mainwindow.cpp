#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "port.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        ui->ScrollArea->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this->ui->ScrollArea, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(showContextMenu(QPoint)));
        Plus();
}




void MainWindow::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("New",  this, SLOT(Plus()));
    myMenu.exec(globalPos);
}




void MainWindow::Plus()
{
    auto prt=new Port(nullptr);
    ui->ScrollArea->widget()->layout()->addWidget(prt);
    prt->move(0,0);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

