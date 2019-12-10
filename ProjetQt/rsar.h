#ifndef RDV_H
#define RDV_H
#include<QDateTime>
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
class RDV
{
    QString nom ;
    QString prenom ;
    QString idmedecin ;
    QDateTime dater;
    QString cin;
    QString  salle ;
    QString numr;
    QString mail ;

public:
    RDV();
    RDV(QString,QString,QDateTime,QString,QString,QString,QString,QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_c();
    QSqlQueryModel * tri_d();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * recherche(QString valeur);


};
class salle
{
    QString num ;
    QString localisation ;
    int capacite ;


public:
    salle();
    salle(QString,QString,int);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_c();
    QSqlQueryModel * tri_d();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * recherche(QString valeur);


};
class RADIO
{
    QString nom ;
    QString prenom ;
    QDateTime dater;
    QString code;
    QString numr;
    QString mail ;

public:
    RADIO();
    RADIO(QString,QString,QDateTime,QString,QString,QString );
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_c();
    QSqlQueryModel * tri_d();
    bool supprimer(QString);
    bool modifier( );
    QSqlQueryModel * recherche(QString valeur);


};
class ANALYSE
{
    QString nom ;
    QString prenom ;
    QDateTime dater;
    QString code;
    QString numr;
    QString mail ;

public:
    ANALYSE();
    ANALYSE(QString,QString,QDateTime,QString,QString,QString );
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_c();
    QSqlQueryModel * tri_d();
    bool supprimer(QString);
    bool modifier( );
    QSqlQueryModel * recherche(QString valeur);


};
#endif // RDV_H
