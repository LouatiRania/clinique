#ifndef CONVENTION_H
#define CONVENTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Convention
{
private:
    int Id;
    QString NomSociete;
    float Remise;

public:
    Convention();
    Convention(int,QString,float);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool ChercherID(int);

    bool modifierNom(int,QString);
    bool modifierRemise(int,float);



};

#endif // CONVENTION_H
