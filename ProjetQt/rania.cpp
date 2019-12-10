#include "rania.h"
#include "ui_rania.h"
#include "reservation.h"
#include "convention.h"
#include <QMessageBox>
#include "QIntValidator"
#include "QValidator"
#include <QRegExpValidator>
#include "QDebug"

rania::rania(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rania)
{
    ui->setupUi(this);
    connect(ui->Envoyer_, SIGNAL(clicked()),this, SLOT(sendMail()));

    ui->mainwidget->setCurrentIndex(0);
      ui->stackedWidget->setCurrentIndex(0);
    reservation r;
    Convention c;
    ui->tableView_Consultation->setModel(c.afficher());
    ui->tableView_affichage->setModel(r.afficher());
    ui->input_CIN->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),ui->input_CIN));
     ui->input_consultation->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),ui->input_consultation));
     ui->input_nuit->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),ui->input_nuit));
     QPixmap fond(":images/fond.jpg");
        ui->fond->setPixmap(fond);
        ui->comboBox_convention->addItem("Pas de Convention");
        QSqlQuery query;
        if(query.exec("select NOMSOCIETE from convention"))
            {
                //int count = 0;
                while (query.next())
                {
                   // count++;
                    ui->comboBox_convention->addItem(query.value(0).toString());
                }
            }
}

rania::~rania()
{
    delete ui;
}
void rania::sendMail()
{
    Smtp* smtp = new Smtp("ahmed.kridiss@esprit.tn","181JMT1540", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("clinique esprit", ui->lineEdit_Email_->text() , ui->subject->text(),ui->msg->toPlainText());

}

void rania::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void rania::on_ajout_clicked()
{
    ui->mainwidget->setCurrentIndex(1);

}

void rania::on_afficher_clicked()
{
    ui->mainwidget->setCurrentIndex(2);
    reservation r;
    ui->tableView_affichage->setModel(r.afficher());
}

void rania::on_supprimer_clicked()
{
    ui->mainwidget->setCurrentIndex(3);
}
void rania::on_modifier_clicked()
{
    ui->mainwidget->setCurrentIndex(4);
}

void rania::on_confirmer_ajout_clicked()
{
    QString nom=ui->input_nom->text();
    QString prenom=ui->input_prenom->text();
    QString consultation=ui->input_consultation->text();
    int nuit=ui->input_nuit->text().toInt();
    QString CIN=ui->input_CIN->text();
    QString convention=ui->comboBox_convention->currentText();
    QSqlQuery query;
    QVector<int> tab;
    if(query.exec("select CIN from reservation"))
        {
            while (query.next())
            {
                tab.push_back(query.value(0).toInt());

            }

        }
    if (tab.size()!=0)
    {
        QMessageBox msg;
        msg.setText("Une reservation avec ce CIN existe deja ");
        msg.exec();
    }
    else
    {
    reservation r(CIN,nom,consultation,nuit,prenom,convention);

    if(r.ajouter())
    {
        QMessageBox msg;
        msg.setText("Ajout avec succes");
        msg.exec();

    }
    else {
        QMessageBox msg;
        msg.setText("Le patient existe deja !");
        msg.exec();
    }
    }

}

void rania::on_confirmer_supp_clicked()
{
    reservation r;
    QString CIN=ui->lineEdit_supp->text();

   // bool found=r.ChercherCIN(CIN);
    if(!r.ChercherCIN(CIN))
    {
        QMessageBox msg;
        msg.setText("Le patient n'existe pas !");
        msg.exec();
    }
    else {
        if(r.supprimer(CIN))
        {
            QMessageBox msg;
            msg.setText("Suppression avec succes");
            msg.exec();
        }
        else {
            QMessageBox msg;
            msg.setText("Erreur de supression");
            msg.exec();
        }
    }

}

void rania::on_lineEdit_search_textChanged(const QString &arg1)
{
    reservation r;
    QString nom=ui->lineEdit_search->text();
    ui->tableView_affichage->setModel(r.rechercher(nom));


}

void rania::on_pushButton_modifier_clicked()
{
    reservation r;
    QString val=ui->lineEdit_newval->text();
    QString cin=ui->lineEdit_modifier->text();
    if(ui->radioButton_nom->isChecked())
    {
       if(r.modifierNom(val,cin))
       {
           QMessageBox msg;
           msg.setText("Modification de nom avec success");
           msg.exec();
       }
    }
    if(ui->radioButton_prenom->isChecked())
    {
       if(r.modifierPrenom(val,cin))
       {
           QMessageBox msg;
           msg.setText("Modification de nom avec success");
           msg.exec();
       }
    }
    if(ui->radioButton_cin->isChecked())
    {
       if(r.modifierCIN(val,cin))
       {
           QMessageBox msg;
           msg.setText("Modification de nom avec success");
           msg.exec();
       }
    }
    if(ui->radioButton_nuit->isChecked())
    {
       if(r.modifierNuit(val,cin))
       {
           QMessageBox msg;
           msg.setText("Modification de nom avec success");
           msg.exec();
       }
    }
    if(ui->radioButton_consultation->isChecked())
    {
       if(r.modifierConsultation(val,cin))
       {
           QMessageBox msg;
           msg.setText("Modification de nom avec success");
           msg.exec();
       }
    }

}

void rania::on_radioButton_nom_clicked()
{
   // ui->radioButton_nom->setChecked(false);
    ui->radioButton_prenom->setChecked(false);
    ui->radioButton_cin->setChecked(false);
    ui->radioButton_nuit->setChecked(false);
    ui->radioButton_consultation->setChecked(false);

}

void rania::on_radioButton_prenom_clicked()
{
    ui->radioButton_nom->setChecked(false);
   // ui->radioButton_prenom->setChecked(false);
    ui->radioButton_cin->setChecked(false);
    ui->radioButton_nuit->setChecked(false);
    ui->radioButton_consultation->setChecked(false);


}





void rania::on_radioButton_cin_clicked()
{
    ui->radioButton_nom->setChecked(false);
    ui->radioButton_prenom->setChecked(false);
    //ui->radioButton_cin->setChecked(false);
    ui->radioButton_nuit->setChecked(false);
    ui->radioButton_consultation->setChecked(false);

}

void rania::on_radioButton_consultation_clicked()
{
    ui->radioButton_nom->setChecked(false);
    ui->radioButton_prenom->setChecked(false);
    ui->radioButton_cin->setChecked(false);
    ui->radioButton_nuit->setChecked(false);
    //ui->radioButton_consultation->setChecked(false);

}

void rania::on_radioButton_nuit_clicked()
{
    ui->radioButton_nom->setChecked(false);
    ui->radioButton_prenom->setChecked(false);
    ui->radioButton_cin->setChecked(false);
    //ui->radioButton_nuit->setChecked(false);
    ui->radioButton_consultation->setChecked(false);

}

void rania::on_pushButton_sort_clicked()
{
    reservation r;
    ui->tableView_affichage->setModel(r.triConsultation());
}

void rania::on_pushButton_convention_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QPixmap fond(":images/aaa.jpg");
       ui->fond->setPixmap(fond);
}

void rania::on_pushButton_Reservation_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
      QPixmap fond(":images/bbb.jpg");
         ui->fond->setPixmap(fond);
}

void rania::on_pushButton_clicked()
{
    float remise=ui->lineEdit_Remise->text().toFloat();
    QString nom=ui->lineEdit_NomSociete->text();
    QVector <int> tab;
    int id=-1;
    int i;
    QSqlQuery query;
    if(query.exec("select id from convention"))
        {
            while (query.next())
            {
                tab.push_back(query.value(0).toInt());

            }

        }
        //sort(tab.begin(),tab.end());
    int aux;
    for(i=0;i<tab.size();i++)
    {
        for(int j=0;i<tab.size()-1;i++)
        {
            if(tab[i]>tab[i+1])
            {
                aux=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=aux;
            }
        }
    }
    for(i=0;i<tab.size();i++)
    {
       qDebug()<<tab[i];
    }
        if(tab.size()==0)
        {
            id=1;
        }
        else if(tab[0]!=1)
        { id=1;}
        else if(tab.size()==1)
        {
            id=2;
        }

        else
        {

            for(i=1;i<tab.size();i++)
        {

            if (tab[i]-tab[i-1]>1)
            {
                id=tab[i-1]+1;
                break;
            }
        }
        }
        if (id==-1)
        {
            id=tab.size()+1;
        }

        Convention c(id,nom,remise);
        qDebug()<<id;
        qDebug()<<nom;
        qDebug()<<remise;
        if(c.ajouter())
        {
            QMessageBox msg;
            msg.setText("Ajout avec succes");
            msg.exec();
        }
        else {
            QMessageBox msg;
            msg.setText("La convention existe deja !");
            msg.exec();
        }

}

void rania::on_pushButton_ajoutConsultation_clicked()
{
    ui->stackedWidget_Consultation->setCurrentIndex(1);
}

void rania::on_pushButton_afficherConsultation_clicked()
{
    Convention c;
    ui->stackedWidget_Consultation->setCurrentIndex(2);
    ui->tableView_Consultation->setModel(c.afficher());
}

void rania::on_pushButton_SupprimerConsultation_clicked()
{
    ui->stackedWidget_Consultation->setCurrentIndex(3);
}

void rania::on_pushButton_Supp_clicked()
{
    Convention c;
    int id=ui->lineEdit_suppConsultation->text().toInt();

   // bool found=r.ChercherCIN(CIN);
    if(!c.ChercherID(id))
    {
        QMessageBox msg;
        msg.setText("Le patient n'existe pas !");
        msg.exec();
    }
    else {
        if(c.supprimer(id))
        {
            QMessageBox msg;
            msg.setText("Suppression avec succes");
            msg.exec();
        }
        else {
            QMessageBox msg;
            msg.setText("Erreur de supression");
            msg.exec();
        }
    }
}

void rania::on_pushButton_ModifierConsultation_clicked()
{
    ui->stackedWidget_Consultation->setCurrentIndex(4);
}

void rania::on_radioButton_nomSociete_clicked()
{
    ui->radioButton_consultation->setChecked(false);
}

void rania::on_radioButton_remise_clicked()
{
    ui->radioButton_nomSociete->setChecked(false);

}

void rania::on_pushButton_ModifierConsultation_2_clicked()
{
    Convention c;
    int id=ui->lineEdit_idconsultation->text().toInt();
    if(ui->radioButton_nomSociete->isChecked())
    {
        QString nom=ui->lineEdit_valConsultation->text();

        if(c.modifierNom(id,nom))
        {
            QMessageBox msg;
            msg.setText("Modification de nom avec success");
            msg.exec();
        }
        else {
            QMessageBox msg;
            msg.setText("Modification de nom avec erreur");
            msg.exec();
        }

    }
    else {
        float remise=ui->lineEdit_valConsultation->text().toFloat();
        if(c.modifierRemise(id,remise))
        {
            QMessageBox msg;
            msg.setText("Modification de remise avec success");
            msg.exec();
        }
        else {
            QMessageBox msg;
            msg.setText("Modification de remise avec erreur");
            msg.exec();
        }
    }
}

void rania::on_modifier_2_clicked()
{
    ui->mainwidget->setCurrentIndex(5);
}




