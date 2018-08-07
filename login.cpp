#include "login.h"
#include "ui_login.h"

#include <QDebug>
#include <QMessageBox>

#include "sqlanalysis.h"
#include "userinfo.h"


//构造函数
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

//析构函数
Login::~Login()
{
    delete ui;
}

///槽-点击进入
void Login::on_pb_enter_clicked()
{
    UserInfo info = SQLAnalysis::selectUserInfo(ui->le_id->text());
    if(info.getPassword() == ui->le_pswd->text())
    {
        emit signalLoginSuccess(info);
        this->hide();
    }else
    {
        QMessageBox msgBox;
        msgBox.setText("ERROR: Your uid or password!!");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Retry);

        int ret = msgBox.exec();
        switch (ret) {
          case QMessageBox::Retry:
              ui->le_id->setFocus();
              msgBox.close();
              break;
          case QMessageBox::Cancel:
              ui->le_id->setFocus();
              break;
          default:
              // should never be reached
              break;
        }
    }
}

///槽-点击取消
void Login::on_pb_cancle_clicked()
{
    this->close();
}
