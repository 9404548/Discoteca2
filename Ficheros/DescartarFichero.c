/*****************************************
 * Nombre: DescartarFichero
 * Argumentos: DISCO **Fichas:   Puntero al array de discos
 *             WINDOW *Wfichero: Ventana para mostrar el nombre del fichero
 * Descripción: Muestra los datos del fichero y los discos almacenados y descarta todos
 *              los discos en memoria y libera la memoria asignada.
 * Reglas de uso: 
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"

void DescartarFichero(DISCO **Fichas, WINDOW *Wfichero)
{
    int i;
    char conf;

    touchwin(Wfichero);
    wrefresh(Wfichero);

    // Comprobar si existen discos
    if (Estadisticas.NumeroFichas == 0) {
        VentanaError("No hay discos para descartar");
        return;
    }

    // Confirmar que se quieren descartar todos los discos
    conf = VentanaSN("Si quiere descartar los discos pulse S, si no N: ");
    if (conf != 'S') {
        return;
    }

    // Liberar la memoria de todos los campos de cada estructura de disco que exista
    for (i = 0; i < Estadisticas.NumeroFichas; i++) {
        if ((*Fichas)[i].Obra != NULL) 
            free((*Fichas)[i].Obra);
        if ((*Fichas)[i].ApellAutor != NULL) 
            free((*Fichas)[i].ApellAutor);
        if ((*Fichas)[i].NomAutor != NULL) 
            free((*Fichas)[i].NomAutor);
        if ((*Fichas)[i].Tonalidad != NULL) 
            free((*Fichas)[i].Tonalidad);
        if ((*Fichas)[i].Opus != NULL) 
            free((*Fichas)[i].Opus);
        if ((*Fichas)[i].Duracion != NULL) 
            free((*Fichas)[i].Duracion);
    }

    // Liberar el espacio del array de estructuras de disco e inicializarlo a NULL
    free(*Fichas);
    *Fichas = NULL;

    // Actualizar las estadísticas (ponerlas a 0)
    if (Estadisticas.Fichero != NULL) {
        free(Estadisticas.Fichero);
        Estadisticas.Fichero = NULL;
    }
    Estadisticas.NumeroFichas = 0;
    Estadisticas.MaxFichas = 0;
    Estadisticas.TiempoCarga = 0;
    Estadisticas.TiempoSeleccion = 0;
    Estadisticas.TiempoBurbuja = 0;
    Estadisticas.TiempoInsercion = 0;
    Estadisticas.TiempoQuicksort = 0;
    Estadisticas.TiempoBusquedaSecuencial = 0;
    Estadisticas.TiempoBusquedaBinaria = 0;
    Estadisticas.TiempoBusquedaArbol = 0;

    // Informar que los discos han sido descartados
    VentanaError("Los discos han sido descartados");
}