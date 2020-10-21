Para el tda hash se tomara en cuenta las siguientes convenciones:

Para poder compilar y ejecutar las pruebas debera ingresar con la siguiente linea de compilacion:
    gcc *.c -o hash -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
y luego:
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./hash


Las pruebas estan distribuidas en 4 partes: por un lado se testean las funciones del tda hash con parametros null,
luego se testean cuando el hash esta vacio(ej: cuando se llama a la funcion obtener, que sucede si el hash esta vacio),
luego se probara con pocos elementos, y por ultimo se haran pruebas del iterador externo.
En los 5 casos se testean casos bordes como normales donde se verifica el correcto funcionamiento de cada una de las fucniones del tda arbol.

Se eligio como criterio realizar un hash abierto y se opto como criterio del struct de hash tener un vector de listas, la capacidad del vector, un destructor de elementos
 y la cantidad de elementos insertados. Se eligio como factor de rehasheo (capacidad_de_elemetos/cantidad_de_elementos) menor a 2.
