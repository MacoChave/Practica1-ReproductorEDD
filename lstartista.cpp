#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "lstartista.h"

NodoArtista::NodoArtista(char *artista_)
{
    artista = new char[sizeof(artista_) + 1];
    strcpy(artista, artista_);
    anterior = NULL;
    siguiente = NULL;
}

LSTArtista::LSTArtista()
{
    primero = NULL;
    ultimo = NULL;
}

void LSTArtista::agregar(NodoArtista *actual, char *artista, char *album, char *cancion, char *path, float valoracion)
{
    if (primero != NULL)
    {
        if (strcmp(primero->artista, artista) > 0)
        {
            /* INSERTAR EN CABEZA */
            NodoArtista *nuevo = new NodoArtista(artista);
            nuevo->siguiente = primero;
            nuevo->anterior = ultimo;
            primero->anterior = nuevo;
            ultimo->siguiente = nuevo;
            primero = nuevo;

            /* AGREGAR ALBUM */
        }
        else if (strcmp(ultimo->artista, artista) < 0)
        {
            /* INSERTAR AL FINAL */
            NodoArtista *nuevo = new NodoArtista(artista);
            nuevo->siguiente = primero;
            nuevo->anterior = ultimo;
            primero->anterior = nuevo;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;

            /* AGREGAR ALBUM */
        }
        else
        {
            if (strcmp(actual->artista, artista) > 0)
            {
                /* INSERTAR ANTES */
                NodoArtista *nuevo = new NodoArtista(artista);
                nuevo->siguiente = actual;
                nuevo->anterior = actual->anterior;
                actual->anterior->siguiente = nuevo;
                actual->anterior = nuevo;

                /* AGREGAR ALBUM */
            }
            else if (strcmp(actual->artista, artista) < 0)
            {
                agregar(actual->siguiente, artista, album, cancion, path, valoracion);
            }
            else
            {
                /* AGREGAR ALBUM */
            }
        }
    }
    else
    {
        primero = new NodoArtista(artista);
        primero->anterior = primero;
        primero->siguiente = primero;
        ultimo = primero;
    }
}

void LSTArtista::eliminar(NodoArtista *actual, char *artista, char *album, char *cancion)
{

}

void LSTArtista::graficar(int contador)
{
    NodoArtista *tmp = primero;

    char dot[256];
    sprintf(dot, "node%d[label=\"", contador);
    while (tmp != ultimo)
    {
        strcat(dot, "<");
        strcat(dot, tmp->artista);
        strcat(dot, ">");
        strcat(dot, tmp->artista);
        strcat(dot, " | ");
        tmp = tmp->siguiente;
    }
    strcat(dot, "<");
    strcat(dot, tmp->artista);
    strcat(dot, ">");
    strcat(dot, tmp->artista);
    strcat(dot, "\"]\n");

    FILE *archivo;
    archivo = fopen("/home/marco/Escritorio/btk.dot", "a");

    if (archivo != NULL)
    {
        fprintf(archivo, "%s", dot);
        fflush(archivo);
        fclose(archivo);
    }
}

void LSTArtista::add(char *artista, char *album, char *cancion, char *path, float valoracion)
{
    agregar(primero, artista, album, cancion, path, valoracion);
}

void LSTArtista::remove(char *artista, char *album, char *cancion)
{

}

void LSTArtista::clear()
{
    if (primero != NULL)
    {
        ultimo->siguiente = NULL;
        primero->anterior = NULL;

        NodoArtista *tmp = primero;
        while(primero != NULL)
        {
            primero = primero->siguiente;
            delete(tmp);
        }
        primero = NULL;
        ultimo = NULL;
    }
}

void LSTArtista::graph()
{
    char dot[128];
    strcpy(dot, "digraph btk {\n");
    strcat(dot, "\tnodesep=.05;\n");
    strcat(dot, "\trankdir=TD;\n");
    strcat(dot, "\tnode [shape=record,width=1.5,height=.5];\n");

    FILE *archivo;
    archivo = fopen("/home/marco/Escritorio/btk.dot", "w");

    if (archivo != NULL)
    {
        fprintf(archivo, "%s", dot);
        fflush(archivo);
        fclose(archivo);
    }

    graficar(0);

    strcpy(dot, "}");

    archivo = fopen("/home/marco/Escritorio/btk.dot", "a");

    if (archivo != NULL)
    {
        fprintf(archivo, "%s", dot);
        fflush(archivo);
        fclose(archivo);
    }

    system("dot -Tpng /home/marco/Escritorio/btk.dot -o /home/marco/Escritorio/btk.png");
}
