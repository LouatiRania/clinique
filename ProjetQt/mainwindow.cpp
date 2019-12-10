#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user = ui-> lineEdit->text();
        QString pass = ui-> lineEdit_2->text();
        QSqlQuery *query = new QSqlQuery();

        query->prepare("SELECT * FROM employe WHERE id= :id");
        query->bindValue(":id", user);
        query->exec();
       // qDebug() << query->lastError();
        int count = 0;
        while (query->next())
        {
            count++;
        }
        if (count == 0)
        {
            QMessageBox::warning(this,"Authentification","Ce compte n'existe pas");
            return;
        }

        query->first();

        QString registered_pass = query->value(1).toString();
        QString role = query->value(2).toString();
       // qDebug() << "Registerd pass" << registered_pass;
        if (registered_pass != pass)
        {
            QMessageBox::warning(this,"Authentification","Mot de passe incorrecte");
            return;
        }

        if((pass==registered_pass)&&(role=="labo")) {
            SecDialog = new anarad(this);
           // hide();
            SecDialog->show();}
      else if((pass==registered_pass)&&(role=="secretaire")) {
            Sec = new rdvsa(this);
           // hide();
            Sec->show();}
        else if((pass==registered_pass)&&(role=="pharmacien"))  {
            g = new GererMed(this);
           // hide();
            g->show();
        }
            else if((pass==registered_pass)&&(role=="admin"))  {
                r = new rania(this);
               // hide();
                r->show();}
                else if((pass==registered_pass)&&(role=="docteur"))  {
                    s = new sarra(this);
                   // hide();
                    s->show();
        }
}
