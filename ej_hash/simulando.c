#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hotel.h"

int main(){
	hotel_t* hotel = hotel_crear();

	srand ((unsigned)time(NULL));
	int aleatorio;
	for (int i = 0; i < 50; i++){
		aleatorio = rand() % 9000 + 1000;
		huesped_t huesped;
		huesped.dni = aleatorio;
		sprintf((char*)huesped.nombre, "%i", aleatorio);
		huesped.es_vip = !(rand()%5);
		hotel_entrar(hotel, huesped);
	}

	hotel_mostrar(hotel);

	hotel_destruir(hotel);
	return 0;
}
