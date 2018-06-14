#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
        losuj();
        ui->setupUi(this);
        dzwig=new QGraphicsScene(-50,-60,ui->graphicsView->width(),ui->graphicsView->height()) ;
        ui->graphicsView->setScene(dzwig);
        tlo.load(":/dzwig.png");
        kwadrat.load(":/kwadrat.png");
        kolo.load(":/kolo.png");
        trojkat.load(":/trojkat.png");
        paleta.load(":/paleta.png");
        tak.load(":/tak.png");
        nie.load(":/nie.png");
        blizej.load(":/blizej.png");
        bob.load(":/bob.png");
        dzwig->addPixmap(tlo);
        pocz_x=50;
        kon_y=200;
        nr_przesuwanej=9;
        ile_odlozono=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::losuj(){
    int a=0;
    for (int i=0; i<8; i++){
        figury[i].czy_rysowac=true;
        figury[i].rodzaj=rand()%3;
        if (figury[i].rodzaj==0) a++;
    }
    if(a<3) losuj();
}


void MainWindow:: rysuj_figury(int a, int b, int nr_przesuwanej){
    QGraphicsPixmapItem * wsk;
    for (int i=0; i<8; i++){
        figury[i].x=50*i;
        figury[i].y=400;
        if(i==nr_przesuwanej && czy_podniesiona==true)
            for (int j=0; j<3; j++){
                if (i==lista_przesunietych[j] ){
                    figury[i].x=a-20;
                    figury[i].y=b;
                }
            }
      // qDebug()<<figury[i].czy_rysowac<<figury[i].rodzaj<<nr_przesuwanej<<pocz_x/50<<lista_przesunietych[0]<<lista_przesunietych[1]<<lista_przesunietych[2];
        if(figury[i].czy_rysowac==true){
            switch(figury[i].rodzaj){
                case 0:
                    wsk= dzwig->addPixmap(kwadrat);     //kwadrat
                    wsk->setPos(figury[i].x, figury[i].y);
                 break;
                 case 1:
                    wsk= dzwig->addPixmap(kolo);     //kolo
                    wsk->setPos(figury[i].x, figury[i].y);
                break;
                case 2:
                    wsk= dzwig->addPixmap(trojkat);     //trojkat
                    wsk->setPos(figury[i].x, figury[i].y);
                break;
                }
        }
    }
}




void MainWindow::odklada(){
    if(pocz_x>410 && czy_podniesiona==true){
        ile_odlozono++;
        czy_podniesiona=false;
        figury[lista_przesunietych[ile_odlozono-1]].czy_rysowac=false;
    }
}


void MainWindow::odswiez(){
    QGraphicsPixmapItem * wsk;
    dzwig->clear();
    dzwig->addPixmap(tlo);
    if(ile_odlozono==0){
        rysuj_figury(pocz_x, kon_y, nr_przesuwanej);
    }
    if(ile_odlozono!=0){
        switch (ile_odlozono){
            case 1:
                wsk= dzwig->addPixmap(kwadrat);
                wsk->setPos(410, 385);
                rysuj_figury(pocz_x, kon_y, nr_przesuwanej);
            break;
            case 2:
                wsk= dzwig->addPixmap(kwadrat);
                wsk->setPos(410, 385);
                wsk= dzwig->addPixmap(kwadrat);
                wsk->setPos(410, 345);
                rysuj_figury(pocz_x, kon_y, nr_przesuwanej);
            break;
            case 3:
                wsk= dzwig->addPixmap(kwadrat);
                wsk->setPos(410, 385);
                wsk= dzwig->addPixmap(kwadrat);
                wsk->setPos(410, 345);
                wsk= dzwig->addPixmap(kwadrat);
                wsk->setPos(410, 305);
                rysuj_figury(pocz_x, kon_y, nr_przesuwanej);
            break;
        }
    }
    QGraphicsPixmapItem * pal= dzwig->addPixmap(paleta);     //paleta
    pal->setPos(400, 430);
    dzwig->addLine(pocz_x,50, pocz_x, kon_y);
    if(ile_odlozono==3){
        wygrana();
    }
}




void MainWindow::wygrana(){
    QGraphicsPixmapItem * wsk;
    dzwig->clear();
    QMediaPlayer* muzyka = new QMediaPlayer();
    muzyka->setMedia(QUrl("qrc:/Bob_The_Builder.mp3"));
    muzyka->play();
    wsk=dzwig->addPixmap(bob);
    wsk->setPos(0, -70);
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






