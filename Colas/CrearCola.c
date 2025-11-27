/*****************************************
 * Nombre: CrearCola
 * Argumentos: N/A
 * Descripción: Crea una cola sin elementos.
 * Reglas de uso: 
 * Código de Retorno: Puntero a la Cola creada (vacía)
 *                    NULL - No se ha podido alocar espacio nuevo
 * Programador: LXMDOC & MCP (NOV 2025)
 *****************************************/

#include "Colas.h"

COLA *CrearCola()
{
    
    // Se pide espacio en memoria para crear la cola
    COLA* nuevaCola = (COLA *)malloc(sizeof(COLA)); 

    /* Si es distinto de null (la cola se creó con éxito en el malloc)
    definimos su cabecera y final como null (ya que está vacía) */
    if(nuevaCola != NULL){
        nuevaCola -> Cabecera = NULL;
        nuevaCola -> Final = NULL;
    }
    // Devolvemos el puntero a la cola creada o NULL si falló el malloc
    return nuevaCola; 
    
}