#ifndef __PRUEBAS_ABB_H__
#define __PRUEBAS_ABB_H__


int DadoUnArbolVacio_CuandoSeQuiereInsertarUnElemento_EntoncesDevolveraExito();
int DadoUnArbolVacio_CuandoSeQuiereBorrarUnElemento_EntoncesDevolveraError();
int DadoUnArbolVacio_CuandoSeQuiereBuscarUnElemento_EntoncesDevolveraNull();
int DadoUnArbolVacio_CuandoSequiereVerSiEstaVacio_EntoncesDevolveraTrue();
int DadoUnArbolVacio_CuandoSequiereVerElNodoRaiz_EntoncesDevolveraNull();
int DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecInorder_EntoncesDevolveraCero();
int DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecPreorden_EntoncesDevolveraCero();
int DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecPostorder_EntoncesDevolveraCero();

int DadoUnArbolNull_CuandoSeQuiereInsertarUnElemento_EntoncesDevolveraError();
int DadoUnArbolNull_CuandoSeQuiereBorrarUnElemento_Entonces_DevolveraError();
int DadoUnArbolNull_CuandoSeQuiereVerElNodoRaiz_EntoncesDevolveraNull();
int DadoUnArbolNull_CuandoSeQuiereVerSiEstaVacio_EntoncesDevolveraTrue();
int DadoUnArbolNull_CuandoSeQuiereBuscarUnElemento_EntoncesDevolveraNull();
int DadoUnArbolNull_CuandoSeLoRecorreInorden_EntoncesDevolveraCero();
int DadoUnArbolNull_CuandoSeLoRecorrePreorden_EntoncesDevolveraCero();
int DadoUnArbolNull_CuandoSeLoRecorrePostOrden_EntoncesDevolveraCero();

int DadoUnArbol_CuandoSeInsertanYBorranElementos_EntoncesElArbolNoEstaVacio();
int DadoUnArbol_CuandoSeInsertanYBorranElementos_EntoncesElArbolEstaVacio();
int DadoUnArbol_CuandoSeBuscaUnElemento_EntoncesElElementoBuscadoSeraElCorrecto();
int DadoUnArbol_CuandoInsertoUnelemento_EntoncesEselementoEslaRaiz();
int DadoUnArbol_CuandoSeBorraUnElemento_EntoncesEsteNoEstaraEnElarbol();
int DadoUnArbol_CuandoSequiereVerQueEliminoUnNodoEnLosTresCasos_EntoncesDevolveraExito();
int DadoUnArbol_CuandoSeQuiereBuscarUnElementoQueNoEsta_EntoncesDeolveraNull();
int DadoUnArbol_CuandoLemandoUnComparadorNull_EntoncesCrearDevuelveNull();


int DadoUnArbol_CuandoSeLoRecorreInorden_EntoncesImprimiraPorPantallaLoCorrecto();
int DadoUnArbol_CuandoSeLoRecorrePostorden_EntoncesImprimiraPorPantallaLoCorrecto();
int DadoUnArbol_CuandoSeLoRecorrePreorden_EntoncesImprimiraPorPantallaLoCorrecto();
int DadoUnArbolConRecorridoPreorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta();
int DadoUnArbolConRecorridoInorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta();
int DadoUnArbolConRecorridoPostorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta();
int DadoUnArbolConRecorridoInorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero();
int DadoUnArbolConRecorridoPreorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero();
int DadoUnArbolConRecorridoPostorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero();
int DadoUnArbol_CuandoLoRecorroInOrdenConIteradorInterno_EntoncesImprimiraLoCorrecto();
int DadoUnArbol_CuandoLoRecorroPreordenConIteradorInterno_EntoncesImprimiraLoCorrecto();
int DadoUnArbol_CuandoLoRecorroPostordenConIteradorInterno_EntoncesImprimiraLoCorrecto();

int DadoUnArbol_CuandoBorroLaRaiz_EntoncesElNuevoNodoRaizSeraElCorrecto();
int DadoUnArbol_CuandoInsertoUnElementoMasGrandeQueLaRaiz_EntoncesIraAlSubArbolDerecho();
int DadoUnArbol_CuandoInsertoUnElementoMasChicoQueLaRaiz_EntoncesIraAlSubArbolizquierdo();
int DadoUnArbol_CuandoInsertoUnElementoIgualALaRaiz_EntoncesIraAlSubArbolDerecho();






#endif /* __PRUEBAS_ABB_H__ */
