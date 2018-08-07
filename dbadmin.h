#ifndef DBADMIN_H
#define DBADMIN_H

#include <QString>

class DBAdmin
{
public:
    DBAdmin(); //数据库管理员类的构造函数

    DBAdmin(QString ID,QString password);//带参数构造函数

    void setID(QString id);//传入ID，赋值数据成员
    void setPassword(QString password);//传入password，赋值数据成员

    QString getID(void) const;//传出数据，返回ID
    QString getPassword(void) const;//传出数据，返回password

private:
    QString m_id;
    QString m_password;
};

#endif // DBADMIN_H
