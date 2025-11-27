/*****************************************
 * Nombre: InsertarCabecera
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento dado en la cabecera de la Cola (primer elemento)
 * Reglas de uso: La Cola tiene que estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo
 * Programador: LXMDOC & MCP (NOV 2025)
 *****************************************/

#include "Colas.h"

int InsertarCabecera(COLA *Cola, void *Elemento)
{
    NODO * pAuxiliar;    
    // Se pide espacio para insertar un nuevo nodo en la cima de la cola
    pAuxiliar = (NODO *) malloc(sizeof(NODO));

    // Se devuelve -1 si falló la petición de memoria o si no está creada la cola
    if(pAuxiliar == NULL || Cola == NULL) return(-1);

    // El elemento en el nodo es el aportado en la llamada a la función
    pAuxiliar->Elemento = Elemento;
    // El siguiente de este nodo será la actual cabecera de la cola
    pAuxiliar->Siguiente = Cola->Cabecera;
    // Ahora se actualiza la cabecera de la cola, indicando que es este nuevo nodo
    Cola->Cabecera = pAuxiliar;

    // Si el final de la cola estaba a NULL (no había elementos), entonces el final es igual inicio de la cola
    if(Cola->Final == NULL) Cola->Final = pAuxiliar; 

    // devolución con éxito
    return(0);
}