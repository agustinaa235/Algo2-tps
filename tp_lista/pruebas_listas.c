#include "lista.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define EXITO 0
#define ERROR -1
#define NO_PASO 0
#define PASO 1

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



int DadaUnaListaVacia_CuandoSeQuiereEnlistar_EntoncesDevolveraExito(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento_1 = 1;
    resultado = verificar_prueba(__func__, lista_insertar(lista, &elemento_1)==EXITO);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaVacia_CuandoQuieroBorrar_EntoncesDevuelveError(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    resultado = verificar_prueba(__func__, lista_borrar(lista)==ERROR);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaVacia_CuandoQuieroInsertarEnUnaPosicion_EntoncesDevolveraExito(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento_1=1;
    resultado = verificar_prueba(__func__, lista_insertar_en_posicion(lista, &elemento_1, 2)==EXITO);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaVacia_CuandoQuieroEliminarEnUnaPosicion_EntoncesDevolveraError(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    resultado = verificar_prueba(__func__, lista_borrar_de_posicion(lista, 2)==ERROR);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaVacia_CuandoQuieroVerElUltimoElemento_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    resultado = verificar_prueba(__func__, lista_ultimo(lista)==NULL);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaVacia_CuandoQuieroVerElElementoEnUnaPosicion_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    resultado = verificar_prueba(__func__, lista_elemento_en_posicion(lista, 2)==NULL);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaVacia_CuandoQuieroVerLaCantidadDeElementos_EntoncesLaCantidadSeraCero(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    resultado = verificar_prueba(__func__, lista_elementos(lista)==0);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaLista_CuandoSeLaCrea_EntoncesEstaraVacia(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    resultado = verificar_prueba(__func__, lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaNull_CuandoSeQuiereInsertar_EntoncesDevolveraError(){

    lista_t* lista = NULL;
    char a= 'a';
    int resultado = verificar_prueba(__func__, lista_insertar(lista, &a)==ERROR);

    return resultado;
}
int DadaUnaListaNull_CuandoSeQuiereInsertarEnUnaPosicion_EntoncesDevolveraError(){

      lista_t* lista = NULL;
      char a='a';
      int resultado = verificar_prueba(__func__, lista_insertar_en_posicion(lista, &a, 1)==ERROR);

      return resultado;
}


int DadaUnaListaNull_CuandoSeQuiereBorrar_EntoncesDevolveraError(){

    lista_t* lista = NULL;

    int resultado = verificar_prueba(__func__, lista_borrar(lista)==ERROR);

    return resultado;
}

int DadaUnaListaNull_CuandoSeQuiereBorrarEnUnaPosicion_EntoncesDevolveraError(){

    lista_t* lista = NULL;

    int resultado = verificar_prueba(__func__, lista_borrar_de_posicion(lista, 2)==ERROR);

    return resultado;
}

int DadaUnaListaNull_CuandoSeQuiereVerElUltimoElemento_EntoncesDevolveraNull(){

    lista_t* lista = NULL;

    int resultado = verificar_prueba(__func__, lista_ultimo(lista)==NULL);

    return resultado;
}

int DadaUnaListaNull_CuandoSeQuiereVerElElemenoEnUnaPosicion_EntoncesDevolveraNull(){

    lista_t* lista = NULL;

    int resultado = verificar_prueba(__func__, lista_elemento_en_posicion(lista, 3)==NULL);

    return resultado;
}

int DadaUnaListaNull_CuandoSeQuiereVerSiEstaVacia_EntoncesDevolveraTrue(){

    lista_t* lista = NULL;

    int resultado = verificar_prueba(__func__, lista_vacia(lista));

    return resultado;
}

int DadaUnaListaNull_CuandoSequiereVerLaCantidadDeElementos_EntoncesEstaSeraCero(){

    lista_t* lista = NULL;

    int resultado = verificar_prueba(__func__, lista_elementos(lista)==0);

    return resultado;
}

int DadaUnalistaInicializada_CuandoSeInsertaYSeBorranElementosAlfinal_EntoncesLaListaQuedaraVacia(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    char a='a', l='l', g='g', o='o';
    int numero = 2;
    lista_insertar(lista, &a);
    lista_insertar(lista, &l);
    lista_insertar(lista, &g);
    lista_insertar(lista, &o);
    lista_insertar(lista, &numero);
    for(int i=0;i<5;i++){
        lista_borrar(lista);
    }
    resultado = verificar_prueba(__func__, lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}
int DadaUnaListaInicializada_CuandoSeInsertaMasElementosDeLosQueSeBorranAlFinal_EntoncesLaListaNoQuedaraVacia(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4;
    for(int i=0; i<5;i++){
        lista_insertar(lista, &elemento_1);
        lista_insertar(lista, &elemento_2);
        lista_insertar(lista, &elemento_3);
        lista_insertar(lista, &elemento_4);
    }
    for(int i=0; i<15;i++){
        lista_borrar(lista);
    }
    resultado = verificar_prueba(__func__, !lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}

int DadadUnaListaInicializada_CuandoSeInsertanYSeEliminanElementosEnDistintasPosiciones_EntoncesLaListaQuedaVacia(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    char a='a', b='b', c='c', d='d', s='s';

    lista_insertar_en_posicion(lista, &a, 0);
    lista_insertar(lista, &d);
    lista_insertar_en_posicion(lista, &b, 3);
    lista_insertar_en_posicion(lista, &c, 1);
    lista_insertar(lista, &s);
    lista_insertar_en_posicion(lista, &a, 2);
    lista_insertar(lista, &s);

    lista_borrar_de_posicion(lista, 3);
    lista_borrar_de_posicion(lista, 0);
    lista_borrar(lista);
    lista_borrar_de_posicion(lista, 6);
    lista_borrar_de_posicion(lista, 2);
    lista_borrar_de_posicion(lista, 1);
    lista_borrar(lista);
    resultado = verificar_prueba(__func__, lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}

int DadadUnaListaInicializada_CuandoSeInsertanMasElementosDeLosQueSeEliminanEnDistintasPosiciones_EntoncesLaListaNoQuedaVacia(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }

    int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4, elemento_5 = 5;

    lista_insertar(lista, &elemento_2);
    lista_insertar_en_posicion(lista, &elemento_1, 3);
    lista_insertar_en_posicion(lista, &elemento_2, 0);
    lista_insertar(lista, &elemento_5);
    lista_insertar(lista, &elemento_3);
    lista_insertar_en_posicion(lista, &elemento_2, 2);
    lista_insertar(lista, &elemento_4);

    lista_borrar_de_posicion(lista, 3);
    lista_borrar(lista);
    lista_borrar(lista);
    lista_borrar_de_posicion(lista, 0);
    resultado = verificar_prueba(__func__, !lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaInicializada_CuandoSeInsertanElementos_EntoncesLaCantidadEsLaCorrecta(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elementos_a_insertar= 15;
    int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4, elemento_5 = 5;
    for(int i=0;i<3;i++){
        lista_insertar_en_posicion(lista, &elemento_1, 0);
        lista_insertar(lista, &elemento_4);
        lista_insertar_en_posicion(lista, &elemento_3, 2);
        lista_insertar(lista, &elemento_5);
        lista_insertar_en_posicion(lista, &elemento_2, 1);
    }
    resultado = verificar_prueba(__func__, lista_elementos(lista)==elementos_a_insertar);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaInicializada_CuandoSeInsertanYseEliminanElementosEnDsitintasPosiciones_EntoncesImprimiraPorPantallaLoCorrecto(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    char a='a', g='g', u='u', s='s', t='t',i='i', n='n';
    lista_insertar(lista, &a);
    lista_insertar(lista, &g);
    lista_insertar(lista, &u);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);
    lista_insertar(lista, &i);
    lista_insertar(lista, &n);
    lista_insertar(lista, &a);
    for(size_t i=0;i<lista_elementos(lista);i++){
        printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));
    }
    printf("\n");
    resultado = verificar_prueba(__func__, !lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}
int DadaUnaListaInicializada_CuandoSeInsertaUnelemento_EntoncesElElementoUltimoSeraEse(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int a=1;
    lista_insertar(lista, &a);
    resultado = verificar_prueba(__func__, lista_ultimo(lista)==&a);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaListaQuedaraVacia(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento1 = rand() % 50;
    int elemento2 = rand() % 50;
    int elemento3 = rand() % 50;
    int elemento4 = rand() % 50;
    int elemento5 = rand() % 50;

    for(size_t i=0; i<200; i++){
        lista_insertar_en_posicion(lista, &elemento1, 3);
        lista_insertar_en_posicion(lista, &elemento2, 2);
        lista_insertar(lista, &elemento3);
        lista_insertar_en_posicion(lista, &elemento4,0);
        lista_insertar(lista, &elemento5);
    }
    for(int i=0;i<1000;i++){
        lista_borrar(lista);
    }
    resultado = verificar_prueba(__func__, lista_vacia(lista));
    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaListaNoQuedaraVacia(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento1 = rand() % 50;
    int elemento2 = rand() % 50;
    int elemento3 = rand() % 50;
    int elemento4 = rand() % 50;
    int elemento5 = rand() % 50;

    for(int i=0; i<200; i++){
        lista_insertar(lista, &elemento1);
        lista_insertar_en_posicion(lista, &elemento2, 2);
        lista_insertar(lista, &elemento3);
        lista_insertar_en_posicion(lista, &elemento4,5);
        lista_insertar(lista, &elemento5);
    }
    for(int i=0;i<800;i++){
        lista_borrar(lista);
    }
    resultado = verificar_prueba(__func__, !lista_vacia(lista));
    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementosEnDistintasPosiciones_EntoncesLaCantidadSeraLaCorrecta(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elementos_a_insertar_final= 100;
    int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4;
    for(int i=0;i<100;i++){
        lista_insertar_en_posicion(lista, &elemento_1, 0);
        lista_insertar(lista, &elemento_4);
        lista_insertar_en_posicion(lista, &elemento_3, 7);
        lista_insertar(lista, &elemento_3);
        lista_insertar_en_posicion(lista, &elemento_2, 1);
    }
    for(int i =0;i<400;i++){
        lista_borrar_de_posicion(lista, 0);
    }
    resultado = verificar_prueba(__func__, lista_elementos(lista)==elementos_a_insertar_final);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaInicizalizada_CuandoSeInsertanYEliminanMuchosElementos_Entonceselultimoelementoseraelcorrecto(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }

    char a='A', l='L', g='G', o='O';
    for(int i=0; i<100;i++){
        lista_insertar(lista, &a);
        lista_insertar(lista, &l);
        lista_insertar(lista, &g);
        lista_insertar(lista, &o);
    }
    for(int i=0;i<200;i++){
        lista_borrar(lista);
    }

    resultado = verificar_prueba(__func__, lista_ultimo(lista)==&o);

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaInicizalizada_CuandoSeInsertaUnElementoEnUnaDeterminaPosicion_ElElementoInsertadoSeraEse(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento1 = 1, elemento2 = 2, elemento3 = 3, elemento4 = 4;
    for(int i=0; i<150; i++){
        lista_insertar(lista, &elemento1);
        lista_insertar(lista, &elemento2);
        lista_insertar(lista, &elemento3);
    }
    lista_insertar_en_posicion(lista, &elemento4, 300);
    resultado = verificar_prueba(__func__, lista_elemento_en_posicion(lista,300)==&elemento4);

    lista_destruir(lista);
    return resultado;
}


int DadaUnaLista_CuandoSeQuiereRecorrerUnaListaConUnElmentoUtilizandoIteradorExterno_EntoncesNotendraUnSiguiente(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento1 = 1;
    lista_insertar(lista, &elemento1);

    lista_iterador_t* iterador = lista_iterador_crear(lista);
    if(!iterador){
        return resultado;
    }
    lista_iterador_siguiente(iterador);
    resultado = verificar_prueba(__func__, !lista_iterador_tiene_siguiente(iterador));

    lista_iterador_destruir(iterador);
    lista_destruir(lista);
    return resultado;

}
int DadaUnaListaInicializada_CuandoSeLaQuiereRecorrerUltilizandoIteradorExternoNull_EntoncesListaIteradorSiguienteDevolveraNull(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    char a='a', l='l', g='g', o='o';
    int numero = 2;

    lista_insertar(lista, &a);
    lista_insertar(lista, &l);
    lista_insertar(lista, &g);
    lista_insertar(lista, &o);
    lista_insertar(lista, &numero);

    lista_iterador_t* iterador = NULL;
    resultado = verificar_prueba(__func__, lista_iterador_siguiente(iterador)==NULL);

    lista_destruir(lista);
    return resultado;

}

int DadaUnaListaInicializada_CuandoSeLaQuiereRecorrerUltilizandoIteradorExternoNull_EntoncesTieneSiguienteDevolveraFalse(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento1 = 1, elemento2 = 2, elemento3 = 3;

    lista_insertar(lista, &elemento1);
    lista_insertar(lista, &elemento2);
    lista_insertar(lista, &elemento3);

    lista_iterador_t* iterador = NULL;
    resultado = verificar_prueba(__func__, !lista_iterador_tiene_siguiente(iterador));

    lista_destruir(lista);
    return resultado;

}

int DadaUnaListaInicializada_CuandoEstoyEnElPrimerElementoDeLaLista_EntoncesTieneSiguenteDevolverTrue(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4, elemento_5 = 5;
    for(int i=0;i<3;i++){
        lista_insertar_en_posicion(lista, &elemento_1, 0);
        lista_insertar(lista, &elemento_4);
        lista_insertar_en_posicion(lista, &elemento_3, 2);
        lista_insertar(lista, &elemento_5);
        lista_insertar_en_posicion(lista, &elemento_2, 1);
    }
    lista_iterador_t* iterador = lista_iterador_crear(lista);
    if(!iterador){
        lista_destruir(lista);
        return resultado;
    }
    lista_iterador_siguiente(iterador);
    resultado = verificar_prueba(__func__, lista_iterador_tiene_siguiente(iterador));

    lista_iterador_destruir(iterador);
    lista_destruir(lista);
    return resultado;

}

int DadaUnaListaInicializada_CuandoEstoyEnLaUltimaPosicionDeLaLista_EntoncesTieneSiguienteDevolveraFalse(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4, elemento_5 = 5;
    int cantidad_total = 7;
    int i=0;

    lista_insertar(lista, &elemento_2);
    lista_insertar_en_posicion(lista, &elemento_1, 3);
    lista_insertar_en_posicion(lista, &elemento_2, 0);
    lista_insertar(lista, &elemento_5);
    lista_insertar(lista, &elemento_3);
    lista_insertar_en_posicion(lista, &elemento_2, 2);
    lista_insertar(lista, &elemento_4);

    lista_iterador_t* iterador = lista_iterador_crear(lista);
    if(!iterador){
        lista_destruir(lista);
        return resultado;
    }
    while(i<cantidad_total){
        lista_iterador_siguiente(iterador);
        i++;
    }

    resultado = verificar_prueba(__func__, !lista_iterador_tiene_siguiente(iterador));

    lista_iterador_destruir(iterador);
    lista_destruir(lista);
    return resultado;
}

int DadaUnaLista_CuandoSequiereRecorrerLaListaUltilizandoUniteradorExterno_EntoncesImprimiraPorpantallaLoCorrecto(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    char a='a', g='g', u='u', s='s', t='t',i='i', n='n';
    lista_insertar(lista, &a);
    lista_insertar(lista, &g);
    lista_insertar(lista, &u);
    lista_insertar(lista, &s);
    lista_insertar(lista, &t);
    lista_insertar(lista, &i);
    lista_insertar(lista, &n);
    lista_insertar(lista, &a);


    lista_iterador_t* iterador = lista_iterador_crear(lista);
    if(!iterador){
        return resultado;
    }

    while(lista_iterador_tiene_siguiente(iterador)){
        printf("%c ", *(char*)lista_iterador_siguiente(iterador));
    }
    printf("\n");
    lista_iterador_destruir(iterador);

    for(int i=0;i<8;i++){
        lista_borrar(lista);
    }
    resultado = verificar_prueba(__func__, lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}

int DadaUnaLista_CuandoSeTieneUnIteradorNull_EntoncesIteradorSiguienteDevolveraNull(){

  int resultado = NO_PASO;
  lista_t* lista = lista_crear();
  if(!lista){
      return resultado;
  }
  int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4, elemento_5 = 5;

  lista_insertar(lista, &elemento_2);
  lista_insertar_en_posicion(lista, &elemento_1, 3);
  lista_insertar_en_posicion(lista, &elemento_2, 0);
  lista_insertar(lista, &elemento_5);
  lista_insertar(lista, &elemento_3);
  lista_insertar_en_posicion(lista, &elemento_2, 2);
  lista_insertar(lista, &elemento_4);

  lista_iterador_t* iterador = NULL;

  resultado = verificar_prueba(__func__, lista_iterador_siguiente(iterador)==NULL);

  lista_destruir(lista);
  return resultado;
}
int DadaUnaLista_CuandoSeTieneUnIteradorNull_EntoncesIteradorTieneSiguienteDevolveraFalse(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    int elemento_1 = 1, elemento_2 = 2, elemento_3 = 3, elemento_4 = 4;
    for(int i=0; i<5;i++){
        lista_insertar(lista, &elemento_1);
        lista_insertar(lista, &elemento_2);
        lista_insertar(lista, &elemento_3);
        lista_insertar(lista, &elemento_4);
    }
    lista_iterador_t* iterador = NULL;

    resultado = verificar_prueba(__func__, !lista_iterador_tiene_siguiente(iterador));

    lista_destruir(lista);
    return resultado;
}

int DadaUnaListaNull_CuandoSeQuiereCrearUnIteradorExterno_EntoncesIteradorCrearDevolveraNull(){

    lista_t* lista = NULL;

    int resultado = verificar_prueba(__func__, lista_iterador_crear(lista)==NULL);

    return resultado;
}

/*
 *Funcion de prueba para el iterador Interno.
*/
void mostrar_elemento(void* elemento){
  if(elemento)
    printf("%c ", *(char*)elemento);
}


int DadaUnaLista_CuandoSequiereRecorrerLaListaUltilizandoUniteradorInterno_EntoncesImprimiraPorpantallaLoCorrecto(){

    int resultado = NO_PASO;
    lista_t* lista = lista_crear();
    if(!lista){
        return resultado;
    }
    char a='a', l='l', g='g', o='o', r='r', i='i', t='t', m='m', s='s';
    lista_insertar(lista, &a);
    lista_insertar(lista, &l);
    lista_insertar(lista, &g);
    lista_insertar(lista, &o);
    lista_insertar(lista, &r);
    lista_insertar(lista, &i);
    lista_insertar(lista, &t);
    lista_insertar(lista, &m);
    lista_insertar(lista, &o);
    lista_insertar(lista, &s);


    lista_con_cada_elemento(lista, mostrar_elemento);
    printf("\n");

    for(int i=0;i<10;i++){
        lista_borrar(lista);
    }
    resultado = verificar_prueba(__func__, lista_vacia(lista));

    lista_destruir(lista);
    return resultado;
}
