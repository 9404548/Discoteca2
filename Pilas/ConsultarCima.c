/*****************************************
 * Nombre: ConsultarCima
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 * Descripción: Devuelve el puntero al primer elemento de la Pila
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento Cima
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Pilas.h"

void *ConsultarCima(PILA *Pila)
{
    // Devuelve NULL si la pila está vacía (no hay elemento cima)
    if(EsPilaVacia(Pila)) return NULL;
    // Devuelve puntero al elemento en la cima de la pila
    return Pila->Elemento;         
}