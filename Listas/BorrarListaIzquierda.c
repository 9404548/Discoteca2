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

    // Extraemos el primer nodo y devolvemos su elemento
    NODO *auxNodo = Lista->Primero;
    void *elemento = auxNodo->Elemento;

    // Avanzamos el Primero de la lista
    Lista->Primero = auxNodo->Siguiente;

    // Si la lista queda vacía, actualizamos Ultimo
    if (Lista->Primero == NULL) Lista->Ultimo = NULL;

    // Liberamos el nodo y devolvemos el elemento
    free(auxNodo);
    return elemento;
}