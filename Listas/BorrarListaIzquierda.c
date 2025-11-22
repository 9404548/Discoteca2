/*****************************************
 * Nombre: BorrarListaIzquierda
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la izquierda.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaIzquierda(LISTA *Lista)
{
    // Si la lista esta vacia, devuelve NULL
    if(EsListaVacia(Lista)) return NULL;

    // Se crea un nodo auxiliar para borrar el primer elemento de la lista
    NODO * auxNodo = (NODO*) malloc(sizeof(NODO));

    // El puntero ahora apunta al primer elemento de la lista
    auxNodo = Lista -> Primero;

    // El primer elemento de la lista es el que se va a borrar, luego por eso ahora el primer elemento de la lista es el siguiente
    Lista -> Primero = Lista -> Primero -> Siguiente;

    // Se devuelve el puntero al elemento que se ha borrado
    return auxNodo;
}