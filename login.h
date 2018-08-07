#ifndef Login_H
#define Login_H

#include <QWidget>
#include "userinfo.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

signals:
    void signalLoginSuccess(UserInfo info); //信号-登陆成功

public:
    explicit Login(QWidget *parent = 0);    //构造函数
    ~Login();   //析构函数

private slots:
    void on_pb_enter_clicked();     //槽-点击进入
    void on_pb_cancle_clicked();    //槽-点击取消

private:
    Ui::Login *ui;
};

#endif // Login_H
