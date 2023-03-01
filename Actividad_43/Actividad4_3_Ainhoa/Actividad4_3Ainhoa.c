#include <stdio.h>
#include <stdlib.h>

int leeValor(void);

int main() {
	int contador1 = 0;
	int contador2 = 0;
	int array1[100];
	int array2[100];
	int *puntero = 0;
	int *contador = 0;

	for (int i = 0; i < 100; i++) {
		int valor = leeValor();
		if (valor == -1) {
			puntero = array1;
			contador = &contador1;
		}
		if (valor == -2) {
			puntero = array2;
			contador = &contador2;
		}
		if (valor > 0) {
			puntero[*contador] = valor;
			(*contador)++;
		}	
	}

	printf("Los elementos del array 1 son: %d\n", contador1+1);
	
	for (int i = 0; i < contador1; i++) {
		printf("%d, ", array1[i]);
	}
	printf("\n");

	printf("Los elementos del array 2 son: %d\n", contador2 + 1);

	for (int i = 0; i < contador2; i++) {
		printf("%d, ", array2[i]);
	}

	printf("\n");

	return(0);
}