/*****************************************
 * Nombre: ConsultarListaDerecha
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Consulta el elemento de la derecha de Lista. No se elimina de Lista
 * Reglas de uso: 
 * Código de Retorno: Puntero al elemento de la derecha de Lista
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Listas.h"

void *ConsultarListaDerecha(LISTA *Lista)
{
    // Devuelve el puntero al elemento que está en la derecha de la lista
    return Lista -> Ultimo -> Elemento;
}