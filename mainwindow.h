#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userinfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);   //构造函数
    ~MainWindow();      //析构函数

    void addOnlineUser(UserInfo info);  //添加在线用户

public slots:
    void slotLoginSuccess(UserInfo info);   //槽-登陆成功

private:
    Ui::MainWindow *ui;

    quint64 m_onlineIndex; //整型，在线用户索引
};

#endif // MAINWINDOW_H
