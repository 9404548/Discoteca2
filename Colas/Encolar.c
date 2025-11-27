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
    // Comprueba argumentos
    if (Cola == NULL) return -1;

    // Pedimos memoria para un nodo nuevo en la cola
    NODO *pAuxiliar = malloc(sizeof(NODO));

    // Si falló la alocación de espacio o no existe la cola, devolvemos -1 
    if(pAuxiliar == NULL) return(-1);
    
    // Se asigna al nodo el elemento a encolar
    pAuxiliar->Elemento = Elemento;
    pAuxiliar->Siguiente = NULL;

    /* Si la cola está vacía, el nuevo nodo es cabecera y final;
       si no, enlazamos al final existente */
    if (EsColaVacia(Cola)) {
        Cola->Cabecera = pAuxiliar;
    } else {
        Cola->Final->Siguiente = pAuxiliar;
    }

    // Se actualiza el final de la cola y se define como pAuxiliar
    Cola->Final = pAuxiliar;

    return 0;
    
}