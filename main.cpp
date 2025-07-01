#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"libfunciones.h"
#include"menuprincipal.c" 
#define MAX_REGISTROS 135
int opcion, peso_v, anioint;
float valor_a_pagar, impverde;
void registro(matricula* lista, int* total) { 
	if (*total >= 100) {
		printf("Se alcanzó el número máximo de registros.\n");
		return;
	}
	matricula* matriculas = &lista[*total];
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
		printf("Ingrese placa (ABC1234 sin guion): \n");
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
		
		if (matriculas->avaluo <= 0 || matriculas->avaluo > 900000) {
			limpiarPantalla();
			printf("Ingrese un avaluo valido.\n");
		}
	} while (matriculas->avaluo <= 0 || matriculas->avaluo > 900000);
	
	//VALIDAR CILINDRAJE
	do{
		printf("Ingrese el cilindraje del vehiculo en centimetro cubicos: \n");
		
		if (scanf("%d", &matriculas->cilindraje) != 1) {
			printf("Error: Entrada invalida. Intente nuevamente. \n");
			while (getchar() != '\n');  
			continue; 
		}
		
		if(matriculas->cilindraje <=0 || matriculas->cilindraje > 110000){
			limpiarPantalla();
			printf("Ingrese un cilindraje valido.\n");
		}
	} while(matriculas->cilindraje <=0 || matriculas->cilindraje > 110000);
	
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
	(*total)++;
	//Recursividad
	printf("¿Desea ingresar mas datos? (Si=1, No=0): ");
	int opcion = 0;
	scanf("%d", &opcion);
	while (getchar() != '\n');
	
	if (opcion == 1) {
		limpiarPantalla();
		registro(lista, total);
	} else {
		printf("Gracias por registrar los datos.\n");
	}
}
	////////// FUNCION DE CALCULAR MATRICULA ////////
void calcular_matricula(matricula* m) {
	float tarifa_edad = 0.0, tarifa_cilindraje = 0.0, valor_de_imp_verde = 0.0;
	int anioExtraido = atoi(m->anio);
	int edad_v = 2025 - anioExtraido;
	
	// Calcular tarifa por cilindraje
	if (m->cilindraje <= 1500) {
		tarifa_cilindraje = 0.0;
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
		tarifa_cilindraje = 0.35;
	}
	
	// Calcular tarifa por edad
	if (edad_v <= 5) {
		tarifa_edad = 0.0;
	} else if (edad_v <= 10) {
		tarifa_edad = 0.05;
	} else if (edad_v <= 15) {
		tarifa_edad = 0.10;
	} else if (edad_v <= 20) {
		tarifa_edad = 0.15;
	} else {
		tarifa_edad = 0.20;
	}
	
	// Calcular impuesto verde
	if (m->tipo == 1) { // Vehículo a combustible
		valor_de_imp_verde = ((m->cilindraje - 1500) * tarifa_cilindraje) * (1 + tarifa_edad);
	} else { // Vehículo eléctrico
		valor_de_imp_verde = 0.0;
	}
	
	// Total a pagar
	float valor_a_pagar = valor_de_imp_verde + (m->avaluo / 100) + 22 + 10;
	
	// Mostrar resultados
	printf("\n--- DETALLES DE MATRICULA ---\n");
	printf("Placa: %s\n", m->placa);
	printf("Anio: %s (Edad: %d años)\n", m->anio, edad_v);
	printf("Cilindraje: %d\n", m->cilindraje);
	printf("Avaluo: %.2f\n", m->avaluo);
	printf("Tipo: %s\n", m->tipo == 1 ? "Combustible" : "Electrico");
	printf("Impuesto verde: %.2f $\n", valor_de_imp_verde);
	printf("Total a pagar: %.2f $\n", valor_a_pagar);
}
/////////////////////////////////////////////////
		void calcularPorPlaca(matricula* registros, int total) {
			char placaBuscar[12];
			int encontrado = 0;
			
			printf("Ingrese la placa para calcular la matricula: ");
			scanf("%s", placaBuscar);
			
			for (int i = 0; i < total; i++) {
				if (strcmp(registros[i].placa, placaBuscar) == 0) {
					calcular_matricula(&registros[i]);
					encontrado = 1;
					break;
				}
			}
			
			if (!encontrado) {
				printf("No se encontro un auto con la placa %s.\n", placaBuscar);
			}
		}
////////////////////////////////////////////////
	void buscarplaca(matricula* matriculas, int total, const char* placaBuscada) {
		int encontrado = 0;
		for (int i = 0; i < total; i++) {
			if (strcmp(matriculas[i].placa, placaBuscada) == 0) {
				printf("Registro encontrado:\n");
				printf("Nombre: %s\n", matriculas[i].nombre);
				printf("Placa: %s\n", matriculas[i].placa);
				printf("Anio: %s\n", matriculas[i].anio);
				printf("Cedula: %s\n", matriculas[i].cedula);
				printf("Avaluo: %.2f\n", matriculas[i].avaluo);
				printf("Cilindraje: %d\n", matriculas[i].cilindraje);
				printf("Tipo: %d\n", matriculas[i].tipo);
				printf("Peso: %d\n", matriculas[i].peso);
				encontrado = 1;
				break;
				}
			}
			if (!encontrado) {
				printf("No se encontro un auto con la placa %s.\n", placaBuscada);
			}
		}
	////////////////////////////////////////////////////////////////////
	void guardarEnArchivo(matricula* registros, int total) {
		FILE* archivo = fopen("vehiculos_registrados.txt", "w");
		
		if (archivo == NULL) {
			printf("Error al abrir el archivo para escritura.\n");
			return;
		}
		
		for (int i = 0; i < total; i++) {
			fprintf(archivo, "Registro #%d\n", i + 1);
			fprintf(archivo, "Nombre: %s\n", registros[i].nombre);
			fprintf(archivo, "Cedula: %s\n", registros[i].cedula);
			fprintf(archivo, "Placa: %s\n", registros[i].placa);
			fprintf(archivo, "Anio: %s\n", registros[i].anio);
			fprintf(archivo, "Avaluo: %.2f\n", registros[i].avaluo);
			fprintf(archivo, "Cilindraje: %d\n", registros[i].cilindraje);
			fprintf(archivo, "Tipo: %s\n", registros[i].tipo == 1 ? "Combustible" : "Eléctrico");
			fprintf(archivo, "Peso: %s\n", registros[i].peso == 1 ? "Pesado" : "Liviano");
			fprintf(archivo, "--------------------------\n");
		}
		
		fclose(archivo);
		printf("Registros guardados exitosamente en 'vehiculos_registrados.txt'\n");
	}
	////////////////////////////////////////////////////////////////////
	
	int main (){
		matricula registros[MAX_REGISTROS]; 
		int totalRegistros = 0;
		int option;
		char placaBuscar[12];
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
				registro(registros, &totalRegistros); 
				limpiarPantalla();
				break;
			case 2:
				limpiarPantalla();
				if (totalRegistros > 0) {
					calcularPorPlaca(registros, totalRegistros); // Último ingresado
				} else {
					printf("No hay registros.\n");
				}
				break;
			case 3:
				limpiarPantalla();
				printf("Ingrese la placa que desea buscar: \n");
				scanf("%s", placaBuscar);
				buscarplaca(registros, totalRegistros, placaBuscar);
				break;
			case 4:
				limpiarPantalla();
				guardarEnArchivo(registros, totalRegistros);
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
