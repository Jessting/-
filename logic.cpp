#include "logic.h"

#include "login.h"
#include "mainwindow.h"
#include "user.h"
#include "listenclient.h"

Logic::Logic(QObject *parent) :
    QObject(parent)

{
     m_tcpServer = new ListenClient();
     m_mainw = new MainWindow();
     m_login = new Login();

    connect(m_login, SIGNAL(signalLoginSuccess(DBAdmin)),
            m_mainw, SLOT(slotLoginSuccess(DBAdmin)));

    connect(m_tcpServer, SIGNAL(signalUserLoginSuccess(User)),
            this, SLOT(slotUserLoginSuccess(User)));
}

Logic::~Logic()
{
    delete m_tcpServer;
    delete m_login;
    delete m_mainw;
}

void Logic::showLoginW(void)
{
    m_login->show();
}

///槽-用户登陆成功
void Logic::slotUserLoginSuccess(User info)
{
    m_mainw->addOnlineUser(info);
}
