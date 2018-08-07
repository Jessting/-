#ifndef TEACHER_H
#define TEACHER_H

#include "student.h"

class Teacher : public Student
{
public:
    Teacher();//教师类构造函数
    //带参数构造函数
    Teacher(QString ID,QString name,QString password,QString kind,
            QString birth,QString sex,QString idCard,QString classID,
            QString departID,QString phone, QString title,QString salary);
    void display(void) const;//继承学生类的打印函数

    void setTitle(QString birth);//传入职称，赋值数据成员
    void setSalary(QString sex);//传入工资，赋值数据成员

    QString getTitle(void) const;//传出数据，返回教师职称
    QString getSalary(void) const;//传出数据，返回教师工资

private:
    QString m_title;
    QString m_salary;

};

typedef QList<Teacher> TeacherList;//定义教师列表

#endif // TEACHER_H
