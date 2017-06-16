#ifndef LSTARTISTA_H
#define LSTARTISTA_H

#include "lstalbum.h"

class NodoArtista
{
public:
    NodoArtista(char *artista_);

    char *artista;
    LstAlbum *lista;
    NodoArtista *anterior;
    NodoArtista *siguiente;
};

class LSTArtista
{
    void agregar(NodoArtista *actual, char* artista, char* album, char *cancion, char *path, float valoracion);
    void eliminar(NodoArtista *actual, char *artista, char *album, char *cancion);
    void graficar();
public:
    LSTArtista();
    NodoArtista *primero;
    NodoArtista *ultimo;

    void add(char* artista, char* album, char *cancion, char *path, float valoracion);
    void remove(char *artista, char *album, char *cancion);
    void graph();
    void clear();
};

#endif // LSTARTISTA_H
