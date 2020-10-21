#ifndef __PRUEBAS_HASH_H__
#define __PRUEBAS_HASH_H__

#include "hash.h"
#include "hash_iterador.h"


int DadoUnhashNull_CuandoSeQuiereInsertar_EntoncesDevolveraError();
int DadoUnHashNull_CuandoSeQuiereBorrar_EntoncesDevolveraError();
int DadoUnHashNull_CuandoSeQuiereObtenerUnElemento_EntoncesDevolveraNull();
int DadoUnHashNull_CuandoSeQuiereVerSiEstaUnElemento_EntoncesHashContieneDevolveraFalse();
int DadoUnHashNull_CuandoSeQuiereVerLaCantidad_EntoncesLaCantidadSeraCero();
int DadoUnHash_CuandoSeQuiereInsertarUnElementoConClaveNull_EntoncesDevolveraError();
int DadoUnHash_CuandoSeQuiereInsertarUnElementoNullConClaveDistintaANull_EntoncesDevolveraExito();

int DadoUnHashVacio_CuandoSeQuiereInsertar_EntoncesDevolveraExito();
int DadoUnHashVacio_CuandoSeQuiereBorrar_EntoncesDevolveraError();
int DadoUnHashVacio_CuandoSeQuiereObtenerUnElemento_EntoncesDevolveraNull();
int DadoUnHashVacio_CuandoSeQuiereVerLaCantidad_EntoncesEstaSeraCero();
int DadoUnHashVacio_CuandoSeQuiereVerSiUnElementoEsta_EntoncesDevolveraFalse();

int DadoUnHash_CuandoSeQuiereInsertarpocosElementos_EntoncesLosInsertaraAtodosCorrectamente();
int DadoUnHash_CuandoSeQuiereBuscarUnElementoYaInsertado_EntoncesHashContienDevolveraTrue();
int DadoUnhash_CuandoSeQuiereBuscarUnElementoYaInsertado_EntoncesHashObtenerDevolveraEseElemento();
int DadoUnHash_CuandoInsertoPocosElementos_EntoncesLaCantidadSeraLaCorrecta();
int DadoUnHash_CuandoBuscoUnElementoQueNoEsta_EntoncesContieneDevolveraFalse();
int DadoUnHash_CuandoBuscoUnElementoQueNoEsta_EntoncesHashObtenerDevolveraNull();
int DadoUnHash_CuandoInsertoUnElementoYLuegoLoBorro_EntoncesHashContieneDevolveraFalse();
int DadoUnHash_CuandoInsertoUnElementoYLuegoLoBorro_EntoncesHashObtenerDevolveraNull();
int DadoUnHash_CuandoIntertoyBorroLaMismaCantidadDeElementos_EntoncesLaCantidadFinalSeraCero();
int DadoUnHash_CuandoInsertoDosElementosConLaMismaClave_EntoncesElElementoSeModificaraPorElSegundo();

int DadoUnHashNull_CuandoSeLoQuiereRecorerConUnIteradorExterno_EntoncesCrearDevolveraNull();
int DadoUnHash_CuandoSeLoQuiereRecorrerConUnIteradorExternoNull_EntocesHashTieneSigueinteDevolveraFalse();
int DadoUnHash_CuandoSeLoQuiereIterarConUnIteradorExternoNull_EntoncesHashSiguienteDevolveraNull();
int DadoUnHash_CuandoSeIteradaConUnIteradorExterno_EntoncesImprimiraPorPantallaLoCorrecto();
int DadoUnHash_CuandoEstoyEnElPrimerElementoDelHash_EntoncesTieneSiguenteDevolverTrue();
int DadoUnHash_CuandoEstoyEnElUltimoElemento_EntoncesTieneSiguienteDevolveraFalse();






#endif /* __PRUEBAS_HASH_H__ */
