#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define EXITO 0
#define ERROR -1


cola_t* cola_crear(){

    cola_t* cola= (cola_t*)malloc(sizeof(cola_t));
    if(!cola){
       return NULL;
    }
    cola->nodo_inicio=NULL;
    cola->nodo_fin=NULL;
    cola->cantidad=0;

    return cola;
}

bool cola_vacia(cola_t* cola){
    if(!cola || cola->cantidad==0){
        return true;
    }else{
      return false;
    }
}


int cola_encolar(cola_t* cola, void* elemento){

    if(!cola){
        return ERROR;
    }
    nodo_t* nodo_aux=(nodo_t*)malloc(sizeof(nodo_t));
    if (!nodo_aux){
        return ERROR;
    }
    nodo_aux->elemento=elemento;
    nodo_aux->siguiente=NULL;

    if(cola_vacia(cola)){
        cola->nodo_inicio=nodo_aux;
        cola->nodo_fin=nodo_aux;
    }
    if(!cola_vacia(cola)){
        cola->nodo_fin->siguiente=nodo_aux;
        cola->nodo_fin=nodo_aux;
    }
    (cola->cantidad)++;
    return EXITO;
}

int cola_desencolar(cola_t* cola){

    if(!cola){
        return ERROR;
    }
    if(cola_vacia(cola)){
        return ERROR;
    }

    nodo_t* nodo_aux=cola->nodo_inicio;
    cola->nodo_inicio=cola->nodo_inicio->siguiente;
    free(nodo_aux);
    (cola->cantidad)--;
    return EXITO;

}
int cola_cantidad(cola_t* cola){
    if(!cola){
       return 0;
    }
    return (cola->cantidad);
}

void* cola_primero(cola_t* cola){

    if(!cola || cola_vacia(cola)){
        return NULL;
    }
    return (cola->nodo_inicio->elemento);

}

void cola_destruir(cola_t* cola){
    if(!cola){
        return;
    }
    while(!cola_vacia(cola)){
        cola_desencolar(cola);
    }

    free(cola);
}
