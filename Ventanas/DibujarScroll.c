/*****************************************
 * Nombre: DibujarScroll
 * Argumentos: Window *Wlistado:   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para los listados de libros, con 10 fichas por pantalla.
 * Reglas de uso:
 * Código de Retorno: N/A
 * Programador: Luis Xavier Montes de Oca Campos, modificado por última vez 5 de octubre del 2025.
 *****************************************/

////Include del módulo funcional
#include "Ventanas.h"

void DibujarScroll(WINDOW *Wlistado)
{
    wcolor_set(Wlistado, 8, NULL);            // Cambio de color a fondo azul, texto celeste
    Cuadrado(Wlistado, 1, 0, 14, 76, SOLIDO); // Impresión de los cuadrados para enmarcar contenido y encabezado
    Cuadrado(Wlistado, 1, 0, 3, 76, SOLIDO);
    wcolor_set(Wlistado, 9, NULL);                         // Texto amarillo, fondo azul
    mvwprintw(Wlistado, 0, 26, "   Listado de Discos   "); // Impresión del título de la ventana
    /* La impresión inferior incluye una determinada cantidad de espacios' ' para
     que los espacios en blanco dentro de la ventana sean coloreados correctamente*/
    mvwprintw(Wlistado, 2, 1, " Numero          Obra                 Autor                               ");
    mvwprintw(Wlistado, 4, 1, "                                                                          ");
    mvwprintw(Wlistado, 5, 1, "                                                                          ");
    mvwprintw(Wlistado, 6, 1, "                                                                          ");
    mvwprintw(Wlistado, 7, 1, "                                                                          ");
    mvwprintw(Wlistado, 8, 1, "                                                                          ");
    mvwprintw(Wlistado, 9, 1, "                                                                          ");
    mvwprintw(Wlistado, 10, 1, "                                                                          ");
    mvwprintw(Wlistado, 11, 1, "                                                                          ");
    mvwprintw(Wlistado, 12, 1, "                                                                          ");
    mvwprintw(Wlistado, 13, 1, "                                                                          ");

    wcolor_set(Wlistado, 2, NULL); // Cambio de color a fondo negro, texto celeste
    mvwprintw(Wlistado, 15, 1, "     ESC=Salir Flechas=Subir/Bajar AvPag/RePag=Pag siguiente/anterior     ");
}