#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>
#include <QWebSocketServer>

class WebServer : public QWebSocketServer
{
    Q_OBJECT
public:
    explicit WebServer(QObject *parent = nullptr);

signals:
void receiveMessage(QString);

private slots:
void onNewConnection();
void onMessageReceived(const QString &message);

private:
QWebSocket *mWebSocket;
};

#endif // WEBSERVER_H
