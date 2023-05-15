#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "singletonClient.h"
#include <QClipboard>
#include <QApplication>
#include <QTimer>
#include <QColor>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth = new AuthForm;
   // ui_user_info = new AboutUserForm;

    //connect(timer1, SIGNAL(timeout()), this, SLOT(update1()));
    //connect(timer2, SIGNAL(timeout()), this, SLOT(update2()));
    //connect(ui_user_info, &AboutUserForm::user_exit_press,
           // this, &MainWindow::user_exit);

    connect(ui_auth, &AuthForm::closed, this, &MainWindow::slot_show);
    connect(SingletonClient::getInstance(),
            &SingletonClient::auth_ok,
            this,
            &MainWindow::slot_on_auth_ok);

    //connect(this, &MainWindow::open_user_info,
           // ui_user_info, &AboutUserForm::show);

    ui_auth->show();

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton->setStyleSheet("border-image:url(:/btn1p.png)");
    ui->pushButton_2->setStyleSheet("border-image:url(:/btn2.png)");
    ui->pushButton_3->setStyleSheet("border-image:url(:/btn3.png)");
}

void MainWindow::on_pushButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(1) ;
   ui->pushButton_2->setStyleSheet("border-image:url(:/btn2p.png)");
   ui->pushButton->setStyleSheet("border-image:url(:/btn1.png)");
   ui->pushButton_3->setStyleSheet("border-image:url(:/btn3.png)");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->pushButton_3->setStyleSheet("border-image:url(:/btn3p.png)");
    ui->pushButton->setStyleSheet("border-image:url(:/btn1.png)");
    ui->pushButton_2->setStyleSheet("border-image:url(:/btn2.png)");
}
void MainWindow::slot_show(QString log)
{
    this->show();
}

/*
void MainWindow::prepare_window_for_user()
{
    ui->pushButton_user_info->setText(user_data["Login"].toString());
    ui->label_access_level->setText("Уровень доступа: " + user_data["Position"].toString());

    QJsonArray ServicesArr = user_data["Services"].toArray();
    for (const QJsonValue& value : ServicesArr)
    {
        QJsonObject object = value.toObject();
        QListWidgetItem* NewService = new QListWidgetItem(object["name"].toString());
        ui->listWidget_services->addItem(NewService);
    }
    ui->frame_2->hide();
}*/

void MainWindow::slot_on_auth_ok(QString user_data)
{
    ui_auth->close();
    this->show();
   // QJsonDocument doc = QJsonDocument::fromJson(user_data.toUtf8());
   // this->user_data = doc.object();
  //  this->prepare_window_for_user();
}


MainWindow::~MainWindow()
{
    delete ui;
}









/*

void MainWindow::user_exit()
{
    this->close();
    ui->listWidget_services->clear();
    ui_auth->show();
}

void MainWindow::on_listWidget_services_itemClicked(QListWidgetItem *item)
{
    if (ui->frame_2->isHidden())
    {
        ui->frame_2->show();
    }

    QJsonArray ServicesArr = user_data["Services"].toArray();
    for (const QJsonValue& value : ServicesArr)
    {
        QJsonObject object = value.toObject();
        if (item->text() == object["name"].toString())
        {
            ui->lineEdit_service_login->setText(object["login"].toString());
            ui->lineEdit_service_password->setText(object["password"].toString());
            break;
        }
    }
}*/


