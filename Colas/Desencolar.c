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
    void *ElementoAux;

    // Si la cola esta vacia, devuelve NULL sin revisar más
    if(EsColaVacia(Cola)) return(NULL);

    // El nodo auxiliar apunta a la cabecera de la cola
    pAuxiliar = Cola->Cabecera;

    // El elemento a borrar es el que está en la cabecera de la cola
    ElementoAux = pAuxiliar->Elemento;

    // La cabecera de la cola ahora es el nodo siguiente a la anterior cabecera
    Cola->Cabecera = Cola->Cabecera->Siguiente;

    // Verificar si ha quedado vacía la cola despues de borrar
    if(!Cola->Cabecera) Cola->Final == NULL;
    // Ya no hacemos uso del nodo auxiliar
    free(pAuxiliar);

    // Devolvemos un puntero al elemento que eliminamos de la cola
    return(ElementoAux);
}