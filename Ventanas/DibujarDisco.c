/*****************************************
 * Nombre: DibujarDisco
 * Argumentos: Window *Wdisco:   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para mostrar o capturar los datos de las fichas de un disco.
 * Reglas de uso:
 * Código de Retorno: N/A
 * Programador: Luis Xavier Montes de Oca Campos, modificado por última vez 5 de octubre del 2025.
 *****************************************/

// Include del módulo funcional
#include "Ventanas.h"

void DibujarDisco(WINDOW *Wdisco)
{
    wcolor_set(Wdisco, 8, NULL);            // Texto celeste, fondo azul
    Cuadrado(Wdisco, 1, 0, 11, 76, SOLIDO); // Dibuja el marco para el contenido de la ventana

    wcolor_set(Wdisco, 9, NULL);                         // Texto amarillo, fondo azul
    mvwprintw(Wdisco, 0, 26, "   Gestion de Discos   "); // Impresión del título de la ventana
    /* La impresión inferior incluye una determinada cantidad de espacios' ' para
     que los espacios en blanco dentro de la ventana sean coloreados correctamente*/
    mvwprintw(Wdisco, 2, 1, " Numero de Disco:                                                         ");
    mvwprintw(Wdisco, 3, 1, " Obra:                                                                    ");
    mvwprintw(Wdisco, 4, 1, " Apellidos del Autor:                                                     ");
    mvwprintw(Wdisco, 5, 1, " Nombre del Autor:                                                        ");
    mvwprintw(Wdisco, 6, 1, " Tonalidad:                                                               ");
    mvwprintw(Wdisco, 7, 1, " Opus:                                                                    ");
    mvwprintw(Wdisco, 8, 1, " Duracion:                                                                ");
    mvwprintw(Wdisco, 9, 1, "                                                                          ");
    mvwprintw(Wdisco, 10, 1, "                                                                          ");

    wcolor_set(Wdisco, 2, NULL); // Texto celeste, fondo negro
    mvwprintw(Wdisco, 11, 18, "Enter=Nuevo/Salir     #-Visualizar Disco");
}