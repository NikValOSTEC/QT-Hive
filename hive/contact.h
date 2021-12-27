#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include<QAction>
#include<QMenu>
#include <QMessageBox>
namespace Ui {
class Contact;
}

class Contact : public QWidget
{
    Q_OBJECT

public:
    explicit Contact(QWidget *parent = nullptr);
    ~Contact();
public slots:
    void showContextMenu(const QPoint &pos);
    void Del();
    void Plus();

private:
    Ui::Contact *ui;
};

#endif // CONTACT_H
