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
	int revisionesTecnicas;
}matricula;

typedef struct{
	char nombre_del_registrador[50]; //viva el snake_case carajoooooooo
	char contrasenia[20];
}PQR; // Es la persona_que_registra pero abreviado que el nombre es muy largo.

int  validarNumeros(const char);
int validarOracion(const char);
int esPlacaValida(const char);
void limpiarEspaciosExtra(const char); 
void limpiarExtremos(const char);
