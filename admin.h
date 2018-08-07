#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

class Admin
{
public:
    Admin();//构造函数
    Admin(QString ID,QString name,QString password);//带参数构造函数

    void setID(QString id);//传入ID，赋值数据成员
    void setName(QString name);//传入name，赋值数据成员
    void setPassword(QString password);//传入password，赋值数据成员

    QString getID(void) const;//传出数据，返回ID
    QString getName(void) const;//传出数据，返回name
    QString getPassword(void) const;//传出数据，返回password

private:
    QString m_id;
    QString m_name;
    QString m_password;

typedef QList<Admin> AdminList;//自定义管理员列表

};

#endif // ADMIN_H
