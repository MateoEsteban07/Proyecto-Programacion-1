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
	float costoTotalMatricula; // Variable para almacenar el resultado del cálculo
	
	do {
		mostrarMenu();
		if (scanf("%d", &opcion) != 1) {
			printf("Entrada inválida. Intente nuevamente.\n");
			while (getchar() != '\n'); // limpiar buffer
			opcion = 0;
			continue;
		}
		while (getchar() != '\n'); // limpiar buffer
		
		switch (opcion) {
		case 1:
			// Llama a la función registro para llenar los datos del vehículo
			registro(&vehiculoRegistrado); 
			
			// Una vez que los datos están en vehiculoRegistrado, llama a la función de cálculo
			costoTotalMatricula = calcularCostoMatricula(&vehiculoRegistrado);
			printf("\nEl costo total de la matricula es: $%.2f\n", costoTotalMatricula);
			break;
		case 2:
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opción no válida. Intente nuevamente.\n");
		}
	} while (opcion != 2);
	
	return 0;
}
