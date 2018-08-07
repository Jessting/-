#include "teacher.h"

#include <QDebug>

Teacher::Teacher()//教师类的构造函数
{
    m_title.clear();
    m_salary.clear();
}

///教师类继承学生类，带参数的构造函数
Teacher::Teacher(QString ID,QString name,QString password,QString kind,
        QString birth,QString sex,QString idCard,QString classID,
        QString departID,QString phone, QString title,QString salary)
        :Student(ID,name,password,kind,birth,sex,idCard, classID,
                 departID,phone)
{
    m_title = title;
    m_salary = salary;
}

///教师类的打印函数，测试教师信息
void Teacher::display(void) const
{
    qDebug() << getID() << " " << getName() << " "
             << getPassword() << " " << getKind();
    qDebug() << getBirth() << " " << getSex() << " " << getIdCard()
             << " " << getClassID() << " " << getDepartID() << " " << getPhone();

    qDebug() << m_title << " " << m_salary ;
}

///传入职称，赋值数据成员
void Teacher::setTitle(QString title)
{
    m_title = title;
}

///传入工资，赋值数据成员
void Teacher::setSalary(QString salary)
{
    m_salary = salary;
}

///传出数据，返回教师职称
QString Teacher::getTitle(void) const
{
    return m_title;
}

///传出数据，返回教师工资
QString Teacher::getSalary(void) const
{
    return m_salary;
}


