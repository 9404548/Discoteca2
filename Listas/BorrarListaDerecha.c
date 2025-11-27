/*****************************************
 * Nombre: BorrarListaDerecha
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la derecha.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Listas.h"

void *BorrarListaDerecha(LISTA *Lista)
{
    // Si la lista esta vacia, devuelve NULL
    if(EsListaVacia(Lista)) return NULL;

    // Si sólo hay un elemento
    NODO *pAuxNodo = Lista->Primero;
    if (pAuxNodo->Siguiente == NULL) {
        void *elemento = pAuxNodo->Elemento;
        Lista->Primero = NULL;
        Lista->Ultimo = NULL;
        free(pAuxNodo);
        return elemento;
    }

    // Buscar el penúltimo nodo
    while (pAuxNodo->Siguiente != Lista->Ultimo) {
        pAuxNodo = pAuxNodo->Siguiente;
    }

    NODO *qAuxNodo = pAuxNodo->Siguiente; /* último nodo */
    void *elemento = qAuxNodo->Elemento;

    /* Desenlazamos el último y actualizamos Ultimo */
    pAuxNodo->Siguiente = NULL;
    Lista->Ultimo = pAuxNodo;

    free(qAuxNodo);
    return elemento;
}