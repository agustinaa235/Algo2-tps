Para el tda abb se tomara en cuenta las siguientes convenciones:

Para poder compilar y ejecutar las pruebas debera ingresar con la siguiente linea de compilacion:
    gcc *.c -o arbol -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
y luego:
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./arbol


Las pruebas estan distribuidas en 5 partes: por un lado se testean las funciones del tda arbol con parametros null,
luego se testean cuando el arbol esta vacio(ej: cuando se llama a la funcion borrar que sucede cuando el arbol esta vacio),
luego se probara con pocos elementos, y luego se haran pruebas del iterador y de los recooridos. y pruebas de implementacion.
En los 5 casos se testean casos bordes como normales donde se verifica el correcto funcionamiento de cada una de las fucniones del tda arbol.
