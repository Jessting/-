#include "teachermainw.h"
#include "ui_teachermainw.h"

TeacherMainW::TeacherMainW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherMainW)
{
    ui->setupUi(this);

    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),
            ui->stackedWidget,SLOT(setCurrentIndex(int)));
}

TeacherMainW::~TeacherMainW()
{
    delete ui;
}

///槽-教师账号显示
void TeacherMainW::slotTeacherID(QString id)
{
    ui->le_teacherID->setText(id);
}
