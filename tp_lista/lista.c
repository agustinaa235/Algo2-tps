#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>

#define ERROR -1
#define EXITO 0


typedef struct nodo {
	void* elemento;
	struct nodo* siguiente;
} nodo_t;


struct lista{
    nodo_t* nodo_inicio;
    nodo_t* nodo_fin;
    int cantidad;
};

struct lista_iterador{
		nodo_t* corriente;
		lista_t* lista;
};

lista_t* lista_crear(){

    lista_t* lista= (lista_t*)malloc(sizeof(lista_t));
    if(!lista){
        return NULL;
    }
    lista->nodo_inicio=NULL;
    lista->nodo_fin= NULL;
    lista->cantidad=0;
    return lista;
}
/*
	*Creara un nodo, reservando la memoria necesaria.
	*Devuelve un puntero al nodo ya inicializado o Null en caso de error.
*/
nodo_t* crear_nodo(void* elemento){

		nodo_t* nodo = (nodo_t*)malloc(sizeof(nodo_t));
		if(!nodo){
				return NULL;
		}
		nodo->elemento = elemento;
		nodo->siguiente = NULL;
		return nodo;
}
/*
	*Eliminara de la lista el elemento que se encuentra en la primera posicion(0).
	*Devuelve 0 si pudo elimnar, sino devuelve -1.
*/
int borrar_al_inicio(lista_t* lista){

    if(!lista || lista_vacia(lista)){
        return ERROR;
    }
    nodo_t* nodo_aux = lista->nodo_inicio;
    lista->nodo_inicio = lista->nodo_inicio->siguiente;
    free(nodo_aux);
    (lista->cantidad)--;
    return EXITO;
}
/*
	*Insertara un elemento al inicio de la lista.
	*Devolvera 0 si pudo insertar, sino -1.
*/
int lista_insertar_al_inicio(lista_t* lista, nodo_t* nodo){

    if(!lista || !nodo){
        return ERROR;
    }
		if(lista_vacia(lista)){
			lista->nodo_inicio = nodo;
			lista->nodo_fin = nodo;
		}else{
    		nodo->siguiente = lista->nodo_inicio;
    		lista->nodo_inicio = nodo;
		}
    (lista->cantidad)++;
    return EXITO;
}

int lista_insertar(lista_t* lista, void* elemento){

    if(!lista){
        return ERROR;
    }
    nodo_t* nodo_aux= crear_nodo(elemento);
		if(!nodo_aux){
				return ERROR;
		}
    if(lista_vacia(lista)){
        lista->nodo_inicio = nodo_aux;
        lista->nodo_fin = nodo_aux;

    }else{
        lista->nodo_fin->siguiente = nodo_aux;
        lista->nodo_fin = nodo_aux;
    }
  	(lista->cantidad)++;
    return EXITO;
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){

		int estado = ERROR;
    if(!lista){
        return estado;
    }
		if(posicion >= lista->cantidad){
         estado = lista_insertar(lista,elemento);
		}else if(posicion==0){

				nodo_t* nodo_aux = crear_nodo(elemento);
				if(!nodo_aux){
						return ERROR;
				}
        estado = lista_insertar_al_inicio(lista, nodo_aux);

		}else{
				nodo_t* nodo_aux = crear_nodo(elemento);
				if(!nodo_aux){
						return ERROR;
				}

        nodo_t* actual = lista->nodo_inicio;
        int i= 1;
        while (i < posicion && actual->siguiente) {

						actual = actual->siguiente;
            i++;
        }
        nodo_aux->siguiente = actual->siguiente;
				actual->siguiente = nodo_aux;

        (lista->cantidad)++;
				estado = EXITO;
    }

    return estado;
}

int lista_borrar(lista_t* lista){

		int estado = ERROR;
    if(!lista || lista_vacia(lista)){
        return estado;
    }if(lista_elementos(lista)==1){
				estado = borrar_al_inicio(lista);
		}else{
    		nodo_t* anterior = lista->nodo_inicio;
    		nodo_t* actual = lista->nodo_inicio->siguiente;
    		while(actual->siguiente){
        		anterior = actual;
        		actual = actual->siguiente;
    		}

				lista->nodo_fin= anterior;
    		anterior->siguiente = NULL;
				free(actual);
    		(lista->cantidad)--;
				estado = EXITO;
		}
  	return estado;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){

		int estado = ERROR;
    if(!lista || lista_vacia(lista)){
        return estado;
    }
    if(posicion >= lista_elementos(lista)){
      	estado = lista_borrar(lista);

    }else if(posicion==0){
        estado = borrar_al_inicio(lista);
    }else{
        nodo_t* anterior = lista->nodo_inicio;
        nodo_t* actual = lista->nodo_inicio->siguiente;
        int i=1;
        while(i<posicion){
            anterior = actual;
            actual = actual->siguiente;
            i++;
        }
        anterior->siguiente= actual->siguiente;
        free(actual);
        (lista->cantidad)--;
				estado = EXITO;
    }

    return estado;

}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){

    if(!lista || lista_vacia(lista)){
        return NULL;
    }
    if(posicion>= lista->cantidad){
        return NULL;
    }
    nodo_t* actual = lista->nodo_inicio;
    int i=0;
    while(i<posicion){
        actual = actual->siguiente;
        i++;
    }
    return actual->elemento;
}


void* lista_buscar_elemento(lista_t* lista, void* elemento){

		if(!lista || lista_vacia(lista)){
				return NULL;
		}
		nodo_t* actual =  lista->nodo_inicio;
		int i = 0;
		while(elemento!=actual->elemento){
				actual = actual->siguiente;
				i++;
		}
		return actual->elemento;

}
void* lista_ultimo(lista_t* lista){

    if(!lista || lista_vacia(lista)){
        return NULL;
    }
    return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t* lista){

    return (!lista || lista->cantidad==0);
}

size_t lista_elementos(lista_t* lista){

		if(!lista){
				return 0;
		}
    return (unsigned int)lista->cantidad;
}

void lista_con_cada_elemento(lista_t* lista, void (*funcion)(void*)){

		if(!lista || lista_vacia(lista)){
				return;
		}
		nodo_t * actual = lista->nodo_inicio;
		while(actual){
				funcion(actual->elemento);
				actual = actual->siguiente;
		}
		return;
}


void lista_destruir(lista_t* lista){

    if(!lista){
        return;
    }
    while(!lista_vacia(lista)){
        borrar_al_inicio(lista);
    }
    free(lista);
    return;
}

lista_iterador_t* lista_iterador_crear(lista_t* lista){

		if(!lista){
				return NULL;
		}
		lista_iterador_t* iterador = (lista_iterador_t*)malloc(sizeof(struct lista_iterador));
		if(!iterador){
				return NULL;
		}
		iterador->corriente = lista->nodo_inicio;
		iterador->lista = lista;
		return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){

		bool estado = false;
		if(!iterador){
				return estado;
		}
		if(((iterador->corriente))!=NULL){
				estado = true;
		}
		return estado;

}

void* lista_iterador_siguiente(lista_iterador_t* iterador){

			if(!iterador){
					return NULL;
			}
			void * elemento = iterador->corriente->elemento;
			if(iterador->corriente){
					iterador->corriente = iterador->corriente->siguiente;
			}

			return elemento;
}

void lista_iterador_destruir(lista_iterador_t* iterador){

			if(!iterador){
					return;
			}
			free(iterador);
}
