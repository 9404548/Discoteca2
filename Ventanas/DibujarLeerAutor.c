/*****************************************
 * Nombre: DibujarLeerAutor
 * Argumentos: Window *Wautor:   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para leer el comienzo del apellido del autor(es) de los que se desean
 *              buscar y listar sus libros.
 * Reglas de uso:
 * Código de Retorno: N/A
 * Programador: Luis Xavier Montes de Oca Campos, modificado por última vez 5 de octubre del 2025.
 *****************************************/

// Include del módulo funcional
#include "Ventanas.h"

void DibujarLeerAutor(WINDOW *Wautor)
{
    wcolor_set(Wautor, 8, NULL);           // Cambio de color de impresión de fondo y de texto (fondo azul, texto celeste)
    Cuadrado(Wautor, 1, 0, 3, 76, SOLIDO); // Llamada a cuadrado para enmarcar el contenido relevante de la ventana

    wcolor_set(Wautor, 9, NULL);                    // Color de fondo azul, texto amarillo
    mvwprintw(Wautor, 0, 29, "Busqueda por autor"); // Impresión del título de la ventana
    /* La impresión inferior incluye una determinada cantidad de espacios' ' para
     que los espacios en blanco dentro de la ventana sean coloreados correctamente*/
    mvwprintw(Wautor, 2, 1, " Apellidos del autor:                                                     ");
}