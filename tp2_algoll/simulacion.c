#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "simulacion.h"
#include "abb.h"
#include "lista.h"

#define ERROR -1
#define EXITO 0
#define MAX_NOMBRE 70
#define EDAD_MAXIMA 60
#define CASA 'C'
#define PERSONAS 'I'
#define MAYOR 1
#define MENOR -1
#define IGUALES 0
#define LEIDOS_CASA 3
#define LEIDOS_PERSONAS 2

extern char* strdup(const char*);

/*
 * Comparador de elementos. Recibe dos elementos pertenecientes al arbol y devuelve
 * 0 en caso de ser iguales, 1 si el primer elemento es mayor al
 * segundo o -1 si el primer elemento es menor al segundo.
 */
int comparador(void* elemento1, void* elemento2){
    if(!elemento1 || !elemento2)
	       return 0;

    if(strcmp(((casa_t*)elemento1)->nombre,((casa_t*)elemento2)->nombre)==MAYOR){
	       return MAYOR;
    }else if(strcmp(((casa_t*)elemento1)->nombre,((casa_t*)elemento2)->nombre)==MENOR){
	       return MENOR;
    }else{
        return IGUALES;
    }
}
/*
  * Liberara la memoria correspondiente de cada lista, incluyendo a las personas.
*/
void destruir_lista_personas(lista_t* lista){

    while(!lista_vacia(lista)){

          persona_t* persona = (persona_t*)lista_ultimo(lista);
          free(persona);
          lista_borrar(lista);
    }
    lista_destruir(lista);
    return;
}
/*
  * Liberara la memoria correspondiente de cada casa.
*/
void destruir_casa(casa_t* casa){

    if(!casa){
        return;
    }
    destruir_lista_personas(casa->miembros);
    free(casa->nombre);
    free(casa);
}
/*
 * Destructor de elementos. Cada vez que un elemento deja el arbol
 * (arbol_borrar o arbol_destruir) se invoca al destructor pasandole
 * el elemento.
 */
void destructor(void* elemento){
    if(!elemento){
	     return;
    }
    destruir_casa((casa_t*)elemento);
}

westeros_t* inicializar_westeros(){

    westeros_t* westeros = (westeros_t*)malloc(sizeof(westeros_t));
    if(!westeros){
        return NULL;
    }
    abb_t* casas_westeros = arbol_crear(comparador, destructor);
    if(!casas_westeros){
        free(westeros);
        return NULL;
    }
    westeros->casas_westeros = casas_westeros;
    westeros->cantidad_casas = 0;
    cola_t* casas_exinguidas = cola_crear();
    if(!casas_exinguidas){
        free(westeros->casas_westeros);
        free(westeros);
        return NULL;
    }
    westeros->casas_extinguidas =  casas_exinguidas;
    return westeros;
}

/*
	*Creara una casa, reservando la memoria necesaria.
	*Devuelve un puntero a la casa ya inicializado o Null en caso de error.
*/
casa_t* inicializar_casa(casa_t* casa){

  casa_t* casa_aux = calloc(1,sizeof(casa_t));
  if(!casa){
      return NULL;
  }
  casa_aux->miembros = lista_crear();
  if(!casa_aux->miembros){
      free(casa);
      return NULL;
  }
  casa_aux->nombre = casa->nombre;
  casa_aux->factor_de_envejecimiento = casa->factor_de_envejecimiento;
  casa_aux->factor_de_nacimiento = casa->factor_de_nacimiento;

  return casa_aux;
}

/*
	*Creara una persona, reservando la memoria necesaria.
	*Devuelve un puntero a la persona ya inicializado o Null en caso de error.
*/
persona_t* inicializar_persona(){

    persona_t* persona = calloc(1,sizeof(persona_t));
    if(!persona){
        return NULL;
    }
    return persona;
}

int agregar_casa(westeros_t* westeros, abb_t* casas_westeros, char nombre_archivo_casa[MAX_NOMBRE], int* cantidad_casas){

    int estado = EXITO;
    if(!westeros || !casas_westeros){
        return ERROR;
    }
    FILE* archivo_casa=fopen(nombre_archivo_casa,"r");
    if(!archivo_casa){
        return ERROR;
    }
    int leidos_casa = 0, leidos_persona = 0;
    char array_aux[200];
    void* elemento= fgets(array_aux, 200, archivo_casa);
    while(elemento && estado == EXITO){
        if(array_aux[0]==CASA){
            casa_t casa_aux;
            char nombre_casa[MAX_NOMBRE];
            leidos_casa = sscanf(array_aux, "C;%[^;];%i;%i", nombre_casa, &(casa_aux.factor_de_envejecimiento), &(casa_aux.factor_de_nacimiento));
            casa_aux.nombre = strdup(nombre_casa);
            casa_t* casa_ya_ingresada = arbol_buscar(casas_westeros, &casa_aux);
            if(leidos_casa == LEIDOS_CASA && casa_ya_ingresada==NULL){
                casa_ya_ingresada = inicializar_casa(&casa_aux);
                if(!casa_ya_ingresada)
                    estado = ERROR;
                estado = arbol_insertar(casas_westeros, casa_ya_ingresada);
                (*cantidad_casas)++;
            }else{
                free(casa_aux.nombre);
            }
            elemento = fgets(array_aux, 200, archivo_casa);
            while(array_aux[0] == PERSONAS && elemento && estado== EXITO){
                persona_t* persona = inicializar_persona();
                if(!persona)
                    estado = ERROR;
                leidos_persona = sscanf(array_aux, "I;%[^;];%i", persona->nombre, &(persona->edad));
                if(leidos_persona == LEIDOS_PERSONAS){
                    estado = lista_insertar(casa_ya_ingresada->miembros, persona);
                }else{
                    estado = ERROR;
                }
                    elemento = fgets(array_aux, 200, archivo_casa);
            }
            if(leidos_casa!=LEIDOS_CASA)
                estado= ERROR;
        }
    }
    fclose(archivo_casa);
    return estado;
}
/*
  * Actualizara a la persona aumento la edad por cada anio de cauerdo al factor de envejecimiento de la casa.
  * Si la persona supera los 60 anios, debera ser elimanda de la lista, liberando la memoria necesaria.
  * Adiconalmente se verificara si la casa quedo vacia, en ese caso pasara a la cola de las casas extintas.
  * Devolvera true si pudo actualizar o false en caso contrario.
*/
bool actualizar_persona(westeros_t* westeros, casa_t* casa, casa_t** casas_a_extinguirse, int* tope_casas_a_extinguirse){

    bool estado = false;
    size_t pos = 0;
    while(pos < lista_elementos(casa->miembros) && !estado){
        persona_t* persona = (persona_t*)lista_elemento_en_posicion(casa->miembros, pos);
        persona->edad+= casa->factor_de_envejecimiento;
        estado = EXITO;
        if(persona->edad>= EDAD_MAXIMA){
            free(persona);
            estado =(lista_borrar_de_posicion(casa->miembros, pos) == ERROR? true:false);
            pos--;
        }
        pos++;
    }
    if(lista_vacia(casa->miembros)){

        cola_encolar(westeros->casas_extinguidas, strdup(casa->nombre));
        casas_a_extinguirse[*tope_casas_a_extinguirse] = casa;
        (*tope_casas_a_extinguirse)++;
    }
    return estado;
}

/*
  * Agregara personas a la casa teniendo en cuenta el factor de nacimiento, reservando la memoria necesaria.
  * Devolvera false si hubo algun error, sino devolvera true.
*/
bool nacimientos(casa_t* casa, FILE* archivo_personas){

    bool estado = false;
    if(!casa){
        return estado;
    }
    size_t cantidad_de_bendis = lista_elementos(casa->miembros)/(size_t)casa->factor_de_nacimiento;
    int i = 0;
    while(i<cantidad_de_bendis && !estado){
        persona_t* persona = inicializar_persona();
        if(!persona){
            estado = false;
        }
        int leidos = fscanf(archivo_personas, "%[^;];%i\n" , persona->nombre, &(persona->edad));
        if(leidos==2 && estado == EXITO){
            estado = (lista_insertar(casa->miembros, persona) == ERROR? true:false);
            leidos = fscanf(archivo_personas, "%[^;];%i\n", persona->nombre, &(persona->edad));
        }else{
            free(persona);
        }
        i++;
    }
    return estado;
}

/*
  * ira actualizando la casa ganadora vericando cual de todas es la que pose la mayor cantidad de miembros.
*/
void obtener_casa_ganadora(abb_t* casas_westeros, casa_t** casa_ganadora, casa_t* casa_actual){

    if(!(*casa_ganadora) || lista_elementos((*casa_ganadora)->miembros)<lista_elementos(casa_actual->miembros)){

          (*casa_ganadora) = casa_actual;
    }
}
/*
  * Borrar la arbol de casas de westeros, liberando la memoria correspondiente.
*/
int borrar_casa(westeros_t* westeros, casa_t** casas_a_borrar, int* tope_casas_a_extinguirse, casa_t** casa_ganadora){

    int estado = false;
    for(int i = 0; i<(*tope_casas_a_extinguirse); i++){
          if(westeros->cantidad_casas==1){
              *casa_ganadora = NULL;
          }
          estado = (arbol_borrar(westeros->casas_westeros, casas_a_borrar[i]) == ERROR? true:false);
          westeros->cantidad_casas--;
  }
    *tope_casas_a_extinguirse = 0;
    return estado;
}

casa_t* simulacion_westeros(westeros_t* westeros, int anios_a_similuar){

    bool estado = false;
    if(!westeros || arbol_vacio(westeros->casas_westeros)){
        return NULL;;
    }
    int i = 0;
    casa_t* casa_ganadora = NULL;
    FILE* archivo_personas = fopen("persona.txt", "r");
    if(!archivo_personas){
        return NULL;
    }
    int tope_casas_a_extinguirse = 0;
    casa_t* casas_a_extinguirse[westeros->cantidad_casas];

    while(i<= anios_a_similuar && westeros->cantidad_casas!=0 && !estado){

        casa_t* casas[westeros->cantidad_casas];
        int cantidad_casas = arbol_recorrido_postorden(westeros->casas_westeros, (void*)casas, westeros->cantidad_casas);

        for(int i = 0; i<cantidad_casas;i++){

            casa_t* casa = casas[i];
            estado = actualizar_persona(westeros, casa, casas_a_extinguirse, &tope_casas_a_extinguirse);
            if(!estado){
                estado = nacimientos(casa, archivo_personas);
            }
            obtener_casa_ganadora(westeros->casas_westeros, &casa_ganadora, casa);
        }
        estado = borrar_casa(westeros,casas_a_extinguirse, &tope_casas_a_extinguirse, &casa_ganadora);
        i++;
    }
    if(estado){
        return NULL;
    }
    fclose(archivo_personas);
    return casa_ganadora;
}

int mostrar_casas_extintas(westeros_t* westeros){

    int estado = EXITO;
    if(!westeros){
        return ERROR;
    }
    int i = 0;
    if(cola_vacia(westeros->casas_extinguidas)){
        printf("No hay casas extinguidas\n");
    }else{
      char* nombre = (char*)cola_primero(westeros->casas_extinguidas);
      while(i<cola_cantidad(westeros->casas_extinguidas) && nombre && estado == EXITO){

            printf("Casas_exitintas: %s\n", nombre);
            estado = cola_desencolar(westeros->casas_extinguidas);
            free(nombre);
            nombre = (char*)cola_primero(westeros->casas_extinguidas);
        }
        i++;
    }
    return estado;
}

/*
  * Ordeada el vector de casas recibido de mayor a menor teniendo en cuenta la cantidad de miembros
  * en cada una de las casas.
*/
void ordenar_vector(casa_t** casas, int cantidad_de_casas){

    casa_t* aux;
    int i = 1;
    bool esta_ordenado = false;
    while(i<cantidad_de_casas && !esta_ordenado){
        esta_ordenado = true;
        for(int j = 0; j<cantidad_de_casas -i;j++){
            if(lista_elementos((casas[j])->miembros)<lista_elementos((casas[j+1])->miembros)){
                  aux = casas[j];
                  casas[j] = casas[j+1];
                  casas[j+1] = aux;
                  esta_ordenado = false;
            }
        }
        i++;
    }
}

int listar_casas_westeros(westeros_t* westeros){

    if(!westeros || !westeros->casas_westeros){
        return ERROR;
    }
    if(westeros->cantidad_casas==0){
        printf("No hay casa para listar.\n");
    }
    casa_t* casas[westeros->cantidad_casas];
    int cantidad_casas = arbol_recorrido_postorden(westeros->casas_westeros, (void*)casas, westeros->cantidad_casas);
    ordenar_vector(casas, cantidad_casas);
    for(int i=0; i<cantidad_casas; i++){
        printf("nombre casa: %s con cantidad de miembros %li \n", casas[i]->nombre, lista_elementos(casas[i]->miembros));
    }
    return EXITO;
}

/*
  * Destruira la cola de casas extintas liberando la memoria correspondiente.
*/
void destruir_cola(cola_t* cola){

    while(!cola_vacia(cola)){

        casa_t* casa = (casa_t*)cola_primero(cola);
        cola_desencolar(cola);
        free(casa);
    }
    cola_destruir(cola);
    return;
}

void destruir_westeros(westeros_t* westeros){

    if(!westeros){
        return;
    }
    arbol_destruir(westeros->casas_westeros);
    destruir_cola(westeros->casas_extinguidas);
    free(westeros);
}
