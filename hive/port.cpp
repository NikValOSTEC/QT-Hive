#include "port.h"
#include "ui_port.h"

Port::Port(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Port),
    _mousePressed(false),
    _mousePosition(QPoint())
{
    ui->setupUi(this);
    setWindowFlags( Qt::FramelessWindowHint);
    ui->ScrollArea->widget()->layout()->setAlignment(Qt::AlignmentFlag::AlignTop);
    ui->ScrollArea->widget()->layout()->setContentsMargins(0,0,0,0);
}

Port::~Port()
{
    delete ui;
}

void Port::on_pushButton_clicked()
{
    Contact* conttact=new Contact();
    ui->ScrollArea->widget()->layout()->addWidget(conttact);
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
        move( mapToParent( e->pos() - _mousePosition ) );
    }
}

void Port::mouseReleaseEvent( QMouseEvent *e )
{
    if ( e->button() == Qt::LeftButton ) {
        _mousePressed = false;
        _mousePosition = QPoint();
    }
}
