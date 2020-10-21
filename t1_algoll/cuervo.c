#include <stdio.h>
#include<stdbool.h>
#include "cuervo_tres_ojos.h"
#include <string.h>
#define ARCHIVO_VISIONES "visiones.txt"
#define PASADO 'P'
#define FUTURO 'F'
#define ERROR -1
#define EXITO 0
#define NOMBRE_CUERVO "pope"
#define   NOMBRE_APRENDIZ "bran"


/*
  *Recibe una vision
  *devolvera true si la vision es pasada sino devolvera false
*/
bool es_vision_pasado(vision_t vision){

    bool es_vision=false;
    if(vision.epoca==PASADO){
       es_vision=true;
    }
    return es_vision;
}
/*
  *Recibe una vision
  *devolvera true si el protagonista de la vision es Daenerys sino devolvera false
*/
bool es_vision_Daenerys_Targaryen(vision_t vision){

    bool es_vision=false;
    if(strcmp(vision.protagonista,"Daenerys Targaryen")==0){
      es_vision=true;
    }
    return es_vision;
}
/*
  *Recibe una vision
  *devolvera true si la casa del protagonista de la vision es starck sino devolvera false
*/
bool es_vision_stark(vision_t vision){

    bool es_vision=false;
    if(strcmp(vision.casa_protagonista,"Stark")==0){
        es_vision=true;
    }
    return es_vision;
}
/*
  *Recibe una vision
  *devolvera true si la vision es futuro sino devolvera false
*/
bool es_vision_futuro(vision_t vision){

    bool es_vision=false;
    if(vision.epoca==FUTURO){
        es_vision=true;
    }
    return es_vision;
}
/*
  *Recibe una vision
  *devolvera true si el protagonista de la vision no pertenece a la casa lannister,sino devolvera false
*/
bool no_es_Lannister(vision_t vision){

    bool es_vision=true;
    if(strcmp(vision.casa_protagonista,"Lannister")==0){
        es_vision=false;
    }
    return es_vision;
}
/*
  *Recibe una vision
  *devolvera true si la descripcion de la vision es mayor a 20 letras, sino devolvera false
*/
bool descripcion_mayor_a_20_letras(vision_t vision){

    bool es_vision=false;
    if(strlen(vision.descripcion)>=20){
        es_vision=true;
    }
    return es_vision;
}

/*
  * Recibe un archivo ya abierto y una vision.
  * La funcion vuelve 0 si no leyo nada, sino devuelve la cantidad de presos que leyo.
*/
int leer_archivo(FILE* archivo, vision_t *vision){

      return fscanf(archivo,"%[^;];%[^;];%[^;];%c\n", vision->protagonista,vision->casa_protagonista,vision->descripcion,&(vision->epoca));

}
/*
  *Recibe un estado de la funcion.
  * si el estado es -1 mostrar por pantalla un mensaje de error y liberara la memoria.
*/
void error_funcion(cuervo_tres_ojos_t* cuervo,cuervo_aprendiz_t* aprendiz){

      printf("Ocurrio un error: Memoria agotada");
      destruir_cuervo(cuervo);
      destruir_aprendiz(aprendiz);
}

int main(){

      char nombre_cuervo_viejo[MAX_NOMBRE]=NOMBRE_CUERVO;
      char nombre_cuervo_aprendiz[MAX_NOMBRE]=NOMBRE_APRENDIZ;
      vision_t vision;
      int agregue=EXITO;
      int transmiti=EXITO;
      FILE* archivo_visiones= fopen(ARCHIVO_VISIONES,"r");
      if(!archivo_visiones){
          printf("Error de apertura del archivo visiones");
          return 0;
      }

      cuervo_tres_ojos_t* cuervo_viejo= invocar_cuervo(nombre_cuervo_viejo);
      cuervo_aprendiz_t* cuervo_aprendiz=invocar_aprendiz(nombre_cuervo_aprendiz);
      if(cuervo_viejo==NULL){
          error_funcion(cuervo_viejo,cuervo_aprendiz);
          return 0;
      }
      if(cuervo_aprendiz==NULL){
          error_funcion(cuervo_viejo,cuervo_aprendiz);
          return 0;
      }
      int visiones_leidas=leer_archivo(archivo_visiones,&vision);

      while (visiones_leidas==4 && agregue==EXITO){
            agregue=agregar_vision(cuervo_viejo,vision);
            visiones_leidas=leer_archivo(archivo_visiones,&vision);

      }
      if(agregue==ERROR){
          fclose(archivo_visiones);
          error_funcion(cuervo_viejo,cuervo_aprendiz);
          return 0;
      }
      fclose(archivo_visiones);

      transmiti=transmitir_visiones(cuervo_viejo,cuervo_aprendiz,es_vision_futuro);
      if(transmiti==ERROR){
          error_funcion(cuervo_viejo,cuervo_aprendiz);
          return 0;
      }
      transmiti=transmitir_visiones(cuervo_viejo,cuervo_aprendiz,es_vision_stark);
      if(transmiti==ERROR){
          error_funcion(cuervo_viejo,cuervo_aprendiz);
          return 0;
      }
      transmiti=transmitir_visiones(cuervo_viejo,cuervo_aprendiz,descripcion_mayor_a_20_letras);
      if(transmiti==ERROR){
          error_funcion(cuervo_viejo,cuervo_aprendiz);
          return 0;
      }

      listar_visiones_transmitidas(*cuervo_aprendiz,es_vision_futuro);
      destruir_cuervo(cuervo_viejo);
      destruir_aprendiz(cuervo_aprendiz);
      return 0;

}
