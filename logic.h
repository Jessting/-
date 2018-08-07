#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include "info.h"

class Login;
class MainWindow;
class ListenClient;

namespace Ui {
class Logic;
}

class Logic : public QObject
{
    Q_OBJECT

public:
    explicit Logic(QObject *parent = 0);
    ~Logic();

    void showLoginW(void);

public slots:
    void slotUserLoginSuccess(User info);

private:

    Login *m_login;
    MainWindow *m_mainw;
    ListenClient *m_tcpServer;
};

#endif // LOGIC_H
