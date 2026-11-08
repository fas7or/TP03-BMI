//https://github.com/fas7or/TP03-BMI

#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int cuantas_piezas(int);
int rectificable(float, float);
int rechazada(float, float);

void cargar_piezas(float *, int);
int contar(int (*)(float, float), float, float *, int);
float* reserva_memoria(int);
void segregar(int (*)(float, float), float, float *, int, float *);
void mostrar_piezas(char *, float *, int);

int main (void) {
	float diametros[TAM] = {0};
	int n;
	float max = 12;
	float min = 10;
	
	n = cuantas_piezas(TAM);
	
	cargar_piezas(diametros, n);
	
	int n_rectificar = contar(rectificable, max, diametros, n);
	float *p_rectificables = reserva_memoria(n_rectificar);
	segregar(rectificable, max, diametros, n, p_rectificables);
	
	int n_rechazar = contar(rechazada, min, diametros, n);
	float *p_rechazadas = reserva_memoria(n_rechazar);
	segregar(rechazada, min, diametros, n, p_rechazadas);
	
	mostrar_piezas("rectificables", p_rectificables, n_rectificar);
	mostrar_piezas("rechazadas", p_rechazadas, n_rechazar);
	
	return 0;
}

int cuantas_piezas(int max) {
	int n;
	
	do {
		printf("Cuantas piezas ingresara? ");
		scanf("%d", &n);
	} while (n < 0 || n > max);
	
	return n;
}

int rectificable(float diametro, float valor) {
	if (diametro > valor)
		return 1;
	else
		return 0;
}

int rechazada(float diametro, float valor) {
	if (diametro < valor)
		return 1;
	else
		return 0;
}

/* a) Cargar los diametros */
void cargar_piezas(float *p, int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		do {
			printf("Ingrese diametro de pieza %d: ", i);
			scanf("%f", p + i);
			
			if (*(p + i) <= 0) {
				printf("Error: el diametro debe ser positivo.\n");
			}
			
		} while (*(p + i) <= 0);
	}
}

/* b) Contar las piezas que cumplen un criterio */
int contar(int (*criterio)(float, float), float valor, float *p, int n) {
	int i;
	int cantidad = 0;
	
	for (i = 0; i < n; i++) {
		if (criterio(*(p + i), valor) == 1) {
			cantidad++;
		}
	}
	
	return cantidad;
}

/* c) Reservar memoria dinamica */
float* reserva_memoria(int n) {
	float *p;
	
	if (n == 0) {
		return NULL;
	}
	
	p = (float*) malloc(n * sizeof(float));
	
	if (p == NULL) {
		printf("Error: no se pudo reservar memoria.\n");
		exit(EXIT_FAILURE);
	}
	
	return p;
}

/* d) Copiar las piezas que cumplen el criterio */
void segregar(int (*criterio)(float, float), float valor,
				   float *p, int n, float *q) {
	int i;
	int j = 0;
	
	for (i = 0; i < n; i++) {
		if (criterio(*(p + i), valor) == 1) {
			*(q + j) = *(p + i);
			j++;
		}
	}
}
				   
				   /* e) Mostrar los diametros */
				   void mostrar_piezas(char *mensaje, float *p, int n) {
					   int i;
					   
					   printf("Piezas %s:\n", mensaje);
					   
					   for (i = 0; i < n; i++) {
						   printf("Diametro: %.2f\n", *(p + i));
					   }
				   }
				   
