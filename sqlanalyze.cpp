#include "sqlanalyze.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant> //QVariant类的作用类似于最常见的Qt数据类型的联合。
#include <QDebug>

SQLAnalyze::SQLAnalyze()
{

}

DBAdmin SQLAnalyze::selectDBAdminInfo(QString id)
{
    DBAdmin dbAdmin;
    QSqlQuery query;
    QString queryString =
            QString ("select * from dbAdmin where id = '%1' ").arg(id);

    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int pswd_idx = query.record().indexOf("password");

        while(query.next())
        {
             QString id = query.value(id_idx).toString();
             QString password = query.value(pswd_idx).toString();

             dbAdmin.setID(id);
             dbAdmin.setPassword(password);
        }
    }
    return dbAdmin;
}

///按id查询用户信息，返回单个用户
User SQLAnalyze::selectUserInfo(QString id)
{
    User user;
    QSqlQuery query;
    QString queryString =
            QString ("select * from user where id = '%1' ").arg(id);

    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int pswd_idx = query.record().indexOf("password");
        int kind_idx = query.record().indexOf("kind");
        while(query.next())
        {
             QString id = query.value(id_idx).toString();
             QString name = query.value(name_idx).toString();
             QString password = query.value(pswd_idx).toString();
             QString kind = query.value(kind_idx).toString();

             user.setID(id);
             user.setName(name);
             user.setPassword(password);
             user.setKind(kind);
        }
    }
    return user;
}

///导出所有的用户信息，返回用户列表
UserList SQLAnalyze::selectUserInfos(void)
{
    UserList list;
    User user;
    QSqlQuery query;//Qt使用QSqlQuery类提供的方法执行SQL语句
    QString queryString = QString("select * from user");//从user表中获取数据

    if(query.exec(queryString))
      {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int pswd_idx = query.record().indexOf("password");
        int kind_idx = query.record().indexOf("kind");

         while(query.next())
           {
             QString id = query.value(id_idx).toString();
             QString name = query.value(name_idx).toString();
             QString password = query.value(pswd_idx).toString();
             QString kind = query.value(kind_idx).toString();

             user.setID(id);
             user.setName(name);
             user.setPassword(password);
             user.setKind(kind);

             User use(id, name,password,kind);

             list.append(use);
            }
        }
    return list;
}

///导出按要求的所有用户信息，返回用户列表
UserList SQLAnalyze::selectUserInfosAS(QString type)
{
    UserList list;
    QSqlQuery query;//Qt使用QSqlQuery类提供的方法执行SQL语句
    QString queryString =
            QString("select * from user where (kind = '%1' )").arg(type);//从user表中获取数据

    if(query.exec(queryString))
      {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int pswd_idx = query.record().indexOf("password");
        int kind_idx = query.record().indexOf("kind");

         while(query.next())
           {
             QString id = query.value(id_idx).toString();
             QString name = query.value(name_idx).toString();
             QString password = query.value(pswd_idx).toString();
             QString kind = query.value(kind_idx).toString();

             User use(id, name,password,kind);

             list.append(use);

            }
        }

    return list;
}

///导出所有的学生信息，返回学生列表
StudentList SQLAnalyze::selectStudentInfos(void)
{
    StudentList list;
    //声明QSqlQuery query时没有与数据库连接名关联啊
    QSqlQuery query;//Qt使用QSqlQuery类提供的方法执行SQL语句
    QString queryString = QString("select * from student");//从student表中获取数据

    if(query.exec(queryString))
      {
         int id_idx = query.record().indexOf("ID");
         int name_idx = query.record().indexOf("name");
         int birth_idx = query.record().indexOf("birth");
         int sex_idx = query.record().indexOf("sex");
         int idCard_idx = query.record().indexOf("idCard");
         int classID_idx = query.record().indexOf("class_id");
         int departID_idx = query.record().indexOf("depart_id");
         int phone_idx = query.record().indexOf("phone");

         while(query.next())
           {
              QString id = query.value(id_idx).toString();
              QString name = query.value(name_idx ).toString();
              QString birth = query.value(birth_idx).toString();
              QString sex = query.value(sex_idx).toString();
              QString idCard = query.value(idCard_idx).toString();
              QString classID = query.value(classID_idx).toString();
              QString departID = query.value(departID_idx).toString();
              QString phone = query.value(phone_idx).toString();


              User user = selectUserInfo(id);
              //user.disp();
              Student student(user.getID(),user.getName(),
                              user.getPassword(),user.getKind(),
                              birth, sex,idCard,classID,departID,phone);
              list.append(student);
            }
        }
    return list;

}

///查询学生信息，返回单个学生
Student SQLAnalyze::selectStudentInfo(QString id)
{
    Student student;
    QSqlQuery query;
    QString queryString =
              QString("select * from student where id = '%1' ").arg(id);
    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int birth_idx = query.record().indexOf("birth");
        int sex_idx = query.record().indexOf("sex");
        int idCard_idx = query.record().indexOf("idCard");
        int classID_idx = query.record().indexOf("class_id");
        int departID_idx = query.record().indexOf("depart_id");
        int phone_idx = query.record().indexOf("phone");
        while(query.next())
        {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx ).toString();
            QString birth = query.value(birth_idx).toString();
            QString sex = query.value(sex_idx).toString();
            QString idCard = query.value(idCard_idx).toString();
            QString classID = query.value(classID_idx).toString();
            QString departID = query.value(departID_idx).toString();
            QString phone = query.value(phone_idx).toString();

            User user = selectUserInfo(id);

            student.setID(user.getID());
            student.setName(user.getName());
            student.setPassword(user.getPassword());
            student.setKind(student.getKind());
            student.setBirth(birth);
            student.setSex(sex);
            student.setIdCard(idCard);
            student.setClassID(classID);
            student.setDepartID(departID);
            student.setPhone(phone);

        }
    }
    return student;
}

///按姓名查询学生信息，返回学生列表
StudentList SQLAnalyze::selectStudentInfos(QString name)
{
    StudentList list;
    QSqlQuery query;
    QString queryString =
              QString("select * from student where name = '%1' ").arg(name);

    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int birth_idx = query.record().indexOf("birth");
        int sex_idx = query.record().indexOf("sex");
        int idCard_idx = query.record().indexOf("idCard");
        int classID_idx = query.record().indexOf("class_id");
        int departID_idx = query.record().indexOf("depart_id");
        int phone_idx = query.record().indexOf("phone");

        while(query.next())
        {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx ).toString();
            QString birth = query.value(birth_idx).toString();
            QString sex = query.value(sex_idx).toString();
            QString idCard = query.value(idCard_idx).toString();
            QString classID = query.value(classID_idx).toString();
            QString departID = query.value(departID_idx).toString();
            QString phone = query.value(phone_idx).toString();

            User user = selectUserInfo(id);
            Student student(user.getID(),user.getName(),
                            user.getPassword(),user.getKind(),
                            birth, sex,idCard,classID,departID,phone);

          list.append(student);
        }
    }
    return list;
}

///按系代号查询学生信息，返回学生列表
StudentList SQLAnalyze::selectStudentInfosAsDept(QString deptID)
{
    StudentList list;
    QSqlQuery query;
    QString queryString =
              QString("select * from student where depart_id = '%1' ").arg(deptID);

    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int birth_idx = query.record().indexOf("birth");
        int sex_idx = query.record().indexOf("sex");
        int idCard_idx = query.record().indexOf("idCard");
        int classID_idx = query.record().indexOf("class_id");
        int departID_idx = query.record().indexOf("depart_id");
        int phone_idx = query.record().indexOf("phone");

        while(query.next())
        {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx ).toString();
            QString birth = query.value(birth_idx).toString();
            QString sex = query.value(sex_idx).toString();
            QString idCard = query.value(idCard_idx).toString();
            QString classID = query.value(classID_idx).toString();
            QString departID = query.value(departID_idx).toString();
            QString phone = query.value(phone_idx).toString();

            User user = selectUserInfo(id);
            Student student(user.getID(),user.getName(),
                            user.getPassword(),user.getKind(),
                            birth, sex,idCard,classID,departID,phone);

          list.append(student);
        }
    }
    return list;
}

///查询所有的系名，返回字符串列表
QStringList SQLAnalyze::selectDeptNames(void)
{
    QStringList list;
    QSqlQuery query;
    QString queryString = QString("select dept_name from department");

    if(query.exec(queryString))
    {
        int deptName_idx = query.record().indexOf("depart_name");

        while(query.next())
        {
             QString deptName = query.value(deptName_idx).toString();
             list.append(deptName);
        }
    }
    return list;
}

///插入学生信息，返回布尔型
bool SQLAnalyze::insertStudentInfo(Student student)
{
    QSqlQuery query;
    QString queryUserInfo =
            QString("insert into user values ('%1','%2','%3',%4)")
            .arg(student.getID()).arg(student.getName())
            .arg(student.getPassword()).arg(student.getKind());
    QString queryStudentInfo =
            QString("insert into student values('%1', '%2', '%3', '%4','%5','%6','%7','%8')")
            .arg(student.getID()).arg(student.getName())
            .arg(student.getBirth()).arg(student.getSex())
            .arg(student.getIdCard()).arg(student.getClassID())
            .arg(student.getDepartID()).arg(student.getPhone());

    //判断
    if(query.exec(queryUserInfo))
    {
        if(query.exec(queryStudentInfo))
        {
            qDebug() << "Success!";
            return true;

            //QMessageBox::information(this,"提示 ","注册成功！");
        }
    }else
    {
       qDebug() << "Fail!!!";
        return false;

       // QMessageBox::information(this,"提示 ","注册失败！！！");
    }

}

///修改学生信息，返回布尔型
bool SQLAnalyze::updateStudentInfo(Student student)
{
    QSqlQuery query;
    QString queryUserInfo =
            QString("update user set pswd = '%1' where id = '%2' ")
            .arg(student.getPassword()).arg(student.getID());

    QString queryStudentInfo =
            QString("update student set name = '%1',birth = '%2',"
                    "sex = '%3',idCard = '%4', classID = '%5',"
                    "departID = '%6', phone = '%7' where id = '%8'")
            .arg(student.getName()).arg(student.getBirth())
            .arg(student.getSex()).arg(student.getIdCard())
            .arg(student.getClassID()).arg(student.getDepartID())
            .arg(student.getPhone()).arg(student.getID());

    //判断
    if(query.exec(queryUserInfo))
    {
        if(query.exec(queryStudentInfo))
        {
            qDebug() << " update Success!";
            return true;
            //QMessageBox::information(this,"提示 ","注册成功！");
        }
    }else
    {
        qDebug() << " update Fail!!!";
        return false;
       // QMessageBox::information(this,"提示 ","注册失败！！！");
    }
}

///返回到第一条学生信息
Student SQLAnalyze::firstStudentInfo(void)
{

}

///返回到最后一条学生信息，返回单个学生
Student SQLAnalyze::lastStudentInfo(void)
{

}

///返回到下一条学生信息，返回单个学生
Student SQLAnalyze::nextStudentInfo(void)
{

}

///返回到上一条学生信息，返回单个学生
Student SQLAnalyze::previousStudentInfo(void)
{

}

///导出所有的教师信息，返回单个教师
TeacherList SQLAnalyze::selectTeacherInfos(void)
{
    TeacherList list;
    QSqlQuery query;//Qt使用QSqlQuery类提供的方法执行SQL语句
    QString queryString = QString("select * from teacher");//从instructor表中获取数据

    if(query.exec(queryString))
      {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int birth_idx = query.record().indexOf("birth");
        int sex_idx = query.record().indexOf("sex");
        int idCard_idx = query.record().indexOf("idCard");
        int classID_idx = query.record().indexOf("class_id");
        int departID_idx = query.record().indexOf("depart_id");
        int phone_idx = query.record().indexOf("phone");
        int title_idx = query.record().indexOf("title");
        int salary_idx = query.record().indexOf("salary");

         while(query.next())
           {
              //qDebug() << "=========";

             QString id = query.value(id_idx).toString();
             QString name = query.value(name_idx ).toString();
             QString birth = query.value(birth_idx).toString();
             QString sex = query.value(sex_idx).toString();
             QString idCard = query.value(idCard_idx).toString();
             QString classID = query.value(classID_idx).toString();
             QString departID = query.value(departID_idx).toString();
             QString phone = query.value(phone_idx).toString();
             QString title = query.value(title_idx).toString();
             QString salary = query.value(salary_idx).toString();

              User user = selectUserInfo(id);
              Teacher teacher(user.getID(),user.getName(),user.getPassword(),
                              user.getKind(), birth,sex,idCard,classID,
                              departID,phone,title,salary);

             list.append(teacher);
            }
        }
    return list;
}

///查询教师信息，返回单个教师
Teacher SQLAnalyze::selectTeacherInfo(QString id)
{
    Teacher teacher;
    QSqlQuery query;
    QString queryString =
              QString("select * from teacher where id = '%1' ").arg(id);
    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int birth_idx = query.record().indexOf("birth");
        int sex_idx = query.record().indexOf("sex");
        int idCard_idx = query.record().indexOf("idCard");
        int classID_idx = query.record().indexOf("class_id");
        int departID_idx = query.record().indexOf("depart_id");
        int phone_idx = query.record().indexOf("phone");
        int title_idx = query.record().indexOf("title");
        int salary_idx = query.record().indexOf("salary");

        while(query.next())
        {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx ).toString();
            QString birth = query.value(birth_idx).toString();
            QString sex = query.value(sex_idx).toString();
            QString idCard = query.value(idCard_idx).toString();
            QString classID = query.value(classID_idx).toString();
            QString departID = query.value(departID_idx).toString();
            QString phone = query.value(phone_idx).toString();
            QString title = query.value(title_idx).toString();
            QString salary = query.value(salary_idx).toString();

            User user = selectUserInfo(id);

            teacher.setID(id);
            teacher.setName(name);
            teacher.setPassword(user.getPassword());
            teacher.setKind(user.getKind());
            teacher.setBirth(birth);
            teacher.setSex(sex);
            teacher.setIdCard(idCard);
            teacher.setClassID(classID);
            teacher.setDepartID(departID);
            teacher.setPhone(phone);
            teacher.setTitle(title);
            teacher.setSalary(salary);

        }
    }
    return teacher;
}

///按姓名查询教师信息，返回教师列表
TeacherList SQLAnalyze::selectTeacherInfos(QString name)
{
    TeacherList list;
    QSqlQuery query;
    QString queryString =
              QString("select * from teacher where name = '%1' ").arg(name);

    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int birth_idx = query.record().indexOf("birth");
        int sex_idx = query.record().indexOf("sex");
        int idCard_idx = query.record().indexOf("idCard");
        int classID_idx = query.record().indexOf("class_id");
        int departID_idx = query.record().indexOf("depart_id");
        int phone_idx = query.record().indexOf("phone");
        int title_idx = query.record().indexOf("title");
        int salary_idx = query.record().indexOf("salary");

        while(query.next())
        {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx ).toString();
            QString birth = query.value(birth_idx).toString();
            QString sex = query.value(sex_idx).toString();
            QString idCard = query.value(idCard_idx).toString();
            QString classID = query.value(classID_idx).toString();
            QString departID = query.value(departID_idx).toString();
            QString phone = query.value(phone_idx).toString();
            QString title = query.value(title_idx).toString();
            QString salary = query.value(salary_idx).toString();

            User user = selectUserInfo(id);
            Teacher teacher(user.getID(),user.getName(),user.getPassword(),
                            user.getKind(), birth,sex,idCard,classID,
                            departID,phone,title,salary);

          list.append(teacher);
        }
    }
    return list;
}

///按系名查询教师信息，返回教师列表
TeacherList SQLAnalyze::selectTeacherInfosAsDept(QString dept)
{
    TeacherList list;
    QSqlQuery query;
    QString queryString =
              QString("select * from instructor where dept_name = '%1' ").arg(dept);

    if(query.exec(queryString))
    {
        int id_idx = query.record().indexOf("ID");
        int name_idx = query.record().indexOf("name");
        int birth_idx = query.record().indexOf("birth");
        int sex_idx = query.record().indexOf("sex");
        int idCard_idx = query.record().indexOf("idCard");
        int classID_idx = query.record().indexOf("class_id");
        int departID_idx = query.record().indexOf("depart_id");
        int phone_idx = query.record().indexOf("phone");
        int title_idx = query.record().indexOf("title");
        int salary_idx = query.record().indexOf("salary");


        while(query.next())
        {
            QString id = query.value(id_idx).toString();
            QString name = query.value(name_idx ).toString();
            QString birth = query.value(birth_idx).toString();
            QString sex = query.value(sex_idx).toString();
            QString idCard = query.value(idCard_idx).toString();
            QString classID = query.value(classID_idx).toString();
            QString departID = query.value(departID_idx).toString();
            QString phone = query.value(phone_idx).toString();
            QString title = query.value(title_idx).toString();
            QString salary = query.value(salary_idx).toString();

            User user = selectUserInfo(id);
            Teacher teacher(user.getID(),user.getName(),user.getPassword(),
                            user.getKind(), birth,sex,idCard,classID,
                            departID,phone,title,salary);

          list.append(teacher);
        }
    }
    return list;
}
