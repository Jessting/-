#include "normalprotocol.h"

#include <QDebug>
#include <QDataStream>
#include "connectclient.h"

//正常协议带参数的构造函数
NormalProtocol::NormalProtocol(quint32 client ,quint8 operType ,
               quint8 operCmd ,quint8 dataType ,QByteArray dataCont)
{
    m_client = client;
    m_operType = operType;
    m_operCmd = operCmd;
    m_dataType = dataType;
    m_dataCont = dataCont;
}


NormalProtocol::~NormalProtocol()//正常协议的析构函数
{

}

///更新正常协议
void NormalProtocol::updateNormalProtocol(quint32 client ,
               quint8 operType , quint8 operCmd ,
               quint8 dataType, QByteArray dataCont)
{
    m_client = client;
    m_operType = operType;
    m_operCmd = operCmd;
    m_dataType = dataType;
    m_dataCont = dataCont;
}

///清除协议数据
void NormalProtocol::clearProtocolData()
{
    m_client = CLIENT_NONE;
    m_operType = OperType_None;
    m_operCmd = MSG_NONE_CMD;
    m_dataType = DataType_None;
    m_dataCont = QByteArray();
}

///打印协议
void NormalProtocol::displayProtocol() const
{
    qDebug() << "NormalProtocol::displayProtocol";
    qDebug() << " Client:" << m_client;
    qDebug() << "operType:"<< m_operType;
    qDebug() << "operCmd:" << m_operCmd;
    qDebug() << "dataType:"<< m_dataType;
    qDebug() << "dataCont:"<< m_dataCont;
    qDebug() << "===============================";
}

///打包协议，传出字节数组
const QByteArray NormalProtocol::packetProtocol () const
{
    QByteArray buffer;
    buffer.clear();

    //QDataStream::QDataStream(QByteArray * a, QIODevice::OpenMode mode)
    //构造一个在字节数组上操作的数据流，该模式描述了如何使用该设备。
    QDataStream out(&buffer,QIODevice::WriteOnly);
     //将数据序列化格式的版本号设置为v，即版本enum的值。
    out.setVersion(QDataStream::Qt_5_4);

    out << m_client;
    out << m_operType;
    out << m_operCmd;
    out << m_dataType;
    out << m_dataCont;

    return buffer;

}

///解包协议，传入字节流引用
void NormalProtocol::unPacketProcotol(QDataStream &in)
{
    in >> m_client;
    in >> m_operType;
    in >> m_operCmd;
    in >> m_dataType;
    in >> m_dataCont;

    ConnectClient::q_queueNormalProtocol.enqueue(*this);//加入队列
}
