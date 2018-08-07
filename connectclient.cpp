#include "connectclient.h"

#include <QDebug>

QueueNormalProtocol ConnectClient::q_queueNormalProtocol;

//构造函数
ConnectClient::ConnectClient(QTcpSocket *nect, QObject *parent)
    :QThread(parent)
{
    m_isThread = false;
    m_execNormalProtocol = new ExecNormalProtocol(parent);
    m_socket = nect;

    connect(m_socket,SIGNAL(readyRead()),
            this,SLOT(slotReadyRead()));
    connect(m_execNormalProtocol,SIGNAL(signalSendDataToClient(QByteArray)),
            this,SLOT(slotSendDataToClient(QByteArray)));
    connect(m_execNormalProtocol,SIGNAL(signalUserLoginSuccess(User)),
            this,SIGNAL(signalUserLoginSuccess(User)));
}

//析构函数
ConnectClient::~ConnectClient()
{
    delete m_execNormalProtocol;
    delete m_socket;
}

///槽-读信号
void ConnectClient::slotReadyRead()
{
    qDebug() << "ConnectClient::slotReadyRead()";
    m_recvDataPacket.clearDataPackect();
    m_recvDataPacket.unPacketData(m_socket);

}

///槽-发送数据到客户端
void ConnectClient::slotSendDataToClient(QByteArray buffer)
{
      qDebug() << "void ConnectClient::slotSendDataToClient(QByteArray *buffer)";
      //qDebug() << "Send: " << buffer.toHex();
      m_socket->write(buffer);
}


void ConnectClient::run()
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

//        if(!q_queueErrorProtocol.isEmpty())
//        {
//            m_normalProtocol.clearProtocolData();
//            m_normalProtocol = g_queueNormalProtocol.dequeue();
//            m_normalProtocol.displayProtocol();
//            m_execNormalProtocol->execOperateCmd(m_normalProtocol);
//        }

        msleep(20);
    }
}

