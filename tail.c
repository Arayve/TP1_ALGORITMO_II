#define _POSIX_C_SOURCE 200809L

#include "cola.h"
#include "stdio.h"//para los fprintf
#include "stdlib.h" // para el atoi
#include "string.h" // para el get
#include "ctype.h" // isdigit


bool es_digito(char* cadena){
	size_t len = strlen(cadena);
	for (int i = 0; i < len; ++i){
		if(!isdigit(cadena[i])) return false;
	}
	return true;
}
int main(int argc , char* argv[]){
	
	if(argc != 2){
		fprintf(stderr, "%s\n","Cantidad de parametros erronea" );
		return 1; 
	}
	if(!es_digito(argv[1])){
		fprintf(stderr, "%s\n","Tipo de parametro incorrecto" );
		return 1; 
	}

	
	int n = atoi(argv[1]);
	size_t contador = 0;
	char* linea = NULL;
	size_t cant = 0;
	ssize_t leidos;
	char* aux;
	cola_t* cola = cola_crear();
	if(!cola) return 1;
	
	while ((leidos = getline(&linea,&cant,stdin))>0){		
		
		aux = malloc(sizeof(char[strlen(linea)+1]));//queria usar cant pero el gdb me dice que es 120 y no se por que
		if(!aux) return 1;
		strcpy(aux,linea);
		
		cola_encolar(cola,aux);
		
		if(n <= contador){
			aux = cola_desencolar(cola);
			free(aux);
		}
		++contador;
	}
	free(linea);

	while(!cola_esta_vacia(cola)){
		aux = cola_desencolar(cola);
		fprintf(stdout, "%s\n", aux );
		free(aux);	  
	}
	cola_destruir(cola,free);
	return 0;
}



