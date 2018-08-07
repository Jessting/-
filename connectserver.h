#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <QThread>//线程头文件

#include "datapacket.h" //数据包的头文件
#include "normalprotocol.h" //正常协议类的头文件
#include "execnormalprotocol.h"  //执行正常协议类的头文件

class QTcpSocket;//QTcpSocket类的前置声明

class ConnectServer : public QThread //继承线程
{
    Q_OBJECT
public:
    explicit ConnectServer(QObject *parent = 0); //构造函数
    ~ConnectServer();   //析构函数

     static QueueNormalProtocol q_queueNormalProtocol;

    void closeThreads(void);//关闭线程

signals:
    void signalUserLoginSuccess(User info);   //信号-用户登陆成功
    void signalAskUserAll(QByteArray buffer); //信号-获取所有用户信息
    void signalUserSelect(QByteArray buffer);
    void signalSelectUserInfos(UserList list);//信号-查询用户列表
    void signalSelectStuAll(QByteArray buffer);
    void signalSelectStuAll(StudentList list);  //信号-获取所有的学生信息

public slots:
    void slotReadyRead();   //槽-接受信息有无的信号
    void slotConnectServer(QByteArray buffer);  //槽-连接服务器

//    void slotConnectServer(QString id,QString password);  //槽-连接服务器


protected:
    void run();

private:
    QTcpSocket *m_socket;   //对象-socket
    bool m_isThread;        //数据-线程

    DataPacket m_recvDataPacket;   //对象-接受数据包
   // DataPacket m_sendDataPacket;   //对象-发送数据包

    NormalProtocol m_normalProtocol; //对象-正常协议
    ExecNormalProtocol *m_execNormalProtocol; //对象-执行正常协议
};

#endif // CONNECTSERVER_H
