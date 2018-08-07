#include <QApplication>

#include "logic.h"
#include "connectsql.h"

#include <QMetaType>

int main(int argc, char *argv[])
{
    qRegisterMetaType<User>("User");
    qRegisterMetaType<UserList>("UserList");

    QApplication a(argc, argv);

    ConnectSQL db;
    Logic lo;
    lo.showLoginW();

    return a.exec();
}
