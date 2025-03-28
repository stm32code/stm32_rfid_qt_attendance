#ifndef USDIALOG_H
#define USDIALOG_H

#include <QDialog>


#include <QComboBox>
#include <QMouseEvent>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QTime>
#include <QDateTime>

namespace Ui {
class UsDialog;
}

class UsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UsDialog(QWidget *parent = 0);
    ~UsDialog();
    QSqlQueryModel *model;
    QString username;
    void init(QString uanme);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::UsDialog *ui;
};

#endif // USDIALOG_H
