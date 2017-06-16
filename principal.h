#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "lstartista.h"

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();
    QString lectura(QString filename);
    void separar(char* texto);
private slots:
    void on_actionAbrir_triggered();

    void on_actionBiblioteca_triggered();

private:
    Ui::Principal *ui;
    LSTArtista *lista;
};

#endif // PRINCIPAL_H
