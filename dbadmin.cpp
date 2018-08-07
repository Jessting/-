#include "dbadmin.h"

DBAdmin::DBAdmin()
{

}

///数据库管理员类带参数的构造函数
DBAdmin::DBAdmin(QString ID,QString password)
{
    m_id = ID;
    m_password = password;
}

///传入ID，赋值数据成员
void DBAdmin::setID(QString id)
{
    m_id = id;
}

///传入password，赋值数据成员
void DBAdmin::setPassword(QString password)
{
    m_password = password;
}

///传出数据，返回ID
QString DBAdmin::getID(void) const
{
    return m_id;
}

///传出数据，返回password
QString DBAdmin::getPassword(void) const
{
    return m_password;
}
