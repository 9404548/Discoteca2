/*****************************************
 * Nombre: EsColaVacía
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve 'true' si la Cola está vacía o 'false' si tiene elementos
 * Reglas de uso: 
 * Código de Retorno: true  - La Cola no tiene elementos
 *                    false - La Cola tiene elementos
 * Programador: LXMDOC & MCP (NOV 2025)
 *****************************************/

#include "Colas.h"

bool EsColaVacia(COLA *Cola)
{
    // Si cola es null o su cabecera es null, es cola vacía
    if (Cola == NULL || Cola->Cabecera == NULL) return true;
    // No es cola vacía
    return false;
}