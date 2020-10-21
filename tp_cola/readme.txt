Para el tda lista se tomara en cuenta las siguientes convenciones:

Para poder compilar y ejecutar las pruebas debera ingresar con la siguiente linea de compilacion:
    gcc *.c -o lista -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
y luego:
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista

Se eligio como criterio del struct de lista tener una referencia al inicio y una al final para que funciones como insertar al final,
lista ultimo sean O(1), asi se evitaba recorrer la lista hasta el final. los mismo sucede con insertar al inicio.

Las pruebas estan distribuidas en 5 partes: por un lado se testean las funciones del tda lista con parametros null,
luego se testean cuando la lista esta vacia(ej: cuando se llama a la funcion borrar que sucede cuando la lista viene vacia),
luego se probara con pocos elementos, con muchos elementos y lego se haran pruebas de los iteradores, tanto para el interno como el externo.
En los 5 casos se testean casos bordes como normales donde se verifica el correcto funcionamiento de cada una de las fucniones del tda lista.
