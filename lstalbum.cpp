#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "lstalbum.h"

LstAlbum::LstAlbum()
{
    primero = NULL;
    ultimo = NULL;
}

NodoAlbum::NodoAlbum(char *album_)
{
    album = new char[sizeof(album_) + 1];
    strcpy(album, album_);
    lista = new LSTCancion();
    anterior = NULL;
    siguiente = NULL;
}

void LstAlbum::agregar(NodoAlbum *actual, char *album, char *cancion, char *path, float valoracion)
{
    if (primero != NULL)
    {
        if (strcmp(primero->album, album) > 0)
        {
            /* INSERTAR EN CABEZA */
            NodoAlbum *nuevo = new NodoAlbum(album);
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;

            /* AGREGAR CANCION */
            primero->lista->add(cancion, path, valoracion);
        }
        else if (strcmp(ultimo->album, album) < 0)
        {
            /* INSERTAR AL FINAL */
            NodoAlbum *nuevo = new NodoAlbum(album);
            nuevo->anterior = ultimo;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;

            /* AGREGAR CANCION */
            ultimo->lista->add(cancion, path, valoracion);
        }
        else
        {
            if (strcmp(actual->album, album) > 0)
            {
                /* INSERTAR ANTES */
                NodoAlbum *nuevo = new NodoAlbum(album);
                nuevo->siguiente = actual;
                nuevo->anterior = actual->anterior;
                actual->anterior->siguiente = nuevo;
                actual->anterior = nuevo;

                /* AGREGAR CANCION */
                nuevo->lista->add(cancion, path, valoracion);
            }
            else if (strcmp(actual->album, album) < 0)
            {
                agregar(actual->siguiente, album, cancion, path, valoracion);
            }
            else
            {
                /* AGREGAR CANCION */
                actual->lista->add(cancion, path, valoracion);
            }
        }
    }
    else
    {
        primero = new NodoAlbum(album);
        ultimo = primero;
        primero->lista->add(cancion, path, valoracion);
    }
}

void LstAlbum::eliminar(NodoAlbum *actual, char *album, char *cancion)
{

}

void LstAlbum::graficar()
{

}

void LstAlbum::add(char *album, char *cancion, char *path, float valoracion)
{
    agregar(primero, album, cancion, path, valoracion);
}

void LstAlbum::remove(char *album, char *cancion)
{

}

void LstAlbum::graph(char *artista)
{
    NodoAlbum *tmp = primero;
    char dot[500];

    /* LISTAR ALBUM */
    sprintf(dot, "\tnd%s[label=\"", artista);
    while (tmp != NULL)
    {
        strcat(dot, "<");
        strcat(dot, tmp->album);
        strcat(dot, ">");
        strcat(dot, tmp->album);
        strcat(dot, " | ");
        tmp = tmp->siguiente;
    }
    strcat(dot, "\"]\n\n");
    strcat(dot, "\tnode0:");
    strcat(dot, artista);
    strcat(dot, " -> nd");
    strcat(dot, artista);
    strcat(dot, ";\n");

    FILE *archivo;
    archivo = fopen("/home/marco/Escritorio/btk.dot", "a");

    if (archivo != NULL)
    {
        fprintf(archivo, "%s", dot);
        fflush(archivo);
        fclose(archivo);
    }

    tmp = primero;
    /* LISTAR CANCIONES */
    while (tmp != NULL)
    {
        tmp->lista->graph(tmp->album, artista);
        tmp = tmp->siguiente;
    }
}

void LstAlbum::clear()
{

}
