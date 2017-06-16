#ifndef LSTALBUM_H
#define LSTALBUM_H

class NodoAlbum
{
public:
    NodoAlbum(char* album_);

    char *album;
    NodoAlbum *siguiente;
    NodoAlbum *anterior;
};

class LstAlbum
{
    void agregar(NodoAlbum *actual, char *album, char *cancion, char *path, float valoracion);
    void eliminar(NodoAlbum *actual, char *album, char *cancion);
    void graficar();
public:
    LstAlbum();
    NodoAlbum *primero;
    NodoAlbum *ultimo;

    void add(char *album, char *cancion, char *path, float valoracion);
    void remove(char *album, char* cancion);
    void graph(char *artista);
    void clear();
};

#endif // LSTALBUM_H
