/*****************************************
 * Nombre: DibujarGestionFichero
 * Argumentos: Window *Wfichero :   Ventana donde se va a dibujar el patrón
 * Descripción: Dibuja el patrón para leer el nombre del fichero y después de tratarlo mostrar
 *              el número de fichas de libros leídas y descartadas.
 * Reglas de uso:
 * Código de Retorno: N/A
 * Programador: LXMDOC (Oct, 2025)
 *****************************************/

// Include del módulo funcional
#include "Ventanas.h"

void DibujarGestionFichero(WINDOW *Wfichero)
{
    wcolor_set(Wfichero, 8, NULL);           // Texto celeste, fondo azul
    Cuadrado(Wfichero, 1, 0, 4, 76, SOLIDO); // Dibuja el marco para el contenido de la ventana

    wcolor_set(Wfichero, 9, NULL);                                  // Texto amarillo, fondo azul
    mvwprintw(Wfichero, 0, 22, "   Importar fichero de discos   "); // Impresión del título de la ventana
    /* La impresión inferior incluye una determinada cantidad de espacios' ' para
     que los espacios en blanco dentro de la ventana sean coloreados correctamente*/
    mvwprintw(Wfichero, 2, 1, " Nombre del fichero:                                                      ");
    mvwprintw(Wfichero, 3, 1, " Fichas tratadas:                 Fichas descartadas:                     ");
}