#include "logic.h"
#include <QApplication>

#include <QMetaType>

int main(int argc, char *argv[])
{
    qRegisterMetaType<User>("User");
    qRegisterMetaType<UserList>("UserList");

    QApplication a(argc, argv);
    logic lo;
    lo.showLoginW();

    return a.exec();
}
