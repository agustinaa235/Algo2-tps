#include "pruebas_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO 0
#define ERROR -1
#define NO_PASO 0
#define PASO 1

extern char* strdup(const char*);

void destruir_string(void* elemento){
  if(elemento){
    free(elemento);
  }
}

void destruir_elemento(void* elemento){
    return;
}

int verificar_prueba(const char* nombre, bool estado){

    int resultado = NO_PASO;
    if(estado){
        printf("\n%s: PASO\n", nombre);
        resultado = PASO;
    }else{
        printf("\n%s: FALLO\n", nombre);
    }
    return resultado;
}

int DadoUnhashNull_CuandoSeQuiereInsertar_EntoncesDevolveraError(){

    hash_t* hash = NULL;

    const char* clave = "Agustina";
    char* elemento = "hoy miercoles fue a la facultad";

    int resultado = verificar_prueba(__func__, hash_insertar(hash, clave, (char*)&elemento)==ERROR);

    return resultado;
}

int DadoUnHashNull_CuandoSeQuiereBorrar_EntoncesDevolveraError(){

    hash_t* hash = NULL;

    const char* clave = "Agustina";

    int resultado = verificar_prueba(__func__, hash_quitar(hash, clave)==ERROR);

    return resultado;
}

int DadoUnHashNull_CuandoSeQuiereObtenerUnElemento_EntoncesDevolveraNull(){

    hash_t* hash = NULL;

    const char* clave = "Agustina";

    int resultado = verificar_prueba(__func__, hash_obtener(hash, clave)==NULL);

    return resultado;
}

int DadoUnHashNull_CuandoSeQuiereVerSiEstaUnElemento_EntoncesHashContieneDevolveraFalse(){

    hash_t* hash = NULL;

    const char* clave = "Agustina";

    int resultado = verificar_prueba(__func__, !hash_contiene(hash, clave));

    return resultado;
}

int DadoUnHashNull_CuandoSeQuiereVerLaCantidad_EntoncesLaCantidadSeraCero(){

    hash_t* hash = NULL;

    int resultado = verificar_prueba(__func__, hash_cantidad(hash)==0);

    return resultado;

}

int DadoUnHash_CuandoSeQuiereInsertarUnElementoConClaveNull_EntoncesDevolveraError(){

    int resultado = ERROR;
    hash_t* hash = hash_crear(destruir_elemento, 3);
    if(!hash){
        return resultado;
    }
    const char* clave = NULL;
    int elemento = 1;

    resultado = verificar_prueba(__func__, hash_insertar(hash, clave, &elemento)==ERROR);

    hash_destruir(hash);
    return resultado;
}
int DadoUnHash_CuandoSeQuiereInsertarUnElementoNullConClaveDistintaANull_EntoncesDevolveraExito(){

    int resultado = ERROR;
    hash_t* hash = hash_crear(destruir_elemento, 3);
    if(!hash){
        return resultado;
    }
    const char* clave = "Agustina";
    void* elemento = NULL;

    resultado = verificar_prueba(__func__, hash_insertar(hash, clave, elemento)==EXITO);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHashVacio_CuandoSeQuiereInsertar_EntoncesDevolveraExito(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave = "Agustina";
    const char* elemento = "Hoy miercoles fui a la facultad";

    resultado = verificar_prueba(__func__, hash_insertar(hash, clave, strdup(elemento))==EXITO);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHashVacio_CuandoSeQuiereBorrar_EntoncesDevolveraError(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave = "Agustina";

    resultado = verificar_prueba(__func__, hash_quitar(hash, clave)==ERROR);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHashVacio_CuandoSeQuiereObtenerUnElemento_EntoncesDevolveraNull(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave = "Agustina";

    resultado = verificar_prueba(__func__, hash_obtener(hash, clave)==NULL);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHashVacio_CuandoSeQuiereVerLaCantidad_EntoncesEstaSeraCero(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }

    resultado = verificar_prueba(__func__, hash_cantidad(hash)==0);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHashVacio_CuandoSeQuiereVerSiUnElementoEsta_EntoncesDevolveraFalse(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave = "Agustina";

    resultado = verificar_prueba(__func__, !hash_contiene(hash, clave));

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoSeQuiereInsertarpocosElementos_EntoncesLosInsertaraAtodosCorrectamente(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";
    const char* clave5 = "Albert";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";
    char* elemento4 = "Esta cosinando";
    char* elemento5 = "Esta Durmiendo";

    int cantidad_elementos_a_insertar = 5;
    int elementos_insertados = 0;

    elementos_insertados+= hash_insertar(hash, clave1, strdup(elemento1));
    elementos_insertados+= hash_insertar(hash, clave2, strdup(elemento2));
    elementos_insertados+= hash_insertar(hash, clave3, strdup(elemento3));
    elementos_insertados+= hash_insertar(hash, clave4, strdup(elemento4));
    elementos_insertados+= hash_insertar(hash, clave5, strdup(elemento5));

    resultado = verificar_prueba(__func__, elementos_insertados == 0 && hash_cantidad(hash) == cantidad_elementos_a_insertar);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoSeQuiereBuscarUnElementoYaInsertado_EntoncesHashContienDevolveraTrue(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";
    const char* clave5 = "Albert";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";
    char* elemento4 = "Esta cosinando";
    char* elemento5 = "Esta Durmiendo";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave2, strdup(elemento2));
    hash_insertar(hash, clave3, strdup(elemento3));
    hash_insertar(hash, clave4, strdup(elemento4));
    hash_insertar(hash, clave5, strdup(elemento5));

    resultado = verificar_prueba(__func__, hash_contiene(hash, clave3));

    hash_destruir(hash);
    return resultado;
}

int DadoUnhash_CuandoSeQuiereBuscarUnElementoYaInsertado_EntoncesHashObtenerDevolveraEseElemento(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";
    const char* clave5 = "Albert";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";
    char* elemento4 = "Esta cosinando";
    char* elemento5 = "Esta Durmiendo";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave2, strdup(elemento2));
    hash_insertar(hash, clave3, strdup(elemento3));
    hash_insertar(hash, clave4, strdup(elemento4));
    hash_insertar(hash, clave5, strdup(elemento5));

    resultado = verificar_prueba(__func__, strcmp(hash_obtener(hash, clave5), elemento5)==0);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoInsertoPocosElementos_EntoncesLaCantidadSeraLaCorrecta(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_elemento, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";
    const char* clave5 = "Albert";

    int elemento1 = 1, elemento2 = 2, elemento3 = 3, elemento4 = 4, elemento5 = 5;

    hash_insertar(hash, clave1, &elemento1);
    hash_insertar(hash, clave2, &elemento2);
    hash_insertar(hash, clave3, &elemento3);
    hash_insertar(hash, clave4, &elemento4);
    hash_insertar(hash, clave5, &elemento5);

    resultado = verificar_prueba(__func__, hash_cantidad(hash) == 5);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoBuscoUnElementoQueNoEsta_EntoncesContieneDevolveraFalse(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave2, strdup(elemento2));
    hash_insertar(hash, clave3, strdup(elemento3));

    resultado = verificar_prueba(__func__, !hash_contiene(hash, clave4));

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoBuscoUnElementoQueNoEsta_EntoncesHashObtenerDevolveraNull(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave2, strdup(elemento2));
    hash_insertar(hash, clave3, strdup(elemento3));

    resultado = verificar_prueba(__func__, hash_obtener(hash, clave4)==NULL);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoInsertoUnElementoYLuegoLoBorro_EntoncesHashContieneDevolveraFalse(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";
    const char* clave5 = "Albert";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";
    char* elemento4 = "Esta cosinando";
    char* elemento5 = "Esta Durmiendo";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave2, strdup(elemento2));
    hash_insertar(hash, clave3, strdup(elemento3));
    hash_insertar(hash, clave4, strdup(elemento4));
    hash_insertar(hash, clave5, strdup(elemento5));

    hash_quitar(hash, clave2);

    resultado = verificar_prueba(__func__, !hash_contiene(hash, clave2));

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoInsertoUnElementoYLuegoLoBorro_EntoncesHashObtenerDevolveraNull(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";
    const char* clave5 = "Albert";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";
    char* elemento4 = "Esta cosinando";
    char* elemento5 = "Esta Durmiendo";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave2, strdup(elemento2));
    hash_insertar(hash, clave3, strdup(elemento3));
    hash_insertar(hash, clave4, strdup(elemento4));
    hash_insertar(hash, clave5, strdup(elemento5));

    hash_quitar(hash, clave2);

    resultado = verificar_prueba(__func__, hash_obtener(hash, clave2)==NULL);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoIntertoyBorroLaMismaCantidadDeElementos_EntoncesLaCantidadFinalSeraCero(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Roberto";
    const char* clave3 = "Mauricio";
    const char* clave4 = "Sofia";
    const char* clave5 = "Albert";

    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";
    char* elemento3 = "Esta estudiando para el parcial";
    char* elemento4 = "Esta cosinando";
    char* elemento5 = "Esta Durmiendo";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave2, strdup(elemento2));
    hash_insertar(hash, clave3, strdup(elemento3));
    hash_insertar(hash, clave4, strdup(elemento4));
    hash_insertar(hash, clave5, strdup(elemento5));
    hash_quitar(hash, clave1);
    hash_quitar(hash, clave2);
    hash_quitar(hash, clave3);
    hash_quitar(hash, clave4);
    hash_quitar(hash, clave5);

    resultado = verificar_prueba(__func__, hash_cantidad(hash) == 0);

    hash_destruir(hash);
    return resultado;
}


int DadoUnHash_CuandoInsertoDosElementosConLaMismaClave_EntoncesElElementoSeModificaraPorElSegundo(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_string, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    char* elemento1 = "Se esta baniando";
    char* elemento2 = "Salio a pasear al perro";

    hash_insertar(hash, clave1, strdup(elemento1));
    hash_insertar(hash, clave1, strdup(elemento2));

    resultado = verificar_prueba(__func__, strcmp(hash_obtener(hash,clave1), elemento2)==0);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHashNull_CuandoSeLoQuiereRecorerConUnIteradorExterno_EntoncesCrearDevolveraNull(){

    int resultado = NO_PASO;
    hash_t* hash = NULL;

    resultado = verificar_prueba(__func__, hash_iterador_crear(hash)==NULL);

    return resultado;
}

int DadoUnHash_CuandoSeLoQuiereRecorrerConUnIteradorExternoNull_EntocesHashTieneSigueinteDevolveraFalse(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_elemento, 4);
    if(!hash){
        return resultado;
    }
    hash_iterador_t* iterador = NULL;
    resultado = verificar_prueba(__func__, !hash_iterador_tiene_siguiente(iterador));

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoSeLoQuiereIterarConUnIteradorExternoNull_EntoncesHashSiguienteDevolveraNull(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_elemento, 4);
    if(!hash){
        return resultado;
    }
    hash_iterador_t* iterador = NULL;
    resultado = verificar_prueba(__func__, hash_iterador_siguiente(iterador)==NULL);

    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoSeIteradaConUnIteradorExterno_EntoncesImprimiraPorPantallaLoCorrecto(){

    int resultado = NO_PASO;
    hash_t* hash = hash_crear(destruir_elemento, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Agustina";
    const char* clave2 = "Pepito";
    const char* clave3 = "Lucas";
    const char* clave4 = "Manuela";
    const char* clave5 = "Florencia";

    int elemento1 = 42773503, elemento2 = 40775662, elemento3 = 41993567, elemento4 = 43667543, elemento5 = 40455324;

    hash_insertar(hash, clave1, &elemento1);
    hash_insertar(hash, clave2, &elemento2);
    hash_insertar(hash, clave3, &elemento3);
    hash_insertar(hash, clave4, &elemento4);
    hash_insertar(hash, clave5, &elemento5);

    hash_iterador_t* iterador = hash_iterador_crear(hash);
    size_t listados = 0;
    if(!iterador){
        hash_destruir(hash);
        return resultado;
    }
    printf("\n");
    while(hash_iterador_tiene_siguiente(iterador)){
        const char* clave = hash_iterador_siguiente(iterador);
        if(clave){
            listados++;
            printf("Clave: %s -- elemento: %i\n", clave, *(int*)hash_obtener(hash, clave));
        }
    }
    resultado = verificar_prueba(__func__, listados == hash_cantidad(hash));
    hash_iterador_destruir(iterador);
    hash_destruir(hash);

    return resultado;
}

int DadoUnHash_CuandoEstoyEnElPrimerElementoDelHash_EntoncesTieneSiguenteDevolverTrue(){

    int resultado = ERROR;
    hash_t* hash = hash_crear(destruir_elemento, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Juliana";
    const char* clave2 = "Julio";
    const char* clave3 = "Marcos";
    const char* clave4 = "Maylen";
    const char* clave5 = "Azul";

    int elemento1 = 1111, elemento2 = 33333, elemento3 = 22222, elemento4 = 55555, elemento5 = 888888;

    hash_insertar(hash, clave1, &elemento1);
    hash_insertar(hash, clave2, &elemento2);
    hash_insertar(hash, clave3, &elemento3);
    hash_insertar(hash, clave4, &elemento4);
    hash_insertar(hash, clave5, &elemento5);

    hash_iterador_t* iterador = hash_iterador_crear(hash);
    if(!iterador){
        hash_destruir(hash);
        return resultado;
    }
    hash_iterador_tiene_siguiente(iterador);

    resultado = verificar_prueba(__func__, hash_iterador_tiene_siguiente(iterador));

    hash_iterador_destruir(iterador);
    hash_destruir(hash);
    return resultado;
}

int DadoUnHash_CuandoEstoyEnElUltimoElemento_EntoncesTieneSiguienteDevolveraFalse(){

    int resultado = ERROR;
    hash_t* hash = hash_crear(destruir_elemento, 3);
    if(!hash){
        return resultado;
    }
    const char* clave1 = "Susana Gimenez";
    const char* clave2 = "Marcelo Tinelli";
    const char* clave3 = "Ricardo Ford";
    const char* clave4 = "Sol Perez";
    const char* clave5 = "Mirtha Legrand";

    int elemento1 = 18567435, elemento2 = 20296017, elemento3 =29456372, elemento4 = 38567489, elemento5 = 00000001;

    hash_insertar(hash, clave1, &elemento1);
    hash_insertar(hash, clave2, &elemento2);
    hash_insertar(hash, clave3, &elemento3);
    hash_insertar(hash, clave4, &elemento4);
    hash_insertar(hash, clave5, &elemento5);

    hash_iterador_t* iterador = hash_iterador_crear(hash);
    if(!iterador){
        hash_destruir(hash);
        return resultado;
    }
    int i =0;
    while(i < hash_cantidad(hash)){
        hash_iterador_tiene_siguiente(iterador);
        printf("%s\n", (char*)hash_iterador_siguiente(iterador));
        i++;
    }

    resultado = verificar_prueba(__func__, !hash_iterador_tiene_siguiente(iterador));

    hash_iterador_destruir(iterador);
    hash_destruir(hash);
    return resultado;
}
