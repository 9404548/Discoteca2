/*****************************************
 * Nombre: Desencolar
 * Argumentos: COLA *Cola:   Puntero al TAD Cola
 * Descripción: Devuelve el puntero al primer elemento de la Cola (Cabecera) y lo elimina de la Cola
 * Reglas de uso: El puntero debe ser void *
 * Código de Retorno: Puntero al elemento desencolado
 *                    NULL si la cola no está creada o no tiene elementos
 * Programador:
 *****************************************/

#include "Colas.h"

void* Desencolar(COLA *Cola)
{
    NODO * pAuxiliar;
    
    // Elemento a borrar
    void *ElementoAux;

    // Si la cola esta vacia, NULL, si no, sigue
    if(EsColaVacia(Cola))
        return(NULL);
    pAuxiliar = Cola->Cabecera;
    ElementoAux = pAuxiliar->Elemento;
    Cola->Cabecera = Cola->Cabecera->Siguiente;
    // Verificar si se queda vacía despues de borrar
    if(Cola->Cabecera == NULL){
        Cola->Final == NULL;
    }
    free(pAuxiliar);
    return(ElementoAux);
}