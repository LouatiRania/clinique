#ifndef RANIA_H
#define RANIA_H

#include <QMainWindow>
#include"smtp.h"
namespace Ui {
class rania;
}

class rania : public QMainWindow
{
    Q_OBJECT

public:
    explicit rania(QWidget *parent = nullptr);
    ~rania();

private slots:
    void sendMail();
    void mailSent(QString);
    void on_ajout_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

    void on_confirmer_ajout_clicked();

    void on_confirmer_supp_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_radioButton_nom_clicked();

    void on_radioButton_prenom_clicked();

    void on_modifier_clicked();

    void on_pushButton_modifier_clicked();

    void on_radioButton_cin_clicked();

    void on_radioButton_consultation_clicked();

    void on_radioButton_nuit_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_convention_clicked();

    void on_pushButton_Reservation_clicked();

    void on_pushButton_clicked();

    void on_pushButton_ajoutConsultation_clicked();

    void on_pushButton_afficherConsultation_clicked();

    void on_pushButton_SupprimerConsultation_clicked();

    void on_pushButton_Supp_clicked();

    void on_pushButton_ModifierConsultation_clicked();

    void on_radioButton_nomSociete_clicked();

    void on_radioButton_remise_clicked();

    void on_pushButton_ModifierConsultation_2_clicked();

    void on_modifier_2_clicked();



private:
    Ui::rania *ui;
};

#endif // RANIA_H
