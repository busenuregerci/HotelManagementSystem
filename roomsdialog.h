#ifndef ROOMSDIALOG_H
#define ROOMSDIALOG_H

#include <QDialog>

namespace Ui {
class RoomsDialog;
}

enum OperationMode{
    CheckIn,
    CheckOut
};

class RoomsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoomsDialog(OperationMode mode, QWidget *parent = nullptr);
    ~RoomsDialog();
    bool isRoomOccupied(int roomNo);
    void updateRoomButtons();

private:
    Ui::RoomsDialog *ui;
    OperationMode m_mode;
private slots:
    void handleRoomButtonClicked();
};

#endif // ROOMSDIALOG_H
