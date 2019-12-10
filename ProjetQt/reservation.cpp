
#include "reservation.h"
#include <QVector>
#include <vector>
#include "QDebug"
reservation::reservation()
{

}
reservation::reservation(QString CIN,QString nom,QString nbconsultation,int nbnuit,QString Prenom,QString conv)
{
    this->CIN=CIN;
    this->nom=nom;
    this->nbconsultation=nbconsultation;
    this->nbnuit=nbnuit;
    this->Prenom=Prenom;
    this->convention=conv;
}
bool reservation::ajouter()
{


    QSqlQuery query;
    QString res= QString::number(nbnuit);
    query.prepare("INSERT INTO reservation (CIN,NOM,NB_CONSULTATION,NB_NUITEE,PRENOM,CONVENTION) "
                        "VALUES (:CIN, :nom, :nbconsultation, :nbnuit, :Prenom, :convention)");
    query.bindValue(":CIN", CIN);
    query.bindValue(":nom", nom);
    query.bindValue(":nbnuit",res );
    query.bindValue(":nbconsultation", nbconsultation);
     query.bindValue(":Prenom", Prenom);
     query.bindValue(":convention", convention);

    return    query.exec();



}

QSqlQueryModel * reservation::afficher()
{


QSqlQuery query;
query.prepare("select * from reservation");
query.exec();
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_CONSULTATION"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_NUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
    return model;
}

QSqlQueryModel * reservation::rechercher(QString nom)
{


QSqlQuery query;
query.prepare("select * from reservation where nom like '%"+nom+"%'");
// le symbole % est un wildcard
query.exec();
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_CONSULTATION"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_NUIT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
    return model;
}

bool reservation::supprimer(QString CIN)
{
QSqlQuery query;
//QString res= QString::number(CIN);
query.prepare("Delete from reservation where CIN = :CIN ");
query.bindValue(":CIN", CIN);
return    query.exec();
}
bool reservation::modifierNom(QString nom,QString CIN)
{
    QSqlQuery query;

    query.prepare("UPDATE reservation set nom = :nom where cin = :cin");
    query.bindValue(":nom", nom);
    query.bindValue(":cin", CIN);

    return    query.exec();

}

bool reservation::modifierPrenom(QString prenom,QString CIN)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE reservation set prenom=:prenom where cin=:cin ");
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", CIN);
    return    query.exec();

}


bool reservation::modifierCIN(QString cin,QString CIN)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE reservation set cin=:xcin where cin=:cin ");
    query.bindValue(":xcin", cin);
    query.bindValue(":cin", CIN);
    return    query.exec();

}
bool reservation::modifierNuit(QString nuit,QString CIN)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE reservation set nb_nuitee=:nuit where cin=:cin ");
    query.bindValue(":nuit", nuit);
    query.bindValue(":cin", CIN);
    return    query.exec();

}

bool reservation::modifierConsultation(QString consultation,QString CIN)
{
    QSqlQuery query;
   // QString res= QString::number(nbnuit);
    query.prepare("UPDATE reservation set nb_consultation=:consultation where cin=:cin ");
    query.bindValue(":consultation", consultation);
    query.bindValue(":cin", CIN);
    return    query.exec();

}

bool reservation::ChercherCIN(QString CIN)
{
 QSqlQuery query;
 /*query.prepare("Select cin from reservation where cin=:cin");
 query.bindValue(":cin",CIN);*/
 QVector <int> tab;
 if(query.exec("Select cin from reservation where cin ='"+CIN+"'"))
 {
     while(query.next())
     {
         tab.push_back(query.value(0).toInt());
     }
     if(tab.size()==0)
     {
         return false;
     }
     else {
         return true;
     }
 }
}

QSqlQueryModel * reservation::triConsultation()
{
    QSqlQuery query;
    query.prepare("select * from reservation order by cast(NB_CONSULTATION as integer) DESC");
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NB_CONSULTATION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_NUIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
        return model;
}
