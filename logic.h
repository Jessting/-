#ifndef LOGIC_H
#define LOGIC_H

#include <QWidget>

#include "connectserver.h"
#include "login.h"
#include "studentmainw.h"
#include "adminmainw.h"
#include "teachermainw.h"

class Login;

namespace Ui {
class logic;
}

class logic :  public QObject
{
    Q_OBJECT

public:
    explicit logic(QObject *parent = 0);
    ~logic();

    void showLoginW(void);

signals:
    void signalStudentID(QString id);
    void signalAdminID(QString id);
    void signalTeacherID(QString id);



public slots:
    void slotUserLoginSuccess(User info);
    void slotCloseProject(void);

private:
    Login         *m_login;
    StudentMainW  *m_stuMainW;
    AdminMainW    *m_adminMainW;
    TeacherMainW  *m_teacherW;

    ConnectServer *m_connectServer;
};

#endif // LOGIC_H
