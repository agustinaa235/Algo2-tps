Para el tda pila se tomara en cuenta las siguientes convenciones:

*Para el pila.c al crear la pila se inicializa su tamanio con 2 que es el tamanio minimo que puede tener la pila.Cuando se quiere redimencionar la convencio que se
tomo fue que cuando la cantidad de elementos apilada es igual al tamanio de mi pila que se redimencione el doble de tamanio de la pila. Cuando se quiere desapilar solo
se redimencionara si el tamanio de mi pila es mayor que el minimo y si mi mi cantidad de elementos es cuatro veces menor que mi tamnio de la pila.
En la funcion redimencionar, si el nuevo tamanio recibido es menor que el minimo establecio, entonces el nuevo tamanio sera el tamanio minimo.

* Con respecto a las pruebas realizadas sobre el tda pila, se tomaron las siguiente convenciones:
*formato: el nombre de las funciones de prueba poseen el formato de dado(una situacion incial) cuando(sucede algun hecho) entonces(pasara el comportamiento adecuado de cada funcion).
          En las pruebas se incializa un resultado inical en 0 y si pasa la prueba devolvera 1.
          Primero se inicializaran los datos conrespondientes, luego se llamara a las funciones determinadas a testear probando y
          si esas funciones cumplen con lo establecido la prubeda devolvera 1.
*testing: los casos que se tomaron en cuenta para testiar fueron bordes o normales. Como casos bordes se encuentra entre ellos
          cuando la pila esta vacia, cuando la pila es null, cuando se quiere ver que redimencione el vector, prueba de volumen, etc.
          A su vez se testearon casos normales donde se apilen y desapilen elementos de la pila.
          En ambos casos de testing, tanto como los bordes como los normales, se comprueba que las funciones llamadan cumplan con el contrato
          establecito en  pila.h y su correcto funcionamiento de cada una.
*compilacion: la linea de compilacion es:
              gcc *.c -o pila_vd -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
              y luego:
               valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pila_vd
