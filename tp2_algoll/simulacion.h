#ifndef _SIMULACION_H_
#define _SIMULACION_H_

#include "abb.h"
#include "lista.h"
#include "cola.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NOMBRE 70

typedef struct persona{

    char nombre[MAX_NOMBRE];
    int edad;
}persona_t;

typedef struct casa{

    char* nombre;
    lista_t* miembros;
    int factor_de_envejecimiento;
    int factor_de_nacimiento;
}casa_t;

typedef struct westeros{

    abb_t* casas_westeros;
    cola_t* casas_extinguidas;
    int cantidad_casas;

}westeros_t;


/*
  *Creara westeros reservando la memoria necesaria.
  *Devuelve un putero del westeros creado o NULL en caso de error.
*/
westeros_t* inicializar_westeros();

/*
  *Insertar una casa al arbol de casas de westeros.
  *Adicionalmente insertara las personas correspondientes a esa casa.
  *Devolver exito si pudo insertar sino devolvera error.
*/
int agregar_casa(westeros_t* westeros, abb_t* casas_westeros, char nombre_archivo_casa[MAX_NOMBRE], int* cantidad_casas);

/*
  * Simulara la cantidad de anios recibida.
  *ira actualizacon las distintas casas con sus respectivos miembros.
  *Al finalar la simulacion devolvera un puntero de la casa ganadora o NULL en caso de que no halla ganador.
*/
casa_t* simulacion_westeros(westeros_t* westeros, int anios_a_similuar);

/*
  * Mostrata la casas extintas o ninguna en caso de no haber nignuna.
  * Devolvera exito si pudo mostrar, sino devolvera error.
*/
int mostrar_casas_extintas(westeros_t* westeros);

/*
  * Mostrara las casas pertenecientes al arbol de casas de westeros,
  * de mayor a menor teniendo ne cuneta la cantidad de miembros pernetecientes a cada casa.
  * Adicionalemte mostrara la cantidad de miembros de esa casa.
*/
int listar_casas_westeros(westeros_t* westeros);

/*
  * Detruye westeros liberando la memoria reservada por el mismo.
  * Adicionamelente se destruira la memoria reservada para cada persona y para cada casa.
*/
void destruir_westeros(westeros_t* westeros);

#endif /* _SIMULACION_H_ */
