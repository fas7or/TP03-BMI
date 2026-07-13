#include <stdio.h>

int main() {
	
	int nota;
	
	printf("Ingrese la calificacion: ");
	scanf("%d", &nota);
	
	if (nota >= 90) {
		printf("Calificacion: A\n");
	}
	else if (nota >= 80) {
		printf("Calificacion: B\n");
	}
	else if (nota >= 70) {
		printf("Calificacion: C\n");
	}
	else if (nota >= 60) {
		printf("Calificacion: D\n");
	}
	else {
		printf("Calificacion: F\n");
	}
	
	return 0;
}
