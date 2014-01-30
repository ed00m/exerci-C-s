/*
    ......................REGISTRO.ACADEMICO.......................
    .........SOFTWARE PARA FINES ACADEMICOS/EDUCATIVOS.............
    .........ed00m:th3d00m | pabloze@gmail.com ....................

    Ejercicios registros alumnos:
    (Matricula,Nombre,CodCarrera,Carrera,Edad,Estado)
    Crear un menu que permita:
        1 Ingresar Registros y grabarlos
        2 Buscar y Mostrar Registros individuales
        3 Mostrar Todos los registros
        4 Eliminar logicamente
        5 Salir

    Implementar funciones
    (En la opcion 4, crear un campo dentro de la estructura que se llame estado; puede contener 2 valores 1=habilitado, 2=Eliminado
*/

#include <stdio.h>
#include <stdlib.h>
#define CANTAl 5
#define edadmin 15
#define edadmax 150

/* funciones */
int menu();
void alum_datos_personal();
void titulo();
void mostrar_registros();
void eliminar_alumnos();
void pausar_programa();
void buscar_alumno();

/* estructura de datos */
struct{
    int id_mat;
    char alumno[30];
    char Carrera[20];
    int CodCarrera;
    int edad;
    int Estado;
}registroacademico[CANTAl];

/* funcion principal */
int main ()
{
	int opcion;
	do{
		opcion=menu();
		switch(opcion){
			case 1:
			alum_datos_personal();
           	break;
			case 2:
			buscar_alumno();
			break;
			case 3:
			mostrar_registros();
			break;
			case 4:
			eliminar_alumnos();
			break;
		}
	}while(opcion!=5);
	return(0);
}

/* Funciones */
int menu(){
	int opcion;
	do{
		titulo();
		printf("1.Ingresar alumno\n");
		printf("2.Buscar\n");
		printf("3.Mostrar registros\n");
		printf("4.Eliminar\n");
		printf("5.Salir\n");
		printf("------------------------------------");
		printf("\nElija una opcion:");
		scanf("%d",&opcion);
			if(opcion <1 || opcion >5){
				printf("Ingrese una opcion valida\n\n");
			}
	}while(opcion <1 || opcion >5);
	return(opcion);
}
//
void alum_datos_personal(){
	int i;
	for (i=0;i<CANTAl;i++){
		system("clear");
		//informacion personal
		titulo();
		printf("Ingrese informacion personal del alumno\n");
		printf("Nombre del Alumno %d : ",i+1);
		scanf("%s",registroacademico[i].alumno);
			do{
				printf("Edad :");
				scanf("%d",&registroacademico[i].edad);
					if(registroacademico[i].edad < edadmin || registroacademico[i].edad > edadmax){
						printf("Ingrese una edad valida\n");
					}
			}while(registroacademico[i].edad < edadmin || registroacademico[i].edad > edadmax);
		system("clear");
		//Informacion academica
		titulo();
		printf("Ingrese informacion Academica de %s\n",registroacademico[i].alumno);
			do{
				printf("Matricula : ");
				scanf("%d",&registroacademico[i].id_mat);
					if(registroacademico[i].id_mat < 0){
						printf("Ingrese un numero de matricula valido\n");
					}
			}while(registroacademico[i].id_mat < 0);
		printf("Carrera : ");
		scanf("%s",registroacademico[i].Carrera);
			do{
				printf("Codigo carrera : ");
				scanf("%d",&registroacademico[i].CodCarrera);
					if(registroacademico[i].CodCarrera < 0){
						printf("Ingrese un codigo de carrera valido\n");
					}
			}while(registroacademico[i].CodCarrera < 0);
			do{
				printf("Estado academico [1=habilitado, 2=Eliminado] :");
				scanf("%d",&registroacademico[i].Estado);
					if(registroacademico[i].Estado < 1 || registroacademico[i].Estado > 2){
						printf("Ingrese un estado valido\n");
					}
			}while(registroacademico[i].Estado < 1 || registroacademico[i].Estado > 2);
		printf("\n...................................\n");
		printf("      Registro del Alumno listo");
		printf("\n...................................\n");
		pausar_programa();
	}
}
//
void titulo(){
	printf(".......REGISTRO.ACADEMICO.......\n");
	printf("-----------------------------------\n");
}
//
void mostrar_registros(){
	int i;
	system("clear");
	titulo();
	printf("\nAlumno | Edad | Matricula | Carrera | Codigo | Estado|\n");
	printf("------------------------------------------------------------------------\n");
		for (i=0;i<CANTAl;i++){
			printf("%s |", registroacademico[i].alumno);
			printf("%d |", registroacademico[i].edad);
			printf("%d |", registroacademico[i].id_mat);
			printf("%s |", registroacademico[i].Carrera);
			printf("%d |", registroacademico[i].CodCarrera);
				if(registroacademico[i].Estado==1){
					printf(" Habilitado |");
				}else{
					printf(" Eliminado |");
				}
			printf("\n");
		}
		pausar_programa();
}
//
void eliminar_alumnos(){
    int i,matricula,estado;
    system("clear");
    titulo();
    printf("\nAlumno | Matricula | Carrera | Estado \n");
	printf("------------------------------------------------------------------------\n");
    	for (i=0;i<CANTAl;i++){
			printf("%s |", registroacademico[i].alumno);
			printf("%d |", registroacademico[i].id_mat);
			printf("%s |", registroacademico[i].Carrera);
				if(registroacademico[i].Estado==1){
					printf(" Habilitado |");
				}else{
					printf(" Eliminado |");
				}
			printf("\n");
		}
    printf("Ingrese matricula del alumno para eliminar : ");
    scanf("%d",&matricula);
    for(i=0;i<CANTAl;i++){
    	if(registroacademico[i].id_mat==matricula){
        	estado=1;
		}
    }
    if(estado==1){
		for(i=0;i<CANTAl;i++){
			if(registroacademico[i].id_mat==matricula){
           		registroacademico[i].Estado=2;
           		printf("\nAlumno: %s | matricula : %d ha sido eliminado y ya no es alumno regular",registroacademico[i].alumno,registroacademico[i].id_mat);
           	}
		}
	}else{
		printf("\nEsta matricula no esta en registro academico\n");
	}
	pausar_programa();
}
//
void pausar_programa(){
	getchar(); getchar(); //pausamos el programa
	system("clear");
}
//
void buscar_alumno(){
	int i,matricula;
    system("clear");
    titulo();
    printf("Matricula del alumno a buscar : ");
    scanf("%d",&matricula);
    for(i=0;i<CANTAl;i++){
    	if(registroacademico[i].id_mat==matricula){
        	printf("\nAlumno | Edad | Matricula | Carrera | Codigo | Estado |\n");
			printf("------------------------------------------------------------------------\n");
        	printf("%s |", registroacademico[i].alumno);
			printf("%d |", registroacademico[i].edad);
			printf("%d |", registroacademico[i].id_mat);
			printf("%s |", registroacademico[i].Carrera);
			printf("%d |", registroacademico[i].CodCarrera);
				if(registroacademico[i].Estado==1){
					printf(" Habilitado |");
				}else{
					printf(" Eliminado |");
				}
			printf("\n");
		}else{
			printf("\nEsta matricula no esta en registro academico\n");
		}
    }
    pausar_programa();
}
