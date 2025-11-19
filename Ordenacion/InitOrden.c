    /*****************************************
 * Nombre: InitOrden
 * Argumentos: LIBRO *Fichas:   Array de libros
 * Descripción: Genera un array con los punteros a los libros ordenados por
 *              su orden numérico, es decir, el mismo orden el que están en
 *              en array de libros Fichas.
 * Reglas de uso: Hay que alocar el espacio para el array de punteros
 * Código de Retorno: Puntero al array de punteros a los libros ordenados (LIBROS **)
 * Programador:
 *****************************************/

#include "../Discoteca.h"

DISCO **InitOrden(DISCO *Fichas)
{
    int num_fichas = Estadisticas.NumeroFichas;
    DISCO** orden = (DISCO**) malloc(num_fichas * sizeof(DISCO*));
    int i;

    if(orden == NULL){
        return(NULL);
    }

    // El array orden termina siendo un conjunto de punteros, por ejemplo, orden[0] apunta a Fichas[0],
    // orden[1] a Fichas[1]...
    for(i=0; i<num_fichas; i++){
        orden[i] = &Fichas[i];
    }

    // Termina devolviendo la "ordenacion" de los discos
    return orden;
    
}