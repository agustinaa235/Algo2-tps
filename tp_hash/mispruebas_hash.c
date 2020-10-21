#include "pruebas_hash.h"
#include <stdio.h>

#define PRUEBAS_TOTALES 28


int main(){

    int pruebas_pasadas=0;
    int pruebas_totales = PRUEBAS_TOTALES;

    printf("\n Pruebas Con Parametros Null\n");

    pruebas_pasadas+= DadoUnhashNull_CuandoSeQuiereInsertar_EntoncesDevolveraError();
    pruebas_pasadas+= DadoUnHashNull_CuandoSeQuiereBorrar_EntoncesDevolveraError();
    pruebas_pasadas+= DadoUnHashNull_CuandoSeQuiereObtenerUnElemento_EntoncesDevolveraNull();
    pruebas_pasadas+= DadoUnHashNull_CuandoSeQuiereVerSiEstaUnElemento_EntoncesHashContieneDevolveraFalse();
    pruebas_pasadas+= DadoUnHashNull_CuandoSeQuiereVerLaCantidad_EntoncesLaCantidadSeraCero();
    pruebas_pasadas+= DadoUnHash_CuandoSeQuiereInsertarUnElementoConClaveNull_EntoncesDevolveraError();
    pruebas_pasadas+= DadoUnHash_CuandoSeQuiereInsertarUnElementoNullConClaveDistintaANull_EntoncesDevolveraExito();

    printf("\n Pruebas con hash vacio\n");

    pruebas_pasadas+= DadoUnHashVacio_CuandoSeQuiereInsertar_EntoncesDevolveraExito();
    pruebas_pasadas+= DadoUnHashVacio_CuandoSeQuiereBorrar_EntoncesDevolveraError();
    pruebas_pasadas+= DadoUnHashVacio_CuandoSeQuiereObtenerUnElemento_EntoncesDevolveraNull();
    pruebas_pasadas+= DadoUnHashVacio_CuandoSeQuiereVerLaCantidad_EntoncesEstaSeraCero();
    pruebas_pasadas+= DadoUnHashVacio_CuandoSeQuiereVerSiUnElementoEsta_EntoncesDevolveraFalse();

    printf("\n Pruebas con pocos Elementos\n");

    pruebas_pasadas+= DadoUnHash_CuandoSeQuiereInsertarpocosElementos_EntoncesLosInsertaraAtodosCorrectamente();
    pruebas_pasadas+= DadoUnHash_CuandoSeQuiereBuscarUnElementoYaInsertado_EntoncesHashContienDevolveraTrue();
    pruebas_pasadas+= DadoUnhash_CuandoSeQuiereBuscarUnElementoYaInsertado_EntoncesHashObtenerDevolveraEseElemento();
    pruebas_pasadas+= DadoUnHash_CuandoInsertoPocosElementos_EntoncesLaCantidadSeraLaCorrecta();
    pruebas_pasadas+= DadoUnHash_CuandoBuscoUnElementoQueNoEsta_EntoncesContieneDevolveraFalse();
    pruebas_pasadas+= DadoUnHash_CuandoBuscoUnElementoQueNoEsta_EntoncesHashObtenerDevolveraNull();
    pruebas_pasadas+= DadoUnHash_CuandoInsertoUnElementoYLuegoLoBorro_EntoncesHashContieneDevolveraFalse();
    pruebas_pasadas+= DadoUnHash_CuandoInsertoUnElementoYLuegoLoBorro_EntoncesHashObtenerDevolveraNull();
    pruebas_pasadas+= DadoUnHash_CuandoIntertoyBorroLaMismaCantidadDeElementos_EntoncesLaCantidadFinalSeraCero();
    pruebas_pasadas+= DadoUnHash_CuandoInsertoDosElementosConLaMismaClave_EntoncesElElementoSeModificaraPorElSegundo();

    printf("\n Pruebas con el iterador externo\n");

    pruebas_pasadas+= DadoUnHashNull_CuandoSeLoQuiereRecorerConUnIteradorExterno_EntoncesCrearDevolveraNull();
    pruebas_pasadas+= DadoUnHash_CuandoSeLoQuiereRecorrerConUnIteradorExternoNull_EntocesHashTieneSigueinteDevolveraFalse();
    pruebas_pasadas+= DadoUnHash_CuandoSeLoQuiereIterarConUnIteradorExternoNull_EntoncesHashSiguienteDevolveraNull();
    pruebas_pasadas+= DadoUnHash_CuandoSeIteradaConUnIteradorExterno_EntoncesImprimiraPorPantallaLoCorrecto();
    pruebas_pasadas+= DadoUnHash_CuandoEstoyEnElPrimerElementoDelHash_EntoncesTieneSiguenteDevolverTrue();
    pruebas_pasadas+= DadoUnHash_CuandoEstoyEnElUltimoElemento_EntoncesTieneSiguienteDevolveraFalse();

    printf("Pasaste %i de %i pruebas\n", pruebas_pasadas, pruebas_totales);
    return 0;
}
