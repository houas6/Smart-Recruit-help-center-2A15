#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QtSql/QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

ui->tableView_2->setModel(Etmp.afficher());
ui->lineEdit_cin->setValidator( new QIntValidator(0, 99999999, this) );
ui->lineEdit_age->setValidator( new QIntValidator(0, 99, this) );
ui->lineEdit_tel->setValidator( new QIntValidator(0, 99999999, this) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    //recuperation des info dans les 7 champs
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    int age=ui->lineEdit_age->text().toInt();
    int tel=ui->lineEdit_tel->text().toInt();
    QString adresse=ui->lineEdit_adresse->text();
    QString departement=ui->lineEdit_departement->text();
    Employes E(cin,nom,prenom,age, tel, adresse, departement);
    bool test=E.ajouter();//inserer employé e dans la table
    if (test)
    {
ui->tableView_2->setModel(E.afficher());

        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectué \n"
                                             "Click Cancel to exist ."),QMessageBox::Cancel);

    }
    else
          QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                      QObject::tr("connection failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);




}


void MainWindow::on_pushButton_supprimer_clicked()
{
    //recuperation du cin
    int cin=ui->lineEdit_cin->text().toInt();Employes E1;
    bool test=E1.supprimer(cin);

    if (test)
    {
  ui->tableView_2->setModel(E1.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n"
                                             "Click Cancel to exist ."),QMessageBox::Cancel);

    }
    else
          QMessageBox::critical(nullptr, QObject::tr("no"),
                      QObject::tr("Suppression failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();Employes E1;
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    int age=ui->lineEdit_age->text().toInt();
    int tel=ui->lineEdit_tel->text().toInt();
    QString adresse=ui->lineEdit_adresse->text();
    QString departement=ui->lineEdit_departement->text();
    Employes E(cin,nom,prenom,age, tel, adresse, departement);
    bool test=E.modifier(cin,nom,prenom,age,tel,adresse,departement);//modifier employe
    if (test)
    {

ui->tableView_2->setModel(E1.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("Modification effectué \n"
                                             "Click Cancel to exist ."),QMessageBox::Cancel);

    }
    else
          QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                      QObject::tr("Modification failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButton_trie_clicked()
{

         Employes E;
         QString choix=ui->comboBox_tri->currentText();
         if (choix=="Nom")
         {
             ui->tableView_2->setModel(E.trie_NOM());
             ui->tableView_2->setModel(E.afficher());
             bool test=E.trie_NOM();//tri Nom
             if (test)
             {

         ui->tableView_2->setModel(E.trie_NOM());
                 QMessageBox::information(nullptr,QObject::tr("ok"),
                                          QObject::tr("tri Nom effectué \n"
                                                      "Click Cancel to exist ."),QMessageBox::Cancel);

             }
             else
                   QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                               QObject::tr("tri Nom failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
         }
         if (choix=="Prenom")
         {
             ui->tableView_2->setModel(E.trie_PRENOM());
             ui->tableView_2->setModel(E.afficher());
             bool test=E.trie_PRENOM();//tri prenom
             if (test)
             {

         ui->tableView_2->setModel(E.trie_PRENOM());
                 QMessageBox::information(nullptr,QObject::tr("ok"),
                                          QObject::tr("tri prenom effectué \n"
                                                      "Click Cancel to exist ."),QMessageBox::Cancel);

             }
             else
                   QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                               QObject::tr("tri prenom failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
         }
         if (choix=="Departement")
         {
             ui->tableView_2->setModel(E.trie_DEPARTEMENT());
             ui->tableView_2->setModel(E.afficher());
             bool test=E.trie_DEPARTEMENT();//tri produit
             if (test)
             {

         ui->tableView_2->setModel(E.trie_DEPARTEMENT());
                 QMessageBox::information(nullptr,QObject::tr("ok"),
                                          QObject::tr("tri departement effectué \n"
                                                      "Click Cancel to exist ."),QMessageBox::Cancel);

             }
             else
                   QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                               QObject::tr("tri departement failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
         }

    }


void MainWindow::on_pushButton_Recherche_clicked()
{

    int cin=ui->lineEdit_cin2->text().toInt();Employes E;

    bool test=E.rech(cin);


    if (test)
    {

ui->tableView_3->setModel(E.rech(cin));


        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("recherche effectué \n"
                                             "Click Cancel to exist ."),QMessageBox::Cancel);
ui->tableView_3->setModel(E.afficher());

    }
    else
          QMessageBox::critical(nullptr, QObject::tr("no"),
                      QObject::tr("recherche failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}

