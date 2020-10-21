#include "pruebas_abb.h"
#include <stdio.h>
#define PRUEBAS_TOTALES 40




int main(){

    int pruebas_pasadas=0;
    int pruebas_totales = PRUEBAS_TOTALES;

    printf("\nPruebas cuando el arbol esta vacio\n\n");

    pruebas_pasadas+= DadoUnArbolVacio_CuandoSeQuiereInsertarUnElemento_EntoncesDevolveraExito();
    pruebas_pasadas+= DadoUnArbolVacio_CuandoSeQuiereBorrarUnElemento_EntoncesDevolveraError();
    pruebas_pasadas+= DadoUnArbolVacio_CuandoSeQuiereBuscarUnElemento_EntoncesDevolveraNull();
    pruebas_pasadas+= DadoUnArbolVacio_CuandoSequiereVerSiEstaVacio_EntoncesDevolveraTrue();
    pruebas_pasadas+= DadoUnArbolVacio_CuandoSequiereVerElNodoRaiz_EntoncesDevolveraNull();
    pruebas_pasadas+= DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecInorder_EntoncesDevolveraCero();
    pruebas_pasadas+= DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecPreorden_EntoncesDevolveraCero();
    pruebas_pasadas+= DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecPostorder_EntoncesDevolveraCero();

    printf("\nPruebas cuando el arbol es null\n\n");

    pruebas_pasadas+= DadoUnArbolNull_CuandoSeQuiereInsertarUnElemento_EntoncesDevolveraError();
    pruebas_pasadas+= DadoUnArbolNull_CuandoSeQuiereBorrarUnElemento_Entonces_DevolveraError();
    pruebas_pasadas+= DadoUnArbolNull_CuandoSeQuiereVerElNodoRaiz_EntoncesDevolveraNull();
    pruebas_pasadas+= DadoUnArbolNull_CuandoSeQuiereVerSiEstaVacio_EntoncesDevolveraTrue();
    pruebas_pasadas+= DadoUnArbolNull_CuandoSeQuiereBuscarUnElemento_EntoncesDevolveraNull();
    pruebas_pasadas+= DadoUnArbolNull_CuandoSeLoRecorreInorden_EntoncesDevolveraCero();
    pruebas_pasadas+= DadoUnArbolNull_CuandoSeLoRecorrePreorden_EntoncesDevolveraCero();
    pruebas_pasadas+= DadoUnArbolNull_CuandoSeLoRecorrePostOrden_EntoncesDevolveraCero();

    printf("\nPruebas con pocos elementos\n\n");

    pruebas_pasadas+= DadoUnArbol_CuandoSeInsertanYBorranElementos_EntoncesElArbolNoEstaVacio();
    pruebas_pasadas+= DadoUnArbol_CuandoSeInsertanYBorranElementos_EntoncesElArbolEstaVacio();
    pruebas_pasadas+= DadoUnArbol_CuandoSeBuscaUnElemento_EntoncesElElementoBuscadoSeraElCorrecto();
    pruebas_pasadas+= DadoUnArbol_CuandoInsertoUnelemento_EntoncesEselementoEslaRaiz();
    pruebas_pasadas+= DadoUnArbol_CuandoSeBorraUnElemento_EntoncesEsteNoEstaraEnElarbol();
    pruebas_pasadas+= DadoUnArbol_CuandoSequiereVerQueEliminoUnNodoEnLosTresCasos_EntoncesDevolveraExito();
    pruebas_pasadas+= DadoUnArbol_CuandoSeQuiereBuscarUnElementoQueNoEsta_EntoncesDeolveraNull();
    pruebas_pasadas+= DadoUnArbol_CuandoLemandoUnComparadorNull_EntoncesCrearDevuelveNull();

    printf("\nPruebas con iterador o reccorridos\n");

    pruebas_pasadas+= DadoUnArbol_CuandoSeLoRecorreInorden_EntoncesImprimiraPorPantallaLoCorrecto();
    pruebas_pasadas+= DadoUnArbol_CuandoSeLoRecorrePostorden_EntoncesImprimiraPorPantallaLoCorrecto();
    pruebas_pasadas+= DadoUnArbol_CuandoSeLoRecorrePreorden_EntoncesImprimiraPorPantallaLoCorrecto();
    pruebas_pasadas+= DadoUnArbolConRecorridoPreorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta();
    pruebas_pasadas+= DadoUnArbolConRecorridoInorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta();
    pruebas_pasadas+= DadoUnArbolConRecorridoPostorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta();
    pruebas_pasadas+= DadoUnArbolConRecorridoInorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero();
    pruebas_pasadas+= DadoUnArbolConRecorridoPreorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero();
    pruebas_pasadas+= DadoUnArbolConRecorridoPostorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero();
    pruebas_pasadas+= DadoUnArbol_CuandoLoRecorroInOrdenConIteradorInterno_EntoncesImprimiraLoCorrecto();
    pruebas_pasadas+= DadoUnArbol_CuandoLoRecorroPreordenConIteradorInterno_EntoncesImprimiraLoCorrecto();
    pruebas_pasadas+= DadoUnArbol_CuandoLoRecorroPostordenConIteradorInterno_EntoncesImprimiraLoCorrecto();



    printf("\nPruebas de implementacion\n\n");
    pruebas_pasadas+= DadoUnArbol_CuandoBorroLaRaiz_EntoncesElNuevoNodoRaizSeraElCorrecto();
    pruebas_pasadas+= DadoUnArbol_CuandoInsertoUnElementoMasGrandeQueLaRaiz_EntoncesIraAlSubArbolDerecho();
    pruebas_pasadas+= DadoUnArbol_CuandoInsertoUnElementoMasChicoQueLaRaiz_EntoncesIraAlSubArbolizquierdo();
    pruebas_pasadas+= DadoUnArbol_CuandoInsertoUnElementoIgualALaRaiz_EntoncesIraAlSubArbolDerecho();


  printf("Pasaste %i de %i pruebas\n", pruebas_pasadas, pruebas_totales);
}
