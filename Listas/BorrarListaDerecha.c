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

    // se crean dos nodos auxiliares para recorrer la lista y borrar el último elemento
    NODO * pAuxNodo = (NODO*) malloc(sizeof(NODO));
    NODO * qAuxNodo = (NODO*) malloc(sizeof(NODO));

    // Se inicializa el puntero al primer elemento de la lista
    pAuxNodo = Lista -> Primero;

    
    while(true){
        // Si el nodo siguiente a pAuxNodo es el ultimo de la lista
        if((pAuxNodo->Siguiente == Lista->Ultimo)){
            // Entonces el nuevo ultimo de la lista es pAuxNodo
            Lista ->Ultimo = pAuxNodo;   
            break; // Y salimos del bucle while
        }
        // Nos desplazamos al siguiente elemento en la lista
        pAuxNodo = pAuxNodo->Siguiente;
    }
    // qAuxNodo es el elemento que se borrará de la lista
    qAuxNodo = pAuxNodo -> Siguiente;
    // Se ha borrado de la lista qAuxNodo al ser desenlazado
    pAuxNodo -> Siguiente = NULL;
    // Devuelve puntero a qAuxNodo
    return qAuxNodo;
}