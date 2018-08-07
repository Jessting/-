#ifndef TEACHERMAINW_H
#define TEACHERMAINW_H

#include <QMainWindow>

namespace Ui {
class TeacherMainW;
}

class TeacherMainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainW(QWidget *parent = 0);
    ~TeacherMainW();

public slots:
    void slotTeacherID(QString id);

private:
    Ui::TeacherMainW *ui;
};

#endif // TEACHERMAINW_H
