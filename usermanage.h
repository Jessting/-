#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QWidget>

namespace Ui {
class UserManage;
}

class UserManage : public QWidget
{
    Q_OBJECT

public:
    explicit UserManage(QWidget *parent = 0);
    ~UserManage();

    enum User_CHIOCE{
        CHOICE_ALL,
        CHOICE_ADMIN,
        CHOICE_TEARCHER,
        CHOICE_STUDENT,
    };

private slots:
    void on_pb_reflash_clicked();

    void on_pb_select_clicked();

    void on_cb_choice_activated(int index);

private:
    Ui::UserManage *ui;

    int m_userChoiceIndex;
};

#endif // USERMANAGE_H
