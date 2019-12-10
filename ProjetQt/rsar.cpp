#include "rsar.h"

RDV::RDV()
{

}
RDV::RDV(QString nom ,QString prenom ,QDateTime dater ,QString idmedecin ,QString cin ,QString salle ,QString numr,QString mail)
{
    this->nom=nom;
    this->prenom=prenom;
    this->dater=dater;
    this->idmedecin=idmedecin;
    this->cin=cin;
    this->salle=salle;
    this->numr=numr;
    this->mail=mail;
}
bool RDV::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO rdv (numr,dater,nom,prenom,idmedecin,cin,mail,salle) "
                        "VALUES (:nu , :d , :n , :p , :im , :cin , :m , :s)");
    query.bindValue(":nu", numr);
    query.bindValue(":d", dater);
    query.bindValue(":n", nom);
    query.bindValue(":p", prenom);
    query.bindValue(":im", idmedecin);
    query.bindValue(":cin", cin);
    query.bindValue(":m", mail);
    query.bindValue(":s", salle);
    return query.exec();
}
QSqlQueryModel * RDV::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numrdv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idmedecin"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("salle"));

    return model;
}
bool RDV::supprimer(QString numr)
{
QSqlQuery query;

query.prepare("Delete from rdv where numr = :nu ");
query.bindValue(":nu", numr);
return    query.exec();
}
bool RDV::modifier(QString x)
{
QSqlQuery query;

query.prepare("update rdv set numr = :nu ,dater = :d ,nom = :n ,prenom = :p ,idmedecin = :im ,cin = :cin ,mail = :m , salle = :s where numr = :x ");
query.bindValue(":x", x);
query.bindValue(":nu", numr);
query.bindValue(":d", dater);
query.bindValue(":n", nom);
query.bindValue(":p", prenom);
query.bindValue(":im", idmedecin);
query.bindValue(":cin", cin);
query.bindValue(":m", mail);
query.bindValue(":s", salle);
return    query.exec();
}
QSqlQueryModel * RDV::recherche(QString valeur )
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
query.prepare("SELECT * FROM rdv WHERE nom like :valeur order by nom ");
 valeur="%"+valeur+"%";
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("numrdv"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("idmedecin"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("cin"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("mail"));
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("salle"));
 return  model;
}
QSqlQueryModel * RDV::tri_c()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv ORDER BY dater ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numrdv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idmedecin"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("salle"));

    return model;
}
QSqlQueryModel * RDV::tri_d()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv ORDER BY dater DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numrdv"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("idmedecin"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("salle"));

    return model;
}

//**************************************************************************
salle::salle()
{

}
salle::salle(QString num ,QString localisation,int capacite)
{
    this->num=num;
    this->localisation=localisation;
    this->capacite=capacite;
}
bool salle::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO salle (num,localisation,capacite) "
                        "VALUES (:nu , :l , :c )");
    query.bindValue(":nu", num);
    query.bindValue(":d", localisation);
    query.bindValue(":c", capacite);
    return query.exec();
}
QSqlQueryModel * salle::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from salle");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num salle"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("localisation"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));

    return model;
}
bool salle::supprimer(QString num)
{
QSqlQuery query;

query.prepare("Delete from salle where num = :nu ");
query.bindValue(":nu", num);
return    query.exec();
}

QSqlQueryModel * salle::recherche(QString valeur )
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
query.prepare("SELECT * FROM salle WHERE num like :valeur order by num ");
 valeur="%"+valeur+"%";
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("num salle"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("localisation"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
 return  model;
}
QSqlQueryModel * salle::tri_c()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from salle ORDER BY capacite ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num salle"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("localisation"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));

    return model;
}
QSqlQueryModel * salle::tri_d()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from salle ORDER BY capacite DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num salle"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("localisation"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));

    return model;
}
bool salle::modifier()
{
    QSqlQuery query;
    query.prepare("update salle set localisation = :d ,capacite = :c  where num = :nu");
    query.bindValue(":nu", num);
    query.bindValue(":d", localisation);
    query.bindValue(":c", capacite);
    return query.exec();
}
//*********************************************************


RADIO::RADIO()
{

}
RADIO::RADIO(QString nom ,QString prenom ,QDateTime dater ,QString code ,QString numr,QString mail)
{
    this->nom=nom;
    this->prenom=prenom;
    this->dater=dater;

    this->code=code;

    this->numr=numr;
    this->mail=mail;
}
bool RADIO::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RADIO (numr,dater,nom,prenom,code,mail) "
                        "VALUES (:nu , :d , :n , :p , :co , :m )");
    query.bindValue(":nu", numr);
    query.bindValue(":d", dater);
    query.bindValue(":n", nom);
    query.bindValue(":p", prenom);

    query.bindValue(":co", code);
    query.bindValue(":m", mail);

    return query.exec();
}
QSqlQueryModel * RADIO::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RADIO");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num RADIO"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

    return model;
}
bool RADIO::supprimer(QString numr)
{
QSqlQuery query;

query.prepare("Delete from RADIO where numr = :nu ");
query.bindValue(":nu", numr);
return    query.exec();
}

QSqlQueryModel * RADIO::recherche(QString valeur )
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
query.prepare("SELECT * FROM RADIO WHERE nom like :valeur order by nom ");
 valeur="%"+valeur+"%";
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("num RADIO"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

 model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

 return  model;
}
QSqlQueryModel * RADIO::tri_c()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RADIO ORDER BY dater ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num RADIO"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

    return model;
}
QSqlQueryModel * RADIO::tri_d()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RADIO ORDER BY dater DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num RADIO"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

    return model;
}


bool RADIO::modifier()
{
    QSqlQuery query;
    query.prepare("update RADIO set dater = :d ,nom = :n ,prenom = :p  ,code = :code ,mail = :m    where numr = :nu");
    query.bindValue(":nu", numr);
    query.bindValue(":d", dater);
    query.bindValue(":n", nom);
    query.bindValue(":p", prenom);

    query.bindValue(":code", code);
    query.bindValue(":m", mail);
    return query.exec();
}
//******************************************************************


ANALYSE::ANALYSE()
{

}
ANALYSE::ANALYSE(QString nom ,QString prenom ,QDateTime dater ,QString code ,QString numr,QString mail)
{
    this->nom=nom;
    this->prenom=prenom;
    this->dater=dater;

    this->code=code;

    this->numr=numr;
    this->mail=mail;
}
bool ANALYSE::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO analyse (numr,dater,nom,prenom,code,mail) "
                        "VALUES (:nu , :d , :n , :p , :co , :m )");
    query.bindValue(":nu", numr);
    query.bindValue(":d", dater);
    query.bindValue(":n", nom);
    query.bindValue(":p", prenom);

    query.bindValue(":co", code);
    query.bindValue(":m", mail);

    return query.exec();
}
QSqlQueryModel * ANALYSE::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from analyse");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num analyse"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

    return model;
}
bool ANALYSE::supprimer(QString numr)
{
QSqlQuery query;

query.prepare("Delete from analyse where numr = :nu ");
query.bindValue(":nu", numr);
return    query.exec();
}
bool ANALYSE::modifier()
{
    QSqlQuery query;
    query.prepare("update ANALYSE set dater = :d ,nom = :n ,prenom = :p  ,code = :code ,mail = :m    where numr = :nu");
    query.bindValue(":nu", numr);
    query.bindValue(":d", dater);
    query.bindValue(":n", nom);
    query.bindValue(":p", prenom);

    query.bindValue(":code", code);
    query.bindValue(":m", mail);
    return query.exec();
}
QSqlQueryModel * ANALYSE::recherche(QString valeur )
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
query.prepare("SELECT * FROM analyse WHERE nom like :valeur order by nom ");
 valeur="%"+valeur+"%";
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("num analyse"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

 model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

 return  model;
}
QSqlQueryModel * ANALYSE::tri_c()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from analyse ORDER BY dater ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num analyse"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

    return model;
}
QSqlQueryModel * ANALYSE::tri_d()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from analyse ORDER BY dater DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num analyse"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

model->setHeaderData(4, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));

    return model;
}
//*******************************************************************
