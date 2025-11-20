/*****************************************
 * Nombre: BorrarListaDerecha
 * Argumentos: LISTA *Lista:   Puntero al TAD Lista
 * Descripción: Borra un elemento de Lista a la derecha.
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento que se ha borrado o NULL si no había elementos
 * Programador:
 *****************************************/

#include "Listas.h"

void *BorrarListaDerecha(LISTA *Lista)
{
    if(EsListaVacia(Lista)) return NULL;

    NODO * pAuxNodo = (NODO*) malloc(sizeof(NODO));
    NODO * qAuxNodo = (NODO*) malloc(sizeof(NODO));
    pAuxNodo = Lista -> Primero;

    while(true){
        if((pAuxNodo->Siguiente == Lista->Ultimo)){
            Lista ->Ultimo = pAuxNodo;   
            break; //Sale del bucle si el Siguiente del elemento es NULL (se llegó al fin de la lista).
        }
        pAuxNodo = pAuxNodo->Siguiente;
    }
    qAuxNodo = pAuxNodo -> Siguiente;
    pAuxNodo -> Siguiente = NULL;
    return qAuxNodo;

    // Código del Alumno
    
}