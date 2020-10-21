#include "abb.h"
#include <stdio.h>
#include <stdbool.h>
#define EXITO 0
#define ERROR -1
#define MAYOR 1
#define MENOR -1
#define IGUALES 0




abb_t* arbol_crear(abb_comparador comparador, abb_liberar_elemento destructor){

    if(!comparador){
        return NULL;
    }
    abb_t* arbol = (abb_t*)calloc(1,sizeof(abb_t));
    if(!arbol){
        return NULL;
    }
    arbol->comparador = comparador;
    arbol->destructor = destructor;
    return arbol;
}
/*
	*Creara un nodo, reservando la memoria necesaria.
	*Devuelve un puntero al nodo ya inicializado o Null en caso de error.
*/
nodo_abb_t* crear_nodo(void* elemento, int* estado){

    nodo_abb_t* nodo = (nodo_abb_t*)malloc(sizeof(nodo_abb_t));
    if(!nodo){
        return NULL;
    }
    nodo->elemento = elemento;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    *estado = EXITO;
    return nodo;
}


/*
 * Inserta un elemento en el arbol.
 * estado es 0 si pudo insertar o -1 si no pudo.
 * Si el elemento ya estba inserto, lo inserta a la derecha;
 */
nodo_abb_t* insertar_elemento_rec(nodo_abb_t* raiz, void* elemento, abb_comparador comparador, int* estado){

    if(!raiz){
        return crear_nodo(elemento, estado);
    }
    else if(comparador(elemento,raiz->elemento)==IGUALES || comparador(elemento,raiz->elemento)==MAYOR){
          raiz->derecha = insertar_elemento_rec(raiz->derecha, elemento, comparador,estado);
    }else{
          raiz->izquierda = insertar_elemento_rec(raiz->izquierda, elemento, comparador, estado);
    }

    return raiz;
}

int arbol_insertar(abb_t* arbol, void* elemento){

    int estado = ERROR;
    if(!arbol){
        return estado;
    }
    arbol->nodo_raiz = insertar_elemento_rec(arbol->nodo_raiz, elemento, arbol->comparador, &estado);
    return estado;

}
/*
 * Busca en el arbol al elemento que recibe(utilizando la
 * funcion de comparación).
 * Devuelve el elemento encontrado o NULL si no lo encuentra.
 */
nodo_abb_t* buscar_elemento_rec(nodo_abb_t* raiz, void* elemento, abb_comparador comparador){

    if(!raiz || comparador(elemento,raiz->elemento)==IGUALES){
        return raiz;
    }
    else if(comparador(elemento,raiz->elemento)==MAYOR){
         return raiz = buscar_elemento_rec(raiz->derecha,elemento, comparador);
    }else{
        return raiz = buscar_elemento_rec(raiz->izquierda, elemento, comparador);
    }

}


void* arbol_buscar(abb_t* arbol, void* elemento){

    if(!arbol || arbol_vacio(arbol)){
        return NULL;
    }
    nodo_abb_t* aux = buscar_elemento_rec(arbol->nodo_raiz, elemento, arbol->comparador);
    if(!aux){
        return NULL;
    }
    return aux->elemento;
}

bool arbol_vacio(abb_t* arbol){
    if(!arbol || !arbol->nodo_raiz){
          return true;
    }else{
          return false;
    }
}

void* arbol_raiz(abb_t* arbol){
    if(!arbol || arbol_vacio(arbol)){
        return NULL;
    }
    return arbol->nodo_raiz->elemento;
}

/*
  * Busca al menor elemento del sub arbol derecho y devulve su nodo
*/
nodo_abb_t* elemento_minimo_de_los_mayores(nodo_abb_t* raiz){

      nodo_abb_t* anterior = raiz;
      nodo_abb_t* actual = raiz->izquierda;

      while(actual && actual->izquierda){
          anterior= actual;
          actual = actual->izquierda;
      }
      return anterior;
}

/*
 * Busca en el arbol un elemento igual al provisto (utilizando la
 * funcion de comparación) y si lo encuentra lo quita del arbol.
 * Adicionalmente, si encuentra el elemento, invoca el destructor con
 * dicho elemento.
 * Estado es 0 si pudo eliminar el elemento o -1 en caso contrario.
 */
nodo_abb_t* borrar_elemento_rec(nodo_abb_t* raiz, void* elemento, abb_comparador comparador, abb_liberar_elemento destructor, int* estado){


      if(comparador(raiz->elemento, elemento)==MAYOR){
          raiz->izquierda = borrar_elemento_rec(raiz->izquierda, elemento, comparador, destructor, estado);
      }else if( comparador(raiz->elemento, elemento)==MENOR){
          raiz->derecha = borrar_elemento_rec(raiz->derecha, elemento, comparador, destructor, estado);
      }else if(comparador(raiz->elemento,elemento)==IGUALES){
          if(!raiz->izquierda && !raiz->derecha){
                destructor(raiz->elemento);
                free(raiz);
                *estado = EXITO;
                return NULL;
          }else if(!raiz->izquierda || !raiz->derecha){
                nodo_abb_t* padre = raiz->derecha?raiz->derecha:raiz->izquierda;
                destructor(raiz->elemento);
                free(raiz);
                *estado = EXITO;
                return padre;
          }else{
                nodo_abb_t* papa_del_papa= elemento_minimo_de_los_mayores(raiz->derecha);
                nodo_abb_t* hijo = papa_del_papa->izquierda;
                if(!hijo){
                    papa_del_papa->izquierda= raiz->izquierda;
                    destructor(raiz->elemento);
                    free(raiz);
                    *estado = EXITO;
                    return papa_del_papa;
                }else{
                    papa_del_papa->izquierda = hijo->derecha;
                    hijo->izquierda = raiz->izquierda;
                    hijo->derecha = raiz->derecha;
                    destructor(raiz->elemento);
                    free(raiz);
                    *estado = EXITO;
                    return hijo;
                }
          }
      }else{
          *estado = ERROR;
      }
      return raiz;
}

int arbol_borrar(abb_t* arbol, void* elemento){

    int estado = ERROR;
    if(arbol_vacio(arbol)){
        return estado;
    }
    arbol->nodo_raiz = borrar_elemento_rec(arbol->nodo_raiz, elemento, arbol->comparador, arbol->destructor, &estado);

    return estado;
}
/*
  * carga al array con el elemento recibido
*/
void llenar_array(void* elemento, void** array, int tamanio_array, int* cantidad_Elementos){

    if(*cantidad_Elementos<tamanio_array){
        array[*cantidad_Elementos]= elemento;
        (*cantidad_Elementos)++;
    }
    return;
}

/*
 * Llena el array del tamaño dado con los elementos de arbol
 * en secuencia inorden.
*/
void recorrido_inorden_rec(nodo_abb_t* raiz, void** array, int tamanio_array, int* cantidad_Elementos){

    if(!raiz || tamanio_array==(*cantidad_Elementos)){
        return;
    }
    recorrido_inorden_rec(raiz->izquierda, array, tamanio_array, cantidad_Elementos);
    llenar_array(raiz->elemento,array, tamanio_array, cantidad_Elementos);
    recorrido_inorden_rec(raiz->derecha,array, tamanio_array, cantidad_Elementos);

}

int arbol_recorrido_inorden(abb_t* arbol, void** array, int tamanio_array){

    int cantidad_Elementos = 0;
    if(arbol_vacio(arbol) || !array || tamanio_array==0){
        return cantidad_Elementos;
    }
    recorrido_inorden_rec(arbol->nodo_raiz,array, tamanio_array, &cantidad_Elementos);
    return cantidad_Elementos;
}
/*
 * Llena el array del tamaño dado con los elementos de arbol
 * en secuencia preorden.
*/
void recorrido_preorden_rec(nodo_abb_t* raiz, void** array, int tamanio_array, int* cantidad_Elementos){

    if(!raiz || tamanio_array==(*cantidad_Elementos)){
        return;
    }
    llenar_array(raiz->elemento, array, tamanio_array, cantidad_Elementos);
    recorrido_preorden_rec(raiz->izquierda,array, tamanio_array, cantidad_Elementos);
    recorrido_preorden_rec(raiz->derecha, array, tamanio_array, cantidad_Elementos);
}

int arbol_recorrido_preorden(abb_t* arbol, void** array, int tamanio_array){

    int cantidad_Elementos = 0;
    if(arbol_vacio(arbol) || !array || tamanio_array==0){
        return cantidad_Elementos;
    }
    recorrido_preorden_rec(arbol->nodo_raiz, array, tamanio_array, &cantidad_Elementos);
    return cantidad_Elementos;
}
/*
 * Llena el array del tamaño dado con los elementos de arbol
 * en secuencia posorden.
*/
void recorrido_postorden_rec(nodo_abb_t* raiz, void** array, int tamanio_array, int *cantidad_Elementos){

    if(!raiz || tamanio_array==(*cantidad_Elementos)){
        return;
    }
    recorrido_postorden_rec(raiz->izquierda,array, tamanio_array, cantidad_Elementos);
    recorrido_postorden_rec(raiz->derecha, array, tamanio_array, cantidad_Elementos);
    llenar_array(raiz->elemento, array, tamanio_array, cantidad_Elementos);
}

int arbol_recorrido_postorden(abb_t* arbol, void** array, int tamanio_array){

    int cantidad_Elementos = 0;
    if(arbol_vacio(arbol) || !array || tamanio_array==0){
        return cantidad_Elementos;
    }
    recorrido_postorden_rec(arbol->nodo_raiz, array, tamanio_array, &cantidad_Elementos);
    return cantidad_Elementos;
}

/*
  *Recorre el arbol e invoca la funcion con cada elemento del mismo. El puntero 'extra' se pasa como segundo
  * parámetro a la función. Si la función devuelve true, se finaliza el
  * recorrido aun si quedan elementos por recorrer. Si devuelve false
  * se sigue recorriendo mientras queden elementos.
  * El recorrido se realiza en secuencia inorden.
*/
void abb_con_cada_elemento_inorder(nodo_abb_t* raiz, bool (*funcion)(void*, void*), void* extra, bool* estado){

      if(!raiz || (*estado)){
          return;
      }
      abb_con_cada_elemento_inorder(raiz->izquierda, funcion, extra, estado);
      if(!(*estado)){
          *estado = funcion(raiz->elemento, extra);
      }
      abb_con_cada_elemento_inorder(raiz->derecha, funcion, extra, estado);
}

/*
  *Recorre el arbol e invoca la funcion con cada elemento del mismo. El puntero 'extra' se pasa como segundo
  * parámetro a la función. Si la función devuelve true, se finaliza el
  * recorrido aun si quedan elementos por recorrer. Si devuelve false
  * se sigue recorriendo mientras queden elementos.
  * El recorrido se realiza en secuencia preorden.
*/
void abb_con_cada_elemento_preorden(nodo_abb_t* raiz, bool (*funcion)(void*, void*), void* extra, bool* estado){

    if(!raiz || (*estado)){
        return;
    }
    *estado = funcion(raiz->elemento, extra);
    abb_con_cada_elemento_preorden(raiz->izquierda, funcion, extra, estado);
    abb_con_cada_elemento_preorden(raiz->derecha, funcion, extra, estado);

}
/*
  *Recorre el arbol e invoca la funcion con cada elemento del mismo. El puntero 'extra' se pasa como segundo
  * parámetro a la función. Si la función devuelve true, se finaliza el
  * recorrido aun si quedan elementos por recorrer. Si devuelve false
  * se sigue recorriendo mientras queden elementos.
  * El recorrido se realiza en secuencia postorden.
*/
void abb_con_cada_elemento_postorden(nodo_abb_t* raiz, bool (*funcion)(void*, void*), void* extra, bool* estado){

    if(!raiz || (*estado)){
        return;
    }
    abb_con_cada_elemento_postorden(raiz->izquierda, funcion, extra, estado);
    abb_con_cada_elemento_postorden(raiz->derecha, funcion, extra, estado);
    if(!(*estado)){
        * estado = funcion(raiz->elemento, extra);
    }
}


void abb_con_cada_elemento(abb_t* arbol, int recorrido, bool (*funcion)(void*, void*), void* extra){

    if(arbol_vacio(arbol) || !funcion){
        return;
    }
    bool estado = false;
    if(recorrido == ABB_RECORRER_INORDEN){
        abb_con_cada_elemento_inorder(arbol->nodo_raiz, funcion, extra, &estado);
    }else if(recorrido == ABB_RECORRER_PREORDEN){
        abb_con_cada_elemento_preorden(arbol->nodo_raiz, funcion, extra, &estado);
    }else if(recorrido == ABB_RECORRER_POSTORDEN){
        abb_con_cada_elemento_postorden(arbol->nodo_raiz, funcion, extra, &estado);
    }else{
        return;
    }
}


/*
  *invoca al destructor, liberando al elemento del nodo
  *Libera la memoria reservada de cada nodo.
*/
void destruir_rec(nodo_abb_t* raiz, abb_liberar_elemento destructor){

      if(!raiz){
          return;
      }
      destruir_rec(raiz->izquierda, destructor);
      destruir_rec(raiz->derecha, destructor);
      destructor(raiz->elemento);
      free(raiz);
}

void arbol_destruir(abb_t* arbol){
     if(!arbol || !arbol->destructor){
        return;
     }
     destruir_rec(arbol->nodo_raiz, arbol->destructor);
     free(arbol);
     return;
}
