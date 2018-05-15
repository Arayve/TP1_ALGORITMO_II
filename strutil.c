#include "strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/******************************************************************/
char** split(const char* str, char sep){
	
	if (!sep)return NULL;

	size_t cant_sep = 2;//Por el Null al final
	size_t i,items,cant_char;
	
	i = items = cant_char = 0;
	
	while(str[i]){
		if(str[i] == sep){
			++cant_sep;
		}
		++i;
	}
	char** vec_dina = malloc(cant_sep*sizeof(char*));
	if (!vec_dina)return NULL;
	vec_dina[cant_sep-1] = NULL; //Contamos desde cero
	
 /* *****************************************************************/	
	i = 0;
	while(str[i]){
		if(str[i] != sep){
			++cant_char;
		}
		else{
			
			char* cad = malloc(cant_char*sizeof(char));
			
			if (!cad){
				free_strv(vec_dina);
				return NULL;
			}
			vec_dina[items] = cad;
			++items;
			cant_char = 0;
		}
		++i;
	}
	char* cad = malloc((cant_char+1)*sizeof(char)); //El +1  SE DEBE  por el '/0' AL final.
	if (!cad){
		free_strv(vec_dina);
		return NULL;
	}
	vec_dina[items] = cad;
/* *****************************************************************/	
	i= cant_char = items= 0;
	while(str[i]){
		if(str[i] != sep){
			vec_dina[items][cant_char]  = str[i];
			++cant_char;
			
		}
		else{
			++items;
			cant_char = 0;
		}
		++i;
	}
	return vec_dina;
}
/* *****************************************************************/	
char* join(char** strv, char sep){
	size_t cont,status_vec,status_cad1,status_cad2;
	cont = status_vec = status_cad1 = status_cad2 = 0;

	if (strv){
		while(strv[status_vec]){
			if(strv[status_vec][status_cad1]){
				++status_cad1;
			}
			else{
				status_cad1 = 0;
				++status_vec;
			}
			++cont;
		}
	}
	char* cad = malloc((cont)*sizeof(char));
	if (!cad) return NULL;
	if(!strv) return cad;

	status_vec = status_cad1 = 0;
	
	while(strv[status_vec]){
		if(strv[status_vec][status_cad1]){
			cad[status_cad2] = strv[status_vec][status_cad1];
			++status_cad1;
			++status_cad2;
		}
		else{
			if (strv[status_vec+1]){
				cad[status_cad2] = sep;// Si  no estoy entre al ffinal
				++status_cad2;
			}
			status_cad1 = 0;
			++status_vec;
		}
	}
	return cad;
}
void free_strv(char* strv[]){
	int i = 0;
	while(strv){
		free(strv[i]);
	}
	free(strv);
}
int main(){
	char* cad1 = "3hola3mundo3";
	char ** vec = split(cad1,'3');
	int i = 0;
	while (vec[i]){
		printf("%s\n",vec[i]);
		i++;
	}
	char* cad2 =join(vec,'3');
	printf("%s\n", cad2);
}
