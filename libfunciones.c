#include<stdio.h>
#include<string.h>
#include<ctype.h>

	//Funcion validar numeros
int validarNumeros(const char *cadena) {
	for (int i = 0; i < strlen(cadena); i++) {
		if (!isdigit(cadena[i])) {
			return 0; 
		}
		}
		return 1;
	}
	//funcion validar letras
int validarOracion(const char *oracion) {
	for (int i = 0; i < strlen(oracion); i++) {
		if (!isalpha(oracion[i]) && oracion[i] != ' ') {
			return 0; 
		}
	}
	return 1;
}
	//Funcion validar placa
int esPlacaValida(const char *placa) {
	if (strlen(placa) != 7)
		return 0;
	
		// Validar letras
	for (int i = 0; i < 3; i++) {
		if (!isalpha(placa[i]) || !isupper(placa[i]))
			return 0;
	}
		
		// Validar digitos
	for (int i = 3; i < 6; i++) {
		if (!isdigit(placa[i]))
			return 0;
	}
		
	return 1;
	}
