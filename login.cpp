#include "login.h"
#include "ui_login.h"

//构造函数
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

//析构函数
login::~login()
{
    delete ui;
}

///点击登陆键
void login::on_pb_login_clicked()
{
    emit signalConnectServer(ui->le_id->text(),ui->le_password->text());
}

///点击退出键
void login::on_pb_quit_clicked()
{
    this->close();
}

///关闭事件
void login::closeEvent(QCloseEvent *ev)
{
    emit signalCloseProject();
    ev->accept();
}
