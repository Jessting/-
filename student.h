#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class Student : public User
{
public:
    Student();//学生类构造函数
    //带参数构造函数
    Student(QString ID,QString name,QString password,QString kind,
            QString birth,QString sex,QString idCard,QString classID,
            QString departID,QString phone);
    void display(void) const;//继承用户类的打印函数

    void updataStudentinfo(Student *info);    //传入指针对象，更新用户信息
    //传入引用，更新用户信息
    void updataStudentinfo(QString birth, QString sex, QString idCard, QString classID,
                           QString departID, QString phone);

    void clearStudentInfo(void);

    virtual void printInfos(void) const;
    virtual QString packageinfos(void);

    void setBirth(QString birth);//传入出生日期，赋值数据成员
    void setSex(QString sex);//传入性别，赋值数据成员
    void setIdCard(QString idCard);//传入身份证号，赋值数据成员
    void setClassID(QString classID);//传入班级号，赋值数据成员
    void setDepartID(QString departID);//传入系别编号，赋值数据成员
    void setPhone(QString phone);//传入手机号，赋值数据成员

    QString getBirth(void) const;//传出数据，返回学生出生日期
    QString getSex(void) const;//传出数据，返回学生性别
    QString getIdCard(void) const;//传出数据，返回学生身份证号
    QString getClassID(void) const;//传出数据，返回学生班级号
    QString getDepartID(void) const;//传出数据，返回学生系别代号
    QString getPhone(void) const;//传出数据，返回学生手机号

private:
    QString m_birth;
    QString m_sex;
    QString m_idCard;
    QString m_classID;
    QString m_departID;
    QString m_phone;
};

typedef QList<Student> StudentList;

#endif // STUDENT_H
