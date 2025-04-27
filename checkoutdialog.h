#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include "roomsdialog.h"

namespace Ui {
class CheckOutDialog;
}

class CheckOutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutDialog(int roomNo, RoomsDialog* roomsDialog,QWidget *parent = nullptr);
    ~CheckOutDialog();

private slots:

    void on_pushButtonFetch_clicked();

    void on_pushButton_clicked();

    void on_pushButtonOk_clicked();

private:
    Ui::CheckOutDialog *ui;
    int m_roomNo;
    int m_reservationId = 0;
    RoomsDialog* m_roomsDialog = nullptr;

};

#endif // CHECKOUTDIALOG_H
