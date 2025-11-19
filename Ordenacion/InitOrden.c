    /*****************************************
 * Nombre: InitOrden
 * Argumentos: DISCO *Fichas:   Array de discos
 * Descripción: Genera un array con los punteros a los discos ordenados por
 *              su orden numérico, es decir, el mismo orden el que están en
 *              el array de discos Fichas.
 * Reglas de uso: Hay que alocar el espacio para el array de punteros
 * Código de Retorno: Puntero al array de punteros a los discos ordenados (discos **)
 * Programador:
 *****************************************/

#include "../Discoteca.h"

DISCO **InitOrden(DISCO *Fichas)
{
    int num_fichas = Estadisticas.NumeroFichas;
    DISCO** orden = (DISCO**) malloc(num_fichas * sizeof(DISCO*));
    int i;

    if(!orden) return(NULL);

    for(i = 0; i < num_fichas; i++){
        orden[i] = &Fichas[i];
    }

    return orden;
}