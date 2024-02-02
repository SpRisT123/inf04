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

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    //ui->label->setText("sdad");
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString qnumber = ui->lineEdit->text();
    std::string number=qnumber.toStdString();

    if(number=="000"){
        ui->label_4->setStyleSheet("border-image: url(':/imgs/000-zdjecie.jpg') 0 0 0 0 stretch stretch;");
        ui->label_5->setStyleSheet("border-image: url(':/imgs/000-odcisk.jpg') 0 0 0 0 stretch stretch;");
    }else if(number=="111"){
        ui->label_4->setStyleSheet("border-image: url(':/imgs/111-zdjecie.jpg') 0 0 0 0 stretch stretch;");
        ui->label_5->setStyleSheet("border-image: url(':/imgs/111-odcisk.jpg') 0 0 0 0 stretch stretch;");
    }else if(number=="333"){
        ui->label_4->setStyleSheet("border-image: url(':/imgs/333-zdjecie.jpg') 0 0 0 0 stretch stretch;");
        ui->label_5->setStyleSheet("border-image: url(':/imgs/333-odcisk.jpg') 0 0 0 0 stretch stretch;");
    }else{
        ui->label_4->setStyleSheet("background:none;");
        ui->label_5->setStyleSheet("background:none;");
    }

}


void MainWindow::on_pushButton_clicked()
{

    QString imie=ui->lineEdit_2->text();
    QString nazwisko=ui->lineEdit_3->text();
    QString kolor;

    if(ui->radioButton->isChecked()){
        kolor=ui->radioButton->text();
    }else if(ui->radioButton_2->isChecked()){
        kolor=ui->radioButton_2->text();
    }else{
        kolor=ui->radioButton_3->text();

    }



    std::string simie= imie.toStdString();
    std::string snazwisko = nazwisko.toStdString();
    QMessageBox msgBox;

    if(simie=="" || snazwisko==""){
        msgBox.setText("Wprowadź dane");
        msgBox.exec();
    }else{
        msgBox.setText(imie+" "+nazwisko+" kolor oczu "+kolor);
        msgBox.exec();
    }


}

