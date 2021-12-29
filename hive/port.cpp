#include "port.h"
#include "ui_port.h"
#include<QDebug>

Port::Port(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Port),
    _mousePressed(false),
    _mousePosition(QPoint())
{
    ui->setupUi(this);
    ui->ScrollArea->widget()->layout()->setAlignment(Qt::AlignmentFlag::AlignTop);
    ui->ScrollArea->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this->ui->ScrollArea, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
}




void Port::showContextMenu(const QPoint &pos)
{
QPoint globalPos = this->mapToGlobal(pos);
QMenu myMenu;
myMenu.addAction("New",  this, SLOT(addContact()));
myMenu.addAction("Delete",  this, SLOT(Del()));
myMenu.exec(globalPos);
}

void Port::Del()
{
    delete this;
}

Port::~Port()
{
    delete ui;
}

void Port::addContact()
{
    Contact* conttact=new Contact();
    ui->ContactsList->addWidget(conttact);
}

void Port::mousePressEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = true;
        _mousePosition = e->pos();
    }
}

void Port::mouseMoveEvent( QMouseEvent *e )
{
    if ( _mousePressed ) {
        curentPosition=mapToParent( e->pos() - _mousePosition );
        move( curentPosition);
    }
}

void Port::mouseReleaseEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = false;
        _mousePosition = QPoint();
    }
}

