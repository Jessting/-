#include "admin.h"

Admin::Admin()//构造函数
{

}

///用户类带参数的构造函数
Admin::Admin(QString ID,QString name,QString password)
{
    m_id = ID;
    m_name = name;
    m_password = password;
}

///传入ID，赋值数据成员
void Admin::setID(QString id)
{
    m_id = id;
}

///传入name，赋值数据成员
void Admin::setName(QString name)
{
    m_name = name;
}

///传入password，赋值数据成员
void Admin::setPassword(QString password)
{
    m_password = password;
}

///传出数据，返回ID
QString Admin::getID(void) const
{
    return m_id;
}

///传出数据，返回name
QString Admin::getName(void) const
{
    return m_name;
}

///传出数据，返回password
QString Admin::getPassword(void) const
{
    return m_password;
}
