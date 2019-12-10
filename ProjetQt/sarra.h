#ifndef SARRA_H
#define SARRA_H
#include "ordo.h"

#include <QMainWindow>
#include <QWidget>
#include <QSound>
namespace Ui {
class sarra;
}

class sarra : public QMainWindow
{
    Q_OBJECT

public:
    explicit sarra(QWidget *parent = nullptr);
    ~sarra();

private slots:
    void on_pb_ajouter_clicked();

    void on_supprimer_clicked();

   void on_pushButton_clicked();

   void on_numm_textChanged(const QString &arg1);

   void on_numm_returnPressed();

   void on_pdf_clicked();

   void on_pb_ajouter_2_clicked();

   void on_pushButton_2_clicked();

   void on_supprimer_2_clicked();

   void on_lineEdit_textChanged(const QString &arg1);

   void on_lineEdit_returnPressed();

private:
    Ui::sarra *ui;
 ordo tmpordo;
 docteur tmpdocteur;
 QSound *son;
};

#endif // SARRA_H

