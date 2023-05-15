#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authform.h"

#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  //  QTimer * timer1 = new QTimer(this);
 //  QTimer * timer2 = new QTimer(this);
public slots:
    void slot_show(QString log);

private slots:




    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();











    void slot_on_auth_ok(QString);





    //void user_exit();

    //void prepare_window_for_user();

    //void on_listWidget_services_itemClicked(QListWidgetItem *item);

signals:
    void open_user_info();

private:
    Ui::MainWindow *ui;
    AuthForm *ui_auth;
 //   AboutUserForm *ui_user_info;

    QJsonObject user_data;
};

#endif // MAINWINDOW_H
