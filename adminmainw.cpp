#include "adminmainw.h"
#include "ui_adminmainw.h"

#include <QByteArray>

//管理员主界面类的构造函数
AdminMainW::AdminMainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainW)
{
    ui->setupUi(this);

    m_userIndex = USER_ALL;

    m_stuManage = new StudentManage;

    ui->tableWidget->setColumnCount(4);

    QStringList headers;
    headers << "账号" << "姓名" << "密码" << "身份类型";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),
            ui->stackedWidget,SLOT(setCurrentIndex(int)));

    connect(m_stuManage,SIGNAL(signalSelectStuAll(QByteArray)),
            this,SIGNAL(signalSelectStuAll(QByteArray)));
    connect(this,SIGNAL(signalSelectStuAll(StudentList)),
            m_stuManage,SLOT(slotSelectStuAll(StudentList)));
}

//管理员主界面类的析构函数
AdminMainW::~AdminMainW()
{
    delete ui;
    delete m_stuManage;
}

///槽-显示管理员账号
void AdminMainW::slotAdminID(QString id)
{
    ui->le_adminID->setText(id);
}

///点击刷新
void AdminMainW::on_pb_reflash_clicked()
{

}


///槽-用户信息
void AdminMainW::slotSelectUserInfos(UserList list)
{
    qDebug() <<"AdminMainW::slotSelectUserInfos";
    UserList userList;
    userList = list;
    ui->tableWidget->setRowCount(userList.count());

     qDebug() <<"AdminMainW::userList.count(" << userList.count();

    for(int i=0; i < userList.count(); i++)
    {

         QTableWidgetItem *item = new QTableWidgetItem(userList.at(i).getID());
         ui->tableWidget->setItem(i, 0, item);

         item = new QTableWidgetItem(userList.at(i).getName());
         ui->tableWidget->setItem(i, 1, item);
         item = new QTableWidgetItem(userList.at(i).getPassword());
         ui->tableWidget->setItem(i, 2, item);
         item = new QTableWidgetItem(userList.at(i).getKind());
         ui->tableWidget->setItem(i,3,item);

     }
          ui->le_num->setText(QString::number(userList.count()));
}


///选择查询类型
void AdminMainW::on_cb_choose_activated(int index)
{
    qDebug() << "选择所有人！";
    m_userIndex = index;
}

///点击查询
void AdminMainW::on_pb_selectUser_clicked()
{
    qDebug() << "点击";

    QString mess;

    if(m_userIndex == USER_ALL)
    {
         mess = "selectAllUser";
    }
    if(m_userIndex == USER_ADMIN)
    {
        mess = "selectAdmin";
    }
    if(m_userIndex == USER_TEACHER)
    {
        mess = "selectTeacher";
    }
    if(m_userIndex == USER_STUDENT)
    {
        mess = "selectStudent";
    }
    qDebug() << mess;

   m_sendDataPacket.clearDataPackect();
   NormalProtocol normalProtocol(CLIENT_NONE,
                                 OperType_User, CmdUser_SelectUser,
                                 DataType_Text, mess.toUtf8());

   m_sendDataPacket.updatePacketData(PacketType_Normal,&normalProtocol);
   QByteArray buffer = m_sendDataPacket.packetData();
   qDebug() << "Send: " << buffer.toHex();

   emit signalUserSelect(buffer);

   qDebug() << "执行到这吗？";
}
