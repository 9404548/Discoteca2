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

    // Si no hay nada en la lista, devuelve NULL
    if(!Lista) return NULL;

    // Se inicializan los punteros de la lista a NULL
    Lista->Primero = NULL;
    Lista->Ultimo = Lista->Primero;
    
    // Devuelve la lista creada
    return Lista;
}