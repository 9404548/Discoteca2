/*****************************************
 * Nombre: InsertarListaIzquierda
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Izquierda
 * Reglas de uso: 
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador:
 *****************************************/

#include "Listas.h"

int InsertarListaIzquierda(LISTA *Lista, void *Elemento)
{
    NODO *auxElemento = (NODO *)malloc(sizeof(NODO));

    if(EsListaVacia(Lista) || !auxElemento) return (-1);
    
    auxElemento -> Elemento = Elemento;
    auxElemento -> Siguiente = Lista -> Primero;
    Lista -> Primero = auxElemento;

    return (0);
    // Código del Alumno
    
}