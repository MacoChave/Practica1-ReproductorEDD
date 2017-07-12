#ifndef LSTCANCION_H
#define LSTCANCION_H

class NodoCancion
{
public:
    NodoCancion(char *cancion_, char *path_, float valoracion);
    char *cancion;
    char *path;
    float valoracion;
    NodoCancion *siguiente;
};

class LSTCancion
{
    void agregar(NodoCancion *actual, char *cancion, char *path, float valoracion);
    void eliminar(NodoCancion *actual, char *cancion);
public:
    LSTCancion();
    NodoCancion *primero;
    NodoCancion *ultimo;

    void add(char *cancion, char *path, float valoracion);
    void remove(char *cancion);
    void graph(char *album, char *artista);
    void clear();
};

#endif // LSTCANCION_H
