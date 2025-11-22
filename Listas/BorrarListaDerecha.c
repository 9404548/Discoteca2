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
    // Si la lista esta vacia, devuelve NULL
    if(EsListaVacia(Lista)) return NULL;

    // En estas dos lineas se crean dos nodos auxiliares para recorrer la lista y borrar el último elemento
    NODO * pAuxNodo = (NODO*) malloc(sizeof(NODO));
    NODO * qAuxNodo = (NODO*) malloc(sizeof(NODO));

    // Se inicializa el puntero al primer elemento de la lista
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