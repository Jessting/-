#include "user.h"

#include <QDebug>

User::User()//用户类构造函数
{
    clearUserInfo();
}

///用户类带参数的构造函数
User::User(QString ID,QString name,QString password,QString kind)
{
    m_id = ID;
    m_name = name;
    m_password = password;
    m_kind = kind;
}

///传入用户指针，更新用户信息
void User::updataUserinfo(User *info)
{
    m_id = info->getID();
    m_name = info->getName();
    m_password = info->getPassword();
    m_kind = info->getKind();
}

///传入用户指针，更新用户信息
void User::updataUserinfo(const QString &ID,const QString &name,
                          const QString &password,const QString &kind)
{
    m_id = ID;
    m_name = name;
    m_password = password;
    m_kind = kind;
}

///清除用户信息
void User::clearUserInfo(void)
{
    m_id.clear();
    m_name.clear();
    m_password.clear();
    m_kind.clear();
}

///打印用户信息
void User::printInfos(void) const
{
    qDebug() << m_id;
    qDebug() << m_name;
    qDebug() << m_password;
    qDebug() << m_kind;
}

///打包用户信息，返回字符类型
QString User::packageinfos(void)
{

    QString data;
    data.clear();

    data.append(getID());
    data.append("|");
    data.append(getName());
    data.append("|");
    data.append(getPassword());
    data.append("|");
    data.append(getKind());

    return data;
}

///传入ID，赋值数据成员
void User::setID(QString id)
{
    m_id = id;
}

///传入name，赋值数据成员
void User::setName(QString name)
{
    m_name = name;
}

///传入password，赋值数据成员
void User::setPassword(QString password)
{
    m_password = password;
}

///传入用户身份类型，赋值数据
void User::setKind(QString kind)
{
    m_kind = kind;
}

///传出数据，返回ID
QString User::getID(void) const
{
    return m_id;
}

///传出数据，返回name
QString User::getName(void) const
{
    return m_name;
}

///传出数据，返回password
QString User::getPassword(void) const
{
    return m_password;
}

///传出数据，返回用户身份类型
QString User::getKind(void) const
{
    return m_kind;
}

///虚函数，打印数据，用于测试
void User::display(void) const //注意:虚函数的写法，与声明处不同
{
    qDebug() << m_id << " " << m_name << " " << m_password << " " << m_kind;
}
