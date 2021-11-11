#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "collaboration.h"
#include <QtDebug>
#include <QMessageBox>
#include <QTableView>
#include <QAbstractItemView>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tabb.afficher());
    ui->id->setValidator(new QIntValidator(0,99,this));
        ui->id_supp->setValidator(new QIntValidator(0,99,this));
    ui->num->setValidator(new QIntValidator(00000000,99999999,this));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    int id=ui->id->text().toInt();
    QString nom =ui->nom->text();
    QString adresse=ui->adresse->text();
    QString mail=ui->mail->text();
    int num =ui->num->text().toInt();
    //
    Collaboration c(nom,adresse,mail,num,id);
    //
    bool test=c.ajouter ();
    if (test)
    {
           ui->tableView->setModel(tabb.afficher());
        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("Ajout effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);

}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("try again.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
    }
}





void MainWindow::on_Supprimer_clicked()
{
    int id =ui->id_supp->text().toInt();
     bool test=tabb.supprimer(id);
     if (test)
     {
         ui->tableView->setModel(tabb.afficher());
        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                      QObject ::tr("suppression effectué\n"
                                   "click cancel to exit"),
                 QMessageBox:: Cancel);

    }
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("try again.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);
     }
}

void MainWindow::on_Modifier_clicked()
{
    int id=ui->id_supp->text().toInt();
    QString nom =ui->nom_2->text();
    QString adresse=ui->adresse_2->text();
    QString mail=ui->mail_2->text();
    int num=ui->num_2->text().toInt();
       Collaboration c(nom,adresse,mail,num,id);
        bool test=c.modifier(id);
        if (test)
        {
               ui->tableView->setModel(tabb.afficher());
            QMessageBox :: information (nullptr, QObject ::tr("OK"),
                         QObject ::tr("modifier effectué\n"
                                      "click cancel to exit"),
                    QMessageBox:: Cancel);

    }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                 QObject::tr("try again.\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_2_clicked()
{
        ui->tableView->setModel(tabb.tri());
}

void MainWindow::on_tri_name_clicked()
{
    ui->tableView->setModel(tabb.trinom());
}
