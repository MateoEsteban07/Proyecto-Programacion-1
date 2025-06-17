#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // Para atoi
#include "libfunciones.h"

// Funciones de validaci�n (estas no cambian, siguen como las ten�as)
int validarNumeros(const char *cadena) {
	for (int i = 0; i < (int)strlen(cadena); i++) {
		if (!isdigit((unsigned char)cadena[i])) {
			return 0;
		}
	}
	return 1;
}

int validarOracion(const char *oracion) {
	for (int i = 0; i < (int)strlen(oracion); i++) {
		if (!isalpha((unsigned char)oracion[i]) && oracion[i] != ' ') {
			return 0;
		}
	}
	return 1;
}

int esPlacaValida(const char *placa) {
	if (strlen(placa) != 6)
		return 0;
	
	for (int i = 0; i < 3; i++) {
		if (!isalpha((unsigned char)placa[i]) || !isupper((unsigned char)placa[i]))
			return 0;
	}
	
	for (int i = 3; i < 6; i++) {
		if (!isdigit((unsigned char)placa[i]))
			return 0;
	}
	
	return 1;
}


// Toma un puntero constante a matricula para acceder a sus datos
float calcularCostoMatricula(const matricula *datosVehiculo) {
	float impuestoVehicular, impuestoAmbiental, sppat, tasaANT = 22.0;
	float total = 0;
	
	// C�lculo del impuesto a la propiedad (2% del aval�o)
	impuestoVehicular = datosVehiculo->avaluo * 0.02;
	
	// Exoneraci�n por discapacidad o veh�culo el�ctrico
	if (datosVehiculo->tieneDiscapacidad == 1 || datosVehiculo->esElectrico == 1) {
		impuestoVehicular = 0;
		impuestoAmbiental = 0;
		sppat = 0;
		tasaANT = 0;
	} else {
		// C�lculo del impuesto ambiental
		if (datosVehiculo->cilindraje > 1500) {
			impuestoAmbiental = 50.0;
		} else {
			impuestoAmbiental = 20.0;
		}
		
		// Seguro SPPAT seg�n tipo de veh�culo
		switch (datosVehiculo->tipoVehiculo) {
		case 1: sppat = 40.0; break; // Autom�vil
		case 2: sppat = 25.0; break; // Moto
		case 3: sppat = 60.0; break; // Camioneta
		case 4: sppat = 35.0; break; // Taxi
		case 5: sppat = 80.0; break; // Cami�n
		default: sppat = 40.0; break; // Por defecto si se ingresa una opci�n inv�lida
		}
	}
	
	// Penalizaci�n si no tiene revisiones completas
	if (datosVehiculo->revisionTecnica == 0) {
		total += 80.0; // multa por no cumplir RTV
	}
	
	// Descuento si es servidor p�blico (solo aplica si no est� exonerado totalmente)
	if (datosVehiculo->esServidorPublico == 1 && impuestoVehicular > 0) {
		impuestoVehicular *= 0.9; // 10% de descuento
	}
	
	// Total acumulado
	total += impuestoVehicular + impuestoAmbiental + sppat + datosVehiculo->multas + tasaANT;
	
	// Resultados (mostrados aqu�, o se podr�a retornar el total y mostrar en main)
	printf("\n---- RESUMEN DEL VALOR DE MATRICULA ----\n");
	printf("Impuesto Vehicular: $%.2f\n", impuestoVehicular);
	printf("Impuesto Ambiental: $%.2f\n", impuestoAmbiental);
	printf("Seguro SPPAT:       $%.2f\n", sppat);
	printf("Tasa ANT:           $%.2f\n", tasaANT);
	printf("Multas:             $%d\n", datosVehiculo->multas);
	if (datosVehiculo->revisionTecnica == 0) {
		printf("Multa RTV:          $80.00\n");
	}
	printf("----------------------------------------\n");
	printf("TOTAL A PAGAR:      $%.2f\n", total);
	
	return total; // Retorna el costo total de la matr�cula
}
