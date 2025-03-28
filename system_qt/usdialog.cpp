#include "usdialog.h"
#include "ui_usdialog.h"

UsDialog::UsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsDialog)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\bysj\\2023\\kaoqin11\\system_qt\\sql.db");

    if(db.open())
    {
        //        QMessageBox::information(NULL,"提示","载入数据库成功",QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(NULL,"提示","系统载入数据库失败，无法运行",QMessageBox::Yes);

    }

    model = new QSqlTableModel(this);



}

UsDialog::~UsDialog()
{
    delete ui;
}

void UsDialog::init(QString uanme)
{
   username = uanme;
}

void UsDialog::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO sql_bk( qdate, uname, qdesc, qstatis, ctime) VALUES (?,?,?,?,?);");
    query.addBindValue(ui->dateEdit->date().toString("yyyy-MM-dd"));
    query.addBindValue(username);
    query.addBindValue(ui->lineEdit->text());
    query.addBindValue("待审批");
    query.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    if(query.exec()){
        QMessageBox::information(this,tr("提示"),tr("成功！"),QMessageBox::Ok);
    }else{
        QMessageBox::information(this,tr("提示"),tr("失败！"),QMessageBox::Ok);
    }

}

void UsDialog::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO sql_qj( qdate, uname, qdesc, qstatis, ctime) VALUES (?,?,?,?,?);");
    query.addBindValue(ui->dateEdit_2->date().toString("yyyy-MM-dd"));
    query.addBindValue(username);
    query.addBindValue(ui->lineEdit_2->text());
    query.addBindValue("待审批");
    query.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    if(query.exec()){
        QMessageBox::information(this,tr("提示"),tr("成功！"),QMessageBox::Ok);
    }else{
        QMessageBox::information(this,tr("提示"),tr("失败！"),QMessageBox::Ok);
    }
}

void UsDialog::on_pushButton_3_clicked()
{
    QSqlQuery query;
    QString sql = "";
     sql = "SELECT * FROM sql_bk where uname = '"+username+"' order by id desc";

    qDebug()<<sql;

    query.prepare(sql);
    qDebug()<<sql;
    query.exec();
    qDebug()<<sql;
    model->setQuery(query);
qDebug()<<sql;
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"时间");
    model->setHeaderData(2,Qt::Horizontal,"用户名");
    model->setHeaderData(3,Qt::Horizontal,"补卡原因");
    model->setHeaderData(4,Qt::Horizontal,"状态");
    model->setHeaderData(5,Qt::Horizontal,"数据添加时间");
    ui->tableView_user->setModel(model);
qDebug()<<sql;
    ui->tableView_user->setColumnWidth(0,70);
    ui->tableView_user->setColumnWidth(1,179);
    ui->tableView_user->setColumnWidth(2,70);
    ui->tableView_user->setColumnWidth(3,179);
    ui->tableView_user->setColumnWidth(4,70);
    ui->tableView_user->setColumnWidth(5,179);
}

void UsDialog::on_pushButton_4_clicked()
{
    QSqlQuery query;
    QString sql = "";
     sql = "SELECT * FROM sql_qj where uname = '"+username+"' order by id desc";

    qDebug()<<sql;

    query.prepare(sql);
    qDebug()<<sql;
    query.exec();
    qDebug()<<sql;
    model->setQuery(query);
qDebug()<<sql;
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"时间");
    model->setHeaderData(2,Qt::Horizontal,"用户名");
    model->setHeaderData(3,Qt::Horizontal,"补卡原因");
    model->setHeaderData(4,Qt::Horizontal,"状态");
    model->setHeaderData(5,Qt::Horizontal,"数据添加时间");
    ui->tableView_user_2->setModel(model);
qDebug()<<sql;
    ui->tableView_user_2->setColumnWidth(0,70);
    ui->tableView_user_2->setColumnWidth(1,179);
    ui->tableView_user_2->setColumnWidth(2,70);
    ui->tableView_user_2->setColumnWidth(3,179);
    ui->tableView_user_2->setColumnWidth(4,70);
    ui->tableView_user_2->setColumnWidth(5,179);
}
