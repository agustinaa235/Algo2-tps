#include "hash.h"
#include "cola.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define EXITO 0
#define AGRANDAR 2
#define POSICION_NO_VALIDA -1
#define IGUALES 0


typedef struct data {

   void* valor;
   char* clave;
} data_t;

struct hash{

    lista_t** tabla_hash;
    hash_destruir_dato_t destructor;
    size_t capacidad;
    int cantidad_elementos;
};

extern char* strdup(const char*);

hash_t* hash_crear(hash_destruir_dato_t destruir_elemento, size_t capacidad){

    hash_t* hash = (hash_t*)calloc(1, sizeof(hash_t));
    if(!hash){
        return NULL;
    }
    lista_t** tabla_hash = (lista_t**)calloc(capacidad, sizeof(lista_t*));
    if(!tabla_hash){
        free(hash);
        return NULL;
    }
    hash->tabla_hash = tabla_hash;
    hash->destructor = destruir_elemento;
    hash->capacidad = capacidad;
    hash->cantidad_elementos = 0;

    bool hay_error = false;
    for(int i=0; i<capacidad ; i++){
        hash->tabla_hash[i] = lista_crear();
        if(!hash->tabla_hash[i]){
            hay_error = true;
        }
    }
    if(hay_error){
        for(int i=0; i<capacidad; i++){
            lista_destruir(hash->tabla_hash[i]);
        }
        free(hash->tabla_hash);
        free(hash);
    }
    return hash;
}
/*
* Devuelve true si el hash no existe o la acntidad de elementos es 0,
* sino devuelve false.
*/
bool hash_vacio(hash_t* hash){

    return (!hash || hash->cantidad_elementos==0);
}
/*
* La funcion devolvera posicion en el hash correspondiente.
*/
size_t funcion_hash(hash_t* hash, const char* clave){

      size_t numero = 0;
      for(int i =0; i<strlen(clave); i++){
          numero+= ((size_t)clave[i]);
      }
      return numero%hash->capacidad;
}
/*
* Si el elemento se encuentra en el hash, devolvera true, sino devolvera false.
* Adicionalemnete modificara la posicion recibidad si el elemento se encuentra en el hash.
*/
bool buscar_elemento(lista_t* lista, const char* clave, int* posicion){

    bool esta = false;
    lista_iterador_t* iterador = lista_iterador_crear( lista);
    if(!iterador){
        return esta;
    }
    int i = 0;
    while(lista_iterador_tiene_siguiente(iterador) && !esta){

          data_t* informacion = (data_t*)lista_iterador_siguiente(iterador);
          if(strcmp(informacion->clave,clave) == IGUALES){
              esta = true;
              (*posicion)= i;
          }
          i++;
    }

    lista_iterador_destruir(iterador);
    return esta;
}

/*
* Devuelve true si la capcidad del hash sovre la cantidad de elementos es menor que el factor de rehasheo.
* Sino devolvera false,
*/
bool factor_de_rehasheo(size_t capacidad_hash, size_t cantidad_elementos){

    return ((capacidad_hash/cantidad_elementos) < 2);
}

/*
* La funcion agrandara el vector (tabla) de hash piediendo la memoria necesaria.
*  Pasara todos los elementos de hash viejo al hash nuevo.
*/
int rehasheo(hash_t* hash){

    int estado = EXITO;
    int i = 0;
    cola_t* cola = cola_crear();
    while(i<hash->capacidad){
        lista_iterador_t* iterador_lista = lista_iterador_crear(hash->tabla_hash[i]);
        if(!iterador_lista){
            estado = ERROR;;
        }
        while(lista_iterador_tiene_siguiente(iterador_lista)){
            data_t* informacion = (data_t*)lista_iterador_siguiente(iterador_lista);
            cola_encolar(cola, informacion);
            lista_borrar_de_posicion(hash->tabla_hash[i], 0);
        }
        lista_iterador_destruir(iterador_lista);
        i++;
    }


    size_t capacidad_vieja = hash->capacidad;
    size_t capacidad_nueva = hash->capacidad*AGRANDAR;
    lista_t** tabla_hash_aux = realloc(hash->tabla_hash, sizeof(lista_t*)* capacidad_nueva);
    if(!tabla_hash_aux){
        estado = ERROR;
    }
    hash->cantidad_elementos = 0;
    hash->capacidad = capacidad_nueva;
    hash->tabla_hash = tabla_hash_aux;
    for(size_t i = capacidad_vieja; i<capacidad_nueva; i++ ){
        hash->tabla_hash[i] = lista_crear();
        if(!hash->tabla_hash[i]){
            estado = ERROR;
        }
    }
    while(!cola_vacia(cola) && estado==EXITO){
        data_t* informacion = (data_t*)cola_primero(cola);
        cola_desencolar(cola);
        estado = hash_insertar(hash, informacion->clave, informacion->valor);
        free(informacion->clave);
        free(informacion);
    }
    free(cola);

    return estado;
}

/*
* borrara el elemento viejo de la lista, e insertara el nuevo con la misma calve camniando el valor.
* Devolvera si pudo actualizar o no.
*/
int actualizar_elemento(hash_t* hash, int pos_elemento_lista, data_t* informacion, size_t pos_hash){

    lista_borrar_de_posicion(hash->tabla_hash[pos_hash], (unsigned int)pos_elemento_lista);
    hash->cantidad_elementos--;
    int estado = lista_insertar(hash->tabla_hash[pos_hash], informacion);
    return estado;

}

/*
* inicializara la informacion(clave-elemento) pidiendo la memoria necesaria.
*  devuelve un puntero a la informacion inicializada o NULL si no pudo inicializarla.
*/
data_t* inicializar_informacion(const char* clave, void* elemento){

    data_t* informacion_aux = (data_t*)malloc(sizeof(data_t));
    if(!informacion_aux){
        return NULL;
    }
    informacion_aux->clave = strdup(clave);
    informacion_aux->valor = elemento;

    return informacion_aux;
}

int hash_insertar(hash_t* hash, const char* clave, void* elemento){

    int estado = ERROR;
    if(!hash || !clave){
        return estado;
    }
    size_t posicion = funcion_hash(hash, clave);
    data_t* informacion = inicializar_informacion(clave, elemento);
    if(!informacion){
        return estado;
    }

    int pos_elemento_lista = POSICION_NO_VALIDA;
    if(buscar_elemento(hash->tabla_hash[posicion], clave, &pos_elemento_lista)){
        data_t* elemento_buscado = (data_t*)lista_elemento_en_posicion(hash->tabla_hash[posicion], (unsigned int)pos_elemento_lista);
        if(hash->destructor){
            hash->destructor(elemento_buscado->valor);
        }
            free(elemento_buscado->clave);
            free(elemento_buscado);
            estado =  actualizar_elemento(hash, pos_elemento_lista, informacion, posicion);

    }else{

        estado = lista_insertar(hash->tabla_hash[posicion], informacion);

    }
    hash->cantidad_elementos++;
    if(factor_de_rehasheo(hash->capacidad, (size_t)hash->cantidad_elementos)){
          estado = rehasheo(hash);
    }

    return estado;
}

int hash_quitar(hash_t* hash, const char* clave){

    int estado = ERROR;
    if(hash_vacio(hash)){
        return estado;
    }
    size_t posicion = funcion_hash(hash, clave);
    int pos_elemento_lista = POSICION_NO_VALIDA;
    buscar_elemento(hash->tabla_hash[posicion], clave, &pos_elemento_lista);
    if(pos_elemento_lista == POSICION_NO_VALIDA){
        return estado;
    }
    data_t* elemento_buscado = (data_t*)lista_elemento_en_posicion(hash->tabla_hash[posicion], (unsigned int)pos_elemento_lista);
    if(strcmp(elemento_buscado->clave, clave)==IGUALES){
        if(hash->destructor){
          hash->destructor(elemento_buscado->valor);
        }
        free(elemento_buscado->clave);
        estado = lista_borrar_de_posicion(hash->tabla_hash[posicion], (unsigned int)pos_elemento_lista);
        free(elemento_buscado);
        (hash->cantidad_elementos)--;
    }
    return estado;
}


bool hash_contiene(hash_t* hash, const char* clave){

    bool estado = false;
    if(hash_vacio(hash)){
        return estado;
    }
    size_t posicion = funcion_hash(hash, clave);
    int pos_elemento_lista = POSICION_NO_VALIDA;
    estado = buscar_elemento(hash->tabla_hash[posicion], clave, &pos_elemento_lista);

    return estado;
}

void* hash_obtener(hash_t* hash, const char* clave){

    if(hash_vacio(hash)){
        return NULL;
    }
    size_t posicion = funcion_hash(hash, clave);
    int pos_elemento_lista = POSICION_NO_VALIDA;
    buscar_elemento(hash->tabla_hash[posicion], clave, &pos_elemento_lista);
    if(pos_elemento_lista == POSICION_NO_VALIDA){
        return NULL;
    }
    data_t* informacion = (data_t*)lista_elemento_en_posicion(hash->tabla_hash[posicion], (unsigned int)pos_elemento_lista);
    return informacion->valor;
}

size_t hash_cantidad(hash_t* hash){

    if(hash_vacio(hash)){
        return 0;
    }
    return (unsigned int)hash->cantidad_elementos;
}

/*
* Destruye la lista recibida, liberando la memoria necesaria e invocando
* a la funcion destructora con cada elemento.
*/
void destruir_lista(lista_t* lista, hash_destruir_dato_t destructor){

    while(!lista_vacia(lista)){

          data_t* informacion = (data_t*)lista_ultimo(lista);

          lista_borrar(lista);
          if(destructor){
              destructor(informacion->valor);
          }
          free(informacion->clave);
          free(informacion);
    }
    lista_destruir(lista);
    return;
}

void hash_destruir(hash_t* hash){
    if(!hash){
          return;
    }
    int i=0;
    while(i<hash->capacidad){

        destruir_lista(hash->tabla_hash[i], hash->destructor);
        i++;
    }
    free(hash->tabla_hash);
    free(hash);
    return;
}
