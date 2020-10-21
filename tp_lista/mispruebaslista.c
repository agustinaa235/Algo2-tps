#include "pruebas_listas.h"
#include "lista.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define PRUEBAS_TOTALES 38



int main(){

    srand((unsigned int)time(NULL));
    int pruebas_pasadas=0;
    int pruebas_totales = PRUEBAS_TOTALES;


    printf("\nprueba buscar elemento\n");
    lista_t* lista = lista_crear();

    int a=1, b=2, c=3, d=4, e=5;
    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    lista_insertar(lista, &d);
    lista_insertar(lista, &e);

    printf("%i\n", *(int*)lista_buscar_elemento(lista, &c));
    lista_destruir(lista);


    printf("\nPruebas cuando la lista esta vacia\n");

    pruebas_pasadas+= DadaUnaListaVacia_CuandoSeQuiereEnlistar_EntoncesDevolveraExito();
    pruebas_pasadas+= DadaUnaListaVacia_CuandoQuieroBorrar_EntoncesDevuelveError();
    pruebas_pasadas+= DadaUnaListaVacia_CuandoQuieroInsertarEnUnaPosicion_EntoncesDevolveraExito();
    pruebas_pasadas+= DadaUnaListaVacia_CuandoQuieroEliminarEnUnaPosicion_EntoncesDevolveraError();
    pruebas_pasadas+= DadaUnaListaVacia_CuandoQuieroVerElUltimoElemento_EntoncesDevolveraNull();
    pruebas_pasadas+= DadaUnaListaVacia_CuandoQuieroVerElElementoEnUnaPosicion_EntoncesDevolveraNull();
    pruebas_pasadas+= DadaUnaListaVacia_CuandoQuieroVerLaCantidadDeElementos_EntoncesLaCantidadSeraCero();
    pruebas_pasadas+= DadaUnaLista_CuandoSeLaCrea_EntoncesEstaraVacia();

    printf("\nPruebas con parametros Null\n");

     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereBorrar_EntoncesDevolveraError();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereInsertarEnUnaPosicion_EntoncesDevolveraError();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereBorrar_EntoncesDevolveraError();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereBorrarEnUnaPosicion_EntoncesDevolveraError();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereVerElUltimoElemento_EntoncesDevolveraNull();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereVerElElemenoEnUnaPosicion_EntoncesDevolveraNull();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereVerSiEstaVacia_EntoncesDevolveraTrue();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSequiereVerLaCantidadDeElementos_EntoncesEstaSeraCero();

     printf("\nPruebas con pocos elementos\n");

     pruebas_pasadas+= DadaUnalistaInicializada_CuandoSeInsertaYSeBorranElementosAlfinal_EntoncesLaListaQuedaraVacia();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoSeInsertaMasElementosDeLosQueSeBorranAlFinal_EntoncesLaListaNoQuedaraVacia();
     pruebas_pasadas+= DadadUnaListaInicializada_CuandoSeInsertanYSeEliminanElementosEnDistintasPosiciones_EntoncesLaListaQuedaVacia();
     pruebas_pasadas+= DadadUnaListaInicializada_CuandoSeInsertanMasElementosDeLosQueSeEliminanEnDistintasPosiciones_EntoncesLaListaNoQuedaVacia();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoSeInsertanElementos_EntoncesLaCantidadEsLaCorrecta();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoSeInsertanYseEliminanElementosEnDsitintasPosiciones_EntoncesImprimiraPorPantallaLoCorrecto();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoSeInsertaUnelemento_EntoncesElElementoUltimoSeraEse();

     printf("\nPruebas con muchos elementos\n");

     pruebas_pasadas+= DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaListaQuedaraVacia();
     pruebas_pasadas+= DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaListaNoQuedaraVacia();
     pruebas_pasadas+= DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaCantidadSeraLaCorrecta();
     pruebas_pasadas+= DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementos_Entonceselultimoelementoseraelcorrecto();
     pruebas_pasadas+= DadaUnaListaInicizalizada_CuandoSeInsertaUnElementoEnUnaDeterminaPosicion_ElElementoInsertadoSeraEse();

     printf("\nPrueba con iteradores\n");

     printf("\n Externo:\n");
     pruebas_pasadas+= DadaUnaLista_CuandoSequiereRecorrerLaListaUltilizandoUniteradorExterno_EntoncesImprimiraPorpantallaLoCorrecto();
     pruebas_pasadas+= DadaUnaLista_CuandoSeQuiereRecorrerUnaListaConUnElmentoUtilizandoIteradorExterno_EntoncesNotendraUnSiguiente();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoEstoyEnElPrimerElementoDeLaLista_EntoncesTieneSiguenteDevolverTrue();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoEstoyEnLaUltimaPosicionDeLaLista_EntoncesTieneSiguienteDevolveraFalse();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoSeLaQuiereRecorrerUltilizandoIteradorExternoNull_EntoncesTieneSiguienteDevolveraFalse();
     pruebas_pasadas+= DadaUnaListaInicializada_CuandoSeLaQuiereRecorrerUltilizandoIteradorExternoNull_EntoncesListaIteradorSiguienteDevolveraNull();
     pruebas_pasadas+= DadaUnaLista_CuandoSeTieneUnIteradorNull_EntoncesIteradorSiguienteDevolveraNull();
     pruebas_pasadas+= DadaUnaLista_CuandoSeTieneUnIteradorNull_EntoncesIteradorTieneSiguienteDevolveraFalse();
     pruebas_pasadas+= DadaUnaListaNull_CuandoSeQuiereCrearUnIteradorExterno_EntoncesIteradorCrearDevolveraNull();

     printf("\n Interno:\n");
     pruebas_pasadas+= DadaUnaLista_CuandoSequiereRecorrerLaListaUltilizandoUniteradorInterno_EntoncesImprimiraPorpantallaLoCorrecto();
     printf("Pasaste %i de %i pruebas\n", pruebas_pasadas, pruebas_totales);
}
