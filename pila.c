#include "pila.h"
#include <stdlib.h>
#include <stdbool.h>

#define CANTIDAD_INICIAL 0
#define CAPACIDAD_INICIAL 8

#define AUMENTAR_DOBLE_DATOS sizeof(void*)*2 
#define DISMINUIR_CUARTO_DATOS sizeof(void*)/4


/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));
	
	if (pila == NULL) {
        return NULL;
    }

    pila->cantidad = CANTIDAD_INICIAL;
    pila->capacidad = CAPACIDAD_INICIAL;
    
    pila->datos=malloc((pila->capacidad)*sizeof(void*));
    
    if (pila->datos == NULL) {
        free(pila);
        return NULL;
    }

    return pila;
}

void pila_destruir(pila_t *pila){
	
	free(pila->datos);
    free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
	
	if(pila->cantidad!=0){
		return false;
	}
	return true;
}

bool pedir_memoria(pila_t *pila, size_t aumento){
	
	void** datos_nuevo= realloc(pila->datos,pila->capacidad*aumento); //Cada vez que ingreso el sizeof con 1/4 me vuelve 0 por truncado,use parentesis pero sigue el mismo error
	if (datos_nuevo == NULL){
		return false;
	}
	pila->datos=datos_nuevo;
	return true;
}

bool pila_apilar(pila_t *pila, void* valor){
	
	if(pila->capacidad == pila->cantidad){
		pedir_memoria(pila,AUMENTAR_DOBLE_DATOS);
		pila->capacidad=(pila->capacidad)*2;//Aumento Capacidad
	}
	pila->datos[pila->cantidad]=valor;
	pila->cantidad=pila->cantidad+1;
	return true;
}

void* pila_ver_tope(const pila_t *pila){
	if(pila->cantidad==0){
		return NULL;
	}
	return pila->datos[pila->cantidad-1];		
}

void* pila_desapilar(pila_t *pila){
	if (pila->cantidad==0){
		return NULL;
	}
	if(pila->cantidad < pila->capacidad/4 && CAPACIDAD_INICIAL<pila->capacidad){
		pedir_memoria(pila,DISMINUIR_CUARTO_DATOS);
		pila->capacidad=(pila->capacidad)/4;//Disminuyo la Capacidad
	}

	pila->cantidad=(pila->cantidad)-1; 
	return pila->datos[pila->cantidad]; // Que posicion se cuenta desde 0
}