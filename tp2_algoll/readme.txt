Para el tp2 se tomaron en cuenta los siguientes criterios:

Para compilarlo ingrese la linea:
gcc *.c -o westeros -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
seguido por:
valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./westeros

Para el tp decidi crear una estructura que se llame westeros donde alli tendre la informacion del juego, se tendra
 el arbol de casas, la cola de casas extintas y la cantidad de casas que se posee en westeros.

* Con respecto a las cuestios de agregar casa, se iran agregando teniendo en cuenta el
  nombre de la casa.

* Con respecto a la funcion simular, simulara los anios ingresados por el usuario y Devolvera
  un puntero a la casa ganadora, si en trascurro de la simulacion se extingieron todas las casas
  o si el usuario decide simulr sin antes haber agregado casas al arbol se devulelve null implicando
  que no hubo casa ganadora.
  En simular se iran:

    *Actualizando las personas donde si llegan a la edad de 60 inclusive ya estan muertas y son eliminadas de las lista.
    Si una casa se queda vacia justo despues de verificar la edad pasa a colas de casas extintas y se eliminara la memoria
    de esa casa mas tarde.
    * Con respecto a los nacimientos iran naciendo personas teniendo en cuenta el factor de nacimiento. A estas PERSONAS
    se las ira leyendo de un archivo propio con el nombre y la edad inicial(cero).
    * Al obtener la casa ganadora se decidio que la primer casa de arbol sea la gandora y que a medida que se van trascurriendo
    los anios se va a ir actualizando de acuedo a la cantidad de miembros de la casa. Si la casa ganadora posee la mismca cantidad
    de miembros con la que se esta comprarando se elije como ganadora la que ya estaba antes.

* Con respecto al mostrar las casas extintas, se iran imprimiendo a medida de que se extinguieron y una vez que se mostraron
las casas extintas cuando se ingreso ese comando, si el usuario decide volver a simular, esas casas seran como si nunca extistieron.
Solo se muestran una vez.

* Con respecto a listar las casas pertenecientes a westeros, se mostraran de mayor a menor teniendo en cuenta la cantidad de
miembros por casa.

*Con respecto a destruir, se ira eliminando toda la memoria correspondiente. Se ira elimando a cada persona de la lista, y
cada casa. Luego se eliminarana las correspondientes estructuras.
