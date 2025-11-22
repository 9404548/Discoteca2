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
    // Se crea un nodo para el elemento auxiliar
    NODO *auxElemento = (NODO *)malloc(sizeof(NODO));

    // Si la lista esta vacia o el elemento auxiliar es NULL, devuelve -1
    if(EsListaVacia(Lista) || !auxElemento) return (-1);
    
    // Si no, se pone el elemento auxiliar al final de la lista
    Lista -> Ultimo -> Siguiente = auxElemento;

    // Se actualiza el puntero al ultimo elemento de la lista
    Lista -> Ultimo = auxElemento;

    // Se asigna al elemento auxiliar el elemento a insertar
    auxElemento -> Elemento = Elemento; 

    // El elemento siguiente del puntero elemento auxiliar es NULL ya que se ha insertado un elemento al final de la lista
    auxElemento -> Siguiente = NULL;

    // Devuelve 0 si se ha insertado correctamente el elemento
    return (0);
}