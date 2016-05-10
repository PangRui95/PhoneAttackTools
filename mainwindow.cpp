#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "attackthread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setValue(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(NULL,"Warnning","请输入号码！",QMessageBox::Yes);
    }
    else
    {
        QString pn = ui->lineEdit->text();
        QMessageBox::about(NULL,"Info","开始轰炸!");
        for(int i = 0;i < ui->spinBox->value();i++)
        {
            AttackThread* attack = new AttackThread(pn);
            act.append(attack);
            act.last()->start();
        }
        ui->pushButton->setEnabled(false);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!act.isEmpty())
    {
        ui->pushButton->setEnabled(true);
        for(int i = 0;i < act.size();i++)
        {
            if(act.at(i)->isRunning())
            {
                act.at(i)->terminate();
                delete act.at(i);
            }
        }
        act.clear();
        QMessageBox::about(NULL,"Info","停止轰炸！");
    }else
    {
        QMessageBox::warning(NULL,"Warnning","轰炸已停止！",QMessageBox::Yes);
    }
}
