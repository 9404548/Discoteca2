/*****************************************
 * Nombre: InsertarListaIzquierda
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Izquierda
 * Reglas de uso: 
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Listas.h"

int InsertarListaIzquierda(LISTA *Lista, void *Elemento)
{
    // Se crea el nodo para el elemento a insertar en la lista
    NODO *auxElemento = (NODO *)malloc(sizeof(NODO));

    // Si la lista no está creada o el elemento auxiliar no se pudo crear, devuelve -1
    if(Lista == NULL || !auxElemento) return (-1);
    
    // Se asigna al elemento auxiliar el elemento a insertar
    auxElemento -> Elemento = Elemento;

    // El elemento siguiente del puntero elemento auxiliar es el primer elemento de la lista
    auxElemento -> Siguiente = Lista -> Primero;

    // Se actualiza el puntero al primer elemento de la lista
    Lista -> Primero = auxElemento;

    // Si la lista estaba vacía, el puntero Ultimo también debe apuntar al nuevo nodo
    if (Lista->Ultimo == NULL) Lista->Ultimo = auxElemento;

    // Devolución con éxito
    return (0);
}