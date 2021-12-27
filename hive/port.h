#ifndef PORT_H
#define PORT_H

#include <QWidget>
#include <QLineEdit>>
#include<QLayout>>
#include "contact.h"
#include <QMouseEvent>

namespace Ui {
class Port;
}

class Port : public QWidget
{
    Q_OBJECT

public:
    explicit Port(QWidget *parent);
    ~Port();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Port *ui;

protected:
    virtual void mousePressEvent( QMouseEvent *e );
    virtual void mouseMoveEvent( QMouseEvent *e );
    virtual void mouseReleaseEvent( QMouseEvent *e );

private:
    bool _mousePressed;
    QPoint _mousePosition;
};

#endif // PORT_H
