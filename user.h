#ifndef USER_H
#define USER_H

#include <QString>
#include <QMetaType>//QMetaType类在元对象系统中管理命名类型。

class User
{
public:
    User();//构造函数
    User(const QString &ID,const QString &name,
         const QString &password,const QString &kind);//带参数构造函数

    void updataUserinfo(User *info);    //传入指针对象，更新用户信息
    //传入引用，更新用户信息
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

/*在使用Qt进行应用程序开发时，经常要自定义数据类型，
 * 而且在需要的时候还要把这些数据放到QVariant中去。
 * 因为QVariant是一个接受绝大部分类型的数据类型。
 * 为了达到这个目的，就必须使用Q_DECLARE_METATYPE。*/

Q_DECLARE_METATYPE(User)//自定义类型


typedef QList<User> UserList;//定义用户列表
Q_DECLARE_METATYPE(UserList)//自定义类型

#endif // USER_H
