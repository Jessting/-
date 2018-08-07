#ifndef SQLANALYZE_H
#define SQLANALYZE_H

#include "info.h"
#include <QString>

class SQLAnalyze
{
public:
    SQLAnalyze();//构造函数

    static DBAdmin selectDBAdminInfo(QString id);

    static User selectUserInfo(QString id);//按id查询用户信息
    static UserList selectUserInfos(void);//导出所有的用户信息
    static UserList selectUserInfosAS(QString type);//导出按要求的所有用户信息

    static StudentList selectStudentInfos(void);//导出所有的学生信息
    static Student selectStudentInfo(QString id);//查询学生信息，返回学生
    static StudentList selectStudentInfos(QString name);//按姓名查询学生信息，返回学生列表
    static StudentList selectStudentInfosAsDept(QString deptID);//按系名查询学生信息，返回学生列表

    static QStringList selectDeptNames(void);//查询所有的系名

    static bool insertStudentInfo(Student student);//插入学生信息
    static bool updateStudentInfo(Student student);//修改学生信息

    static Student firstStudentInfo(void);//返回到第一条学生信息
    static Student lastStudentInfo(void);//返回到最后一条学生信息
    static Student nextStudentInfo(void);//返回到下一条学生信息
    static Student previousStudentInfo(void);//返回到上一条学生信息

    static TeacherList selectTeacherInfos(void);//导出所有的教师信息
    static Teacher selectTeacherInfo(QString id);//查询教师信息，返回单个教师
    static TeacherList selectTeacherInfos(QString name);//按姓名查询教师信息，返回教师列表
    static TeacherList selectTeacherInfosAsDept(QString dept);//按系名查询教师信息，返回教师列表
};

#endif // SQLANALYZE_H
