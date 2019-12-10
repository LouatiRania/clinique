#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class reservation
{
protected:
    QString CIN;
    QString nom;
    QString nbconsultation;
    int nbnuit;
    QString Prenom;
    QString convention;



public:
    reservation();
    bool ajouter();
    QSqlQueryModel *afficher();
    reservation(QString,QString,QString,int,QString,QString);
    bool supprimer(QString);
   QSqlQueryModel * rechercher(QString);
   bool modifierNom(QString,QString);
   bool modifierPrenom(QString,QString);
   bool modifierCIN(QString,QString);
   bool modifierConsultation(QString,QString);
   bool modifierNuit(QString,QString);
   bool ChercherCIN(QString);
   QSqlQueryModel * triConsultation();
};

#endif // RESERVATION_H
