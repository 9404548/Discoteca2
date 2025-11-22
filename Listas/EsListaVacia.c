/*****************************************
 * Nombre: EsListaVacia
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Comprueba si la Lista está vacía o tiene elementos
 * Reglas de uso: 
 * Código de Retorno: true  - La lista está vacía
 *                    false - La lista tiene elementos
 * Programador:
 *****************************************/

#include "Listas.h"

bool EsListaVacia(LISTA *Lista)
{
    // Devuelve true si la lista no existe o el primer elemento es NULL
    return((!Lista || !Lista->Primero));
}