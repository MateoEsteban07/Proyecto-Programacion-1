#ifndef LIBFUNCIONES_H
#define LIBFUNCIONES_H

// Si tu compilador es C++, se asegurar� de que estas funciones se enlacen como C
#ifdef __cplusplus
extern "C" {
#endif
	
	// Definici�n de la estructura matricula
	typedef struct {
		char nombre[50];
		char placa[12];
		char anio[10];
		char cedula[20];
		float avaluo;
		// Nuevos campos para el c�lculo de matr�cula
		int cilindraje;
		int esServidorPublico;
		int tieneDiscapacidad;
		int esElectrico;
		int tipoVehiculo; // 1. Autom�vil, 2. Moto, 3. Camioneta, 4. Taxi, 5. Cami�n
		int multas; // Valor total de multas pendientes
		int revisionTecnica; // 1 = S�, 0 = No
	} matricula;
	
	// Declaraciones de funciones de validaci�n
	int validarNumeros(const char *cadena);
	int validarOracion(const char *oracion);
	int esPlacaValida(const char *placa);
	
	// Declaraci�n de la funci�n registro (recibe un puntero, como hab�amos acordado)
	void registro(matricula *matriculas); 
	
	// NUEVA FUNCI�N: Declaraci�n para calcular el costo de la matr�cula
	float calcularCostoMatricula(const matricula *datosVehiculo);
	
#ifdef __cplusplus
}
#endif

#endif // LIBFUNCIONES_H
