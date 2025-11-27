/*****************************************
 * Nombre: ImortarFichero
 * Argumentos: DISCO **Fichas:   Puntero al array de discos
 *             WINDOW *Wfichero: Ventana para capturar el nombre del fichero
 *             bool sumar:       Si es true las fichas de discos se añaden a las existentes,
 *                               si es false la lista de discos tiene que estar vacía.
 * Descripción: Lee el nombre del fichero que contendrá los datos a importar. Carga los discos del fichero
 *              en el array de discos, dimensionándolo si es necesario y descartando los que no tengan título o autor.
 * Reglas de uso:
 * Código de Retorno:
 * Programador: JMSM (Sept-24)
 *****************************************/

#include "Ficheros.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#define MAX_BUF 8192

void ImportarFichero(DISCO **Fichas, WINDOW *Wfichero, bool sumar)
{
    FILE *fp;
    char **Linea;
    char *Aux;
    char caracter;
    char nombreFichero[50];
    int numerocaracteres = 0;
    int numeroLineas = 0;
    int caracterLinea = 0;
    int i, j;
    int numeroDiscos;
    int numFichas = Estadisticas.NumeroFichas;
    char buffer[MAX_BUF + 1];

    if (!sumar) // Si sumar = false y numFichas != 0, hay error.
    {
        if (numFichas)
        {
            VentanaError("Ya hay discos cargados.");
            return;
        }
    }
    else // Si sumar = true y numFichas == 0, hay error.
    {
        if (!numFichas)
        {
            VentanaError("No hay discos cargados para sumar.");
            return;
        }
    }

    // Limpio la ventana
    werase(Wfichero);
    DibujarGestionFichero(Wfichero);
    wcolor_set(Wfichero, 9, NULL);
    mvwprintw(Wfichero, 2, 22, "                                                   ");
    mvwprintw(Wfichero, 3, 18, "                ");

    while (true) // Captura el nombre del fichero a importar.
    {
        curs_set(1); // Activa visibilidad del cursor en pantalla.
        echo();
        nombreFichero[0] = 0;
        mvwgetnstr(Wfichero, 2, 22, nombreFichero, 50);                              // Captura el string ingresado en pantalla como nombre del fichero a importar.
        if (strlen(nombreFichero) == 0 || (strstr(nombreFichero, ".csv\0") == NULL)) // Control de errores para ficheros no validos.
        {
            VentanaError("El nombre del fichero no puede estar vacio y debe tener la extension .csv");
            return;
        }
        else
            break;
    }

    if ((fp = fopen(nombreFichero, "r")) == NULL) // Apertura del fichero indicado y control de errores.
    {
        VentanaError("Error al abrir el fichero.");
        return;
    }

    // Capturar el tiempo de inicio con microsegundos
    struct timeval tiempoInicio, tiempoFin;
    gettimeofday(&tiempoInicio, NULL);

    // Primero, contar el número de líneas para dimensionar correctamente
    numeroLineas = 0;
    while ((caracter = fgetc(fp)) != EOF)
    {
        if (caracter == '\n')
            numeroLineas++;
    }
    numeroDiscos = numeroLineas - 1; // # de discos igual a # de líneas - 1 (por el encabezado)

    // Reiniciar el puntero del archivo al inicio
    rewind(fp);

    if (sumar) // Si la operación es sumar, realocamos suficiente memoria.
        *Fichas = realloc(*Fichas, (numeroDiscos + numFichas + 1) * sizeof(DISCO));
    else // Si la operacion no es sumar, simplemente alocamos memoria por primera vez.
        *Fichas = (DISCO *)malloc((numeroDiscos + 1) * sizeof(DISCO));

    if (*Fichas == NULL) // Control de errores por falta de memoria o apertura del fichero.
    {
        VentanaError("Error al abrir el fichero.");
        return;
    }

    if (numeroDiscos < 1) // Si hay 0 o 1 lineas en el fichero, indicar que no hay discos en el fichero.
    {
        VentanaError("No hay discos en el fichero.");
        return;
    }

    // Descartar la primera linea (cabecera)
    fgets(buffer, sizeof(buffer), fp);

    // Reiniciar contadores para la lectura de las líneas de datos
    numeroLineas = 0;
    caracterLinea = 0;
    numerocaracteres = 0;

    // Lectura del fichero hasta EOF
    int fichasTratadas = 0;    // Índice para asignar discos válidos
    int fichasDescartadas = 0; // Contador acumulativo de discos descartados
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Cambiar el salto de línea a '\0'
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        // Tokenizar la línea usando strsep con delimitador ';'
        char *token;
        char *line = buffer;
        char *obra = strsep(&line, ";");
        char *apellAutor = strsep(&line, ";");
        char *nomAutor = strsep(&line, ";");
        char *tonalidad = strsep(&line, ";");
        char *opus = strsep(&line, ";");
        char *duracion = strsep(&line, ";");

        // Verificar si tiene título (obra) y autor (apellAutor)
        // El nomAutor no se debe verificar para descartar la ficha del disco
        if (obra && strlen(obra) > 0 && apellAutor && strlen(apellAutor) > 0)
        {
            // Asignar a la estructura DISCO
            (*Fichas)[fichasTratadas + numFichas].Obra = strdup(obra);
            (*Fichas)[fichasTratadas + numFichas].ApellAutor = strdup(apellAutor);
            (*Fichas)[fichasTratadas + numFichas].NomAutor = strdup(nomAutor);
            (*Fichas)[fichasTratadas + numFichas].Tonalidad = tonalidad ? strdup(tonalidad) : NULL;
            (*Fichas)[fichasTratadas + numFichas].Opus = opus ? strdup(opus) : NULL;
            (*Fichas)[fichasTratadas + numFichas].Duracion = duracion ? strdup(duracion) : NULL;
            fichasTratadas++;
        }
        else
        {
            // Incrementar numero de discos descartados
            fichasDescartadas++;
        }
        mvwprintw(Wfichero, 3, 19, "%d", fichasTratadas);
        mvwprintw(Wfichero, 3, 54, "%d", fichasDescartadas);
        wrefresh(Wfichero);
    }

    // Ajustar numeroDiscos al número real de discos válidos
    numeroDiscos = fichasTratadas;

    // Cerrar el fichero
    fclose(fp);

    // Capturar el tiempo de fin
    gettimeofday(&tiempoFin, NULL);

    // Actualizar las estadísticas
    Estadisticas.Fichero = strdup(nombreFichero);
    Estadisticas.NumeroFichas += numeroDiscos;
    Estadisticas.TiempoCarga = DifTiempo(tiempoInicio, tiempoFin);

    // Informar que se ha importado correctamente
    VentanaError("Los discos han sido importados correctamente");
}