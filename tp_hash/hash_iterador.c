#include "hash_iterador.h"
#include "hash.h"
#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct hash_iter{

    lista_iterador_t* corriente;
    int posicion_tabla_hash;
    hash_t* hash;
};

struct hash{

    lista_t** tabla_hash;
    hash_destruir_dato_t destructor;
    size_t capacidad;
    int cantidad_elementos;
};

typedef struct data {

   void* valor;
   char* clave;
} data_t;



bool proxima_lista_con_elementos(hash_t* hash, int* posicion){

    bool lista_no_vacia = false;
    int i = *posicion;
    while(i< hash->capacidad && !lista_no_vacia){

          if(!lista_vacia(hash->tabla_hash[i])){
              *posicion = i;
              lista_no_vacia = true;
          }
          i++;
    }

    return lista_no_vacia;
}

hash_iterador_t* hash_iterador_crear(hash_t* hash){

      if(!hash || !hash->tabla_hash){
          return NULL;
      }
      hash_iterador_t* iterador_hash = (hash_iterador_t*)malloc(sizeof(struct hash_iter));
      if(!iterador_hash){
          return NULL;
      }
      iterador_hash->hash = hash;
      iterador_hash->posicion_tabla_hash = 0;
      if(!proxima_lista_con_elementos(hash, &iterador_hash->posicion_tabla_hash)){
          free(hash);
          return NULL;
      }
      lista_iterador_t* iterador_lista = lista_iterador_crear(hash->tabla_hash[iterador_hash->posicion_tabla_hash]);
      if(!iterador_lista){
          free(iterador_hash);
          return NULL;
      }
      iterador_hash->corriente = iterador_lista;
      return iterador_hash;
}

void* hash_iterador_siguiente(hash_iterador_t* iterador){

      if(!iterador || !iterador->corriente){
          return NULL;
      }
      data_t* informacion = (data_t*)lista_iterador_siguiente(iterador->corriente);
      return (void*)informacion->clave;
}

bool hash_iterador_tiene_siguiente(hash_iterador_t* iterador){

    if(!iterador || !iterador->corriente){
        return false;
    }
    if(iterador->corriente && lista_iterador_tiene_siguiente(iterador->corriente)){
        return lista_iterador_tiene_siguiente(iterador->corriente);
    }else if(!lista_iterador_tiene_siguiente(iterador->corriente)){

        lista_iterador_destruir(iterador->corriente);
        iterador->corriente = NULL;
        iterador->posicion_tabla_hash++;
        if(!proxima_lista_con_elementos(iterador->hash, &iterador->posicion_tabla_hash)){
              return false;
        }else{
            iterador->corriente = lista_iterador_crear(iterador->hash->tabla_hash[iterador->posicion_tabla_hash]);
            if(!iterador->corriente){
                return false;
            }
            return lista_iterador_tiene_siguiente(iterador->corriente);
        }
    }else{
        return false;
    }
    return true;
}



void hash_iterador_destruir(hash_iterador_t* iterador){

    if(!iterador){
        return;
    }
    lista_iterador_destruir(iterador->corriente);
    free(iterador);
}
