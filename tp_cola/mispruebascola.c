#include "cola.h"
#include "pruebas_cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PRUEBAS_TOTALES 23


int main(){
    srand((unsigned int)time(NULL));
    int pruebas_pasadas = 0;
    int pruebas_totales = PRUEBAS_TOTALES;
    printf("\nPruebas cuando la cola esta vacia:\n");

    pruebas_pasadas+=DadaUnaColaVacia_CuandoSeQuiereEncolar_EntoncesEncolarDevolveraCero();
    pruebas_pasadas+=DadaUnaCola_CuandoSeLaCrea_EntoncesLaPilaEstaVacia();
    pruebas_pasadas+=DadaUnaColaVacia_CuandoSeQuiereDesencolar_EntoncesDesencolarDevolveraMenosUno();
    pruebas_pasadas+=DadaUnaColaVacia_CuandoSeQuiereVerLaCantidad_EntoncesLaCantidadSeraCero();
    pruebas_pasadas+=DadaUnaColaVacia_CuandoSeQuiereVerElPrimerElemento_EntoncesDevolveraNull();

    printf("\nPruebas con parametros null:\n");

    pruebas_pasadas+=DadaUnaColaNull_CuandoSeQuiereEncolar_EntoncesDevolveraNull();
    pruebas_pasadas+=DadaUnaColaNull_CuandoSeQuiereDecencolar_EntoncesDevolveraNull();
    pruebas_pasadas+=DadaUnaColaNull_CuandoSeQuiereVerSiLaColaEstaVacia_EntoncesDevolveraTrue();
    pruebas_pasadas+=DadaUnaColaNull_CuandoSeQuiereVerLaCantidadDeElementos_EntoncesDevolveraCero();
    pruebas_pasadas+=DadaUnaColaNull_CuandoSeQuiereVerElPrimerElemento_EntoncesDevolveraNull();
    pruebas_pasadas+=DadaUnaColaNull_CuandoSeEncolaUnElementoNull_EntoncesDevolveraMenosUno();
    pruebas_pasadas+=DadaUnaColaDistintaDeNull_CuandoSeEncolaUnElementoNull_EntoncesDevolveraCero();
    pruebas_pasadas+=DadaUnaColaDistintaDeNull_CuandoSeDesencolaUnElementoNull_EntoncesDevolveraCero();

    printf("\nPrubeas con pocos elementos\n");

    pruebas_pasadas+=DadaUnaColaInicializada_CuandoSeEncolanYDesencoLaMismaCantidadDeElementos_EntoncesLaColaQuedaraVacia();
    pruebas_pasadas+=DadaUnaColaInicializa_CuandoSeEncolanElementos_EntoncesLaCantidadDeElementosEncoladaEsLaCorrecta();
    pruebas_pasadas+=DadaUnaColaInicializada_cuandoSeEncolaUnElemento_EntoncesElPrimerElementoSeraEse();
    pruebas_pasadas+=DadaUnaColaInicializada_CuandoSeEncolanMasElementosDeLosQueSeDesencolan_EntoncesLaColaNoEstaVacia();
    pruebas_pasadas+=DadaUnaColaInicializada_CuandoSeEncolanYDesencolanElementos_EntoncesDevolveraElElementoCorrecto();
    pruebas_pasadas+=DadaUnaColaInicializada_CuandoSeDesencolanElementos_EntoncesDeveraImprimirloCorrectamente();

    printf("\nPruebas con muchos elementos\n");
    pruebas_pasadas+=DadaUnaColaInicializada_CuandoEncoloMuchosElementos_EntoncesLaCantidadSeraLaCorrecta();
    pruebas_pasadas+=DadaUnaColaIniciliazada_CuandoEncoloYDesencoloMuchosElementos_EntoncesLaColaQuedaVacia();
    pruebas_pasadas+=DadaUnaColaInicializada_CuandoSeEncolaronYSesencolaronMuchosElementos_EntoncesLaColaNoEstaVacia();
    pruebas_pasadas+=DadaUnaColaInicializada_CuandoSeEncolanYDesencolanMuchosElementos_EntonceseElElementoPrimeroEsElCorrecto();

    printf("\npaso %i pruebas de %i\n", pruebas_pasadas, pruebas_totales);

}
