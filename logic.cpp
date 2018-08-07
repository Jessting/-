#include "logic.h"


#include "connectserver.h"
#include "login.h"
#include "adminmainw.h"

#include <QDebug>

//构造函数
logic::logic(QObject *parent) :
     QObject(parent)
{
    m_login = new Login;
    m_stuMainW = new StudentMainW;
    m_adminMainW = new AdminMainW;
    m_teacherW = new TeacherMainW;

    m_connectServer = new ConnectServer;

    connect(m_login,SIGNAL(signalCloseProject()),
            this,SLOT(slotCloseProject()));
//    connect(m_login,SIGNAL(signalConnectServer(QString,QString)),
//            m_connectServer,SLOT(slotConnectServer(QString,QString)));

    connect(m_login,SIGNAL(signalConnectServer(QByteArray)),
            m_connectServer,SLOT(slotConnectServer(QByteArray)));

    connect(m_adminMainW,SIGNAL(signalUserSelect(QByteArray)),
            m_connectServer,SLOT(slotConnectServer(QByteArray)));

    connect(m_connectServer,SIGNAL(signalUserLoginSuccess(User)),
            this,SLOT(slotUserLoginSuccess(User)));
    connect(m_connectServer,SIGNAL(signalSelectUserInfos(UserList)),
            m_adminMainW,SLOT(slotSelectUserInfos(UserList)));
    connect(m_adminMainW,SIGNAL(signalSelectStuAll(QByteArray)),
            m_connectServer,SLOT(slotConnectServer(QByteArray)));


    connect(this,SIGNAL(signalStudentID(QString)),
            m_stuMainW,SLOT(slotStudentID(QString)));
    connect(this,SIGNAL(signalAdminID(QString)),
            m_adminMainW,SLOT(slotAdminID(QString)));
    connect(this,SIGNAL(signalTeacherID(QString)),
            m_teacherW,SLOT(slotTeacherID(QString)));

    m_connectServer->start();//打开线程
    //通过调用run（）开始执行线程。
    //操作系统将根据优先级参数调度线程。
    //如果线程已经在运行，这个函数什么也不做。
}

//析构函数
logic::~logic()
{
    if(m_login != NULL)
    {
        delete m_login;
        m_login = NULL;
    }

    if(m_stuMainW != NULL)
    {
        delete m_stuMainW;
        m_stuMainW = NULL;
    }

    if(m_adminMainW!= NULL)
    {
        delete m_adminMainW;
        m_adminMainW= NULL;
    }

    if(m_teacherW != NULL)
    {
        delete m_teacherW;
        m_teacherW= NULL;
    }


    if(m_connectServer != NULL)
    {
        delete m_connectServer;
        m_connectServer = NULL;
    }
}

///显示登陆界面
void logic::showLoginW(void)
{
    m_login->show();
}

///关闭线程
void logic::slotCloseProject()
{
    m_connectServer->closeThreads();
}

///槽-用户登录成功显示学生主界面
void logic::slotUserLoginSuccess(User info)
{
    m_login->hide();

    if(info.getKind() == "student")
    {
        m_stuMainW->show();
        emit signalStudentID(info.getID());
    }

    if(info.getKind() == "admin")
        {
        m_adminMainW->show();
        emit signalAdminID(info.getID());
    }

    if(info.getKind() == "teacher")
        {
        m_teacherW->show();
        emit signalTeacherID(info.getID());
    }
}

