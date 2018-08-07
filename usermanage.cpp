#include "usermanage.h"
#include "ui_usermanage.h"

UserManage::UserManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManage)
{
    ui->setupUi(this);

    m_userChoiceIndex = CHOICE_ALL;

//    ui->tableWidget->setColumnCount(4);

//    QStringList headers;
//    headers << "账号" << "姓名" << "密码" << "身份类型";
//    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

UserManage::~UserManage()
{
    delete ui;
}

void UserManage::on_pb_reflash_clicked()
{

}

void UserManage::on_pb_select_clicked()
{

}

void UserManage::on_cb_choice_activated(int index)
{

}
