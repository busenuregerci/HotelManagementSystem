#ifndef GUESSLISTDIALOG_H
#define GUESSLISTDIALOG_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class GuessListDialog;
}

class GuessListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GuessListDialog(QWidget *parent = nullptr);
    ~GuessListDialog();
    void updateGuessList(); // Misafir listesini güncellemek için bir fonksiyon

private:
    Ui::GuessListDialog *ui;
    QTableWidget *m_tableWidget; // Misafirleri göstereceğimiz QTableWidget
};

#endif // GUESSLISTDIALOG_H
