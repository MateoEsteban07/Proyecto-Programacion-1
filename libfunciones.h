#ifndef LIBFUNCIONES_H
#define LIBFUNCIONES_H


#ifdef __cplusplus
extern "C" {
#endif
	
	// Definición de la estructura matricula
	typedef struct {
		char nombre[50];
		char placa[12];
		char anio[10];
		char cedula[20];
		float avaluo;
		// Nuevos campos para el cálculo de matrícula
		int cilindraje;
		int esServidorPublico;
		int tieneDiscapacidad;
		int esElectrico;
		int tipoVehiculo; // 1. Automóvil, 2. Moto, 3. Camioneta, 4. Taxi, 5. Camión
		int multas; // Valor total de multas pendientes
		int revisionTecnica; // 1 = Sí, 0 = No
	} matricula;
	
	// Declaraciones de funciones de validación
	int validarNumeros(const char *cadena);
	int validarOracion(const char *oracion);
	int esPlacaValida(const char *placa);
	
	// Declaración de la función registro (recibe un puntero, como habíamos acordado)
	void registro(matricula *matriculas); 
	
	// NUEVA FUNCIÓN: Declaración para calcular el costo de la matrícula
	float calcularCostoMatricula(const matricula *datosVehiculo);
	
#ifdef __cplusplus
}
#endif

#endif // LIBFUNCIONES_H
