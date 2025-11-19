/*****************************************
 * Nombre: CreaLista
 * Argumentos: N/A
 * Descripción: Crea una Lista vacía
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Lista creada (vacía)
 * Programador:
 *****************************************/

#include "Listas.h"

LISTA *CrearLista()
{
    LISTA  *Lista = (LISTA *)malloc(sizeof(LISTA));

    if(!Lista) return NULL;

    Lista->Primero = NULL;
    Lista->Ultimo = Lista->Primero;
    
    return Lista;
}