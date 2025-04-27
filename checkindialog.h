#ifndef CHECKINDIALOG_H
#define CHECKINDIALOG_H

#include <QDialog>
#include "roomsdialog.h"

namespace Ui {
class CheckInDialog;
}

class CheckInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInDialog(int roomNo, RoomsDialog* roomsDialog, QWidget *parent = nullptr);
    ~CheckInDialog();

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::CheckInDialog *ui;
    int m_roomNo;
    RoomsDialog* m_roomsDialog = nullptr;
};

#endif // CHECKINDIALOG_H
