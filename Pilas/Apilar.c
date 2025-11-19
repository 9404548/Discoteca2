/*****************************************
 * Nombre: Apilar
 * Argumentos: PILA *Pila:      Puntero al TAD Pila
 *             void *Elemento:  Puntero al elemento a apilar
 * Descripción: Apila el elemento Elemento al comienzo de la Pila
 * Reglas de uso: 
 * Código de Retorno: Nuevo Puntero al TAD Pila
 * Programador:
 *****************************************/

#include "Pilas.h"

PILA *Apilar(PILA *Pila,void *Elemento)
{
    PILA * ptrAuxiliar = malloc(sizeof(PILA));
    if(EsPilaVacia(ptrAuxiliar)) {
        return NULL;
    }else {
        ptrAuxiliar->Elemento = Elemento;
        ptrAuxiliar->Siguiente = Pila;
        return ptrAuxiliar;
    }
    // Código del Alumno
    
}