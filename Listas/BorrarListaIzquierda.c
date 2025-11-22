/*****************************************
 * Nombre: BorrarListaIzquierda
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la izquierda.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Listas.h"

void *BorrarListaIzquierda(LISTA *Lista)
{
    // Si la lista esta vacia, devuelve NULL
    if(EsListaVacia(Lista)) return NULL;

    // Se crea un nodo auxiliar para borrar el primer elemento de la lista
    NODO * auxNodo = (NODO*) malloc(sizeof(NODO));

    // auxNodo apunta al primer elemento de la lista
    auxNodo = Lista -> Primero;

    // El nuevo primer elemento es el que el original primero tenía como siguiente
    Lista -> Primero = Lista -> Primero -> Siguiente;

    // Se devuelve el puntero al elemento que se ha desenlazado de la lista
    return auxNodo;
}