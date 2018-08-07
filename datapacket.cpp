#include "datapacket.h"

#include <QDataStream>
#include <QByteArray>

#include "abstructprotocol.h"
#include "normalprotocol.h"

DataPacket::DataPacket()  //构造函数
{
    m_startFlag = FLAG_START;
    m_packetType = PacketType_Normal;
    m_packetSize = PACKET_SIZE_INIT;
    m_protocol = PROTOCOL_PTR_INIT;
    m_endFlag = FLAG_END;
}

DataPacket::~DataPacket()   //析构函数
{
    if(m_protocol != PROTOCOL_PTR_INIT)
    {
        delete m_protocol;
        m_protocol = PROTOCOL_PTR_INIT;
    }
}

///打包数据，返回字节数组
QByteArray DataPacket::packetData(void)
{
    QByteArray buffer;//QByteArray类提供了一个字节数组。
   // buffer.clear();

    QDataStream out(&buffer,QIODevice::WriteOnly);//QDataStream 处理字节流
    //QDataStream::QDataStream ( QByteArray a, int mode )
    //构造一个通过内置的QBuffer设备来操作一个字节数组a的数据流。
    //mode就是QIODevice::mode()，通常不是IO_ReadOnly就是IO_WriteOnly。

    out.setVersion(QDataStream::Qt_5_4);

    out << m_startFlag;
    //out << FLAG_START;
    out << (quint16)0;
    out << m_packetType;
    out << m_protocol->packetProtocol();
    out << m_endFlag;
    //out << FLAG_END;

    //m_packetSize = (quint16)(buffer.size() - sizeof(quint16));
    m_packetSize = (quint16)(buffer.size() - sizeof(quint16)-sizeof(quint16) );
    out.device()->seek(2);  //指回长度,seek函数是按字节进行计算的
    out << m_packetSize;

    qDebug() << "m_startFlag" << FLAG_START;
    qDebug() << "m_packetSize" << m_packetSize;
    qDebug() << "m_packetType" << m_packetType;
    qDebug() << "m_protocol" << m_protocol;
    qDebug() << "m_endFlag" << FLAG_END;


    return buffer;
}

///传入socket指针，解包数据
void DataPacket::unPacketData(QTcpSocket *socket)
{
    qDebug() << "DataPacket::unpacketData(QTcpSocket *socket)";
    QDataStream in(socket);//构造一个使用输入/输出设备d的数据流。
    in.setVersion(QDataStream::Qt_5_4);

    in >> m_startFlag;
    qDebug() <<"m_startFlag" << m_startFlag;

    if(m_startFlag != 0XAAAA)
    {
        return ;
    }else
    {

        if(m_packetSize == 0)
        {
            if(socket->bytesAvailable() < sizeof(quint16))
                return;

            in >> m_packetSize;
            qDebug() << "m_packetSize"<<  m_packetSize;
        }

        if(socket->bytesAvailable() < m_packetSize)
        {
            return;
        }

        in >> m_packetType;
        //qDebug() << "m_packetType"<< m_packetType;

        QByteArray unpacketData;
        in >> unpacketData;
        //qDebug() << "Recv: " << unpacketData.toHex();
        QDataStream unpacketDataStream(unpacketData);
        unpacketDataStream.setVersion(QDataStream::Qt_5_4);

        switch (m_packetType) {
        case PacketType_Error:

            break;
        case PacketType_Normal:
            m_protocol = new NormalProtocol;
            m_protocol->unPacketProcotol(unpacketDataStream);
            break;
        default:
            break;
        }

        in >> m_endFlag;
        qDebug() <<"m_endFlag"<< m_endFlag;
        if(m_endFlag == 0XBBBB)
            return;
    }

}

///清除数据包
void DataPacket::clearDataPackect(void)
{
    m_startFlag = FLAG_START;
    m_packetType = PacketType_Normal;
    m_packetSize = PACKET_SIZE_INIT;
    m_protocol = PROTOCOL_PTR_INIT;
    m_endFlag = FLAG_END;
}

///更新数据库
void DataPacket::updatePacketData(quint8 packetType, AbstructProtocol *protocol)
{
    m_packetType = packetType;
    m_protocol = protocol;
}

///得到包的起始位
quint16 DataPacket::getPacketStart(void) const
{
    return m_startFlag;
}

///得到包的类型
quint16 DataPacket::getPacketType(void) const
{
    return m_packetType;
}

///得到包的大小
quint16 DataPacket::getPacketSize(void) const
{
    return m_packetSize;
}

///得到包的协议
AbstructProtocol *DataPacket::getProtocol(void) const
{
    return m_protocol;
}

///得到包的结束位
quint16 DataPacket::getPacketEnd(void) const
{
    return m_endFlag;
}
