#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>
#include <QNetworkInterface>

#include "userinfo.h"

//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_onlineIndex = 0;

    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setColumnCount(3);

    QStringList headers;
    headers << "UID" << "Name" << "Time";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}

///添加在线用户
void MainWindow::addOnlineUser(UserInfo info)
{
    QTableWidgetItem *item = new QTableWidgetItem(info.getUID());
    ui->tableWidget->setItem(m_onlineIndex, 0, item);
    item = new QTableWidgetItem(info.getName());
    ui->tableWidget->setItem(m_onlineIndex, 1, item);
    item = new QTableWidgetItem(info.getTime());
    ui->tableWidget->setItem(m_onlineIndex++, 2, item);
}

///槽-登陆成功
void MainWindow::slotLoginSuccess(UserInfo info)
{
    ui->le_name->setText(info.getName());
    ui->le_pswd->setText(info.getPassword());

    QStringList ipv4;
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list)
    {
       if(address.protocol() == QAbstractSocket::IPv4Protocol)
       //使用IPv4地址
       ipv4.append(address.toString());
    }

    ui->le_ipAddr->setText(ipv4.at(1));
    this->show();
}
