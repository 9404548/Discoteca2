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
    // El puntero al elemento contiene la antigua cima de la pila (el elemento desapilado)
    *Elemento = Pila;
    // La nueva cima de la pila es ahora el siguiente elemento a la original cima
    Pila = Pila->Siguiente;
    // Se llibera el espacio que ocupaba la antigua cima de la pila
    free(*Elemento);
    // Se devuelve el puntero a lla cima actual de la pila
    return Pila;
}