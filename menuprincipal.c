#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h> //System
//Funcion Menu principal
 
	//Funcion para limpiar pantalla
void limpiarPantalla (){  
	system("cls"); 
}
void limpiarBuffer(){
	int c ; 
	while ((c = getchar()) != '\n' && c != EOF);
}

	void mostrarMenu() {
	printf("__________________________________________________\n");
	printf("|Bienvenido al Sistema de Matriculacion Vehicular|\n");
	printf("|----------------------------------------------- |\n");   
	printf("|  1. Registrar vehiculo                         |\n");
	printf("|                                                |\n");
	printf("|  2. Calcular matricula                         |\n");
	printf("|                                                |\n");
	printf("|  3. Buscar vehiculo por placa                  |\n");
	printf("|                                                |\n");
	printf("|  4. Generar Comprobante                        |\n");
	printf("|                                                |\n");
	printf("|  5. Salir                                      |\n");
	printf("|________________________________________________|\n");
	printf("Seleccione una opcion: ");
}
