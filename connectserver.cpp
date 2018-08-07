#include "connectserver.h"

#include <QTcpSocket>
#include <QDebug>

#include "logic.h" //逻辑层头文件

QueueNormalProtocol ConnectServer::q_queueNormalProtocol;

ConnectServer::ConnectServer(QObject *parent) :
    QThread(parent) //构造函数
{
      m_isThread = false;
      m_execNormalProtocol = new ExecNormalProtocol;
      m_socket = new QTcpSocket(this);

      connect(m_socket,SIGNAL(readyRead()),
              this,SLOT(slotReadyRead()));

      connect(m_execNormalProtocol,SIGNAL(signalUserLoginSuccess(User)),
              this,SIGNAL(signalUserLoginSuccess(User)));
      connect(m_execNormalProtocol,SIGNAL(signalSelectUserInfos(UserList)),
              this,SIGNAL(signalSelectUserInfos(UserList)));
      connect(m_execNormalProtocol,SIGNAL(signalSelectStuAll(StudentList)),
              this,SIGNAL(signalSelectStuAll(StudentList)));


      m_socket->connectToHost("localhost", 55555);
}

///析构函数
ConnectServer::~ConnectServer()
{
    if(m_socket != NULL)
    {
        delete m_socket;
        m_socket = NULL;
    }
}

///关闭线程
void ConnectServer::closeThreads(void)
{
    m_isThread = true;
    this->exit();
}

///run
void ConnectServer::run()
{
    while(!m_isThread)
    {
        if(!q_queueNormalProtocol.isEmpty())
        {
            m_normalProtocol.clearProtocolData();
            m_normalProtocol = q_queueNormalProtocol.dequeue();
            m_normalProtocol.displayProtocol();
            m_execNormalProtocol->execOperateCmd(m_normalProtocol);
        }
        msleep(20);
    }
}

///槽-传入id和password，连接服务器
void ConnectServer::slotConnectServer(QByteArray buffer)
{
//    QString mess = id + "|" + password;
//    m_sendDataPacket.clearDataPackect();
//    NormalProtocol normalProtocol(CLIENT_NONE,
//                                  OperType_Login, CmdLogin_LoginAsk,
//                                  DataType_Text, mess.toLatin1());

//    m_sendDataPacket.updatePacketData(PacketType_Normal,&normalProtocol);
//    QByteArray buffer = m_sendDataPacket.packetData();
//    qDebug() << "Send: " << buffer.toHex();
    m_socket->write(buffer);
}

///槽-准备读
void ConnectServer::slotReadyRead()
{
    qDebug() << "ConnectServer::slotReadyRead";

    m_recvDataPacket.clearDataPackect();
    m_recvDataPacket.unPacketData(m_socket);

}

