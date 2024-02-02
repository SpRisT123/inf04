#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    char cyfry[10]={'0','1','2','3','4','5','6','7','8','9'};
    char znaki[14]={'!','@','#','$','%','^','&','(',')','_','+','-','='};
    char litery[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char litery2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    QString ilosc=ui->textEdit_3->toPlainText();
    int iloscZnakow=ilosc.toInt();
    QString haslo="";

    srand(time(NULL));

    if(ui->checkBox_2->isChecked()){
        iloscZnakow=iloscZnakow-1;
        haslo+=cyfry[0+rand()%9];
    }

    if(ui->checkBox_3->isChecked()){
        iloscZnakow=iloscZnakow-1;
        haslo+=znaki[0+rand()%13];
    }

    if(ui->checkBox->isChecked()){
        iloscZnakow=iloscZnakow-1;
        haslo+=litery2[0+rand()%25];

    }

    for(int j=0;j<iloscZnakow;j++){
        haslo+=litery[0+rand()%25];
    }

    std::fstream plik;
    plik.open("haslo.txt",std::ios::out);
    plik<<haslo.toStdString();
    plik.close();

    QMessageBox msgBox1;
    msgBox1.setText(haslo);
    msgBox1.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    QString userhaslo;
    QString imie=ui->textEdit->toPlainText();
    QString nazwisko=ui->textEdit_2->toPlainText();
    QString stanowsiko=ui->comboBox->currentText();
    std::string haslo;

    std::fstream plik;
    plik.open("haslo.txt",std::ios::in);
    std::getline(plik,haslo);
    userhaslo=QString::fromStdString(haslo);
    plik.close();

    QMessageBox msgbox;
    msgbox.setText("Dane pracownika: "+imie+" "+nazwisko+" "+stanowsiko+" Hasło: "+userhaslo);
    msgbox.exec();

}

