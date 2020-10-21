#ifndef __HOTEL_H__
#define __HOTEL_H__

#include <stdbool.h>

#define MAX_NOMBRE 100
#define MAX_HABITACIONES 100

typedef struct huesped{
	int dni;
	char nombre[MAX_NOMBRE];
	bool es_vip;
} huesped_t;

typedef struct habitacion_t{
	int numero;
	huesped_t huesped;
	int ocupada;
} habitacion_t;

typedef struct hotel{
	habitacion_t habitaciones[MAX_HABITACIONES];
	int cantidad_habitaciones;
	int ocupacion;
	int cantidad_quejas;
} hotel_t;

/*
 * Crea un hotel reservando la memoria para el y lo devuelve.
 */
hotel_t* hotel_crear();

/*
 * Chekinea un huesped, devuelve 0 si pudo o 1 si no pudo.
 */
int hotel_entrar(hotel_t* hotel, huesped_t huesped);

/*
 * Chekoutea un huesped, devuelve 0 si pudo o 1 si no pudo.
 */
int hotel_salir(hotel_t* hotel, huesped_t huesped);

/*
 * Destrye el hotel.
 */
void hotel_destruir(hotel_t* hotel);

/*
 * Muestra las habitaciones del hotel.
 */
void hotel_mostrar(hotel_t* hotel);

#endif /*__HOTEL_H__*/
