/*****************************************
 * Nombre: InsertarListaDerecha
 * Argumentos: Lista *Lista:    Puntero al TAD Lista
 *             void *Elemento:  Puntero al elemento a insertar
 * Descripción: Inserta el elemento Elemento en Lista por la Derecha
 * Reglas de uso: 
 * Código de Retorno:  0 - Éxito
 *                    -1 - La lista no está creada o no se ha podido alocar memoria nueva
 * Programador: LXMDOC (NOV 2025)
 *****************************************/

#include "Listas.h"

int InsertarListaDerecha(LISTA *Lista, void *Elemento)
{   
    // Se crea un nodo para el elemento auxiliar
    NODO *auxElemento = malloc(sizeof(NODO));
    if (!auxElemento) return -1;

    // Inicializa el nuevo nodo
    auxElemento->Elemento = Elemento;
    auxElemento->Siguiente = NULL;

    // Si la lista está vacía, el nuevo nodo es primero y último
    if (EsListaVacia(Lista)) {
        Lista->Primero = auxElemento;
        Lista->Ultimo = auxElemento;
    } else {
        // Enlista al final
        Lista->Ultimo->Siguiente = auxElemento;
        Lista->Ultimo = auxElemento;
    }

    return (0);
}