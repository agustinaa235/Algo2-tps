#ifndef __PRUEBAS_LISTA_H__
#define __PRUEBAS_LISTA_H__


int DadaUnaListaVacia_CuandoSeQuiereEnlistar_EntoncesDevolveraExito();
int DadaUnaListaVacia_CuandoQuieroBorrar_EntoncesDevuelveError();
int DadaUnaListaVacia_CuandoQuieroInsertarEnUnaPosicion_EntoncesDevolveraExito();
int DadaUnaListaVacia_CuandoQuieroEliminarEnUnaPosicion_EntoncesDevolveraError();
int DadaUnaListaVacia_CuandoQuieroVerElUltimoElemento_EntoncesDevolveraNull();
int DadaUnaListaVacia_CuandoQuieroVerElElementoEnUnaPosicion_EntoncesDevolveraNull();
int DadaUnaListaVacia_CuandoQuieroVerLaCantidadDeElementos_EntoncesLaCantidadSeraCero();
int DadaUnaLista_CuandoSeLaCrea_EntoncesEstaraVacia();

int DadaUnaListaNull_CuandoSeQuiereBorrar_EntoncesDevolveraError();
int DadaUnaListaNull_CuandoSeQuiereInsertarEnUnaPosicion_EntoncesDevolveraError();
int DadaUnaListaNull_CuandoSeQuiereBorrar_EntoncesDevolveraError();
int DadaUnaListaNull_CuandoSeQuiereBorrarEnUnaPosicion_EntoncesDevolveraError();
int DadaUnaListaNull_CuandoSeQuiereVerElUltimoElemento_EntoncesDevolveraNull();
int DadaUnaListaNull_CuandoSeQuiereVerElElemenoEnUnaPosicion_EntoncesDevolveraNull();
int DadaUnaListaNull_CuandoSeQuiereVerSiEstaVacia_EntoncesDevolveraTrue();
int DadaUnaListaNull_CuandoSequiereVerLaCantidadDeElementos_EntoncesEstaSeraCero();

int DadaUnalistaInicializada_CuandoSeInsertaYSeBorranElementosAlfinal_EntoncesLaListaQuedaraVacia();
int DadaUnaListaInicializada_CuandoSeInsertaMasElementosDeLosQueSeBorranAlFinal_EntoncesLaListaNoQuedaraVacia();
int DadadUnaListaInicializada_CuandoSeInsertanYSeEliminanElementosEnDistintasPosiciones_EntoncesLaListaQuedaVacia();
int DadadUnaListaInicializada_CuandoSeInsertanMasElementosDeLosQueSeEliminanEnDistintasPosiciones_EntoncesLaListaNoQuedaVacia();
int DadaUnaListaInicializada_CuandoSeInsertanElementos_EntoncesLaCantidadEsLaCorrecta();
int DadaUnaListaInicializada_CuandoSeInsertanYseEliminanElementosEnDsitintasPosiciones_EntoncesImprimiraPorPantallaLoCorrecto();
int DadaUnaListaInicializada_CuandoSeInsertaUnelemento_EntoncesElElementoUltimoSeraEse();

int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaListaQuedaraVacia();
int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaListaNoQuedaraVacia();
int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaCantidadSeraLaCorrecta();
int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementos_Entonceselultimoelementoseraelcorrecto();
int DadaUnaListaInicizalizada_CuandoSeInsertaUnElementoEnUnaDeterminaPosicion_ElElementoInsertadoSeraEse();

int DadaUnaLista_CuandoSeQuiereRecorrerUnaListaConUnElmentoUtilizandoIteradorExterno_EntoncesNotendraUnSiguiente();
int DadaUnaListaInicializada_CuandoSeLaQuiereRecorrerUltilizandoIteradorExternoNull_EntoncesTieneSiguienteDevolveraFalse();
int DadaUnaListaInicializada_CuandoSeLaQuiereRecorrerUltilizandoIteradorExternoNull_EntoncesListaIteradorSiguienteDevolveraNull();
int DadaUnaListaInicializada_CuandoEstoyEnElPrimerElementoDeLaLista_EntoncesTieneSiguenteDevolverTrue();
int DadaUnaListaInicializada_CuandoEstoyEnLaUltimaPosicionDeLaLista_EntoncesTieneSiguienteDevolveraFalse();
int DadaUnaLista_CuandoSequiereRecorrerLaListaUltilizandoUniteradorExterno_EntoncesImprimiraPorpantallaLoCorrecto();
int DadaUnaLista_CuandoSeTieneUnIteradorNull_EntoncesIteradorSiguienteDevolveraNull();
int DadaUnaLista_CuandoSeTieneUnIteradorNull_EntoncesIteradorTieneSiguienteDevolveraFalse();
int DadaUnaListaNull_CuandoSeQuiereCrearUnIteradorExterno_EntoncesIteradorCrearDevolveraNull();

int DadaUnaLista_CuandoSequiereRecorrerLaListaUltilizandoUniteradorInterno_EntoncesImprimiraPorpantallaLoCorrecto();

#endif /* __PRUEBAS_LISTA_H__ */
