#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <cstdlib>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_out_clicked()
{

    QString str = ui->lineEdit->text();
    std::string str1 = str.toStdString();
    const int N = 16;
    int card[N];
    int somma = 0;
    int sommaPari=0, sommaDispari=0;

    for(int i=0; i<str.length(); i++)
    {
        card[i] = str1[i] - '0';
    }

    if(str.length()==16)
    {

        for(int i=N-1; i>=0; i--)
        {
            int p;
            int num = card[i];
            if(i%2==0)
            {
                p=num*2;
                if(p>9)
                {
                    p=p-9;
                }
                sommaDispari += p;
            }
            else
            {
                p=num;
                sommaPari += p;
            }
        }
        somma = sommaPari + sommaDispari;

        if(somma%10==0)
        {
            QMessageBox::information(this, "main", "La carta di credito è valida");
        }
        else
        {
            QMessageBox::warning(this, "main", "La carta di credito non è valida");
        }
    }
    else
    {
        QMessageBox::warning(this, "main", "La carta di credito non è valida");
    }

    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();
    }

}

