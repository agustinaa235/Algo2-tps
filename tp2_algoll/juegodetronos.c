#include <stdio.h>
#include "simulacion.h"
#include "abb.h"
#include "lista.h"


#define ARCHIVO_WESTEROS "westeros.txt"
#define AYUDAS 'H'
#define INICIALIZAR_SIMULACION 'S'
#define AGREGAR_CASA 'A'
#define LISTAR_CASAS 'L'
#define CASAS_EXTINTAS 'E'
#define FINALIZAR 'Q'
#define MAX_NOMBRE 70
#define EXITO 0
#define ERROR -1

void ingresar_comando(char* opcion){

    printf("\ningrese una letra con la que desea arrancar, ingrese la letra H para ver las ayudas.\n");
    scanf(" %c", opcion);
}

void comando_inicializar_simulacion(){
    printf("\nComando de simulacion:\n");
    printf("Ingrese la letra S para inicializar la simulacion. Ingresando esta letra, podra simular el programa.");
    printf("Para eso, debera ingresar la cantidad de anios que desea que se simulen.Al finalizar, devolvera la casa ganadora.\n");
}
void comando_agregra_casa(){
    printf("\nComando de agregado de casa:\n");
    printf("Ingrese la letra A para agregar una casa, Para ello debera ingresar el nombre del archivo deseado(ej: nombre_casa.txt).\n");
}
void comando_casas_extintas(){
    printf("\nComando de casas extintas:\n");
    printf("Ingrese la letra E si desea ver el nombre de las casa extintas.\n");
}
void comando_listar_casa(){
    printf("\nComando de lista de casas:\n");
    printf("Ingrese la letra L si desea ver los nombres de la casas de forma decresiente\n");
}
void comando_finalizar_ejecucion(){
    printf("\nComando finalizar simulacion:\n");
    printf("Ingrese la letra Q si desea finalizar con la ejecucion del programa\n");
}

void ayudas(){
    printf("Sus comando son: \n");
    comando_inicializar_simulacion();
    comando_agregra_casa();
    comando_casas_extintas();
    comando_listar_casa();
}

int main(){

    westeros_t* westeros = inicializar_westeros();
    if(!westeros){
        return 0;
    }
    char archivo_casa[MAX_NOMBRE];
    char opcion;
    int anios_a_similuar = 0;
    printf("\n\nBienvenido a la simulacion de westeros\n\n");
    do{
        ingresar_comando(&opcion);
        if(INICIALIZAR_SIMULACION == opcion){
              printf("\n ingrese la cantidad de anios que desea que trancurran\n");
              scanf(" %i", &anios_a_similuar);
              casa_t* casa_ganadora = simulacion_westeros(westeros, anios_a_similuar);
              if(!casa_ganadora){
                  printf("No hay casa ganadora.\n");
              }else{
                  printf("La casa ganadora es:%s\n", casa_ganadora->nombre);
              }
          }else if(AYUDAS == opcion ){
                  ayudas();
          }else if(AGREGAR_CASA == opcion){
              printf("ingrese el nombre del archivo: \n");
              scanf(" %s", archivo_casa);
              (agregar_casa(westeros, westeros->casas_westeros, archivo_casa, &(westeros->cantidad_casas)) == EXITO? printf("operacion exitosa\n"): printf("Fallo operacion\n"));
          }else if(LISTAR_CASAS == opcion){

                (listar_casas_westeros(westeros)== EXITO? printf("operacion exitosa\n"): printf("Fallo operacion\n"));;

          }else if(CASAS_EXTINTAS == opcion){

              (mostrar_casas_extintas(westeros) == EXITO? printf("operacion exitosa\n"): printf("Fallo operacion\n"));

          }else{
              printf("ingresaste mal un comando, ingrese la letra H si desea ver las ayudas\n");
          }
    }while(opcion!=FINALIZAR);

    if(opcion == FINALIZAR){
        destruir_westeros(westeros);
    }
return 0;

}
