#include "studentmanage.h"
#include "ui_studentmanage.h"

//学籍管理类的构造函数
StudentManage::StudentManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentManage)
{
    ui->setupUi(this);

    m_studentIndex = CHOICE_DEPARTMENT;

    ui->tableWidget->setColumnCount(9);

    QStringList headers;
    headers << "账号" << "姓名" << "密码" << "出生日期" << "性别"
            << "身份证号" << "班级号" << "系代号" << "联系方式";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

}

//学籍管理类的析构函数
StudentManage::~StudentManage()
{
    delete ui;
}

///查看全部学生
void StudentManage::on_pb_all_clicked()
{
    QString mess = "selectAllStudent";
    qDebug() << mess;

   m_sendDataPacket.clearDataPackect();
   NormalProtocol normalProtocol(CLIENT_NONE,
                                 OperType_Student, CmdStudent_AskStuInfo,
                                 DataType_Text, mess.toUtf8());

   m_sendDataPacket.updatePacketData(PacketType_Normal,&normalProtocol);
   QByteArray buffer = m_sendDataPacket.packetData();
   qDebug() << "Send: " << buffer.toHex();
   emit signalSelectStuAll(buffer);
}

///按要求查看学生
void StudentManage::on_pb_select_clicked()
{

}

///选择要求
void StudentManage::on_cb_choice_activated(int index)
{

}


///槽-全部的学生信息
void StudentManage::slotSelectStuAll(StudentList list)
{
    qDebug() <<"StudentManage::slotSelectStuAll";
    StudentList stuList;
    stuList = list;
    ui->tableWidget->setRowCount(stuList.count());


    for(int i=0; i < stuList.count(); i++)
    {

         QTableWidgetItem *item = new QTableWidgetItem(stuList.at(i).getID());
         ui->tableWidget->setItem(i, 0, item);

         item = new QTableWidgetItem(stuList.at(i).getName());
         ui->tableWidget->setItem(i, 1, item);
         item = new QTableWidgetItem(stuList.at(i).getPassword());
         ui->tableWidget->setItem(i, 2, item);
         item = new QTableWidgetItem(stuList.at(i).getBirth());
         ui->tableWidget->setItem(i,3,item);
         item = new QTableWidgetItem(stuList.at(i).getSex());
         ui->tableWidget->setItem(i,4,item);
         item = new QTableWidgetItem(stuList.at(i).getIdCard());
         ui->tableWidget->setItem(i,5,item);
         item = new QTableWidgetItem(stuList.at(i).getClassID());
         ui->tableWidget->setItem(i,6,item);
         item = new QTableWidgetItem(stuList.at(i).getDepartID());
         ui->tableWidget->setItem(i,7,item);
         item = new QTableWidgetItem(stuList.at(i).getPhone());
         ui->tableWidget->setItem(i,8,item);


     }
          ui->le_num->setText(QString::number(stuList.count()));
}

void StudentManage::on_pb_allStudent_clicked()
{
    qDebug() << "全部学生";
    QString mess = "selectAllStudent";
    qDebug() << mess;

   m_sendDataPacket.clearDataPackect();
   NormalProtocol normalProtocol(CLIENT_NONE,
                                 OperType_Student, CmdStudent_AskStuInfo,
                                 DataType_Text, mess.toUtf8());

   m_sendDataPacket.updatePacketData(PacketType_Normal,&normalProtocol);
   QByteArray buffer = m_sendDataPacket.packetData();
   qDebug() << "Send: " << buffer.toHex();
   emit signalSelectStuAll(buffer);
}
