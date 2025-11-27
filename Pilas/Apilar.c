/*****************************************
 * Nombre: Apilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void *Elemento:  Puntero al elemento a apilar
 * Descripción: Apila el elemento Elemento al comienzo de la Pila
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Pilas.h"

PILA *Apilar(PILA *Pila,void *Elemento)
{
    // Se pide espacio para otro nodo en la pila
    PILA * ptrAuxiliar = malloc(sizeof(PILA));
    // Si falló la petición de memoria devolvemos NULL
    if(EsPilaVacia(ptrAuxiliar)) return NULL;
    // El elemento del nodo es el Elemento aportado en la llamada
    ptrAuxiliar->Elemento = Elemento;
    // El elemento siguiente a este nodo es la anterior cima de la pila
    ptrAuxiliar->Siguiente = Pila;
    // Se devuele el puntero a la cima de la pila
    return ptrAuxiliar;
}