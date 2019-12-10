#ifndef RDVSA_H
#define RDVSA_H
#include<QMessageBox>
#include"rsar.h"
#include <QMainWindow>
#include "smtp.h"
#include<QMediaPlayer>
#include"qcustomplot.h"
namespace Ui {
class rdvsa;
}

class rdvsa : public QMainWindow
{
    Q_OBJECT

public:
    explicit rdvsa(QWidget *parent = nullptr);
    ~rdvsa();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);
    void sendMail();
    void mailSent(QString);
    void makePlot();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_verticalSlider_sliderMoved(int position);

private:
    Ui::rdvsa *ui;
    RDV tmprdv;
    salle tmps;

    QString valeur;
      QMediaPlayer *music =new  QMediaPlayer();

};

#endif // RDVSA_H
