#ifndef WAITROOM_H
#define WAITROOM_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QWebSocket>
#include <QLabel>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>

class WaitRoom : public QDialog
{
    Q_OBJECT
public:
    WaitRoom(QString filename, QJsonObject room, QWebSocket *socket, QWidget *parent = nullptr);
private slots:
    void processBinaryMessage(QByteArray message);
    void onFinished(int);
    void sendChat();
    void startGame();
private:
    QWebSocket *webSocket = nullptr;
    QLabel *pName[4];
    QPlainTextEdit *chatWindow;
    QLineEdit *chatEdit;
    QString player_name;
    int player_number;
    QString file_name;
    int room_port;
    QPushButton *startGameButton;
};

#endif // WAITROOM_H