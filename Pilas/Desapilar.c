/*****************************************
 * Nombre: Desapilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void **Elemento: Puntero de referencia al puntero del elemento que se desapila
 * Descripción: Desapila el primer elemento de la pila y guarda el puntero desapilado en *Elemento
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Pilas.h"

PILA *Desapilar(PILA *Pila,void **Elemento)
{
    //Comprueba pila vacía
    if (EsPilaVacia(Pila)) {
        *Elemento = NULL;
        return NULL;
    }

    // Guarda el nodo cima y el elemento a devolver
    NODO *pNodo = Pila;
    void *elem = pNodo->Elemento;

    // Avanza la cima de la pila
    PILA *nuevaCima = Pila->Siguiente;

    // Libera el nodo desapilado, pero el elemento sigue guardado 
    free(pNodo);

    // Devuelve el elemento mediante el puntero de salida y devuelve la nueva cima.
    *Elemento = elem;
    return nuevaCima;
}