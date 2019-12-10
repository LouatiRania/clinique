#ifndef ANARAD_H
#define ANARAD_H
#include"rsar.h"
#include <QMainWindow>
#include "smtp.h"
#include<QMediaPlayer>
namespace Ui {
class anarad;
}

class anarad : public QMainWindow
{
    Q_OBJECT

public:
    explicit anarad(QWidget *parent = nullptr);
    ~anarad();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);
    void sendMail();
    void mailSent(QString);


    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_4_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_verticalSlider_sliderMoved(int position);

private:
    Ui::anarad *ui;
    ANALYSE tmprdv;
    RADIO tmps;

    QString valeur;
    QMediaPlayer *music =new  QMediaPlayer();

};

#endif //ANARAD_H
