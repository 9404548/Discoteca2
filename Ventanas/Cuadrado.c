/*****************************************
 * Nombre: Cuadrado
 * Argumentos: Window *Wventana :   Ventana donde se va a dibujar el cuadrado
 *             int y            :   Coordenada y de la esquina superior izquierda
 *             int x            :   Coordenada x de la esquina superior izquierda
 *             int lineas       :   Alto del cuadrado medido en líneas
 *             int columnas     :   Ancho del cuadrado medido en columnas
 *             char tipo        :   SOLIDO -> Se dibuja el cuadrado con los caracteres gráficos sólidos
 *                              :   DOSRAYAS -> Se dibuja el cuadrado con los cracteres gráficos de dos rayas simples
 * Descripción: Dibuja un cuadrado en pantalla con los datos dados
 * Reglas de uso:
 * Código de Retorno: N/A
 * Programador: Luis Xavier Montes de Oca Campos, modificado por última vez 5 de octubre del 2025.
 *****************************************/

// Include del módulo funcional
#include "Ventanas.h"

void Cuadrado(WINDOW *Wventana, int y, int x, int lineas, int columnas, char tipo)
{
    int i;
    char lineaSolido[7] = {'L', 'K', 'M', 'J', 'Q', 'X', '\0'}; // array de caracteres cuyo char alternativo corresponde a los componentes de un marco sólido
    char lineaRayas[7] = {'C', 'B', 'D', 'A', 'R', 'Y', '\0'};  // array de caracteres cuyo char alternativo corresponde a los componentes de un marco de dos rayas
    char linea[7];                                              // char vacío en donde se va a copiar el tipo de marco elegido

    if (tipo == SOLIDO) // condición 'if' que determina el array de chars a copiar al array vacío según la configuración elegida en la llamada a la función
    {
        strcpy(linea, lineaSolido);
    }
    else if (tipo == DOSRAYAS)
    {
        strcpy(linea, lineaRayas);
    }

    wattron(Wventana, A_ALTCHARSET); // activa los caracteres alternativos, de manera que se imprima el cuadrado en vez de las letras en los arrays

    mvwaddch(Wventana, y, x, linea[0]);                             // imprime en la posición fila y, columna x (esquina superior izquierda)
    mvwaddch(Wventana, y, x + columnas - 1, linea[1]);              // imprime en la fila 'y', última columna
    mvwaddch(Wventana, y + lineas - 1, x, linea[2]);                // imprime en la última fila, primera columna
    mvwaddch(Wventana, y + lineas - 1, x + columnas - 1, linea[3]); // imprime en la última fila, última columna

    for (i = 1; i < columnas - 1; i++) // imprime las filas superior e inferior del cuadrado
    {
        mvwaddch(Wventana, y, x + i, linea[4]);
        mvwaddch(Wventana, y + lineas - 1, x + i, linea[4]);
    }

    for (i = 1; i < lineas - 1; i++) // imprime las columnas laterales (izq. y der.)
    {
        mvwaddch(Wventana, y + i, x, linea[5]);
        mvwaddch(Wventana, y + i, x + columnas - 1, linea[5]);
    }

    wattroff(Wventana, A_ALTCHARSET); // desactiva los caracteres alternativos
    wrefresh(Wventana);               // recarga la ventana para mostrar los cambios realizados

    return;
}