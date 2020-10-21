#include "pila.h"
#include "pruebas.h"
#include <stdio.h>
#define EXITO 0
#define ERROR -1
#define RESULTADO_CORRECTO 1
#define MINIMO_TAM 2
#define CANTIDAD_DE_PRUEBAS 18



int main(){

  int pruebas_pasadas=0;
  int pruebas_totales=CANTIDAD_DE_PRUEBAS;

    pruebas_pasadas+=dadaunapilavacia_cuandosequieredesapilar_entoncesdevolveramenosuno();
    pruebas_pasadas+=dadaunapilavacia_cuandosequiereverelelementodeltope_entonesdevolveranull();
    pruebas_pasadas+=dadaunapilanull_cuandosequiereapilar_entoncesdevolveramenosuno();
    pruebas_pasadas+=dadaunapilanull_cuandosequieredesapilar_entoncesdevolveramenosuno();
    pruebas_pasadas+=dadaunapilayainicializada_cuandosequiereapilarydesapilarlamismacantidaddeelelementos_entonceslapilaquedaravacia();
    pruebas_pasadas+=dadaunapila_cuandoseapilaunnumerograndedeelementos_entoncesveoqueapiletodos();
    pruebas_pasadas+=dadaunapila_cuandosequiereverqueredimencione_entoncesseagrandaraoachicaraelvector();
    pruebas_pasadas+=dadaunapilaconelementos_cuandosequiereverquedesapilecorrectamente_entoncesimprimiraloselementosalrevez();
    pruebas_pasadas+=dadaunapilainicializada_cuandoapilomaselementosdelosquedesapilo_entonceslacantidaddeelementosesmayorquecero();
    pruebas_pasadas+=dadaunapilanull_cuandosequieresabersiestavacia_entoncesdaratrue();
    pruebas_pasadas+=dadaunapilainicializada_cuandosequiereagregarunelemento_entonceseltopeeselelementoapilado();
    pruebas_pasadas+=dadaunapila_cuandoselaquierecrear_entoncesdeberacumplirconlascondicionesiniciales();
    pruebas_pasadas+=dadaunapilainicializada_cuandosequiereapilarydesapilarelementosnull_entoncesdevolveraexito();
    pruebas_pasadas+=dadaunapilainicializada_cuandosedeseadesapilar3elementos_entoncesdevolveraeltopeadecuado();
    pruebas_pasadas+=dadaunapilanull_cuandonosequiereverlacantidaddeelmentos_entoncesdevolveracero();
    pruebas_pasadas+=dadaunapilainicializada_cuandoapilanelementos_entonceseltopedeveserdistintodenull();
    pruebas_pasadas+=dadaunapilainicializada_cuandosedesapilaelultimoelemento_entoncespilatopedevuleveelelemetocorrespondiente();
    pruebas_pasadas+=dadaunapilainilizalizada_cuandoseapilanmaselementosdelosquesedesapilan_entonceslapilanoestaravacia();

    printf("pasaste %i de %i pruebas \n", pruebas_pasadas, pruebas_totales);

}
