#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include "anarad.h"
#include "rdvsa.h"
#include"gerermed.h"
#include"rania.h"
#include"sarra.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    anarad *SecDialog;
    rdvsa *Sec;
    GererMed *g ;
    sarra *s;
    rania *r;
};

#endif // MAINWINDOW_H
