#include <stdio.h>
#include "libfunciones.h" 

void mostrarMenu() {
	printf("=====================================\n");
	printf("=== Menu de Registro de Vehiculos ===\n");
	printf("1. Registrar vehiculo\n");
	printf("2. Buscar vehiculo por placa\n");
	printf("3. Listar vehiculos registrados\n");
	printf("4. Salir\n");
	printf("==============================\n");
	printf("Seleccione una opcion: ");
}

int main() {
	matricula vehiculoRegistrado; 
	int opcion;
	float costoTotalMatricula; // Variable para almacenar el resultado del c�lculo
	
	do {
		mostrarMenu();
		if (scanf("%d", &opcion) != 1) {
			printf("Entrada inv�lida. Intente nuevamente.\n");
			while (getchar() != '\n'); // limpiar buffer
			opcion = 0;
			continue;
		}
		while (getchar() != '\n'); // limpiar buffer
		
		switch (opcion) {
		case 1:
			// Llama a la funci�n registro para llenar los datos del veh�culo
			registro(&vehiculoRegistrado); 
			
			// Una vez que los datos est�n en vehiculoRegistrado, llama a la funci�n de c�lculo
			costoTotalMatricula = calcularCostoMatricula(&vehiculoRegistrado);
			printf("\nEl costo total de la matricula es: $%.2f\n", costoTotalMatricula);
			break;
		case 2:
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opci�n no v�lida. Intente nuevamente.\n");
		}
	} while (opcion != 2);
	
	return 0;
}
