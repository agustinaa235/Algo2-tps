#include <stdio.h>
#include "cola.h"
#include <time.h>
#include <stdlib.h>
#define PASO 1
#define EXITO 0
#define NO_PASO 0
#define ERROR -1




int DadaUnaColaVacia_CuandoSeQuiereEncolar_EntoncesEncolarDevolveraCero(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int elemento_1 = 1;

      int estado_prueba = cola_encolar(cola, (void*)&elemento_1);
      if(estado_prueba==EXITO){
            printf("%s :PASO\n", __func__);
            resultado = PASO;
      }else{
            printf("%s :FALLO\n", __func__);
      }
      cola_desencolar(cola);
      cola_destruir(cola);
      return resultado;
}
int DadaUnaCola_CuandoSeLaCrea_EntoncesLaPilaEstaVacia(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    if(cola_vacia(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaVacia_CuandoSeQuiereDesencolar_EntoncesDesencolarDevolveraMenosUno(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int estado_prueba = cola_desencolar(cola);
    if(estado_prueba==ERROR){
      printf("%s :PASO\n", __func__);
      resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaVacia_CuandoSeQuiereVerLaCantidad_EntoncesLaCantidadSeraCero(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    if(cola_cantidad(cola)==EXITO){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaVacia_CuandoSeQuiereVerElPrimerElemento_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    if(cola_primero(cola)==NULL){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaNull_CuandoSeQuiereEncolar_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    cola_t* cola = NULL;

    char elemento_1 = 'a';
    if(cola_encolar(cola,(void*)&elemento_1)==ERROR){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    return resultado;
}

int DadaUnaColaNull_CuandoSeQuiereDecencolar_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    cola_t* cola = NULL;
    if(cola_desencolar(cola)==ERROR){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    return resultado;
}

int DadaUnaColaNull_CuandoSeQuiereVerSiLaColaEstaVacia_EntoncesDevolveraTrue(){

    int resultado = NO_PASO;
    cola_t* cola = NULL;
    if(cola_vacia(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    return resultado;
}

int DadaUnaColaNull_CuandoSeQuiereVerLaCantidadDeElementos_EntoncesDevolveraCero(){

    int resultado = NO_PASO;
    cola_t* cola = NULL;
    if(cola_cantidad(cola)==EXITO){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    return resultado;
}

int DadaUnaColaNull_CuandoSeQuiereVerElPrimerElemento_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    cola_t* cola = NULL;
    if(cola_primero(cola)==NULL){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    return resultado;
}

int DadaUnaColaNull_CuandoSeEncolaUnElementoNull_EntoncesDevolveraMenosUno(){

    int resultado = NO_PASO;
    cola_t*cola = NULL;

    void* elemento = NULL;
    if(cola_encolar(cola, (void*)&elemento)==ERROR){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    return resultado;
}

int DadaUnaColaDistintaDeNull_CuandoSeEncolaUnElementoNull_EntoncesDevolveraCero(){

    int resultado = NO_PASO;
    cola_t*cola = cola_crear();
    if(!cola){
        return resultado;
    }
    void* elemento = NULL;
    if(cola_encolar(cola, (void*)&elemento)==EXITO){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaDistintaDeNull_CuandoSeDesencolaUnElementoNull_EntoncesDevolveraCero(){

    int resultado = NO_PASO;
    cola_t*cola = cola_crear();
    if(!cola){
        return resultado;
    }
    void* elemento = NULL;
    cola_encolar(cola, (void*)&elemento);
    if(cola_desencolar(cola)==EXITO){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}


int DadaUnaColaInicializada_CuandoSeEncolanYDesencoLaMismaCantidadDeElementos_EntoncesLaColaQuedaraVacia(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;
    int elemento_4 = 4;
    int elemento_5 = 5;
    int elemento_6 = 6;

    cola_encolar(cola, (void*)&elemento_1);
    cola_encolar(cola, (void*)&elemento_2);
    cola_encolar(cola, (void*)&elemento_3);
    cola_encolar(cola, (void*)&elemento_4);
    cola_encolar(cola, (void*)&elemento_5);
    cola_encolar(cola, (void*)&elemento_6);

    for(int i=0; i<6; i++){
        cola_desencolar(cola);
    }
    if(cola_vacia(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializa_CuandoSeEncolanElementos_EntoncesLaCantidadDeElementosEncoladaEsLaCorrecta(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int elemento_1 = 1;
    int cantidad_total_elementos=0;
    for(int i=0; i<3;i++){
        cola_encolar(cola, (void*)&elemento_1);
        cantidad_total_elementos++;
    }
    if(cola_cantidad(cola)==cantidad_total_elementos){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializada_cuandoSeEncolaUnElemento_EntoncesElPrimerElementoSeraEse(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    char elemento_1 = 'A';
    cola_encolar(cola, (void*)&elemento_1);
    if(cola_primero(cola)==(&elemento_1)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_desencolar(cola);
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializada_CuandoSeEncolanMasElementosDeLosQueSeDesencolan_EntoncesLaColaNoEstaVacia(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    char elemento_1 = 'A';
    char elemento_2 = 'B';
    char elemento_3 = 'C';
    for(int i=0; i<3; i++){
      cola_encolar(cola, (void*)&elemento_1);
      cola_encolar(cola, (void*)&elemento_2);
      cola_encolar(cola, (void*)&elemento_3);
    }
    for(int i=0; i<6; i++){
        cola_desencolar(cola);
    }
    if(!cola_vacia(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializada_CuandoSeEncolanYDesencolanElementos_EntoncesDevolveraElElementoCorrecto(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int elemento_1 = 1;
    int elemento_2 = 2;
    int elemento_3 = 3;

    for(int i=0; i<3; i++){
        cola_encolar(cola, (void*)&elemento_1);
        cola_encolar(cola, (void*)&elemento_2);
        cola_encolar(cola, (void*)&elemento_3);
    }
    for(int i=0; i<6; i++){
        cola_desencolar(cola);
    }
    if(cola_primero(cola)== (&elemento_1)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializada_CuandoSeDesencolanElementos_EntoncesDeveraImprimirloCorrectamente(){

    int resultado =  NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    char elemento_1 = 'A';
    char elemento_2 = 'G';
    char elemento_3 = 'U';
    char elemento_4 = 'S';
    char elemento_5 = 'T';
    char elemento_6 = 'I';
    char elemento_7 = 'N';
    char elemento_8 = 'A';

    cola_encolar(cola, (void*)&elemento_1);
    cola_encolar(cola, (void*)&elemento_2);
    cola_encolar(cola, (void*)&elemento_3);
    cola_encolar(cola, (void*)&elemento_4);
    cola_encolar(cola, (void*)&elemento_5);
    cola_encolar(cola, (void*)&elemento_6);
    cola_encolar(cola, (void*)&elemento_7);
    cola_encolar(cola, (void*)&elemento_8);

    for(int i=0;i<8;i++){
        printf("%c", *(char*)cola_primero(cola));
        cola_desencolar(cola);
    }
    if(cola_vacia(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializada_CuandoEncoloMuchosElementos_EntoncesLaCantidadSeraLaCorrecta(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    char elemento_1 = 'A';
    char elemento_2 = 'L';
    char elemento_3 = 'G';
    char elemento_4 = 'O';
    int elemento_5 = 2;
    int cantidad_total_elementos = 200;
    for(int i=0; i<40; i++){
        cola_encolar(cola, (void*)&elemento_1);
        cola_encolar(cola, (void*)&elemento_2);
        cola_encolar(cola, (void*)&elemento_3);
        cola_encolar(cola, (void*)&elemento_4);
        cola_encolar(cola, (void*)&elemento_5);

    }
    if(cantidad_total_elementos== cola_cantidad(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaIniciliazada_CuandoEncoloYDesencoloMuchosElementos_EntoncesLaColaQuedaVacia(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int elemento = rand()%50;
    for(int i=0; i<600; i++){
        cola_encolar(cola, (void*)&elemento);
    }
    for(int i=0; i<600; i++){
        cola_desencolar(cola);
    }
    if(cola_vacia(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
      }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializada_CuandoSeEncolaronYSesencolaronMuchosElementos_EntoncesLaColaNoEstaVacia(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int elemento = rand() % 50;
    for(int i=0; i<450; i++){
        cola_encolar(cola, (void*)&elemento);
    }
    for(int i=0; i<350; i++){
        cola_desencolar(cola);
    }
    if(!cola_vacia(cola)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}

int DadaUnaColaInicializada_CuandoSeEncolanYDesencolanMuchosElementos_EntonceseElElementoPrimeroEsElCorrecto(){

    int resultado = NO_PASO;
    cola_t* cola = cola_crear();
    if(!cola){
        return resultado;
    }
    int elemento_1 = 0;
    int elemento_2 = 1;
    int elemento_3 = 2;
    int elemento_4 = 3;


    for(int i=0; i<50; i++){
        cola_encolar(cola, (void*)&elemento_1);
        cola_encolar(cola, (void*)&elemento_2);
        cola_encolar(cola, (void*)&elemento_3);
        cola_encolar(cola, (void*)&elemento_4);

    }

    for(int i=0; i<100; i++){
        cola_desencolar(cola);
    }

    if(cola_primero(cola)==(&elemento_1)){
        printf("%s :PASO\n", __func__);
        resultado = PASO;
    }else{
        printf("%s :FALLO\n", __func__);
    }
    cola_destruir(cola);
    return resultado;
}
