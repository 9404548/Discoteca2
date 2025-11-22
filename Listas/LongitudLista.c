/*****************************************
 * Nombre: LongitudLista
 * Argumentos: Lista *Lista:   Puntero al TAD Lista
 * Descripción: Calcula el número de elementos de Lista
 * Reglas de uso: 
 * Código de Retorno: el número de elementos de Lista
 * Programador:
 *****************************************/

#include "Listas.h"

int LongitudLista(LISTA *Lista)
{

    if(EsListaVacia(Lista)) return (0); // Salida rápida si la lista está vacía.

    // Se inicializa un nodo auxiliar en el primer elemento de la lista que haya
    NODO *auxElemento = Lista->Primero;
    int contador = 0; // Inicializado a 1 por el primer elemento de la lista.

    // Bucle para recorrer la lista hasta el final, entra al bucle siempre que haya un siguiente elemento
    while(true){

        // Incrementa el contador por cada elemento encontrado
        contador++;
        if(!(auxElemento->Siguiente)) break; //Sale del bucle si el Siguiente del elemento es NULL (se llegó al fin de la lista).
        
        // Avanza al siguiente elemento de la lista
        auxElemento = auxElemento->Siguiente;

    }

    // Devuelve el numero de elementos encontrados en la lista
    return contador;
}