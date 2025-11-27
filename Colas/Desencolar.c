/*****************************************
 * Nombre: Desencolar
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve el puntero al primer elemento de la Cola (Cabecera) y lo elimina de la Cola
 * Reglas de uso: El puntero debe ser void *
 * Código de Retorno: Puntero al elemento desencolado
 *                    NULL si la cola no está creada o no tiene elementos
 * Programador: LXMDOC & MCP (NOV 2025)
 *****************************************/

#include "Colas.h"

void* Desencolar(COLA *Cola)
{
    NODO * pAuxiliar;
    
    // Elemento a borrar
    void *elementoAux;
    // Comprueba existencia de cola y sus contenidos
    if (Cola == NULL || EsColaVacia(Cola)) return NULL;

    // El nodo auxiliar apunta a la cabecera de la cola
    pAuxiliar = Cola->Cabecera;

    // Guardamos el elemento que devolveremos
    elementoAux = pAuxiliar->Elemento;

    // Avanzamos la cabecera al siguiente nodo
    Cola->Cabecera = pAuxiliar->Siguiente;

    // Si la cola ha quedado vacía, actualizamos Final a NULL
    if (Cola->Cabecera == NULL) {
        Cola->Final = NULL;
    }

    // Devolvemos un puntero al elemento que eliminamos de la cola
    return(elementoAux);
}