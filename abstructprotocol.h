#ifndef ABSTRUCTPROTOCOL_H
#define ABSTRUCTPROTOCOL_H

#include <QByteArray>
#include <QString>

#define CLIENT_NONE 0
#define MSG_NONE_CMD 0

//枚举-数据类型定义
enum DATA_TYPE{
    DataType_None = 0X30, //注意：枚举用","换行
    DataType_Text,
    DataType_Image,
    DataType_AudIo,
    DataType_video

};

class AbstructProtocol
{
public:
    AbstructProtocol() {} //构造函数，////此时注意是空函数，不用";" 换行
    virtual ~AbstructProtocol() {} //析构函数////此时注意是空函数，不用";" 换行

    virtual void clearProtocolData() = 0; //纯虚函数（只能被继承，不能实例化）-清除协议数据
    virtual void displayProtocol() const = 0; //纯虚函数-打印协议
    virtual const QByteArray packetProtocol () const = 0; //纯虚函数-打包协议，传出字节数组
    virtual void unPacketProcotol(QDataStream &in) = 0; //纯虚函数-解包协议，传入字节流引用

    quint32 m_client; //客户端
};

#endif // ABSTRUCTPROTOCOL_H
