#include "webserver.h"
#include <QWebSocket>

WebServer::WebServer(QObject *parent) :
    QWebSocketServer("MiServidor", QWebSocketServer::NonSecureMode, parent)
{
    mWebSocket = NULL;
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}


void WebServer::onNewConnection()
{
    mWebSocket = nextPendingConnection();
    connect (mWebSocket, SIGNAL(textMessageReceived(QString)), this ,
    SLOT (onMessageReceived(QString)));

}


void WebServer::onMessageReceived(const QString &message)
{
    emit receiveMessage(message);
}
