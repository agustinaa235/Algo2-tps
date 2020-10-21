#include "abb.h"
#include <stdio.h>
#define NO_PASO 0
#define PASO 1
#define ERROR -1
#define EXITO 0
#define MAYOR 1
#define MENOR -1
#define IGUALES 0
#define NO_EXISTE -2


typedef struct elemento{
    int clave;
    char contenido[10];
}elemento_t;

elemento_t* crear_elemento(int clave){

    elemento_t* elemento= (elemento_t*)malloc(sizeof(elemento_t));
    if(!elemento){
        return NULL;
    }
	  elemento->clave = clave;
    return elemento;
}
void destruir_elemento(elemento_t* elemento){

    if(!elemento){
        return;
    }
	  free(elemento);
    return;
}

int comparar_elementos(void* elemento1, void* elemento2){

    if(!elemento1 || !elemento2){
	       return NO_EXISTE;
    }
    if(((elemento_t*)elemento1)->clave>((elemento_t*)elemento2)->clave){
	       return MAYOR;
    }
    if(((elemento_t*)elemento1)->clave<((elemento_t*)elemento2)->clave){
	       return MENOR;
    }
    return IGUALES;
}

int comparador_de_elementos2(void* elemento1, void* elemento2){

    if(elemento1>elemento2){
        return MAYOR;
    }
    if(elemento1<elemento2){
        return MENOR;
    }
    return IGUALES;
}

void destructor_de_elementos2(void* elemento1){
      return;
}

void destructor_de_elementos(void* elemento){

    if(!elemento){
        return;
    }
    destruir_elemento((elemento_t*)elemento);
}


int verificar_prueba(const char* nombre, bool estado){

    int resultado = NO_PASO;
    if(estado){
        printf("%s: PASO\n", nombre);
        resultado = PASO;
    }else{
        printf("%s: FALLO\n", nombre);
    }
    return resultado;
}

int DadoUnArbolVacio_CuandoSeQuiereInsertarUnElemento_EntoncesDevolveraExito(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    elemento_t* e1 = crear_elemento(1);

    resultado = verificar_prueba(__func__, arbol_insertar(arbol, e1)==EXITO);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolVacio_CuandoSeQuiereBorrarUnElemento_EntoncesDevolveraError(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    elemento_t* e1 = crear_elemento(1);

    resultado = verificar_prueba(__func__, arbol_borrar(arbol, e1)==ERROR);

    free(e1);
    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolVacio_CuandoSeQuiereBuscarUnElemento_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    elemento_t* e2 = crear_elemento(2);

    resultado = verificar_prueba(__func__, arbol_buscar(arbol, e2)==NULL);

    free(e2);
    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolVacio_CuandoSequiereVerSiEstaVacio_EntoncesDevolveraTrue(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    resultado = verificar_prueba(__func__, arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolVacio_CuandoSequiereVerElNodoRaiz_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    resultado = verificar_prueba(__func__, arbol_raiz(arbol)==NULL);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecInorder_EntoncesDevolveraCero(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    elemento_t* elementos[10];
    resultado = verificar_prueba(__func__, arbol_recorrido_inorden(arbol, (void**)elementos, 10)==0);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecPreorden_EntoncesDevolveraCero(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    elemento_t* elementos[10];

    resultado = verificar_prueba(__func__, arbol_recorrido_preorden(arbol, (void**)elementos, 10)==0);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolVacio_CuandoSeloQuiereRecorrerUtilizandoRecPostorder_EntoncesDevolveraCero(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);

    elemento_t* elementos[10];
    resultado = verificar_prueba(__func__, arbol_recorrido_postorden(arbol, (void**)elementos, 10)==0);

    arbol_destruir(arbol);
    return resultado;
}


int DadoUnArbolNull_CuandoSeQuiereInsertarUnElemento_EntoncesDevolveraError(){

    int resultado = ERROR;
    abb_t* arbol = NULL;

    int elemento = 2;

    resultado = verificar_prueba(__func__, arbol_insertar(arbol, &elemento)==ERROR);

    return resultado;

}

int DadoUnArbolNull_CuandoSeQuiereBorrarUnElemento_Entonces_DevolveraError(){

    int resultado = ERROR;
    abb_t* arbol = NULL;

    int elemento = 2;

    resultado = verificar_prueba(__func__, arbol_borrar(arbol, &elemento)==ERROR);

    return resultado;
}

int DadoUnArbolNull_CuandoSeQuiereVerElNodoRaiz_EntoncesDevolveraNull(){

  int resultado = ERROR;
  abb_t* arbol = NULL;

  resultado = verificar_prueba(__func__, arbol_raiz(arbol)==NULL);

  return resultado;
}

int DadoUnArbolNull_CuandoSeQuiereVerSiEstaVacio_EntoncesDevolveraTrue(){
    int resultado = ERROR;
    abb_t* arbol = NULL;

    resultado = verificar_prueba(__func__, arbol_vacio(arbol));

    return resultado;
}

int DadoUnArbolNull_CuandoSeQuiereBuscarUnElemento_EntoncesDevolveraNull(){

    int resultado = ERROR;
    abb_t* arbol = NULL;

    int elemento = 2;

    resultado = verificar_prueba(__func__, arbol_buscar(arbol, &elemento)==NULL);

    return resultado;
}

int DadoUnArbolNull_CuandoSeLoRecorreInorden_EntoncesDevolveraCero(){

    int resultado = ERROR;
    abb_t* arbol = NULL;

    elemento_t* elementos[10];
    resultado = verificar_prueba(__func__, arbol_recorrido_inorden(arbol, (void**)elementos, 10)==0);

    return resultado;
}

int DadoUnArbolNull_CuandoSeLoRecorrePreorden_EntoncesDevolveraCero(){

  int resultado = ERROR;
  abb_t* arbol = NULL;

  elemento_t* elementos[10];
  resultado = verificar_prueba(__func__, arbol_recorrido_preorden(arbol, (void**)elementos, 10)==0);

  return resultado;
}

int DadoUnArbolNull_CuandoSeLoRecorrePostOrden_EntoncesDevolveraCero(){

  int resultado = ERROR;
  abb_t* arbol = NULL;

  elemento_t* elementos[10];
  resultado = verificar_prueba(__func__, arbol_recorrido_postorden(arbol, (void**)elementos, 10)==0);

  return resultado;
}

int DadoUnArbol_CuandoSeInsertanYBorranElementos_EntoncesElArbolNoEstaVacio(){

    int resultado = ERROR;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }

    elemento_t* c1= crear_elemento(1);
    elemento_t* c2= crear_elemento(2);
    elemento_t* c3= crear_elemento(3);
    elemento_t* c4= crear_elemento(4);
    elemento_t* c5= crear_elemento(5);
    elemento_t* c6= crear_elemento(6);
    elemento_t* c7= crear_elemento(7);

    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c7);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c1);

    arbol_borrar(arbol, c1);
    arbol_borrar(arbol, c5);

    resultado = verificar_prueba(__func__, !arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoSeInsertanYBorranElementos_EntoncesElArbolEstaVacio(){

    int resultado = ERROR;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }

    elemento_t* c1= crear_elemento(1);
    elemento_t* c2= crear_elemento(2);
    elemento_t* c3= crear_elemento(3);
    elemento_t* c4= crear_elemento(4);
    elemento_t* c5= crear_elemento(5);
    elemento_t* c6= crear_elemento(6);
    elemento_t* c7= crear_elemento(7);

    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c7);

    arbol_borrar(arbol, c1);
    arbol_borrar(arbol, c2);
    arbol_borrar(arbol, c3);
    arbol_borrar(arbol, c4);
    arbol_borrar(arbol, c5);
    arbol_borrar(arbol, c6);
    arbol_borrar(arbol, c7);

    resultado = verificar_prueba(__func__, arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoSeBuscaUnElemento_EntoncesElElementoBuscadoSeraElCorrecto(){

    int resultado = ERROR;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }

    elemento_t* c1= crear_elemento(10);
    elemento_t* c3= crear_elemento(2);
    elemento_t* c5= crear_elemento(5);
    elemento_t* c4= crear_elemento(15);
    elemento_t* c6= crear_elemento(12);
    elemento_t* c7= crear_elemento(7);

    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c7);

    resultado = verificar_prueba(__func__, *(int*)arbol_buscar(arbol, c5) == c5->clave);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoInsertoUnelemento_EntoncesEselementoEslaRaiz(){

    int resultado = ERROR;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }

    elemento_t* c1= crear_elemento(10);
    arbol_insertar(arbol, c1);

    resultado = verificar_prueba(__func__, *(int*)arbol_raiz(arbol) == c1->clave);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoSeBorraUnElemento_EntoncesEsteNoEstaraEnElarbol(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }

    elemento_t* c1= crear_elemento(1);
    elemento_t* c2= crear_elemento(2);
    elemento_t* c3= crear_elemento(3);
    elemento_t* c4= crear_elemento(4);
    elemento_t* c5= crear_elemento(5);
    elemento_t* c6= crear_elemento(6);
    elemento_t* c7= crear_elemento(7);

    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c7);

    arbol_borrar(arbol, c3);
    elemento_t* testing= crear_elemento(3);
    resultado = verificar_prueba(__func__, arbol_buscar(arbol, testing)==NULL);

    destructor_de_elementos(testing);
    arbol_destruir(arbol);
    return resultado;
}


int DadoUnArbol_CuandoSequiereVerQueEliminoUnNodoEnLosTresCasos_EntoncesDevolveraExito(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c1= crear_elemento(15);
    elemento_t* c2= crear_elemento(10);
    elemento_t* c3= crear_elemento(13);
    elemento_t* c4= crear_elemento(18);
    elemento_t* c5= crear_elemento(21);
    elemento_t* c6= crear_elemento(4);
    elemento_t* c7= crear_elemento(7);
    elemento_t* c8= crear_elemento(17);
    elemento_t* c9= crear_elemento(1);
    elemento_t* c10= crear_elemento(20);

    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c7);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c9);
    arbol_insertar(arbol, c10);

    int estado1 = arbol_borrar(arbol, c9);
    int estado2 = arbol_borrar(arbol, c5);
    int estado3 = arbol_borrar(arbol, c2);
    printf("Borro nodo hoja (1): %s\n", estado1==EXITO?"SI":"NO");
    printf("Borro nodo hoja (21): %s\n", estado2==EXITO?"SI":"NO");
    printf("Borro nodo hoja (10): %s\n", estado3==EXITO?"SI":"NO");

    resultado = verificar_prueba(__func__, (estado1)==EXITO && (estado2)==EXITO && (estado3)==EXITO);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoSeQuiereBuscarUnElementoQueNoEsta_EntoncesDeolveraNull(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c1= crear_elemento(1);
    elemento_t* c3= crear_elemento(3);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c23= crear_elemento(23);
    elemento_t* c7= crear_elemento(7);
    elemento_t* c13= crear_elemento(13);

    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c7);
    arbol_insertar(arbol, c23);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c13);

    resultado = verificar_prueba(__func__, arbol_buscar(arbol, c3)==NULL);

    arbol_destruir(arbol);
    destructor_de_elementos(c3);
    return resultado;
}

int DadoUnArbol_CuandoSeLoRecorreInorden_EntoncesImprimiraPorPantallaLoCorrecto(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c16= crear_elemento(16);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c20= crear_elemento(20);
    elemento_t* c18= crear_elemento(18);

    arbol_insertar(arbol, c16);
    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c20);
    arbol_insertar(arbol, c18);
    elemento_t* elementos[10];

    printf("Recorrido inorden (deberian salir en orden 8 10 15 16 18 20): ");
    int cantidad = arbol_recorrido_inorden(arbol, (void**)elementos, 10);
    for(int i=0;i<cantidad;i++){
	       printf("%i ", elementos[i]->clave);
    }
    printf("\n");
    resultado = verificar_prueba(__func__, !arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoSeLoRecorrePostorden_EntoncesImprimiraPorPantallaLoCorrecto(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c16= crear_elemento(16);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c20= crear_elemento(20);
    elemento_t* c18= crear_elemento(18);

    arbol_insertar(arbol, c16);
    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c20);
    arbol_insertar(arbol, c18);
    elemento_t* elementos[10];

    printf("Recorrido postorden (deberian salir en orden 8 15 10 18 20 16): ");
    int cantidad = arbol_recorrido_postorden(arbol, (void**)elementos, 10);
    for(int i=0;i<cantidad;i++){
	       printf("%i ", elementos[i]->clave);
    }
     printf("\n");
    resultado = verificar_prueba(__func__, !arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoSeLoRecorrePreorden_EntoncesImprimiraPorPantallaLoCorrecto(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c16= crear_elemento(16);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c20= crear_elemento(20);
    elemento_t* c18= crear_elemento(18);

    arbol_insertar(arbol, c16);
    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c20);
    arbol_insertar(arbol, c18);
    elemento_t* elementos[10];

    printf("Recorrido preorden (deberian salir en orden 16 10 8 15 20 18): ");
    int cantidad = arbol_recorrido_preorden(arbol, (void**)elementos, 10);
    for(int i=0;i<cantidad;i++){
        printf("%i ", elementos[i]->clave);
    }
    printf("\n");
    resultado = verificar_prueba(__func__, !arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;

}
int DadoUnArbolConRecorridoPreorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c16= crear_elemento(16);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c20= crear_elemento(20);
    elemento_t* c18= crear_elemento(18);

    arbol_insertar(arbol, c16);
    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c20);
    arbol_insertar(arbol, c18);
    int tope = 3;
    elemento_t* elementos[tope];
    resultado = verificar_prueba(__func__, arbol_recorrido_preorden(arbol, (void**)elementos, tope)==tope);

    arbol_destruir(arbol);
    return resultado;

}
int DadoUnArbolConRecorridoPostorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta(){

    int resultado = ERROR;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }

    elemento_t* c1= crear_elemento(10);
    elemento_t* c3= crear_elemento(2);
    elemento_t* c5= crear_elemento(5);
    elemento_t* c4= crear_elemento(15);
    elemento_t* c6= crear_elemento(12);
    elemento_t* c7= crear_elemento(7);

    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c7);

    int tope = 4;
    elemento_t* elementos[tope];
    resultado = verificar_prueba(__func__, arbol_recorrido_postorden(arbol, (void**)elementos, tope)==tope);

    arbol_destruir(arbol);
    return resultado;
}
int DadoUnArbolConRecorridoInorden_CuandoLePasoUnArrayChico_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsLaCorrecta(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }

    elemento_t* c1= crear_elemento(1);
    elemento_t* c2= crear_elemento(2);
    elemento_t* c3= crear_elemento(3);
    elemento_t* c4= crear_elemento(4);
    elemento_t* c5= crear_elemento(5);
    elemento_t* c6= crear_elemento(6);
    elemento_t* c7= crear_elemento(7);

    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c7);

    int tope = 5;
    elemento_t* elementos[tope];
    resultado = verificar_prueba(__func__, arbol_recorrido_inorden(arbol, (void**)elementos, tope)==tope);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolConRecorridoInorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparador_de_elementos2, destructor_de_elementos2);
    if(!arbol){
      return resultado;
    }
    char elemento1 = 'c';
    char elemento2 = 'h';

    arbol_insertar(arbol, &elemento2);
    arbol_insertar(arbol, &elemento1);

    elemento_t** elementos= NULL;

    resultado = verificar_prueba(__func__, arbol_recorrido_inorden(arbol, (void**)elementos, 4)==0);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolConRecorridoPreorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparador_de_elementos2, destructor_de_elementos2);
    if(!arbol){
      return resultado;
    }
    char elemento1 = 'c';
    char elemento2 = 'h';

    arbol_insertar(arbol, &elemento2);
    arbol_insertar(arbol, &elemento1);

    elemento_t** elementos= NULL;

    resultado = verificar_prueba(__func__, arbol_recorrido_preorden(arbol, (void**)elementos, 4)==0);

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbolConRecorridoPostorden_CuandoLePasoUnArrayNull_EntoncesLaCantidadDeElementosInsertadosEnElArrayEsCero(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparador_de_elementos2, destructor_de_elementos2);
    if(!arbol){
      return resultado;
    }
    char elemento1 = 'c';
    char elemento2 = 'h';

    arbol_insertar(arbol, &elemento2);
    arbol_insertar(arbol, &elemento1);

    elemento_t** elementos= NULL;

    resultado = verificar_prueba(__func__, arbol_recorrido_postorden(arbol, (void**)elementos, 4)==0);

    arbol_destruir(arbol);
    return resultado;

}

int DadoUnArbol_CuandoLemandoUnComparadorNull_EntoncesCrearDevuelveNull(){

    int resultado = NO_PASO;
    abb_comparador comparador = NULL;

    resultado = verificar_prueba(__func__, !arbol_crear(comparador, destructor_de_elementos));

    return resultado;
}


int DadoUnArbol_CuandoBorroLaRaiz_EntoncesElNuevoNodoRaizSeraElCorrecto(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c1= crear_elemento(1);
    elemento_t* c2= crear_elemento(2);
    elemento_t* c3= crear_elemento(3);
    elemento_t* c4= crear_elemento(4);
    elemento_t* c5= crear_elemento(5);
    elemento_t* c6= crear_elemento(6);
    elemento_t* c7= crear_elemento(7);

    arbol_insertar(arbol, c4);
    arbol_insertar(arbol, c2);
    arbol_insertar(arbol, c6);
    arbol_insertar(arbol, c1);
    arbol_insertar(arbol, c3);
    arbol_insertar(arbol, c5);
    arbol_insertar(arbol, c7);

    arbol_borrar(arbol, c4);
    printf("Cuando borras al 4, entonces el nodo raiz deberia ser 5: %s\n", *(int*)arbol_raiz(arbol) == c5->clave?"SI":"NO");

    resultado = verificar_prueba(__func__, *(int*)arbol_raiz(arbol) == c5->clave);

    arbol_destruir(arbol);
    return resultado;

}

int DadoUnArbol_CuandoInsertoUnElementoMasGrandeQueLaRaiz_EntoncesIraAlSubArbolDerecho(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparador_de_elementos2, destructor_de_elementos2);
    if(!arbol){
        return resultado;
    }
    char elemento1 = 'c';
    char elemento2 = 'h';

    arbol_insertar(arbol, &elemento1);
    arbol_insertar(arbol, &elemento2);

    resultado = verificar_prueba(__func__, arbol->nodo_raiz->derecha->elemento == (&elemento2));

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoInsertoUnElementoMasChicoQueLaRaiz_EntoncesIraAlSubArbolizquierdo(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparador_de_elementos2, destructor_de_elementos2);
    if(!arbol){
        return resultado;
    }
    char elemento1 = 'c';
    char elemento2 = 'h';

    arbol_insertar(arbol, &elemento2);
    arbol_insertar(arbol, &elemento1);

    resultado = verificar_prueba(__func__, arbol->nodo_raiz->izquierda->elemento == (&elemento1));

    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoInsertoUnElementoIgualALaRaiz_EntoncesIraAlSubArbolDerecho(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparador_de_elementos2, destructor_de_elementos2);
    if(!arbol){
        return resultado;
    }
    int elemento1 = 1;

    arbol_insertar(arbol, &elemento1);
    arbol_insertar(arbol, &elemento1);

    resultado = verificar_prueba(__func__, arbol->nodo_raiz->derecha->elemento == (&elemento1));

    arbol_destruir(arbol);
    return resultado;
}

bool mostrar_elemento(void* elemento, void* extra){
    extra=extra;
    if(elemento)
        printf("%i ", ((elemento_t*)elemento)->clave);
    return false;
}



int DadoUnArbol_CuandoLoRecorroInOrdenConIteradorInterno_EntoncesImprimiraLoCorrecto(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c16= crear_elemento(16);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c20= crear_elemento(20);
    elemento_t* c18= crear_elemento(18);

    arbol_insertar(arbol, c16);
    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c20);
    arbol_insertar(arbol, c18);

    printf("Recorrido inorden con iterador interno(deberian salir en orden 8 10 15 16 18 20): ");

    abb_con_cada_elemento(arbol, ABB_RECORRER_INORDEN, mostrar_elemento, NULL);
    printf("\n");

    resultado = verificar_prueba(__func__, !arbol_vacio(arbol));
    arbol_destruir(arbol);
    return resultado;
}

int DadoUnArbol_CuandoLoRecorroPreordenConIteradorInterno_EntoncesImprimiraLoCorrecto(){

    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c16= crear_elemento(16);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c20= crear_elemento(20);
    elemento_t* c18= crear_elemento(18);

    arbol_insertar(arbol, c16);
    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c20);
    arbol_insertar(arbol, c18);

    printf("Recorrido preorden iterador interno (deberian salir en orden 16 10 8 15 20 18): ");
    abb_con_cada_elemento(arbol, ABB_RECORRER_PREORDEN, mostrar_elemento, NULL);
    printf("\n");

    resultado = verificar_prueba(__func__, !arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;

}
int DadoUnArbol_CuandoLoRecorroPostordenConIteradorInterno_EntoncesImprimiraLoCorrecto(){


    int resultado = NO_PASO;
    abb_t* arbol = arbol_crear(comparar_elementos, destructor_de_elementos);
    if(!arbol){
        return resultado;
    }
    elemento_t* c16= crear_elemento(16);
    elemento_t* c10= crear_elemento(10);
    elemento_t* c8= crear_elemento(8);
    elemento_t* c15= crear_elemento(15);
    elemento_t* c20= crear_elemento(20);
    elemento_t* c18= crear_elemento(18);

    arbol_insertar(arbol, c16);
    arbol_insertar(arbol, c10);
    arbol_insertar(arbol, c15);
    arbol_insertar(arbol, c8);
    arbol_insertar(arbol, c20);
    arbol_insertar(arbol, c18);

    printf("Recorrido postorden con iterador interno (deberian salir en orden 8 15 10 18 20 16): ");
    abb_con_cada_elemento(arbol, ABB_RECORRER_POSTORDEN, mostrar_elemento, NULL);
    printf("\n");

    resultado = verificar_prueba(__func__, !arbol_vacio(arbol));

    arbol_destruir(arbol);
    return resultado;
}
