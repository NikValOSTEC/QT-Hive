#include "contact.h"
#include "ui_contact.h"

Contact::Contact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contact)
{
    ui->setupUi(this);
    ui->lineEdit_contact_name->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->lineEdit_contact_name, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
}




void Contact::showContextMenu(const QPoint &pos){
        // Handle global position
        QPoint globalPos = ui->lineEdit_contact_name->mapToGlobal(pos);

        // Create menu and insert some actions
        QMenu myMenu;
        myMenu.addAction("Delete", this, SLOT(Del()));


        // Show context menu at handling position
        myMenu.exec(globalPos);
}

void Contact::Del()
{
    delete this;
}

void Contact::Plus()
{

}

Contact::~Contact()
{
    delete ui;
}
