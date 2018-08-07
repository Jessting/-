#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H

#include <QWidget>

#include "info.h"
#include "datapacket.h" //数据包的头文件
#include "normalprotocol.h" //正常协议类的头文件

namespace Ui {
class StudentManage;
}

class StudentManage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentManage(QWidget *parent = 0);
    ~StudentManage();

    enum STUCHOICE{
        CHOICE_DEPARTMENT,
        CHOICE_CLASS,
        CHOICE_ID,
        CHOICE_NAME,
        CHOICE_SEX,
    };

signals:
    void signalSelectStuAll(QByteArray buffer);

public slots:
    void slotSelectStuAll(StudentList list);

private slots:
    void on_pb_all_clicked();

    void on_pb_select_clicked();

    void on_cb_choice_activated(int index);

    void on_pb_allStudent_clicked();

private:
    Ui::StudentManage *ui;

    DataPacket m_sendDataPacket;   //对象-接受数据包
    int m_studentIndex;
};

#endif // STUDENTMANAGE_H
