#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include "principal.h"
#include "ui_principal.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    lista = new LSTArtista();
}

Principal::~Principal()
{
    lista->clear();
    delete ui;
}

QString Principal::lectura(QString filename)
{
    QFile file(filename);

    if (!file.open(QFile::ReadOnly | QFile::Text))
        return NULL;
    else
    {
        QTextStream in (&file);
        QString texto = in.readAll();

        file.close();

        return texto;
    }
}

void Principal::separar(char* texto)
{
    bool fin = false;

    char *artista;
    char *album;
    char *cancion;
    char *path;
    float valoracion;

    artista = strtok(texto, "_\n");
    album = strtok(NULL, "_\n");
    cancion = strtok(NULL, "_\n");
    path = strtok(NULL, "_\n");
    valoracion = atof(strtok(NULL, "_\n"));

    lista->add(artista, album, cancion, path, valoracion);
    while (!fin)
    {
        artista = strtok(NULL, "_\n");

        if (strcmp(artista, "#") != 0)
        {
            album = strtok(NULL, "_\n");
            cancion = strtok(NULL, "_\n");
            path = strtok(NULL, "_\n");
            valoracion = atof(strtok(NULL, "_\n"));

            lista->add(artista, album, cancion, path, valoracion);
        }
        else
            fin = true;
    }
}

void Principal::on_actionAbrir_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Seleccionar archivo"),
                                                    "/home/marco/Escritorio/",
                                                    "Archivo de Texto(*.txt)");
    QString texto = lectura(filename);

    if (texto != NULL)
        separar(texto.toLatin1().data());
}

void Principal::on_actionBiblioteca_triggered()
{
    if (lista->primero != NULL)
        lista->graph();
}
