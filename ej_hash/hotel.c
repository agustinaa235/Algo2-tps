#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hotel.h"

#define INICIO_VIP 90
#define INICIO_BUFFER_COMUN 80

hotel_t* hotel_crear(){
	hotel_t* hotel = calloc(1,sizeof(hotel_t));
	hotel->cantidad_habitaciones = MAX_HABITACIONES;
	hotel->ocupacion = 0;
	hotel->cantidad_quejas = 0;
	for (int i = 0; i < hotel->cantidad_habitaciones; i++)
		hotel->habitaciones[i].ocupada = 0;

	return hotel;
}

int jashiar(huesped_t huesped){
	if(huesped.es_vip){
		int algo = huesped.dni%10;
		return INICIO_VIP+algo;
	}
	return huesped.dni%INICIO_BUFFER_COMUN;
}

int obtener_habitacion_libre(hotel_t* hotel, huesped_t huesped){
	if(huesped.es_vip){
		int habitacion_inicial = jashiar(huesped);
		int habitacion = habitacion_inicial+1;

		if(habitacion >= MAX_HABITACIONES) habitacion = INICIO_VIP;

		while(hotel->habitaciones[habitacion].ocupada == 1 && habitacion != habitacion_inicial)
			if(++habitacion >= MAX_HABITACIONES) habitacion = INICIO_VIP;

		if(habitacion != habitacion_inicial)
			return habitacion;
	}

	int habitacion = INICIO_BUFFER_COMUN;
	while(hotel->habitaciones[habitacion].ocupada == 1 && habitacion < INICIO_VIP)
			habitacion++;

	if(habitacion < INICIO_VIP)
		return habitacion;

	return -1;
}

int hotel_entrar(hotel_t* hotel, huesped_t huesped){
	int habitacion = jashiar(huesped);

	int colision = hotel->habitaciones[habitacion].ocupada;

	if(colision==1)
		habitacion = obtener_habitacion_libre(hotel, huesped);

	if(huesped.es_vip && habitacion<INICIO_VIP)
		hotel->cantidad_quejas++;

	if(habitacion<0){
		if(huesped.es_vip)
			hotel->cantidad_quejas++;
		return -1;
	}

	hotel->habitaciones[habitacion].huesped = huesped;
	hotel->habitaciones[habitacion].ocupada = 1;
	hotel->ocupacion++;

	return 0;
}

int hotel_salir(hotel_t* hotel, huesped_t huesped){
	return 0;
}

void hotel_destruir(hotel_t* hotel){
	free(hotel);
}

void hotel_mostrar(hotel_t* hotel){
	for (int i = 0; i < hotel->cantidad_habitaciones; i++){
		//if (i%10 == 0 && i > 0) printf("\n============= PISO %i =============\n", ((i/10)%10)-1);
		if (i%10 == 0) printf("\n\n============= PISO %i =============", ((i/10)%10));
		if (i%5 == 0) printf("\n");
		if (hotel->habitaciones[i].ocupada == 1) {
			printf("%i-%c ", hotel->habitaciones[i].huesped.dni, hotel->habitaciones[i].huesped.es_vip?'S':'N');
		} else{
			printf("____-_ ");
		}
	}
	//printf("\n============= PISO 9 =============\n");
	printf("\n\n");
	printf("Cantidad quejas: %i\n\n", hotel->cantidad_quejas);
}
