#include "studentmainw.h"
#include "ui_studentmainw.h"

StudentMainW::StudentMainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMainW)
{
    ui->setupUi(this);

    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),
            ui->stackedWidget,SLOT(setCurrentIndex(int)));
}

StudentMainW::~StudentMainW()
{
    delete ui;
}

///槽-显示学生账号
void StudentMainW::slotStudentID(QString id)
{
    ui->le_stuID->setText(id);
}
