#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"libfunciones.h"
#include"menuprincipal.c" 

void registro(matricula matriculas){ 
	int opcion; 
	
	//VALIDACION DE NOMBRE    
	do{
		printf ("Ingrese su nombre completo: \n");
		fgets(matriculas.nombre, sizeof(matriculas.nombre), stdin);
		matriculas.nombre[strcspn(matriculas.nombre, "\n")] = 0;
		if(validarOracion(matriculas.nombre)==0){
			limpiarPantalla();
			printf("Ingrese solo letras.\n");
		}
	}while(validarOracion(matriculas.nombre)==0);
	
	//VALIDACION DE CEDULA
	do{
		printf("Ingrese cedula: \n");
		fgets(matriculas.cedula, sizeof(matriculas.cedula), stdin);
		matriculas.cedula[strcspn(matriculas.cedula, "\n")] = 0;
		if (validarNumeros(matriculas.cedula)==0 || strlen(matriculas.cedula)!=10){
			limpiarPantalla();
			printf("Ingrese una cedula valida (10 digitos-solo numeros).\n");
		}
	}while(validarNumeros(matriculas.cedula)==0 || strlen(matriculas.cedula)!=10);
	
	//VALIDAR PLACA
	do{
		printf("Ingrese placa: \n");
		fgets(matriculas.placa, sizeof(matriculas.placa), stdin);
		matriculas.placa[strcspn(matriculas.placa, "\n")] = 0;
		if (esPlacaValida(matriculas.placa)==0){
			limpiarPantalla();
			printf("Ingrese placa valida (ABC123 sin guion).\n");
		}
	}while(esPlacaValida(matriculas.placa)==0);    
	
	//VALIDAR ANIO
	int anioint;
	do{
		printf("Ingrese el anio del vehiculo: \n");
		fgets(matriculas.anio, sizeof(matriculas.anio), stdin);
		matriculas.anio[strcspn(matriculas.anio, "\n")] = 0;
		anioint = atoi(matriculas.anio); 
		if (validarNumeros(matriculas.anio)==0 || anioint < 1900 || anioint > 2025){
			limpiarPantalla();
			printf("Ingrese un anio valido 1900-2025.\n");
		}
	}while(validarNumeros(matriculas.anio)==0 || anioint < 1900 || anioint > 2025);
	
	//VALIDAR AVALUO    
	do {
		printf("Ingrese el avaluo del vehiculo: \n");
		
		if (scanf("%f", &matriculas.avaluo) != 1) {  
			printf("Error: Entrada invalida. Intente nuevamente.\n");
			while (getchar() != '\n');  
			continue;  
		}
		
		if (matriculas.avaluo <= 0) {
			limpiarPantalla();
			printf("Ingrese un avaluo valido.\n");
		}
	} while (matriculas.avaluo <= 0);
	limpiarPantalla();
	//Recursividad
	printf("¿Desea ingresar mas datos?(Si=1, No=0)\n");
	scanf("%d", &opcion);
	while (getchar()!= '\n');
	if (opcion == 0){   //caso base//
		printf("GRACIAS POR USAR\n");
		return;
	} else{ 
		limpiarPantalla();
		registro(matriculas); 
	}
}
	
	int main (){
		matricula vehiculoRegistrado; 
				
		int option;
		do {
			mostrarMenu();
			if (scanf("%d", &option) != 1) {
				printf("Entrada invalida. Intente nuevamente.\n");
				limpiarBuffer(); 
				option = 0;
				continue;
			}
			limpiarBuffer();        
			switch (option) {
			case 1:
				limpiarPantalla();
				registro(vehiculoRegistrado); 
				limpiarPantalla();
				break;
			case 2:
				limpiarPantalla();
				printf("No aun\n");
				break;
			case 3:
				limpiarPantalla();
				printf("Funcion no implementada\n");
				break;
			case 4:
				limpiarPantalla();
				printf("Funcion no implementada\n"); 
				break;
			case 5:
				limpiarPantalla();
				printf("Nos vemos pronto...\n");
				break;
			default:
				limpiarPantalla();
				printf("Opcion no valida.(1-5).\n");
			}
		} while (option != 5);
		
		return 0;
	}
