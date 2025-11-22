/*****************************************
 * Nombre: ExportarFichero
 * Argumentos: DISCO **Fichas:   Puntero al array de discos
 *             WINDOW *Wfichero: Ventana para capturar el nombre del fichero
 * Descripción: Lee el nombre del fichero que contendrá los datos a exportar. Exporta los datos de la estructura
 *              de todos los discos en el fichero.
 * Reglas de uso:
 * Código de Retorno:
 * Programador: JMSM (Sept-24), LXMDOC (Oct-25)
 *****************************************/

#include "Ficheros.h"

void ExportarFichero(DISCO **Fichas, WINDOW *Wfichero)
{
    char linea[52];
    char linea1[52];
    char Tecla;
    int i;
    FILE *exportarFichero;

    //     Comprobar si hay discos para exportar. Mostrar error si no los hay.
    if (Estadisticas.NumeroFichas == 0)
    {
        VentanaError("No hay discos para exportar.");
    }
    else
    {
        // Se captura el nombre del fichero que contendrá los discos exportados. No puede estar en blanco
        while (true)
        {
            curs_set(1); // Encender visibilidad del cursor
            echo();
            linea[0] = 0;
            mvwgetnstr(Wfichero, 2, 23, linea, 50); // Captura los caracteres escritos sobre la pantalla en las coordenadas indicadas y las guarda en linea.
            if (strlen(linea) == 0)                 // Captura el error de un nombre de fichero vacio
            {
                //     Capturar el nombre del fichero que contendrá los discos exportados.
                Tecla = VentanaSN("El nombre del fichero no puede estar vacio. Desea continuar (S/N)?");
                if (Tecla == 'N')
                    VentanaError("");
                return;
            }
            else
                break;
        }

        curs_set(0); // Apagar visibilidad del cursor.

        if ((exportarFichero = fopen(linea, "w")) == NULL) // Abrir el fichero en escritura y controlar si ha habido error.
            VentanaError("Error al crear/abrir el fichero ingresado para exportar.");

        fprintf(exportarFichero, "Obra;Apellido Autor;Nombre Autor;Tonalidad;Opus;Duracion\n"); // Escribir la cabecera en el fichero.

        for (i = 1; i < Estadisticas.NumeroFichas; i++) // Escribir linea por linea con los datos del disco separados por ‘;’,
            fprintf(exportarFichero, "%s;%s;%s;%s;%s;%s\n", (*Fichas)[i].Obra, (*Fichas)[i].ApellAutor, (*Fichas)[i].NomAutor, (*Fichas)[i].Tonalidad, (*Fichas)[i].Opus, (*Fichas)[i].Duracion);

        fclose(exportarFichero); //     Cerrar el fichero

        mvwprintw(Wfichero, 3, 9, "exportadas: %d", Estadisticas.NumeroFichas); // Mostrar el número de discos exportados.

        touchwin(Wfichero);
        wrefresh(Wfichero);

        VentanaError("Los discos se han exportado correctamente"); // Informar que los discos se han exportado correctamente
    }
}
