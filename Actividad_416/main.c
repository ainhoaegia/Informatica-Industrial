#include <stdio.h>

typedef struct {
    unsigned char izquierda;    // 1 byte
    unsigned char derecha;      // 1 byte
} Estructura;

int main(int argc, char const *argv[]) {
    
    // Variables
    int contador = 1;
    int contadorGeneral = 0;
    int izq = 128;
    int drc = 1;

    // Instancia de la estructura Estructura
    Estructura e = {izq, drc};

    for (int a = 7; a >= 0; a--) {
        printf("%d", (e.izquierda >> a) & 1);
    } for (int b = 7; b >= 0; b--) {
        printf("%d", (e.derecha >> b) & 1);
    }

    int paleta = (2*sizeof(int)-1); // 7

    while (contadorGeneral < 2) {   // Limite de 2 para que no esté ejecuntando eternamente.
                                    // En caso de querer ejecucion eterna, poner while(1).
        contadorGeneral++;
        if ((e.izquierda == 128) && (e.derecha == 1)) {
            contador = 0;
            while (contador < paleta) {
                contador++;
                e.izquierda = e.izquierda / 2;
                e.derecha = e.derecha * 2;

                printf("\n");

                for (int a = 7; a >= 0; a--)
                {
                    printf("%d", (e.izquierda >> a) & 1);
                }
                for (int b = 7; b >= 0; b--)
                {
                    printf("%d", (e.derecha >> b) & 1);
                }
            }
        } if ((e.izquierda == 1) && (e.derecha == 128)) {
            contador = 0;
            while (contador < paleta)
            {
                contador++;
                e.izquierda = e.izquierda * 2;
                e.derecha = e.derecha / 2;

                printf("\n");

                for (int a = 7; a >= 0; a--)
                {
                    printf("%d", (e.izquierda >> a) & 1);
                }
                for (int b = 7; b >= 0; b--)
                {
                    printf("%d", (e.derecha >> b) & 1);
                }
            }
        }
    }
    return 0;
}