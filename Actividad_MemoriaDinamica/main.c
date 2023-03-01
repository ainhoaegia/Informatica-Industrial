#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la subestructura
typedef struct
{
    short codigo;
    char texto[30];
} Subestructura;

// Definición de la estructura principal
typedef struct
{
    char texto[30];
    int cantidad_lineas;
    Subestructura *subestructuras;
} Estructura;

// Función para leer el fichero de texto
void* LeeConfig(Estructura *estructura, char *nombre_fichero)
{
    FILE *fichero;
    char linea[100];
    int num_lineas = 0;
    int i = 0;

    // Abrir el fichero en modo lectura
    fichero = fopen(nombre_fichero, "r");
    if (fichero == NULL)
    {
        printf("Error al abrir el fichero.\n");
        exit(1);
    }

    // Leer el fichero línea por línea
    while (fgets(linea, 100, fichero))
    {
        num_lineas++;
    }

    // Asignar la cantidad de líneas leídas a la estructura
    estructura->cantidad_lineas = num_lineas;

    // Asignar memoria dinámicamente para la subestructura
    estructura->subestructuras = (Subestructura *)malloc(num_lineas * sizeof(Subestructura));
    if (estructura->subestructuras == NULL)
    {
        printf("Error al asignar memoria para la subestructura.\n");
        exit(1);
    }

    // Volver al inicio del fichero
    rewind(fichero);

    // Leer el fichero línea por línea y almacenar la información en la estructura
    while (fgets(linea, 100, fichero))
    {
        // Obtener el texto de no más de 30 caracteres
        strncpy(estructura->subestructuras[i].texto, linea, 30);
        estructura->subestructuras[i].texto[30] = '\0';

        // Obtener el código identificador de tipo short
        sscanf(linea + 16, "%hd", &estructura->subestructuras[i].codigo);

        i++;
    }

    // Cerrar el fichero
    fclose(fichero);
}

int main()
{
    char nombre_fichero[100];
    Estructura estructura;
    int i;
    int j;

    // Llamar a la función para leer el fichero
    LeeConfig(&estructura, "DatosConfig.txt");

    // Imprimir la información almacenada en la estructura
    printf("Ordenador donde esta el programa %s\n", estructura.subestructuras[0].texto);

    for (i = 2; i < estructura.cantidad_lineas; i++)
    {
        printf("Codigo del PLC %s\n", estructura.subestructuras[i].texto);
    }

    // Liberar la memoria asignada para la subestructura
    free(estructura.subestructuras);

    return 0;
}