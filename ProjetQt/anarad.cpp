#include "anarad.h"
#include "ui_anarad.h"

#include<QMessageBox>
anarad::anarad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::anarad)
{
    ui->setupUi(this);
    music->setMedia(QUrl("C:/Users/dell/Desktop/nouveau dossier/True Detective - Intro Opening Song - Theme (The Handsome Family - Far From Any Road) + LYRICS.mp3"));

    ui->comboBox->addItem("afficher");
    ui->comboBox->addItem("trier date ordre croissant");
     ui->comboBox->addItem("trier date ordre decroissant");
     ui->comboBox_2->addItem("afficher");
     ui->comboBox_2->addItem("trier capacite ordre croissant");
      ui->comboBox_2->addItem("trier date capacite decroissant");
    ui->tableView->setModel(tmprdv.afficher());
    ui->tableView_5->setModel(tmprdv.afficher());
    ui->tableView_2->setModel(tmps.afficher());
    ui->tableView_6->setModel(tmps.afficher());
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));


}

anarad::~anarad()
{
    delete ui;
}

void anarad::on_pushButton_clicked()
{
    QString nom = ui->nom->text();
    QString prenom= ui->prenom->text();
    QDateTime dater=ui->date->dateTime();

    QString code= ui->cin->text();

    QString mail= ui->mail->text();
    QString numr= ui->numr->text();

        ANALYSE r(nom , prenom ,dater  ,code ,numr,mail);
        bool test=r.ajouter ();
        if(test)
      {ui->tableView->setModel(tmprdv.afficher());//refresh
             ui->tableView_5->setModel(tmprdv.afficher());
      QMessageBox::information(nullptr, QObject::tr("Ajouter un avion"),
                        QObject::tr("avion ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un avion"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }


void anarad::on_comboBox_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->tableView->setModel(tmprdv.afficher());
    }
    if(index==1)
    {
        ui->tableView->setModel(tmprdv.tri_c());
    }
    if(index==2)
    {
        ui->tableView->setModel(tmprdv.tri_d());
    }
}

void anarad::on_pushButton_2_clicked()
{
    QString numr = ui->sup->text();
    bool test=tmprdv.supprimer(numr);
    if(test)
    {ui->tableView->setModel(tmprdv.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un ANALYSE"),
                    QObject::tr("rendez vous supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un ANALYSE"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void anarad::on_pushButton_3_clicked()
{
    QString nom = ui->nom_6->text();
    QString prenom= ui->prenom_6->text();
    QDateTime dater=ui->date_6->dateTime();

    QString code= ui->cin_6->text();

    QString mail= ui->mail_6->text();
    QString numr= ui->numr_6->text();

        ANALYSE r(nom , prenom ,dater  ,code ,numr,mail);
    bool test=r.modifier ();
    if(test)
  {ui->tableView_2->setModel(tmps.afficher());//refresh
         ui->tableView_6->setModel(tmps.afficher());
  QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                    QObject::tr("salle ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
void anarad::on_lineEdit_textChanged(const QString &arg1)
{

     ui->tableView_5->setModel(tmprdv.recherche(arg1));
}

void anarad::sendMail()
{
    Smtp* smtp = new Smtp("ahmed.kridiss@esprit.tn","181JMT1540", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("ahmed.kridiss@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void anarad::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void anarad::on_comboBox_2_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->tableView_2->setModel(tmps.afficher());
    }
    if(index==1)
    {
        ui->tableView_2->setModel(tmps.tri_c());
    }
    if(index==2)
    {
        ui->tableView_2->setModel(tmps.tri_d());
    }
}

void anarad::on_pushButton_4_clicked()
{
    QString nom = ui->nom_4->text();
    QString prenom= ui->prenom_4->text();
    QDateTime dater=ui->date_4->dateTime();

    QString code= ui->cin_4->text();

    QString mail= ui->mail_4->text();
    QString numr= ui->numr_4->text();

        RADIO r(nom , prenom ,dater  ,code ,numr,mail);
    bool test=r.ajouter ();
    if(test)
  {ui->tableView_2->setModel(tmps.afficher());//refresh
         ui->tableView_6->setModel(tmps.afficher());
  QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                    QObject::tr("salle ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void anarad::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView_6->setModel(tmps.recherche(arg1));
}

void anarad::on_pushButton_5_clicked()
{
    QString numr = ui->sup_2->text();
    bool test=tmps.supprimer(numr);
    if(test)
    {ui->tableView_2->setModel(tmps.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("salle supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void anarad::on_pushButton_6_clicked()
{
    QString nom = ui->nom_5->text();
    QString prenom= ui->prenom_5->text();
    QDateTime dater=ui->date_4->dateTime();

    QString code= ui->cin_5->text();

    QString mail= ui->mail_5->text();
    QString numr= ui->numr_5->text();

        RADIO s(nom , prenom ,dater  ,code ,numr,mail);
    bool test=s.modifier ();
    if(test)
  {ui->tableView_2->setModel(tmps.afficher());//refresh
         ui->tableView_6->setModel(tmps.afficher());
  QMessageBox::information(nullptr, QObject::tr("modifier une salle"),
                    QObject::tr("salle modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void anarad::on_pushButton_7_clicked()
{
    music->play();
}

void anarad::on_pushButton_8_clicked()
{
    music->pause();
}

void anarad::on_verticalSlider_sliderMoved(int position)
{
    music->setVolume(position);
}
