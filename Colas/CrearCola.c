/*****************************************
 * Nombre: CrearCola
 * Argumentos: N/A
 * Descripción: Crea una cola sin elementos.
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Cola creada (vacía)
 *                    NULL - No se ha podido alocar espacio nuevo
 * Programador:
 *****************************************/

#include "Colas.h"

COLA *CrearCola()
{
    COLA* nuevaCola = malloc(sizeof(COLA));
    if(nuevaCola!=NULL){
        nuevaCola -> Cabecera = NULL;
        nuevaCola -> Final = NULL;
    }
    return nuevaCola;
    
}