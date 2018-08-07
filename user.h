#ifndef USER_H
#define USER_H

#include <QString>
#include <QMetaType>

class User
{
public:
    User();//构造函数
    User(QString ID,QString name,QString password,QString kind);//带参数构造函数


    void updataUserinfo(User *info);
    void updataUserinfo(const QString &ID,const QString &name,
                        const QString &password,const QString &kind);

    void clearUserInfo(void);

    virtual void printInfos(void) const;
    virtual QString packageinfos(void);

    void setID(QString id);//传入ID，赋值数据成员
    void setName(QString name);//传入name，赋值数据成员
    void setPassword(QString password);//传入password，赋值数据成员
    void setKind(QString kind);//传入用户身份类型，赋值数据

    QString getID(void) const;//传出数据，返回ID
    QString getName(void) const;//传出数据，返回name
    QString getPassword(void) const;//传出数据，返回password
    QString getKind(void) const;//传出数据，返回用户身份类型

    virtual void display(void) const;//虚函数，打印数据，用于测试

private :
    QString m_id;
    QString m_name;
    QString m_password;
    QString m_kind;
};

typedef QList<User> UserList;//定义用户列表

Q_DECLARE_METATYPE(User)

Q_DECLARE_METATYPE(UserList)//自定义类型

#endif // USER_H
