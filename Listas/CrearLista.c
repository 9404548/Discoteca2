/*****************************************
 * Nombre: CreaLista
 * Argumentos: N/A
 * Descripción: Crea una Lista vacía
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Lista creada (vacía)
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Listas.h"

LISTA *CrearLista()
{
    // Se crea la lista pidiendo espacio para ella
    LISTA  *Lista = (LISTA *)malloc(sizeof(LISTA));

    // Si falló la creación de la lista, se devuelve NULL
    if(!Lista) return NULL;

    // Se inicializan los punteros de la lista a NULL
    Lista->Primero = NULL;
    Lista->Ultimo = Lista->Primero;
    
    // Devuelve la lista creada
    return Lista;
}