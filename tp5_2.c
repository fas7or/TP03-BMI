//repositorio: https://github.com/fas7or/TP03-BMI/tree/main//


#include <stdio.h>

int main() {
	
	float peso;
	float altura;
	float bmi;
	
	do {
		
		printf("Ingrese el peso en kg: ");
		scanf("%f", &peso);
		
		if (peso < 0) {
			printf("Error. El peso no puede ser negativo.\n");
		}
		
	} while (peso < 0);
	
	do {
		
		printf("Ingrese la altura en metros: ");
		scanf("%f", &altura);
		
		if (altura < 0) {
			printf("Error. La altura no puede ser negativa.\n");
		}
		
	} while (altura < 0);
	
	bmi = peso / (altura * altura);
	
	printf("\nIMC = %.2f\n\n", bmi);
	
	printf("Clasificacion:\n");
	printf("------------------------\n");
	printf("<18.5        Bajo peso\n");
	printf("18.5-24.9    Normal\n");
	printf("25.0-29.9    Sobrepeso\n");
	printf(">=30         Obesidad\n\n");
	
	if (bmi < 18.5)
		printf("Su condicion es: Bajo peso\n");
	else if (bmi < 25)
		printf("Su condicion es: Normal\n");
	else if (bmi < 30)
		printf("Su condicion es: Sobrepeso\n");
	else
		printf("Su condicion es: Obesidad\n");
	
	return 0;
}
