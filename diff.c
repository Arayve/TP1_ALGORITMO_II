#define _POSIX_C_SOURCE 200809L

#include "stdio.h"//para los fprintf
#include "string.h" // para el get
#include <stdlib.h> // para el free

int main(int argc , char* argv[]){
	if(argc != 3){
		fprintf(stderr, "%s\n","Cantidad de parametros erronea" );
		return 1; 
	}

	FILE* archivo_1 = fopen(argv[1],"r");
	FILE* archivo_2 = fopen(argv[2],"r");

	if(!archivo_1 || !archivo_2){
		fprintf(stderr, "%s\n","Archivo erroneo");
		return 1; 
	}

	size_t contador = 1;
	int aux;
	char* linea_1 = NULL;
	size_t cant_1 = 0;
	ssize_t leidos_1;
	char* linea_2 = NULL;
	size_t cant_2 = 0;
	ssize_t leidos_2;

	char* aux_linea_1;
	char* aux_linea_2;

	leidos_1 = getline(&linea_1,&cant_1,archivo_1);
	leidos_2 = getline(&linea_2,&cant_2,archivo_2);

	aux_linea_1 = linea_1;
	aux_linea_2 = linea_2;

	while(leidos_1>0 || leidos_2>0 ){
		if(leidos_1<0){
			aux_linea_1 = "";
		}
		if (leidos_2<0)
		{
			aux_linea_2 = "";
		}
		aux = strcmp(aux_linea_1,aux_linea_2);
		
		if(aux != 0 ){
			fprintf(stdout, "%s%ld\n", "Diferencia en linea: ",contador );
			fprintf(stdout, "%s%s\n",">",aux_linea_1);
			fprintf(stderr, "%s\n","---");
			fprintf(stdout, "%s%s\n",">",aux_linea_2);
		}
		if(leidos_1>0){
			leidos_1 = getline(&linea_1,&cant_1,archivo_1);
			aux_linea_1 = linea_1;
		}
		if(leidos_2>0){
			leidos_2 = getline(&linea_2,&cant_2,archivo_2);
			aux_linea_2 = linea_2;
		}
		++contador;
	}
	free(linea_1);
	free(linea_2);
	fclose(archivo_1);
	fclose(archivo_2);
	return 0;
}
