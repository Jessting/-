#include "connectsql.h"

#include <QSqlError> //QSqlError 类提供了SQL数据库错误信息。
#include <QDebug>

ConnectSQL::ConnectSQL()//构造函数，打开数据库
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");//添加数据库（类型）
    db.setDatabaseName("../Database/Chen.db");//确定数据库的名字

    if(!db.open())
    {
        qCritical("Can't open database: %s(%s)",
                  db.lastError().text().toLocal8Bit().data(),
                  qt_error_string().toLocal8Bit().data());

    }
}

ConnectSQL::~ConnectSQL()//析构函数
{
    QSqlDatabase::database().close();//关闭数据库
}
