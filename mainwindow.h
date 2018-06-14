#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QDebug>





struct polozenie{
    int x;
    int y;
    int rodzaj;
    bool  czy_rysowac;
};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();



private:
    void odswiez();
    void losuj();
    void rysuj_figury(int a, int b, int nr_przesuwanej);
    void przenosi_figure ();
    void odklada();
    void czyszczenie();
    void wygrana();
    Ui::MainWindow *ui;
    QGraphicsScene *dzwig;
    QPixmap kwadrat;
    QPixmap trojkat;
    QPixmap kolo;
    QPixmap tlo;
    QPixmap paleta;
    QPixmap tak;
    QPixmap nie;
    QPixmap blizej;
    QPixmap bob;
    int pocz_x, kon_y;
    int nr_przesuwanej;
    polozenie figury[9];
    bool czy_sprawdzone;
    bool czy_podniesiona;
    int ile_odlozono;
    int lista_przesunietych [3];


};

#endif // MAINWINDOW_H
