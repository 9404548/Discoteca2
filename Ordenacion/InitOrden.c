    /*****************************************
 * Nombre: InitOrden
 * Argumentos: DISCO *Fichas:   Array de discos
 * Descripción: Genera un array con los punteros a los discos ordenados por
 *              su orden numérico, es decir, el mismo orden el que están en
 *              el array de discos Fichas.
 * Reglas de uso: Hay que alocar el espacio para el array de punteros
 * Código de Retorno: Puntero al array de punteros a los discos ordenados (discos **)
 * Programador: MCP (NOV 2025)
 *****************************************/

#include "../Discoteca.h"

DISCO **InitOrden(DISCO *Fichas)
{
    int num_fichas = Estadisticas.NumeroFichas;

    // Se pide memoria para el puntero a un array de punteros a 
    // tantos Discos como hay registrados en el número de fichas
    DISCO** orden = (DISCO**) malloc(num_fichas * sizeof(DISCO*));

    int i;
    // Si falló la creación del puntero al array de punteros, se devuelve NULL
    if(!orden) return(NULL);
    // Se asigna a cada puntero en el array de punteros la dirección de cada Ficha (Disco)
    for(i = 0; i < num_fichas; i++) orden[i] = &Fichas[i];
    // Termina devolviendo la "ordenación" de los discos, el puntero al array de punteros
    return orden;
}