#include "student.h"

#include <QDebug>

Student::Student()//学生类构造函数
{
    m_birth.clear();
    m_sex.clear();
    m_idCard.clear();
    m_classID.clear();
    m_departID.clear();
    m_phone.clear();
}

///带参数构造函数
Student::Student(QString ID,QString name,QString password,QString kind,
        QString birth,QString sex,QString idCard,QString classID,
        QString departID,QString phone)
        : User(ID,name,password,kind)
{
    m_birth = birth;
    m_sex = sex;
    m_idCard = idCard;
    m_classID = classID;
    m_departID = departID;
    m_phone = phone;
}

///学生类的打印函数，测试学生信息
void Student::display(void) const
{
    qDebug() << getID() << " " << getName() << " "
             << getPassword() << " " << getKind();
    qDebug() << m_birth << " " << m_sex << " " << m_idCard << " "
             << m_classID << " " << m_departID << " " << m_phone;
}

///传入出生日期，赋值数据成员
void Student::setBirth(QString birth)
{
    m_birth = birth;
}

///传入性别，赋值数据成员
void Student::setSex(QString sex)
{
    m_sex = sex;
}

///传入身份证号，赋值数据成员
void Student::setIdCard(QString idCard)
{
    m_idCard = idCard;
}

///传入班级号，赋值数据成员
void Student::setClassID(QString classID)
{
    m_classID = classID;
}

///传入系别编号，赋值数据成员
void Student::setDepartID(QString departID)
{
    m_departID = departID;
}

///传入手机号，赋值数据成员
void Student::setPhone(QString phone)
{
    m_phone = phone;
}

///传出数据，返回学生出生日期
QString Student::getBirth(void) const
{
    return m_birth;
}

///传出数据，返回学生性别
QString Student::getSex(void) const
{
    return m_sex;
}

///传出数据，返回学生身份证号
QString Student::getIdCard(void) const
{
    return m_idCard;
}

///传出数据，返回学生班级号
QString Student::getClassID(void) const
{
    return m_classID;
}

///传出数据，返回学生系别代号
QString Student::getDepartID(void) const
{
    return m_departID;
}

///传出数据，返回学生手机号
QString Student::getPhone(void) const
{
    return m_phone;
}

///传入指针对象，更新用户信息
void Student::updataStudentinfo(Student *info)
{
    updataUserinfo(info->getID(),info->getName(),info->getPassword(),info->getKind());
    m_birth = info->getBirth();
    m_sex = info->getSex();
    m_idCard = info->getIdCard();
    m_classID = info->getClassID();
    m_departID = info->getDepartID();
    m_phone = info->getPhone();
}

///传入引用，更新用户信息
void Student::updataStudentinfo(QString birth,QString sex,QString idCard,
                                QString classID,  QString departID,QString phone)
{
    m_birth = birth;
    m_sex = sex;
    m_idCard = idCard;
    m_classID = classID;
    m_departID = departID;
    m_phone = phone;
}

///清除学生信息
void Student::clearStudentInfo(void)
{
    m_birth.clear();
    m_sex.clear();
    m_idCard.clear();
    m_classID.clear();
    m_departID.clear();
    m_phone.clear();
}

///打印学生信息
void Student::printInfos(void) const
{
    qDebug() << "UserInfo-----------------------------------";
    qDebug() << "ID: " << getID();
    qDebug() << "name: " << getName();
    qDebug() << "password: " << getPassword();
    qDebug() << "kind " << getKind();
    qDebug() << "StudentInfo-----------------------------------";
    qDebug() << "birth: " << getBirth();
    qDebug() << "sex: " << getSex();
    qDebug() << "idCard: " << getIdCard();
    qDebug() << "classID: " << getClassID();
    qDebug() << "departID: " << getDepartID();
    qDebug() << "phone: " << getPhone();
    qDebug() << "===================================";
}

///打包信息
QString Student::packageinfos(void)
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
    data.append("|");

    data.append(getBirth());
    data.append("|");
    data.append(getSex());
    data.append("|");
    data.append(getIdCard());
    data.append("|");
    data.append(getClassID());
    data.append("|");
    data.append(getDepartID());
    data.append("|");
    data.append(getPhone());

    return data;
}
