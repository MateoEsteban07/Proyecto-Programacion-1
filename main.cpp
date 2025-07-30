#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"libfunciones.h"
#include"menuprincipal.c"
#include"menusecundario.c"
#define MAX_REGISTROS 135

int opcion, peso_v, anioint;
float valor_a_pagar, impverde;

void guardar_administrador( PQR adm){
	FILE* archivo = fopen("admins.txt","a");
	if (archivo == NULL) {
		printf("Error al abrir el archivo.\n"); 
		return;
	}
	fprintf(archivo, "%s|%s\n", adm.nombre_del_registrador, adm.contrasenia);
	fclose(archivo);
	limpiarPantalla();
	printf("Admin guardado exitosamente.\n");
	
}

	int administrador_Existe(char* nombre) {
		FILE* archivo = fopen("admins.txt", "r");
		if (archivo == NULL) return 0;
		
		char linea[100], nombre_archivo[50];
		while (fgets(linea, sizeof(linea), archivo)) {
			sscanf(linea, "%[^|]", nombre_archivo);
			while (nombre_archivo[0] == ' ') memmove(nombre_archivo, nombre_archivo + 1, strlen(nombre_archivo));
			if (strcmp(nombre_archivo, nombre) == 0) {
				fclose(archivo);
				return 1;
			}
		}
		fclose(archivo);
		return 0;
	}
	
void registrar_administrador( PQR adm){
	do{
		printf ("Nombre del administrador: ");
		fgets(adm.nombre_del_registrador, sizeof(adm.nombre_del_registrador), stdin);
		adm.nombre_del_registrador[strcspn(adm.nombre_del_registrador, "\n")]= 0;
		limpiarEspaciosExtra(adm.nombre_del_registrador);
		limpiarExtremos(adm.nombre_del_registrador);
		limpiarExtremos(adm.contrasenia);
		
		if(validarOracion(adm.nombre_del_registrador)==0){
			limpiarPantalla();
			printf("Ingrese solo letras.\n");
		}
	} while(validarOracion(adm.nombre_del_registrador)==0);
	if (administrador_Existe(adm.nombre_del_registrador)) {
		printf("El nombre ya esta registrado.\n");
		return;
	}
	do {
		printf("Ingrese la contrasenia (minimo 6 caracteres): ");
		fgets(adm.contrasenia, sizeof(adm.contrasenia), stdin);
		adm.contrasenia[strcspn(adm.contrasenia, "\n")] = 0;
		
		if (strlen(adm.contrasenia) < 6) {
			limpiarPantalla();
			printf("La contrasenia debe tener al menos 6 caracteres.\n");
		}
	} while (strlen(adm.contrasenia) < 6);
	guardar_administrador(adm);
}

	
	int login_Administrador() {
		char nombre[50]; 
		char contrasenia[30];
		printf("Ingrese nombre: ");
		fgets(nombre, sizeof(nombre), stdin);
		nombre[strcspn(nombre, "\n")] = 0;
		limpiarEspaciosExtra(nombre);
		limpiarExtremos(nombre);
		
		printf("Ingrese contrasenia: ");
		fgets(contrasenia, sizeof(contrasenia), stdin);
		contrasenia[strcspn(contrasenia, "\n")] = 0;
		limpiarExtremos(contrasenia);
		
		
		FILE* archivo = fopen("admins.txt", "r");
		if (archivo == NULL) {
			printf("Archivo no disponible.\n");
			return 0;
		}
		
		char linea[100], nombre_archivo[50], pass_archivo[30];
		while (fgets(linea, sizeof(linea), archivo)) {
			sscanf(linea, "%[^|]|%[^\n]", nombre_archivo, pass_archivo);
			limpiarExtremos(nombre_archivo);
			limpiarExtremos(pass_archivo);
			limpiarEspaciosExtra(nombre_archivo);
			
			if (strcmp(nombre_archivo, nombre) == 0 && strcmp(pass_archivo, contrasenia) == 0) {
				fclose(archivo);
				return 1;
			}
		}
		
		fclose(archivo);
		return 0;
	}
	
///////////////////////////////////////////////////////////////////
void registro(matricula* lista, int* total) { 
	if (*total >= 100) {
		printf("Se alcanzó el número máximo de registros.\n");
		return;
	}
	matricula* matriculas = &lista[*total];
	//VALIDACION DE NOMBRE    
	do{
		printf ("Ingrese el nombre del propietario del vehiculo: \n");
		fgets(matriculas->nombre, sizeof(matriculas->nombre), stdin);
		matriculas->nombre[strcspn(matriculas->nombre, "\n")] = 0;
		if(validarOracion(matriculas->nombre)==0){
			limpiarPantalla();
			printf("Ingrese solo letras.\n");
		}
	}while(validarOracion(matriculas->nombre)==0);
	
	//VALIDACION DE CEDULA
	do{
		printf("Ingrese cedula del propietario del vehiculo: \n");
		fgets(matriculas->cedula, sizeof(matriculas->cedula), stdin);
		matriculas->cedula[strcspn(matriculas->cedula, "\n")] = 0;
		if (validarNumeros(matriculas->cedula)==0 || strlen(matriculas->cedula)!=10){
			limpiarPantalla();
			printf("Ingrese una cedula valida (10 digitos-solo numeros).\n");
		}
	}while(validarNumeros(matriculas->cedula)==0 || strlen(matriculas->cedula)!=10);
	
	//VALIDAR PLACA
	do{
		printf("Ingrese placa del vehiculo a matricular(ABC1234 sin guion): \n");
		fgets(matriculas->placa, sizeof(matriculas->placa), stdin);
		for (int i = 0; matriculas->placa[i]; i++) {
			matriculas->placa[i] = toupper(matriculas->placa[i]);
		}
		matriculas->placa[strcspn(matriculas->placa, "\n")] = 0;
		if (esPlacaValida(matriculas->placa)==0){
			limpiarPantalla();
			printf("Ingrese placa valida (ABC1234 sin guion).\n");
		}
	}while(esPlacaValida(matriculas->placa)==0);    
	
	//VALIDAR ANIO

	do{
		printf("Ingrese el anio de fabricacion del vehiculo a matricular: \n");
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
		printf("Ingrese el avaluo del vehiculo a matricular: \n");
		
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
		printf("Ingrese el cilindraje del vehiculo a matricular en centimetro cubicos: \n");
		
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
		int valido;
		do{
			printf("Ingrese el tipo de vehiculo, electrico[0] combustible[1]: \n");
			valido= scanf("%d", &matriculas->tipo);
			if( valido != 1){
				limpiarPantalla();
				printf("Error: Entrada invalida. Intente nuevamente. \n");
				while (getchar() != '\n');  
			}
		}while(valido != 1);
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
		int invalido;
		do{
			printf("Ingrese el tipo de vehiculo, liviano[0] pesado[1]: \n");
			invalido= scanf("%d", &matriculas->peso);
			if (invalido != 1){
				limpiarPantalla();
				printf("Error: Entrada invalida. Intente nuevamente. \n");
				while (getchar() != '\n');  
			}
		}while(invalido != 1);
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
	//validar revisiones tecnicas
	int valido;
	do{
		printf("Numero de revisiones tecnicas anuales del vehiculo a matricular?\n");
		valido = scanf("%d", &matriculas->revisionesTecnicas);
		limpiarBuffer();
		if (valido != 1 || matriculas->revisionesTecnicas < 0 || matriculas->revisionesTecnicas > 366){
			limpiarPantalla();
			printf("Ingreso un valor no permitido\n");
		}
	} while(valido != 1 || matriculas->revisionesTecnicas < 0 || matriculas->revisionesTecnicas > 366);
	limpiarPantalla();
	(*total)++;
	//Recursividad
	printf("Desea matricular otro vehiculo? (Si=1, No=0): ");
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
	int edad_v = 2025 - anioExtraido, multaRevisiones;
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
	if(m->revisionesTecnicas < 3){
		multaRevisiones = 50 * (3-m->revisionesTecnicas);
	}
	// Total a pagar
	float valor_a_pagar = valor_de_imp_verde + (m->avaluo / 100) + 22 + 10 + multaRevisiones;
	// Mostrar resultados
	printf("\n--- DETALLES DE MATRICULA ---\n");
	printf("Placa: %s\n", m->placa);
	printf("Anio: %s (Edad: %d anios)\n", m->anio, edad_v);
	printf("Cilindraje: %d\n", m->cilindraje);
	printf("Avaluo: %.2f\n", m->avaluo);
	printf("Tipo: %s\n", m->tipo == 1 ? "Combustible" : "Electrico");
	printf("Impuesto verde: %.2f $\n", valor_de_imp_verde);
	printf("Multa por falta de revisiones tecnicas: %d\n", multaRevisiones);
	printf("Total a pagar: %.2f $\n", valor_a_pagar);
}
/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void generarComprobante(matricula* m) {
	char nombreArchivo[100];
	sprintf(nombreArchivo, "comprobante_%s.txt", m->placa);
	FILE* archivo = fopen(nombreArchivo, "w");
	if (archivo == NULL) {
		printf("Error al abrir el archivo para escritura.\n");
		return;
	}
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
	if (m->tipo == 1) {
		valor_de_imp_verde = ((m->cilindraje - 1500) * tarifa_cilindraje) * (1 + tarifa_edad);
	} else {
		valor_de_imp_verde = 0.0;
	}
	float valor_a_pagar = valor_de_imp_verde + (m->avaluo / 100) + 22 + 10;
	// Guardar en archivo
	fprintf(archivo, "--- COMPROBANTE DE MATRÍCULA ---\n");
	fprintf(archivo, "Nombre: %s\n", m->nombre);
	fprintf(archivo, "Cédula: %s\n", m->cedula);
	fprintf(archivo, "Placa: %s\n", m->placa);
	fprintf(archivo, "Año: %s (Edad: %d años)\n", m->anio, edad_v);
	fprintf(archivo, "Avaluo: %.2f\n", m->avaluo);
	fprintf(archivo, "Cilindraje: %d\n", m->cilindraje);
	fprintf(archivo, "Tipo: %s\n", m->tipo == 1 ? "Combustible" : "Eléctrico");
	fprintf(archivo, "Peso: %s\n", m->peso == 1 ? "Pesado" : "Liviano");
	fprintf(archivo, "Impuesto verde: %.2f $\n", valor_de_imp_verde);
	fprintf(archivo, "Total a pagar: %.2f $\n", valor_a_pagar);
	fprintf(archivo, "-------------------------------\n");
	fclose(archivo);
	limpiarPantalla();
	printf("Comprobante generado exitosamente: %s\n", nombreArchivo);
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////
		void calcularPorPlaca(matricula* registros, int total) {
			int eleccion;
			char placaBuscar[12];
			int encontrado = 0;
			do{
				printf("Ingrese la placa a buscar (ABC1234 sin guion): \n");
				fgets(placaBuscar, sizeof(placaBuscar), stdin);
				for (int i = 0; placaBuscar[i]; i++) {
					placaBuscar[i] = toupper(placaBuscar[i]);
				}
				placaBuscar[strcspn(placaBuscar, "\n")] = 0;
				if (esPlacaValida(placaBuscar)==0){
					limpiarPantalla();
					printf("Ingrese una placa valida.\n");
				}
				
			}while(esPlacaValida(placaBuscar)==0); 
			for (int i = 0; i < total; i++) {
				if (strcmp(registros[i].placa, placaBuscar) == 0) {
					calcular_matricula(&registros[i]);
					encontrado = 1;
					do{
						printf("Quiere confirmar pago? Si=[1] No=[0] \n");
						scanf("%d",& eleccion);
						limpiarBuffer();
						switch(eleccion){
						case 1:
							generarComprobante(&registros[i]);
							break;
						case 0:
							limpiarPantalla();
							printf("Gracias por usar \n");
							break;
						default:
							limpiarPantalla();
							printf("Entrada invalida\n");
						}
					}while(eleccion != 1 && eleccion != 0);
					break;
				}
			}
			if (!encontrado) {
				limpiarPantalla();
				printf("No se encontro un auto con la placa %s.\n", placaBuscar);
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
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
			fprintf(archivo, "--------------------------\n");
			fprintf(archivo, "COMPROBANTE DE REGISTRO #%d\n", i + 1);
			fprintf(archivo, "Datos del propietario \n");
			fprintf(archivo, "--------------------------\n");
			fprintf(archivo, "Nombre: %s\n", registros[i].nombre);
			fprintf(archivo, "Cedula: %s\n", registros[i].cedula);
			fprintf(archivo, "--------------------------\n");
			fprintf(archivo, "Datos del Vehiculo \n");
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
		int totalRegistros = 0;
		int option;
		int opcion_adm;
		int estadoLogin;
		char placaBuscar[12];
		matricula registros[MAX_REGISTROS]; 
		PQR nuevo;
		do{	
			mostrarMenu1();
			if (scanf("%d", & opcion_adm)!=1) {
				limpiarBuffer();
				limpiarPantalla();
				printf("Entrada invalida. Use solo numeros (0-2).\n");
				opcion_adm = -1;
				continue;
			}
			limpiarBuffer();
			switch (opcion_adm) {
			case 0:
				limpiarPantalla();
				printf("Programa finalizado! \n");
				break;
			case 1:
				registrar_administrador(nuevo);
				break;
			case 2:
				estadoLogin=login_Administrador();
				if (estadoLogin == 1) {
					limpiarPantalla();
					printf("Sesion iniciada!\n");
					do {
						mostrarMenu();
						if (scanf("%d", &option) != 1) {
							limpiarPantalla();
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
								limpiarPantalla();
								printf("No hay registros.\n");
							}
							break;
						case 3:
							limpiarPantalla();
							printf("Ingrese la placa que desea buscar: \n");
							scanf("%s", placaBuscar);
							for (int i = 0; placaBuscar[i]; i++) {
								placaBuscar[i] = toupper(placaBuscar[i]);
							}
							buscarplaca(registros, totalRegistros, placaBuscar);
							break;
						case 4:
							limpiarPantalla();
							if(totalRegistros==0){
								printf("No hay nada para guardar en un archivo \n");
							} 
							else{
								guardarEnArchivo(registros, totalRegistros);
							}
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
				} else {
					limpiarPantalla();
					printf("Admin no encontrado.\n");
				}
				break;
			default:
				limpiarPantalla();
				printf("Seleccione un numero valido.\n");
				break;
			}
		} while(opcion_adm !=0);
		
	}
