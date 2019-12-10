#include "mainwindow.h"
#include <QApplication>
#include<QFile>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>

int main(int argc, char *argv[])
{  QApplication a(argc, argv);
    QApplication::setStyle("plastique");
    Connexion c;
    QFile File("C:/Users/dell/Documents/RS/Perstfic.qss");
    File.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(File.readAll());
    a.setStyleSheet(stylesheet);

  bool test=c.ouvrirConnexion();
  MainWindow w;
  if(test)
  {w.show();

      QMessageBox::information(nullptr, QObject::tr("database is  open"),
                  QObject::tr("connection avec succés.\n"
                              "Click OK to exit."), QMessageBox::Ok);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();}
