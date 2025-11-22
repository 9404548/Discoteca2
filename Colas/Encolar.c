/*****************************************
 * Nombre: Encolar
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al Elemento a insertar
 * Descripción: Se inserta el elemento dado al final de la cola.
 *              Se aloca el espacio que sea necesario
 * Reglas de uso: La cola debe estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo 
 * Programador: LXMDOC & MCP (NOV 2025)
 *****************************************/

#include "Colas.h"

int Encolar(COLA *Cola, void *Elemento)
{
    NODO * pAuxiliar;

    // Pedimos memoria para un nodo nuevo en la cola
    pAuxiliar = (NODO *) malloc(sizeof(NODO));

    // Si falló la alocación de espacio o no existe la cola, devolvemos -1 
    if(!pAuxiliar || !Cola) return(-1);
    
    // Se asigna al nodo el elemento a encolar
    pAuxiliar->Elemento = Elemento;
    // Se asigna al nodo que su siguiente es null, ya que será el último elemento de la cola
    pAuxiliar->Siguiente = NULL;

    // El nodo pAuxiliar se asigna como el elemento siguiente al actual fin de la cola
    Cola->Final->Siguiente = pAuxiliar;

    // Se actualiza el final de la cola y se define como pAuxiliar
    Cola->Final = pAuxiliar;

    // Si la cabecera estaba NULL (no había elementos encolados) ahora la cabecera es también pAuxiliar
    if(!Cola->Cabecera) Cola->Cabecera = pAuxiliar;
    // retorno con éxito
    return(0);
    
}