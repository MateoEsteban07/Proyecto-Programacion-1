#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"libfunciones.h"
#include"menuprincipal.c" 
int opcion, peso_v, anioint;
float valor_a_pagar, impverde;
void registro(matricula* matriculas){ 
	//VALIDACION DE NOMBRE    
	do{
		printf ("Ingrese su nombre completo: \n");
		fgets(matriculas->nombre, sizeof(matriculas->nombre), stdin);
		matriculas->nombre[strcspn(matriculas->nombre, "\n")] = 0;
		if(validarOracion(matriculas->nombre)==0){
			limpiarPantalla();
			printf("Ingrese solo letras.\n");
		}
	}while(validarOracion(matriculas->nombre)==0);
	
	//VALIDACION DE CEDULA
	do{
		printf("Ingrese cedula: \n");
		fgets(matriculas->cedula, sizeof(matriculas->cedula), stdin);
		matriculas->cedula[strcspn(matriculas->cedula, "\n")] = 0;
		if (validarNumeros(matriculas->cedula)==0 || strlen(matriculas->cedula)!=10){
			limpiarPantalla();
			printf("Ingrese una cedula valida (10 digitos-solo numeros).\n");
		}
	}while(validarNumeros(matriculas->cedula)==0 || strlen(matriculas->cedula)!=10);
	
	//VALIDAR PLACA
	do{
		printf("Ingrese placa: \n");
		fgets(matriculas->placa, sizeof(matriculas->placa), stdin);
		matriculas->placa[strcspn(matriculas->placa, "\n")] = 0;
		if (esPlacaValida(matriculas->placa)==0){
			limpiarPantalla();
			printf("Ingrese placa valida (ABC1234 sin guion).\n");
		}
	}while(esPlacaValida(matriculas->placa)==0);    
	
	//VALIDAR ANIO

	do{
		printf("Ingrese el anio del vehiculo: \n");
		fgets(matriculas->anio, sizeof(matriculas->anio), stdin);
		matriculas->anio[strcspn(matriculas->anio, "\n")] = 0;
		anioint = atoi(matriculas->anio); 
		if (validarNumeros(matriculas->anio)==0 || anioint < 1900 || anioint > 2025){
			limpiarPantalla();
			printf("Ingrese un anio valido 1900-2025.\n");
		}
	}while(validarNumeros(matriculas->anio)==0 || anioint < 1900 || anioint > 2025);
	
	//VALIDAR AVALUO    
	do {
		printf("Ingrese el avaluo del vehiculo: \n");
		
		if (scanf("%f", &matriculas->avaluo) != 1) {  
			printf("Error: Entrada invalida. Intente nuevamente.\n");
			while (getchar() != '\n');  
			continue;  
		}
		
		if (matriculas->avaluo <= 0) {
			limpiarPantalla();
			printf("Ingrese un avaluo valido.\n");
		}
	} while (matriculas->avaluo <= 0);
	
	//VALIDAR CILINDRAJE
	do{
		printf("Ingrese el cilindraje del vehiculo en centimetro cubicos: \n");
		
		if (scanf("%d", &matriculas->cilindraje) != 1) {
			printf("Error: Entrada invalida. Intente nuevamente. \n");
			while (getchar() != '\n');  
			continue; 
		}
		
		if(matriculas->cilindraje <=0){
			limpiarPantalla();
			printf("Ingrese un cilindraje valido.\n");
		}
	} while(matriculas->cilindraje <=0);
	
	//VALIDAR TIPO
	do{
		printf("Ingrese el tipo de vehiculo, electrico[0] combustible[1]: \n");
		scanf("%d", &matriculas->tipo);
		
		switch(matriculas->tipo){
		case 0:
			impverde=0;
			break;
		case 1:
			impverde=1; //VALOR TEMPORAL
			break;
		default:
			limpiarPantalla();
			printf("Error: Entrada invalida. Intente nuevamente. \n");
		}
	} while(matriculas->tipo != 0 && matriculas->tipo !=1);
	
	// VALIDAR PESO
	do{
		printf("Ingrese el tipo de vehiculo, liviano[0] pesado[1]: \n");
		scanf("%d", &matriculas->peso);
		
		switch(matriculas->peso){
		case 0:
			peso_v=0;
			break;
		case 1:
			peso_v=1; //VALOR TEMPORAL
			break;
		default:
			limpiarPantalla();
			printf("Error: Entrada invalida. Intente nuevamente. \n");
		}
	} while(matriculas->peso != 0 && matriculas->peso !=1);
	
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
	////////// FUNCION DE CALCULAR MATRICULA ////////
	void calcular_matricula(matricula* m){
		float edad_v, tarifa_edad, tarifa_cilindraje, valor_de_imp_verde;
		edad_v= 2025- anioint;
		
		if (m->cilindraje <= 1500) {
			tarifa_cilindraje = 0;
		} else if (m->cilindraje <= 2000) {
			tarifa_cilindraje = 0.08;
		} else if (m->cilindraje <= 2500) {
			tarifa_cilindraje = 0.09;
		} else if (m->cilindraje <= 3000) {
			tarifa_cilindraje = 0.11;
		} else if (m->cilindraje <= 3500) {
			tarifa_cilindraje = 0.12;
		} else if (m->cilindraje <= 4000) {
			tarifa_cilindraje = 0.24;
		} else {
			tarifa_cilindraje = 0.35; // Para cilindrajes mayores a 4000
		}
		
		if (edad_v <= 5) {
			tarifa_edad = 0;
		} else if (edad_v <= 10) {
			tarifa_edad = 0.05;
		} else if (edad_v <= 15) {
			tarifa_edad = 0.1;
		} else if (edad_v <= 20) {
			tarifa_edad = 0.15;
		} else {
			tarifa_edad = 0.20; // Para anos mayores a 20
		}
		
		if(impverde==1){
			valor_de_imp_verde=((m->cilindraje-1500)*tarifa_cilindraje)*(1+ tarifa_edad);
			printf("\n El valor del impuesto verde es de: %.3f $ \n ",valor_de_imp_verde);
			printf("\n El valor a pagar es de: %.3f $ \n ", valor_de_imp_verde + (m->avaluo)/100 +22 + 10);
			
		}
		if(impverde==0){
			valor_de_imp_verde= 0;
			printf("\n El valor del impuesto verde es de: %.3f $ \n ",valor_de_imp_verde);
			printf("\n El valor a pagar es de: %.3f $ \n ", valor_de_imp_verde + (m->avaluo)/100 +22 + 10);
		}

	}
	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////
	
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
				registro(&vehiculoRegistrado); 
				limpiarPantalla();
				break;
			case 2:
				limpiarPantalla();
				calcular_matricula(&vehiculoRegistrado);
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
