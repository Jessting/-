#ifndef ADMINMAINW_H
#define ADMINMAINW_H

#include <QMainWindow>

#include "info.h"
#include "datapacket.h" //数据包的头文件
#include "normalprotocol.h" //正常协议类的头文件

#include "studentmanage.h"

namespace Ui {
class AdminMainW;
}

class AdminMainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainW(QWidget *parent = 0);
    ~AdminMainW();

    enum USERCHOICE{
        USER_ALL,
        USER_ADMIN,
        USER_TEACHER,
        USER_STUDENT,
    };

signals:

    void signalSelectStuAll(QByteArray buffer);
    void signalUserSelect(QByteArray buffer); //信号-查询用户信息

    void signalSelectStuAll(StudentList list);  //信号-获取所有的学生信息


public slots:
    void slotAdminID(QString id);
    void slotSelectUserInfos(UserList list);


private slots:

    void on_pb_reflash_clicked();

    void on_cb_choose_activated(int index);

    void on_pb_selectUser_clicked();

private:
    Ui::AdminMainW *ui;

    DataPacket m_sendDataPacket;   //对象-接受数据包
    int m_userIndex;

    StudentManage *m_stuManage;
};

#endif // ADMINMAINW_H
