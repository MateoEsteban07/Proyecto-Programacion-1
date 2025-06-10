#include<stdio.h>
#include<string.h>

typedef struct{
	char nombre[50];
	char placa[12];
	char anio[10];
	char cedula[12];
	float valuo;
}matricula;
void registro(matricula matriculas){
	int opcion;
	printf ("Ingrese su nombre completo: \n");
	fgets(matriculas.nombre, sizeof(matriculas.nombre), stdin);
	matriculas.nombre[strcspn(matriculas.nombre, "\n")] = 0;
	printf("Ingrese cedula: \n");
	fgets(matriculas.cedula, sizeof(matriculas.cedula), stdin);
	matriculas.cedula[strcspn(matriculas.cedula, "\n")] = 0;
	printf("Ingrese placa: \n");
	fgets(matriculas.placa, sizeof(matriculas.placa), stdin);
	matriculas.placa[strcspn(matriculas.placa, "\n")] = 0;
	printf("Ingrese el año del vehiculo: \n");
	fgets(matriculas.anio, sizeof(matriculas.anio), stdin);
	matriculas.anio[strcspn(matriculas.anio, "\n")] = 0;
	printf("Ingrese el valuo del vehiculo: \n");
	scanf("%f", &matriculas.valuo);
	printf("¿Desea ingresar mas datos?(Si=1, No=0)\n");
	scanf("%d", &opcion);
	while (getchar()!= '\n');
	if (opcion == 0){   //caso base//
		printf("Gracias por usar");
		return;
	} else{ 
		registro(matriculas);
	}
}
int main (){
	matricula matriculas;
	registro(matriculas);
	return 0;
}
