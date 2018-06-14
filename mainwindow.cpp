#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    odswiez();
}

void MainWindow::on_pushButton_5_clicked()      //przycisk w górę
{
    kon_y=kon_y-5;
    if(kon_y<50) kon_y=50;
    odswiez();
}


void MainWindow::on_pushButton_2_clicked()      //przycisk w lewo
{
    pocz_x=pocz_x-5;
    if(pocz_x<15) pocz_x=15;
    odswiez();
}

void MainWindow::on_pushButton_3_clicked()      //przycisk w prawo
{
    pocz_x=pocz_x+5;
    if(pocz_x>435) pocz_x=435;
    odswiez();
}

void MainWindow::on_pushButton_4_clicked()      //przycisk w dół
{
    kon_y=kon_y+5;
    if (pocz_x>410){
        switch (ile_odlozono){
            case 0:
                if(kon_y>385) kon_y=385;
            break;
            case 1:
                if(kon_y>345) kon_y=345;
            break;
            case 2:
                if(kon_y>305) kon_y=305;
            break;
        }
     }
    else {
        if(kon_y>420) kon_y=420;
    }
    odswiez();
}

void MainWindow::on_pushButton_6_clicked()      //sprawdza czy kwadrat
{
    QGraphicsPixmapItem * wsk;
    if(figury[pocz_x/50].rodzaj==0) {
        czy_sprawdzone=true;
    }
    else {
        czy_sprawdzone=false;
    }
    if(czy_sprawdzone==true){
        if (kon_y>390) {
            czy_podniesiona=true;
            nr_przesuwanej=pocz_x/50;
            lista_przesunietych[ile_odlozono]=nr_przesuwanej;
            odswiez();
            wsk= dzwig->addPixmap(tak);     //tak
            wsk->setPos(650, 100);
        }
        else {
            odswiez();
            wsk= dzwig->addPixmap(blizej);     //tak
            wsk->setPos(650, 100);
        }
    }
    else{
        odswiez();
        wsk= dzwig->addPixmap(nie);     //nie
        wsk->setPos(700, 150);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
        odklada();
        odswiez();
}






