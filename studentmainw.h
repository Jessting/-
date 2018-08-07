#ifndef STUDENTMAINW_H
#define STUDENTMAINW_H

#include <QMainWindow>

namespace Ui {
class StudentMainW;
}

class StudentMainW : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMainW(QWidget *parent = 0);
    ~StudentMainW();

public slots:
    void slotStudentID(QString id);

private:
    Ui::StudentMainW *ui;
};

#endif // STUDENTMAINW_H
