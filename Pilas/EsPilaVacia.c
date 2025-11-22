/*****************************************
 * Nombre: EsPilaVacia
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 * Descripción: Comprueba si la Pila está vacía
 * Reglas de uso: 
 * Código de Retorno: true  - La Pila está vacía
 *                    false - La Pila tiene elementos
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Pilas.h"

bool EsPilaVacia(PILA *Pila)
{
    // Devuelve si la pila está vacía o no existe aún
    return (Pila == NULL); 
}