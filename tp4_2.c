#include <stdio.h>
#include <stdlib.h>

float peso;
float altura;
float bmi;

int main() {
	
	printf("Ingrese el peso en kg: ");
	scanf("%f", &peso);
	
	printf("\nIngrese la altura en metros: ");
	scanf("%f", &altura);
	
	bmi = peso / (altura * altura);
	
	printf("\n\nSu indice de masa corporal es: %.2f\n\n", bmi);
	
	printf("    Indice    |  Condicion\n");
	printf("-----------------------------\n");
	printf("    <18.5     |  Bajo peso\n");
	printf(" 18.5 a 24.9  |  Normal\n");
	printf(" 25.0 a 29.9  |  Sobrepeso\n");
	printf("     >=30     |  Obesidad\n\n");
	
	if (bmi < 18.5) {
		printf("Su condicion es: Bajo peso\n");
	}
	else if (bmi < 25.0) {
		printf("Su condicion es: Normal\n");
	}
	else if (bmi < 30.0) {
		printf("Su condicion es: Sobrepeso\n");
	}
	else {
		printf("Su condicion es: Obesidad\n");
	}
	
	return 0;
}
