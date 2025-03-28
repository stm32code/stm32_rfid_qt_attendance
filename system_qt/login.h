#ifndef LOGIN_H
#define LOGIN_H

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
class LOGIN;
}

class LOGIN : public QDialog
{
    Q_OBJECT

public:
    explicit LOGIN(QWidget *parent = 0);
    ~LOGIN();
    QSqlQueryModel *model;
private slots:
    void on_pushButton_clicked();

private:
    Ui::LOGIN *ui;
};

#endif // LOGIN_H
