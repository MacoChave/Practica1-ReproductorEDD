#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "lstcancion.h"

LSTCancion::LSTCancion()
{
    primero = NULL;
    ultimo = NULL;
}

NodoCancion::NodoCancion(char *cancion_, char *path_, float valoracion)
{
    cancion = new char[sizeof(cancion)];
    strcpy(cancion, cancion_);

    path = new char[sizeof(path)];
    strcpy(path, path_);

    valoracion = valoracion;

    siguiente = NULL;
}

void LSTCancion::agregar(NodoCancion *actual, char *cancion, char *path, float valoracion)
{
    if (primero != NULL)
    {
        if (strcmp(primero->cancion, cancion) > 0)
        {
            /* INSERTAR EN CABEZA */
            NodoCancion *nuevo = new NodoCancion(cancion, path, valoracion);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else if (strcmp(ultimo->cancion, cancion) < 0)
        {
            /* INSERTAR AL FINAL */
            NodoCancion *nuevo = new NodoCancion(cancion, path, valoracion);
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
        else
        {
            if (strcmp(actual->siguiente->cancion, cancion) > 0)
            {
                /* INSERTAR ANTES */
                NodoCancion *nuevo = new NodoCancion(cancion, path, valoracion);
                nuevo->siguiente = actual->siguiente;
                actual->siguiente = nuevo;
            }
            else if (strcmp(actual->siguiente->cancion, cancion) < 0)
            {
                agregar(actual->siguiente, cancion, path, valoracion);
            }
        }
    }
    else
    {
        primero = new NodoCancion(cancion, path, valoracion);
    }
}

void LSTCancion::eliminar(NodoCancion *actual, char *cancion)
{

}

void LSTCancion::add(char *cancion, char *path, float valoracion)
{
    agregar(primero, cancion, path, valoracion);
}

void LSTCancion::remove(char *cancion)
{

}

void LSTCancion::graph(char *album, char *artista)
{
    NodoCancion *tmp = primero;
    char dot[500];

    /* LISTAR CANCION */
    sprintf(dot, "\tnd%s[label=\"", album);
    while (tmp != NULL)
    {
        strcat(dot, "<");
        strcat(dot, tmp->cancion);
        strcat(dot, ">");
        strcat(dot, tmp->cancion);
        strcat(dot, " | ");
        tmp = tmp->siguiente;
    }
    strcat(dot, "\"]\n\n\t");
    strcat(dot, "nd");
    strcat(dot, artista);
    strcat(dot, ":");
    strcat(dot, album);
    strcat(dot, " -> nd");
    strcat(dot, album);
    strcat(dot, ";\n");

    FILE *archivo;
    archivo = fopen("/home/marco/Escritorio/btk.dot", "a");

    if (archivo != NULL)
    {
        fprintf(archivo, "%s", dot);
        fflush(archivo);
        fclose(archivo);
    }
}

void LSTCancion::clear()
{

}
