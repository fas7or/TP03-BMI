#include <stdio.h>

int main() {
	
	int cantidad;
	int i;
	float nota;
	float suma = 0;
	float promedio;
	float mayor, menor;
	
	// Validación de la cantidad de estudiantes
	do {
		printf("Ingrese la cantidad de estudiantes: ");
		scanf("%d", &cantidad);
		
		if (cantidad <= 0) {
			printf("Error. Debe ingresar un numero positivo.\n\n");
		}
		
	} while (cantidad <= 0);
	
	// Ingreso de la primera nota
	do {
		printf("\nIngrese las calificaciones de los estudiantes.\n");
		printf("Las calificaciones deben estar comprendidas entre 0 y 100.\n\n");
		printf("\nIngrese la calificacion del estudiante 1: ");
		scanf("%f", &nota);
		
		if (nota < 0 || nota > 100) {
			printf("Error. La calificacion debe estar entre 0 y 100.\n");
		}
		
	} while (nota < 0 || nota > 100);
	
	suma = nota;
	mayor = nota;
	menor = nota;
	
	// Ingreso del resto de las notas
	for (i = 2; i <= cantidad; i++) {
		
		do {
			printf("Ingrese la calificacion del estudiante %d: ", i);
			scanf("%f", &nota);
			
			if (nota < 0 || nota > 100) {
				printf("Error. La calificacion debe estar entre 0 y 100.\n");
			}
			
		} while (nota < 0 || nota > 100);
		
		suma += nota;
		
		if (nota > mayor) {
			mayor = nota;
		}
		
		if (nota < menor) {
			menor = nota;
		}
		
	}
	
	promedio = suma / cantidad;
	
	printf("\n--------------------------------\n");
	printf("Promedio: %.2f\n", promedio);
	printf("Calificacion mas alta: %.2f\n", mayor);
	printf("Calificacion mas baja: %.2f\n", menor);
	
	return 0;
}
