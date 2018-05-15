#define _POSIX_C_SOURCE 200809L

#include "pila.h"
#include <stdio.h>//para los fprintf
#include <string.h> // para el get
#include <stdlib.h> // para el free
#include <stdbool.h>


int _pertenece_caracter(char caracter , char* cadena, size_t n){
	if(!caracter) return 0;
	for(int i=0;i<n;i++){
		if(caracter == cadena[i]) return 1;
	}
	return 0;
}
int _posicion_caracter(char caracter , char* cadena){
	if(!caracter) return -1;
	for(int i=0;i<strlen(cadena);i++){
		if(caracter == cadena[i]) return i;
	}
	return -1;
}
bool invertir_booleano(bool booleano){
	if (booleano) return false;
	return true;
}

int main(int argc , char* argv[]){

	char abierto[3] = "[{(";
	char cerrado[3] = "]})"; 

	char* linea = NULL;
	size_t cant = 0;
	ssize_t leidos;
	bool comilla_abiertas = false;
	bool errores = false;
	size_t len_linea;
	while ((leidos = getline(&linea,&cant,stdin))>0){
		len_linea = strlen(linea);
		pila_t* pila_abierto = pila_crear();
		if(!pila_abierto) return 1;
		for(int i = 0; i < len_linea; i++){
			
			if(linea[i] ==  '\''){
				comilla_abiertas = invertir_booleano(comilla_abiertas);
				continue;
			}
			if(comilla_abiertas) continue;
			
			if(_pertenece_caracter(linea[i],abierto,3)){
				pila_apilar(pila_abierto,&linea[i]);
				continue;
			}
			if(_pertenece_caracter(linea[i],cerrado,3)){
				char* caracter = pila_desapilar(pila_abierto);				
				if(_posicion_caracter(*caracter,abierto) != _posicion_caracter(linea[i],cerrado)){
					errores = true;
					break;//cuidado no se que rompe el for o el while
				}
			}
		}
		
		if(comilla_abiertas){
			fprintf(stdout, "%s\n", "ERROR");
		}
		else if(errores || !pila_esta_vacia(pila_abierto)){
			fprintf(stdout, "%s\n", "ERROR");
		}
		else{
			fprintf(stdout, "%s\n", "OK");
		}
		errores = false;
		comilla_abiertas = false;
		pila_destruir(pila_abierto);
	}
	free(linea);
}