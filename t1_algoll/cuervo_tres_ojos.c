#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"cuervo_tres_ojos.h"

#define PASADO 'P'
#define FUTURO 'F'
#define ERROR -1
#define EXITO 0


cuervo_tres_ojos_t* invocar_cuervo(char* nombre){

      cuervo_tres_ojos_t* cuervo_viejo=(cuervo_tres_ojos_t*)calloc(1,sizeof(cuervo_tres_ojos_t));

      if (cuervo_viejo== NULL){
          return NULL;
      }
      strcpy(cuervo_viejo->nombre, nombre);
      return cuervo_viejo;
}

cuervo_aprendiz_t* invocar_aprendiz(char* nombre){

      cuervo_aprendiz_t* cuervo_aprendiz=(cuervo_aprendiz_t*)calloc(1,sizeof(cuervo_aprendiz_t));

      if(cuervo_aprendiz==NULL){
          return NULL;
      }
      strcpy(cuervo_aprendiz->nombre,nombre);
      return cuervo_aprendiz;
}

/*
  *Agregara una vision al vector del cuervo reservando espacio la memoria necesaria para ella.
  *Devolvera 0 si pudo agregar, sino devolvera -1.
*/
int agregar_visiones(vision_t**visiones_del_cuervo,int* cantidad_de_visiones,vision_t vision){

      vision_t* visiones=NULL;
      if((*cantidad_de_visiones)==0){
          visiones=(vision_t*)malloc(sizeof(vision_t));

      }else{
          visiones=(vision_t*)realloc(*visiones_del_cuervo,((long unsigned)(*cantidad_de_visiones)+1)*sizeof(vision_t));
      }
      if(visiones==NULL){
          return ERROR;
      }
      *visiones_del_cuervo=visiones;

      (*visiones_del_cuervo)[*cantidad_de_visiones]=vision;
      (*cantidad_de_visiones)++;
      return EXITO;
}

int agregar_vision(cuervo_tres_ojos_t* cuervo, vision_t vision){

      int agrego=EXITO;
      if(vision.epoca==PASADO){
          agrego=agregar_visiones(&cuervo->visiones_del_pasado,&cuervo->cantidad_visiones_pasado,vision);
      }else if(vision.epoca==FUTURO){
          agrego=agregar_visiones(&cuervo->visiones_del_futuro,&cuervo->cantidad_visiones_futuro,vision);
      }
      return agrego;
}

/*
  * La funcion devolvera true si la vision a agregar se cuentra en el vector de visiones del aprendiz, sino devolvera false.
*/
bool ya_esta_insertada(vision_t visiones_del_aprendiz[], vision_t vision, int tope_aprendiz){

      bool ya_inserte=false;
      for(int i=0;i<tope_aprendiz;i++){
          if(strcmp(visiones_del_aprendiz[i].protagonista,vision.protagonista)==0 && strcmp(visiones_del_aprendiz[i].casa_protagonista,vision.casa_protagonista)==0 && strcmp(visiones_del_aprendiz[i].descripcion,vision.descripcion)==0 && visiones_del_aprendiz[i].epoca==vision.epoca){
              ya_inserte=true;
          }
      }
      return ya_inserte;
}
/*
  *Transmitirá al aprendiz las visiones del pasado y del futuro del cuervo que sean
  *transmisibles de acuerdo a la función recibida como parámetro.
  *En caso de que la vision ya sea conocida por el aprendiz, esta no se transmitira.
  * Devolvera 0 si pudo pasar la vision , sino devolvera -1.
*/
int pasar_visiones(vision_t visiones[],int cantidad_visiones, cuervo_aprendiz_t* aprendiz, bool (*es_transmisible)(vision_t)){

      int i=0;

      while(i<cantidad_visiones){
          if(es_transmisible(visiones[i]) && ya_esta_insertada(aprendiz->visiones_adquiridas,visiones[i],aprendiz->cantidad_visiones)==false){
              if(aprendiz->cantidad_visiones==0){
                  vision_t* vision_a_trasmitir= (vision_t*)malloc(sizeof(vision_t));
                  if(vision_a_trasmitir==NULL){
                      return ERROR;
                  }else{
                      aprendiz->visiones_adquiridas=vision_a_trasmitir;
                  }
              }else{

                  vision_t* vision_a_trasmitir_aux=(vision_t*)realloc(aprendiz->visiones_adquiridas,((long unsigned)(aprendiz->cantidad_visiones)+1)*sizeof(vision_t));
                  if(vision_a_trasmitir_aux==NULL){
                      return ERROR;
                  }else{
                      aprendiz->visiones_adquiridas=vision_a_trasmitir_aux;
                  }
              }
              aprendiz->visiones_adquiridas[aprendiz->cantidad_visiones]=visiones[i];
              aprendiz->cantidad_visiones++;

          }
          i++;
      }
      return EXITO;
}

int transmitir_visiones(cuervo_tres_ojos_t* cuervo, cuervo_aprendiz_t* aprendiz, bool (*es_transmisible)(vision_t)){

      int transmitio=EXITO;

      transmitio=pasar_visiones(cuervo->visiones_del_pasado,cuervo->cantidad_visiones_pasado,aprendiz,es_transmisible);
      transmitio=pasar_visiones(cuervo->visiones_del_futuro,cuervo->cantidad_visiones_futuro,aprendiz,es_transmisible);

    return transmitio;
}

void listar_visiones_transmitidas(cuervo_aprendiz_t aprendiz, bool (*es_listable)(vision_t)){

      printf("\nvisiones transmitadas al cuervo:\n\n");

      for(int i=0;i<aprendiz.cantidad_visiones;i++){
          if(es_listable(aprendiz.visiones_adquiridas[i])){

              printf("%s, %s, %s, %c\n", (aprendiz.visiones_adquiridas[i]).protagonista,(aprendiz.visiones_adquiridas[i]).casa_protagonista,(aprendiz.visiones_adquiridas[i]).descripcion,(aprendiz.visiones_adquiridas[i]).epoca);
          }
      }
}

int destruir_cuervo(cuervo_tres_ojos_t* cuervo){

      if(cuervo==NULL){
          return ERROR;
      }if(cuervo->visiones_del_pasado!=NULL){
          free(cuervo->visiones_del_pasado);
      }if(cuervo->visiones_del_futuro!=NULL){
          free(cuervo->visiones_del_futuro);
      }
      free(cuervo);

      return EXITO;
}

int destruir_aprendiz(cuervo_aprendiz_t* aprendiz){
      if(aprendiz==NULL){
          return ERROR;
      }if(aprendiz->visiones_adquiridas!=NULL){
          free(aprendiz->visiones_adquiridas);
      }
      free(aprendiz);

      return EXITO;
}
