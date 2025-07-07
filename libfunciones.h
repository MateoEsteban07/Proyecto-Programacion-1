#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"libfunciones.c"

typedef struct{
	char nombre[50];
	char placa[12];
	char anio[10];
	char cedula[20];
	float avaluo;
	int cilindraje;
	int tipo;
	int peso;
}matricula;

int  validarNumeros(const char);
int validarOracion(const char);
int esPlacaValida(const char);

