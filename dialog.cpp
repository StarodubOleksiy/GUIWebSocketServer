#include "dialog.h"
#include "ui_dialog.h"
#include "webserver.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mWebServer = new WebServer(this);
    mWebServer->listen(QHostAddress::Any, 1234);
    connect (mWebServer, SIGNAL(receiveMessage(QString)), this,
        SLOT(sendMessage(QString)));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::sendMessage(const QString &message)
{
   ui->listWidget->addItem(message);

}
