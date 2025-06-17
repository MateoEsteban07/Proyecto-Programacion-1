#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libfunciones.h" 

// La función registro ahora recibe un PUNTERO a matricula y pide TODOS los datos
void registro(matricula *matriculas) { 
	// Validación nombre
	do {
		printf("Ingrese su nombre completo: \n");
		fgets(matriculas->nombre, sizeof(matriculas->nombre), stdin); 
		matriculas->nombre[strcspn(matriculas->nombre, "\n")] = 0;
		if (validarOracion(matriculas->nombre) == 0) {
			printf("Ingrese solo letras.\n");
		}
	} while (validarOracion(matriculas->nombre) == 0);
	
	// Validación cédula
	do {
		printf("Ingrese cedula: \n");
		fgets(matriculas->cedula, sizeof(matriculas->cedula), stdin);
		matriculas->cedula[strcspn(matriculas->cedula, "\n")] = 0;
		if (validarNumeros(matriculas->cedula) == 0 || strlen(matriculas->cedula) != 10) {
			printf("Ingrese una cedula valida (10 digitos - solo numeros).\n");
		}
	} while (validarNumeros(matriculas->cedula) == 0 || strlen(matriculas->cedula) != 10);
	
	// Validación placa
	do {
		printf("Ingrese placa: \n");
		fgets(matriculas->placa, sizeof(matriculas->placa), stdin);
		matriculas->placa[strcspn(matriculas->placa, "\n")] = 0;
		if (esPlacaValida(matriculas->placa) == 0) {
			printf("Ingrese placa valida (ABC123 sin guion).\n");
		}
	} while (esPlacaValida(matriculas->placa) == 0);
	
	// Validar año (del vehículo)
	int anioint;
	do {
		printf("Ingrese el anio del vehiculo (1900-2025): \n");
		fgets(matriculas->anio, sizeof(matriculas->anio), stdin);
		matriculas->anio[strcspn(matriculas->anio, "\n")] = 0;
		anioint = atoi(matriculas->anio);
		if (validarNumeros(matriculas->anio) == 0 || anioint < 1900 || anioint > 2025) {
			printf("Ingrese un año valido.\n");
		}
	} while (validarNumeros(matriculas->anio) == 0 || anioint < 1900 || anioint > 2025);
	
	// Validar avalúo
	do {
		printf("Ingrese el avaluo del vehiculo (en USD): \n");
		if (scanf("%f", &matriculas->avaluo) != 1) { 
			printf("Error: Entrada invalida. Intente nuevamente.\n");
			while (getchar() != '\n'); // Limpiar buffer
			continue;
		}
		if (matriculas->avaluo <= 0) {
			printf("Ingrese un avaluo valido.\n");
		}
		while (getchar() != '\n'); // Limpiar buffer después de scanf
	} while (matriculas->avaluo <= 0);
	
	
	printf("Ingrese el cilindraje (cc): \n");
	// Asegúrate de limpiar el buffer si usas scanf después de fgets, o viceversa
	if (scanf("%d", &matriculas->cilindraje) != 1) {
		printf("Entrada invalida para cilindraje.\n");
		while (getchar() != '\n');
	}
	while (getchar() != '\n'); // Limpiar buffer
	
	printf("¿Es servidor publico? (1 = Si, 0 = No): \n");
	if (scanf("%d", &matriculas->esServidorPublico) != 1) {
		printf("Entrada invalida para servidor público.\n");
		while (getchar() != '\n');
	}
	while (getchar() != '\n'); // Limpiar buffer
	
	printf("¿El propietario tiene discapacidad? (1 = Si, 0 = No): \n");
	if (scanf("%d", &matriculas->tieneDiscapacidad) != 1) {
		printf("Entrada invalida para discapacidad.\n");
		while (getchar() != '\n');
	}
	while (getchar() != '\n'); // Limpiar buffer
	
	printf("¿El vehículo es electrico? (1 = Si, 0 = No): \n");
	if (scanf("%d", &matriculas->esElectrico) != 1) {
		printf("Entrada invalida para eléctrico.\n");
		while (getchar() != '\n');
	}
	while (getchar() != '\n'); 
	
	do {
		printf("Seleccione el tipo de vehiculo:\n");
		printf("1. Automovil\n2. Moto\n3. Camioneta\n4. Taxi\n5. Camión\n");
		if (scanf("%d", &matriculas->tipoVehiculo) != 1 || matriculas->tipoVehiculo < 1 || matriculas->tipoVehiculo > 5) {
			printf("Opción de tipo de vehiculo invalida.\n");
			while (getchar() != '\n');
			matriculas->tipoVehiculo = 0; // Para asegurar que el bucle continúe
		}
		while (getchar() != '\n'); 
	} while (matriculas->tipoVehiculo < 1 || matriculas->tipoVehiculo > 5);
	
	printf("Ingrese el valor total de multas pendientes (en USD): \n");
	if (scanf("%d", &matriculas->multas) != 1) {
		printf("Entrada invalida para multas.\n");
		while (getchar() != '\n');
	}
	while (getchar() != '\n'); 
	
	printf("¿Cumplio con las 3 revisiones tecnicas anuales? (1 = Si, 0 = No): \n");
	if (scanf("%d", &matriculas->revisionTecnica) != 1 || (matriculas->revisionTecnica != 0 && matriculas->revisionTecnica != 1)) {
		printf("Entrada invalida para revision técnica.\n");
		while (getchar() != '\n');
		matriculas->revisionTecnica = -1; // Para asegurar que el bucle continúe si se desea validación más estricta
	}
	while (getchar() != '\n'); 
	
}
