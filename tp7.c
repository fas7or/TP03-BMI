#include <stdio.h>
#define TAM 5

int main() {
	int codigos[TAM];
	float precios[TAM];
	int i;
	int codigo;
	float precio;
	int posicionMayor = 0;
	int posicionMenor = 0;
	
	printf("Ingrese %d productos, se solicitara el codigo y precio:\n", TAM);
	
	for (i = 0; i < TAM; i++) {
		
				do {
			printf("Ingrese el codigo de barras (1-999999999): ");
			scanf("%d", &codigo);
			
			if (codigo < 1 || codigo > 999999999) {
				printf("Error. El codigo de barras debe estar entre 1 y 999999999\n");
			}
			
		} while (codigo < 1 || codigo > 999999999);
		
		codigos[i] = codigo;
		
				do {
			printf("Ingrese el precio: ");
			scanf("%f", &precio);
			
			if (precio < 0) {
				printf("Error. El precio no puede ser negativo.\n");
			}
			
		} while (precio < 0);
		
		precios[i] = precio;
	}
	
		printf("\nCodigo       Precio\n");
	
	for (i = 0; i < TAM; i++) {
		printf("%-12d %.2f\n", codigos[i], precios[i]);
	}
	
		for (i = 1; i < TAM; i++) {
		if (precios[i] > precios[posicionMayor]) {
			posicionMayor = i;
		}
		
		if (precios[i] < precios[posicionMenor]) {
			posicionMenor = i;
		}
	}
	
		printf("\nMas caro: [%d] %.2f\n",
		   codigos[posicionMayor], precios[posicionMayor]);
	
	printf("Mas barato: [%d] %.2f\n",
		   codigos[posicionMenor], precios[posicionMenor]);
	
	return 0;
}
