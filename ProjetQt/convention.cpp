#include "convention.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


Convention::Convention()
{
}

Convention::Convention(int id,QString nom,float remise)
{
    this->Id=id;
    this->NomSociete=nom;
    this->Remise=remise;
}
bool Convention::ajouter()
{

    QSqlQuery query;
    int id= (int)Id;
    int remise =(float)Remise;
    QString res=(QString)NomSociete;
    query.prepare("INSERT INTO convention (id,nomsociete,remise) "
                        "VALUES (:ID, :NOM, :REMISE)");
    query.bindValue(":ID",id);
    query.bindValue(":NOM", res);
    query.bindValue(":REMISE",remise );


    return    query.exec();

}
QSqlQueryModel *Convention::afficher()
{
    QSqlQuery query;
    query.prepare("select * from convention");
    query.exec();
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM DE LA SOCIETE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REMISE"));

        return model;
}

bool Convention::supprimer(int id)
{
    QSqlQuery query;
    //QString res= QString::number(CIN);
    query.prepare("Delete from convention where id = :id ");
    query.bindValue(":id", id);
    return    query.exec();

}

bool Convention::ChercherID(int id)
{
    QSqlQuery query;
    QString numero=(QString)id;

    QVector <int> tab;
    query.prepare("SELECT id from Convention where id =:id");
    query.bindValue(":id",id);
    if(query.exec())
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

bool Convention::modifierNom(int id , QString nom)
{
    QSqlQuery query;

    query.prepare("UPDATE convention set nomsociete = :nom where id = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":id", id);

    return    query.exec();
}

bool Convention::modifierRemise(int id , float remise)
{
    QSqlQuery query;
    int res=(int)remise;
    query.prepare("UPDATE convention set remise = :remise where id = :id");
    query.bindValue(":remise", res);
    query.bindValue(":id", id);

    return    query.exec();
}

