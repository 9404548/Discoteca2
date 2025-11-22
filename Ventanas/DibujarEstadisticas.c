/*****************************************
 * Nombre: DibujarEstadisticas
 * Argumentos: Window *Westad :   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para er las estadísticas del programa
 * Reglas de uso:
 * Código de Retorno: N/A
 * Programador: Luis Xavier Montes de Oca Campos, modificado por última vez 5 de octubre del 2025.
 *****************************************/

// Include del módulo funcional
#include "Ventanas.h"

void DibujarEstadisticas(WINDOW *Westad)
{
    wcolor_set(Westad, 8, NULL);            // Texto celeste, fondo azul
    Cuadrado(Westad, 1, 0, 13, 76, SOLIDO); // Dibuja marco para el coontenido de la ventana

    wcolor_set(Westad, 9, NULL);                    // Texto amarillo, fondo azul
    mvwprintw(Westad, 0, 29, "   Estadisticas   "); // Impresión del título de la ventana
    /* La impresión inferior incluye una determinada cantidad de espacios' ' para
     que los espacios en blanco dentro de la ventana sean coloreados correctamente*/
    mvwprintw(Westad, 2, 1, " Nombre del fichero:                                                      ");
    mvwprintw(Westad, 3, 1, " Fichas de discos:                                                        ");
    mvwprintw(Westad, 4, 1, " Numero de discos con memoria reservada:                                  ");
    mvwprintw(Westad, 5, 1, " Microsegundos en Importar:                                               ");
    mvwprintw(Westad, 6, 1, " Microsegundos en ordenar por Seleccion:                                  ");
    mvwprintw(Westad, 7, 1, " Microsegundos en ordenar por Burbuja:                                    ");
    mvwprintw(Westad, 8, 1, " Microsegundos en ordenar por Insercion:                                  ");
    mvwprintw(Westad, 9, 1, " Microsegundos en ordenar por Quicksort:                                  ");
    mvwprintw(Westad, 10, 1, " Microsegundos en crear el arbol binario:                                 ");
    mvwprintw(Westad, 11, 1, " Microsegundos en buscar por obra:                                        ");
    mvwprintw(Westad, 12, 1, " Microsegundos en buscar por autor:                                       ");
}