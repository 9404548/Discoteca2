/*****************************************
 * Nombre: ConsultarListaIzquierda
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Consulta el elemento a la izquierda de Lista. No se elimina el elemento
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento a la izquierda de la Lista 
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Listas.h"

void *ConsultarListaIzquierda(LISTA *Lista)
{
    // Devuelve el puntero al elemento que esta en la izquierda de la lista
    return Lista -> Primero -> Elemento;    
}