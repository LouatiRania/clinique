#include "rdvsa.h"
#include "ui_rdvsa.h"

rdvsa::rdvsa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rdvsa)
{
    ui->setupUi(this);
    music->setMedia(QUrl("C:/Users/dell/Desktop/nouveau dossier/True Detective - Intro Opening Song - Theme (The Handsome Family - Far From Any Road) + LYRICS.mp3"));
    rdvsa::makePlot();
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

rdvsa::~rdvsa()
{
    delete ui;
}
void rdvsa::makePlot()
{    QSqlQuery qry;
     int t120=0;
      int t220=0;
       int t320=0;
        int t119=0;
        int t219=0;
        int t319=0;
         int t118=0;
        int t218=0;
        int t318=0;
         int t117=0;
        int t217=0;
        int t317=0;

     qry.prepare("select * from rdv where dater >= '01-JAN-20' and dater <  '01-DEC-20'");
     if (qry.exec())
     {
         while (qry.next())
         {
           if(qry.value(4)=="1") t120++;
           else if(qry.value(4)=="2") t220++;
           else if(qry.value(4)=="3") t320++;
       }
     }
     qry.prepare("select * from rdv where dater >= '01-JAN-19' and dater <  '01-DEC-19'");
     if (qry.exec())
     {
         while (qry.next())
         {
           if(qry.value(4)=="1") t119++;
           else if(qry.value(4)=="2") t219++;
           else if(qry.value(4)=="3") t319++;
       }
     }
     qry.prepare("select * from rdv where dater >= '01-JAN-18' and dater <  '01-DEC-18'");
     if (qry.exec())
     {
         while (qry.next())
         {
           if(qry.value(4)=="1") t118++;
           else if(qry.value(4)=="2") t218++;
           else if(qry.value(4)=="3") t318++;
       }
     }
     qry.prepare("select * from rdv where dater >= '01-JAN-17' and dater <  '01-DEC-17'");
     if (qry.exec())
     {
         while (qry.next())
         {
           if(qry.value(4)=="1") t117++;
           else if(qry.value(4)=="2") t217++;
           else if(qry.value(4)=="3") t317++;
       }
     }
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *m3= new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *m2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *m1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    m3->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    m2->setAntialiased(false);
    m1->setAntialiased(false);
    m3->setStackingGap(1);
    m2->setStackingGap(1);
    m1->setStackingGap(1);
    // set names and colors:
    m1->setName("medecin 1 ");
    m1->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    m1->setBrush(QColor(111, 9, 176));
    m2->setName("medecin 2 ");
    m2->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    m2->setBrush(QColor(250, 170, 20));
    m3->setName("medecin 3 ");
    m3->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    m3->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    m2->moveAbove(m1);
    m3->moveAbove(m2);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 ;
    labels << "2020" << "2019" << "2018" << "2017" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 5);
    ui->customPlot->yAxis->setPadding(30); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Nombre de rendez vous par medecin et annee");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> m1data, m2data, m3data;
    m1data  << t120 << t119<< t118 <<t117  ;
    m2data << t220 << t219 << t218 << t217 ;
    m3data   << t320 << t319 << t217 << t317 ;
    m1->setData(ticks, m1data);
    m2->setData(ticks, m2data);
    m3->setData(ticks, m3data);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
void rdvsa::on_pushButton_clicked()
{   ui->e1->setText("");
    QString nom = ui->nom->text();
    QString prenom= ui->prenom->text();
    QDateTime dater=ui->date->dateTime();
    QString idmedecin= ui->medecin->text();
    QString cin= ui->cin->text();
    QString salle= ui->salle->text();
    QString mail= ui->mail->text();
    QString numr= ui->numr->text();
    if(nom.isEmpty())
    {
        ui->e1->setText("please enter a valid name ");
    }
    else {
        RDV r(nom , prenom ,dater ,idmedecin ,cin ,salle ,numr,mail);
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
    }


void rdvsa::on_comboBox_currentIndexChanged(int index)
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

void rdvsa::on_pushButton_2_clicked()
{
    QString numr = ui->sup->text();
    bool test=tmprdv.supprimer(numr);
    if(test)
    {ui->tableView->setModel(tmprdv.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un rdv"),
                    QObject::tr("rendez vous supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un rdv"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void rdvsa::on_pushButton_3_clicked()
{
    /*modifier m ;
    m.setModal(true);
    m.exec();
    QString x = ui->mod->text();
    RDV r=m.on_buttonBox_accepted();
    bool test=r.modifier(x);
    if(test)
    {ui->tableView->setModel(tmprdv.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un rdv"),
                    QObject::tr("rendez vous trouvé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("!!!!!!!!!!!"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/


}
void rdvsa::on_lineEdit_textChanged(const QString &arg1)
{

     ui->tableView_5->setModel(tmprdv.recherche(arg1));
}

void rdvsa::sendMail()
{
    Smtp* smtp = new Smtp("ahmed.kridiss@esprit.tn","181JMT1540", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("clinique esprit", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());

}

void rdvsa::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void rdvsa::on_comboBox_2_currentIndexChanged(int index)
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

void rdvsa::on_pushButton_4_clicked()
{
    QString num = ui->nums->text();
    QString localisation= ui->locs->text();

    int capacite= ui->caps->text().toInt();

    salle s(num , localisation ,capacite );
    bool test=s.ajouter ();
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

void rdvsa::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView_6->setModel(tmps.recherche(arg1));
}

void rdvsa::on_pushButton_5_clicked()
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

void rdvsa::on_pushButton_6_clicked()
{
    QString num = ui->mod_2->text();
    QString localisation= ui->mod_3->text();

    int capacite= ui->mod_4->text().toInt();

    salle s(num , localisation ,capacite );
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

void rdvsa::on_pushButton_7_clicked()
{
    music->play();
}

void rdvsa::on_pushButton_8_clicked()
{
    music->pause();
}

void rdvsa::on_verticalSlider_sliderMoved(int position)
{
    music->setVolume(position);
}
