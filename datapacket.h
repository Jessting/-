#ifndef DATAPACKET_H
#define DATAPACKET_H

#include <QByteArray>
#include <QTcpSocket>

#define PACKET_SIZE_INIT 0      //宏定义-数据包长度初始化为0
#define PROTOCOL_PTR_INIT NULL  //宏定义-协议初始化是空
//#define FLAG_START   "@$@"
//#define FLAG_END     "@$@"

#define FLAG_START     0XAAAA
#define FLAG_END     0XBBBB

/*
消息类型		          编号
错误消息	TypeError	    E	详情见‘错误信息协议’
正常消息	TypeNormal	    N	详情见‘正常协议’
*/
enum PACKET_TYPE{
    PacketType_Error = 'E',//注意：枚举类型换行用","，不是";"
    PacketType_Normal = 'N'
};

class AbstructProtocol;//抽象协议类的前置声明（下面的类会用到这个类）

class DataPacket
{
public:
    DataPacket();  //构造函数
    ~DataPacket(); //析构函数

    QByteArray packetData(void); //打包数据，返回字节数组
    void unPacketData(QTcpSocket *socket); //传入socket指针，解包数据

    void clearDataPackect(void);//清除数据包
    void updatePacketData(quint8 packetType, AbstructProtocol *protocol);//更新数据库
    quint16 getPacketStart(void) const;//得到包的起始位
    quint16 getPacketType(void) const;//得到包的类型
    quint16 getPacketSize(void) const;//得到包的大小
    AbstructProtocol *getProtocol(void) const;//得到包的协议
    quint16 getPacketEnd(void) const;//得到包的结束位

private:

    quint16         m_startFlag;
    quint16            m_packetType;
    quint16           m_packetSize;
    AbstructProtocol *m_protocol;
    //QString           m_endFlag;
    quint16         m_endFlag;

};

#endif // DATAPACKET_H
