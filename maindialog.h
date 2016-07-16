#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "hat.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private slots:

    void on_btnOpebFile_clicked();

    void on_btnSay_clicked();

private:
    Ui::MainDialog *ui;
    hat _hat;
};

#endif // MAINDIALOG_H
