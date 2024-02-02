#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        ui->label->clear();
        ui->label_2->clear();
           ui->label->setText("Cena: 1 zł");
        ui->label_2->setStyleSheet("background-image: url(':/imgs/resources/pocztowka.png'); background-repeat: no-repeat;");
    }else if(ui->radioButton_2->isChecked()){
        ui->label->clear();
        ui->label_2->clear();
        ui->label->setText("Cena: 1.5 zł");
        ui->label_2->setStyleSheet("background-image: url(':/imgs/resources/list.png'); background-repeat: no-repeat;");
    }else{
        ui->label->clear();
        ui->label_2->clear();
        ui->label->setText("Cena: 10 zł");
        ui->label_2->setStyleSheet("background-image: url(':/imgs/resources/paczka.png'); background-repeat: no-repeat;");
    }
}




void MainWindow::on_pushButton_2_clicked()
{
    QString kodpocztowy = ui->textEdit_2->toPlainText();
    QMessageBox msgBox;

    if (kodpocztowy.length() != 5) {
        msgBox.setText("Nieprawidłowa liczba cyfr w kodzie pocztowym");
        msgBox.exec();

    } else {
        bool zawieraZnak = false;
        for (int i = 0; i < kodpocztowy.length(); i++) {
            if (!kodpocztowy[i].isDigit()) {
                zawieraZnak = true;
                break;
            }
        }
        if (zawieraZnak) {
            msgBox.setText("Kod pocztowy zawiera coś innego niż liczby");
            msgBox.exec();

        } else {
            msgBox.setText("Dane zostały wprowadzone");
            msgBox.exec();
        }
    }
}


