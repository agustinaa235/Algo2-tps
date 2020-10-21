#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "pila.h"
#define MINIMO_TAM 2
#define AGRANDAR 2
#define ACHICAR 4
#define EXITO 0
#define ERROR -1


/*
  *La funcion redimencionara el vector de elementos.
  *Si el vector vector de elementos es null  o no pudo reallocar devolvera false, sino devolvera true.
  *Si el tamanio nuevo recibido es menor que el minimo establecido, pasara a ser el minimo.
*/
bool redimencionar(pila_t * pila, int nuevo_tamanio){

    if(!pila->elementos){
        return false;
    }
    if(nuevo_tamanio< MINIMO_TAM){
        nuevo_tamanio=MINIMO_TAM;
    }

    void** nuevo=realloc(pila->elementos,(unsigned)nuevo_tamanio* sizeof(void*));
    if(!nuevo){
        return false;
    }

    pila->elementos=nuevo;
    pila->tamanio=nuevo_tamanio;
    return true;
}

pila_t* pila_crear(){

     pila_t* pila= (pila_t*)malloc(sizeof(pila_t));
     if(!pila){
        return NULL;
     }

     pila->elementos=malloc(MINIMO_TAM*sizeof(void *));
     if(!pila->elementos){
        free(pila);
        return NULL;
     }
     pila->tope=0;
     pila->tamanio=MINIMO_TAM;

     return pila;
}

int pila_apilar(pila_t* pila, void* elemento){

    if(!pila){
        return ERROR;
    }

    if(pila->tope == pila->tamanio){
        if((redimencionar(pila,AGRANDAR*pila->tamanio)==false)){
            return ERROR;
        }
    }
        pila->elementos[pila->tope]= elemento;
        (pila->tope)++;


    return EXITO;
}
bool pila_vacia(pila_t* pila){

    if(pila==NULL){
        return true;
    }
    if(pila->tope==0){
        return true;
    }else{
      return false;
    }
}

void* pila_tope(pila_t* pila){
    if(!pila){
        return NULL;
    }if(pila_vacia(pila)){
        return NULL;
    }

    return pila->elementos[(pila->tope)-1];
}

int pila_cantidad(pila_t* pila){

      if(!pila){
          return EXITO;
      }
      return pila->tope;
}


int pila_desapilar(pila_t* pila){

    if(!pila){
        return ERROR;
    }
    if(pila_vacia(pila)){
        return ERROR;
    }
    (pila->tope)--;

    if(pila->tamanio>=MINIMO_TAM && pila->tope<(pila->tamanio)/ACHICAR){
        if(!redimencionar(pila,(pila->tamanio/AGRANDAR))){
            return ERROR;
        }

    }
    return EXITO;
}

void pila_destruir(pila_t* pila){

    if(!pila){
      return;
    }
    if(!pila->elementos){
      free(pila);
    }

    free(pila->elementos);
    free(pila);
}
