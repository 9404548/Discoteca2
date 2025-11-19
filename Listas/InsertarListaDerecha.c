/*****************************************
 * Nombre: InsertarListaDerecha
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Derecha
 * Reglas de uso: 
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador:
 *****************************************/

#include "Listas.h"

int InsertarListaDerecha(LISTA *Lista, void *Elemento)
{   
    NODO *auxElemento = (NODO *)malloc(sizeof(NODO));

    if(EsListaVacia(Lista) || !auxElemento) return (-1);
    
    Lista -> Ultimo -> Siguiente = auxElemento;
    Lista -> Ultimo = auxElemento;
    auxElemento -> Elemento = Elemento; 
    auxElemento -> Siguiente = NULL;

    return (0);
    // Código del Alumno

}