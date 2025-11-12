/*****************************************
 * Nombre: Encolar
 * Argumentos: COLA *Cola:      Puntero al TAD Cola
 *             void *Elemento:  Puntero al Elemento a insertar
 * Descripción: Se inserta el elemento dado al final de la cola.
 *              Se aloca el espacio que sea necesario
 * Reglas de uso: La cola debe estar creada
 * Código de Retorno:  0 - Éxito
 *                    -1 - La Cola no está creada o no se pudo alocar espacio nuevo 
 * Programador:
 *****************************************/

#include "Colas.h"

int Encolar(COLA *Cola, void *Elemento)
{
    NODO * pAuxiliar;

    pAuxiliar = (NODO *) malloc(sizeof(NODO));
    if(!pAuxiliar){
        return(-1);
    }

    pAuxiliar->Elemento = Elemento;
    pAuxiliar->Siguiente = NULL;

    // pAuxiliar ahora apunta al nuevo nodo, no a null
    Cola->Final->Siguiente = pAuxiliar;

    // Actualizo la cola diciendo que existe un ultimo elemento nuevo que es el pAuxiliar
    Cola->Final = pAuxiliar;

    if(Cola->Cabecera == NULL){
        Cola->Cabecera = pAuxiliar;
    }

    return(0);
    
}