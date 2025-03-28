#include "login.h"
#include "ui_login.h"
#include "usdialog.h"
#include "maindialog.h"“
LOGIN::LOGIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LOGIN)
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
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::on_pushButton_clicked()
{
    QSqlQuery query;
    QString sql = "SELECT pwd FROM sql_login WHERE uname = '"+ui->lineEdit->text()+"'";
    query.prepare(sql);
    query.exec();
    if(query.next()){
        QString pwd = query.value(0).toString();
        if(pwd == ui->lineEdit_2->text()){
            if(ui->lineEdit->text() == "admin"){
                qDebug()<<"管理员";
//                MainDialog w;
//                w.show();

                MainDialog *admin = new MainDialog;
                                admin->show();
//                                this->hide();
                this->hide();
            }else{
                qDebug()<<"普通用户";
//                UsDialog w;
                UsDialog *admin = new UsDialog;
                                admin->show();
//                w.show();
                admin->init(ui->lineEdit->text());
                this->hide();
            }
        }else{
            QMessageBox::information(NULL,"提示","密码不正确",QMessageBox::Yes);
        }
     }else{
        QMessageBox::information(NULL,"提示","用户信息不存在",QMessageBox::Yes);

    }
}
