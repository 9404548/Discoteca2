/*****************************************
 * Nombre: InsertarCabecera
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento dado en la cabecera de la Cola (primer elemento)
 * Reglas de uso: La Cola tiene que estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

int InsertarCabecera(COLA *Cola, void *Elemento)
{
    NODO * pAuxiliar;    
    pAuxiliar = (NODO *) malloc(sizeof(NODO));
    if(!pAuxiliar){
        return(-1);
    }

    pAuxiliar->Elemento = Elemento;
    // Apunto a la primera posicion de la cola, ya que antes estaba en el segundo porque hemos metido uno nuevo
    pAuxiliar->Siguiente = Cola->Cabecera;


    // Actualizo la cola diciendo que existe un ultimo elemento nuevo que es el pAuxiliar
    Cola->Cabecera = pAuxiliar;

    if(!(Cola->Final)) Cola->Final = pAuxiliar;

    return(0);
}