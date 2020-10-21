#include "pila.h"
#include "pruebas.h"
#include <stdio.h>
#define EXITO 0
#define ERROR -1
#define RESULTADO_CORRECTO 1
#define MINIMO_TAM 2
#define CANTIDAD_DE_PRUEBAS 11
#define RESULTADO_INICIAL 0


int dadaunapilavacia_cuandosequieredesapilar_entoncesdevolveramenosuno(){

  printf("\nprubea 1\n");
  int resultado=RESULTADO_INICIAL;
  pila_t* pila=pila_crear();
  if(!pila){
      return resultado;
  }
  if(pila_desapilar(pila)==ERROR){
      resultado=RESULTADO_CORRECTO;
      printf("En una pila vacia, cuando se desea apilar entonces devolvera-1: PASO\n");
  }else{
      printf("En una pila vacia, cuando se desea apilar entonces devolvera-1: FALLO\n");
  }
  pila_destruir(pila);
  return resultado;

}
int dadaunapilavacia_cuandosequiereverelelementodeltope_entonesdevolveranull(){

    printf("\nprueba 2\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=pila_crear();
    if(!pila){
        return resultado;
    }
    if(pila_tope(pila)==NULL){
        resultado=RESULTADO_CORRECTO;
        printf("En una pila vacia el tope devuelve null:PASO\n");
    }else{
        printf("En una pila vacia el tope devuelve null:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}

int dadaunapilanull_cuandosequiereapilar_entoncesdevolveramenosuno(){

    printf("\nprueba 3\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=NULL;
    int elemento_1= 1;

    if(pila_apilar(pila,&elemento_1)==ERROR){
        printf("En una pila null, cuando se quiera apilar, devuelve -1: PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("En una pila null, cuando se quiera apilar, devuelve -1: FALLO\n");
    }

    return resultado;
}
int dadaunapilanull_cuandosequieredesapilar_entoncesdevolveramenosuno(){

    printf("\nprueba 4\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=NULL;

    if(pila_desapilar(pila)==ERROR){
        printf("En una pila null,cuando se quiere desapilar, deuelve -1:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("En una pila null,cuando se quiere desapilar, deuelve -1:FALLO\n");
    }

    return resultado;
}

int dadaunapilayainicializada_cuandosequiereapilarydesapilarlamismacantidaddeelelementos_entonceslapilaquedaravacia(){

    printf("\nPrueba 5\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=pila_crear();
    if(!pila){
        return resultado;
    }
    char elemento_1 = 'a';
	  char elemento_2 = 'n';
	  char elemento_3 = 'i';
	  char elemento_4 = 't';
	  char elemento_5 = 's';
    char elemento_6 = 'u';
    char elemento_7 = 'g';
    char elemento_8 = 'a';
    printf("tamanio de mi pila inicialmente: %i\n", pila->tamanio);
    printf("cantidad de elementos inicialmente: %i\n", pila_cantidad(pila));

    printf("apilo\n");
		pila_apilar(pila, &elemento_1);
		pila_apilar(pila, &elemento_2);
		pila_apilar(pila, &elemento_3);
		pila_apilar(pila, &elemento_4);
		pila_apilar(pila, &elemento_5);
    pila_apilar(pila, &elemento_6);
    pila_apilar(pila, &elemento_7);
    pila_apilar(pila, &elemento_8);

    printf("desapilo\n");
    for (int i = 0; i < 8; i++) {
        pila_desapilar(pila);

    }
    printf("cantidad de elementos final: %i\n", pila_cantidad(pila));
    printf("Tamanio pila final: %i\n", pila->tamanio);
    if(pila_vacia(pila)){
        printf("En una pila cuando se apilan y desapilan la misma cantida de elementos la pila queda vacia:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("En una pila cuando se apilan y desapilan la misma cantida de elementos la pila queda vacia:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}

int dadaunapila_cuandoseapilaunnumerograndedeelementos_entoncesveoqueapiletodos(){

    printf("\nprueba 6\n");
    int resultado=RESULTADO_INICIAL;
    int cantidad_de_elementos=25;
    pila_t* pila= pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;
    int elemento_4 = 4;
    int elemento_5 = 5;
    for(int i=0;i<5;i++){
        pila_apilar(pila, &elemento_1);
        pila_apilar(pila, &elemento_2);
        pila_apilar(pila, &elemento_3);
        pila_apilar(pila, &elemento_4);
        pila_apilar(pila, &elemento_5);

    }
    printf("\ncantidad de elementos %i\n", pila_cantidad(pila));
    if(pila_cantidad(pila)==cantidad_de_elementos){
        printf("La cantidad de elementos es la correcta:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("La cantidad de elementos es la correcta:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}

int dadaunapila_cuandosequiereverqueredimencione_entoncesseagrandaraoachicaraelvector(){

    printf("prueba 7");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila= pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;
    printf("\napile:\n");
    for(int i=0;i<40;i++){
        pila_apilar(pila, &elemento_1);
        pila_apilar(pila, &elemento_2);
        pila_apilar(pila, &elemento_3);
        printf("tamanio de mi pila: %i\n", pila->tamanio);
    }
    printf("tamanio de mi pila: %i", pila->tamanio);
    printf("\ndesapila\n");
    for (int i = 0; i <100 ; i++) {

        printf("tamanio de mi pila: %i\n", pila->tamanio);
        pila_desapilar(pila);
      }
    if(pila->tamanio> MINIMO_TAM){
        printf("La pila se redimenciona:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("La pila se redimenciona:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}
int dadaunapilaconelementos_cuandosequiereverquedesapilecorrectamente_entoncesimprimiraloselementosalrevez(){

    printf("\nprueba 8\n");
    int resultado=RESULTADO_INICIAL;
    char elemento_1= '2';
    char elemento_2= 'o';
    char elemento_3= 'g';
    char elemento_4= 'l';
    char elemento_5= 'a';

    pila_t* pila= pila_crear();
    if(!pila){
        return resultado;
    }
    pila_apilar(pila, &elemento_1);
    pila_apilar(pila, &elemento_2);
    pila_apilar(pila, &elemento_3);
    pila_apilar(pila, &elemento_4);
    pila_apilar(pila, &elemento_5);

    for(int i=0;i<5;i++){
        printf("%c\n", *(char*)pila_tope(pila));
        pila_desapilar(pila);
    }
    if(pila_vacia(pila)){
        printf("Se imprime los elementos correspondientes:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("Se imprime los elementos correspondientes:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}
int dadaunapilainicializada_cuandoapilomaselementosdelosquedesapilo_entonceslacantidaddeelementosesmayorquecero(){

    printf("\nprueba 9\n");
    int resultado = RESULTADO_INICIAL;
    pila_t* pila = pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;
    for(int i=0;i<3;i++){
        printf("apilo\n");
        pila_apilar(pila, &elemento_1);
        pila_apilar(pila, &elemento_2);
        pila_apilar(pila, &elemento_3);
    }

    for (int i = 0; i <6; i++) {
        printf("desapilo\n");
        pila_desapilar(pila);
    }
    printf("¿La pila está vacía?: %s\n", pila_vacia(pila)?"SI":"NO");
    printf("el elemento de mi tope es: %i\n", *(int*)pila_tope(pila));
    printf("cantidad de elementos en la pila: %i\n", pila_cantidad(pila));
    if(!pila_vacia(pila) && pila_cantidad(pila)!=0){
        printf("La cantidad de elementos es mayor que 0:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("La cantidad de elementos es mayor que 0:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}
int dadaunapilanull_cuandosequieresabersiestavacia_entoncesdaratrue(){

    printf("\nprueba 10\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=NULL;
    if(pila_vacia(pila)){
        printf("En una pila null, la pila esta vacia:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("En una pila null, la pila esta vacia:FALLO\n");
    }
    return resultado;
}

int dadaunapilainicializada_cuandosequiereagregarunelemento_entonceseltopeeselelementoapilado(){

    printf("\nprueba 11\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila= pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento= 8;
    pila_apilar(pila,&elemento);
    printf("el elemento del tope es:%i\n", *(int*)pila_tope(pila));
    if(elemento== *(int*)pila_tope(pila)){
        printf("El tope es el correcto:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("El tope es el correcto:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}

int dadaunapila_cuandoselaquierecrear_entoncesdeberacumplirconlascondicionesiniciales(){

    printf("\nprueba 12\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=pila_crear();
    if(!pila){
        return resultado;
    }
    if(pila_vacia(pila) && pila->tamanio==MINIMO_TAM){
        printf("Se crea una pila lista para poder apilar:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("Se crea una pila lista para poder apilar:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}

int dadaunapilainicializada_cuandosequiereapilarydesapilarelementosnull_entoncesdevolveraexito(){

    printf("\nprueba 13\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=pila_crear();
    if(!pila){
        return resultado;
    }
    void* elemento=NULL;
    for(int i=0;i<5;i++){
        pila_apilar(pila, elemento);
    }
    for(int i=0;i<5;i++){
        pila_desapilar(pila);
    }
    if(pila_vacia(pila)){
        printf("apilaste y desapilaste elementos null:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("apilaste y desapilaste elementos null:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}

int dadaunapilainicializada_cuandosedeseadesapilar3elementos_entoncesdevolveraeltopeadecuado(){
    printf("\nprueba 14\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;
    int elemento_4 = 4;
    int elemento_5 = 5;
    int elemento_6 = 6;
    int elemento_7 = 7;

    pila_apilar(pila, &elemento_1);
		pila_apilar(pila, &elemento_2);
		pila_apilar(pila, &elemento_3);
		pila_apilar(pila, &elemento_4);
		pila_apilar(pila, &elemento_5);
    pila_apilar(pila, &elemento_6);
    pila_apilar(pila, &elemento_7);
    for(int i =0;i<3;i++){
        pila_desapilar(pila);
    }
    if(*(int*)pila_tope(pila)==elemento_4){
        printf("El tope es el correcto:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("El tope es el correcto:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}
int dadaunapilanull_cuandonosequiereverlacantidaddeelmentos_entoncesdevolveracero(){

    printf("\nprueba 15\n");
    int resultado=RESULTADO_INICIAL;
    pila_t* pila=NULL;
    if(pila_cantidad(pila)==EXITO){
      printf("En una pila null, la cantidad de elementos es 0:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("En una pila null, la cantidad de elementos es 0:FALLO\n");
    }
    return resultado;
}
int dadaunapilainicializada_cuandoapilanelementos_entonceseltopedeveserdistintodenull(){

    printf("\nprueba 16\n");
    int resultado = RESULTADO_INICIAL;
    pila_t* pila = pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;

    for(int i=0;i<3;i++){
        pila_apilar(pila, &elemento_1);
        pila_apilar(pila, &elemento_2);
        pila_apilar(pila, &elemento_3);
    }
    pila_desapilar(pila);
    pila_desapilar(pila);
    if(pila_tope(pila)!=NULL){
        printf("El tope no es null:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("El tope no es null:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}

int dadaunapilainicializada_cuandosedesapilaelultimoelemento_entoncespilatopedevuleveelelemetocorrespondiente(){

    printf("\nprueba 17\n");
    int resultado = RESULTADO_INICIAL;
    pila_t* pila = pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;

    for(int i=0;i<3;i++){
        pila_apilar(pila, &elemento_1);
        pila_apilar(pila, &elemento_2);
        pila_apilar(pila, &elemento_3);
    }
    pila_desapilar(pila);
    if(pila_tope(pila)== &elemento_2){
        printf("Si se desapila el ultimo elemento, el tope es el correcto:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("Si se desapila el ultimo elemento, el tope es el correcto:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}
int dadaunapilainilizalizada_cuandoseapilanmaselementosdelosquesedesapilan_entonceslapilanoestaravacia(){
    printf("\nprueba 18\n");
    int resultado = RESULTADO_INICIAL;
    pila_t* pila = pila_crear();
    if(!pila){
        return resultado;
    }
    int elemento_1 = 1;
    for(int i=0;i<25;i++){
        pila_apilar(pila, &elemento_1);
    }
    for(int i=0;i<20;i++){
        pila_desapilar(pila);
    }
    if(!pila_vacia(pila)){
        printf("La pila no esta vacia:PASO\n");
        resultado=RESULTADO_CORRECTO;
    }else{
        printf("La pila no esta vacia:FALLO\n");
    }
    pila_destruir(pila);
    return resultado;
}
