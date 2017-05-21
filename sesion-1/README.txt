Curso de programación de videojuegos con SFML
Sesión 1 - Bucle principal, Ventana SFML y gestión básica de eventos

Esta sesión tiene como objetivo hacer un programa sencillo que cree una ventana y responda al input del usuario.

En el directorio src se encuentra el código fuente de todos los ejemplos y los esqueletos de los ejericios propuestos. El archivo Makefile, presente en este mismo directorio, contiene las directivas necesarias para compilar los programas en src y almacenar los ejecutables resultantes en el directorio bin.

/** ejemplo-1 **/
Este programa crea, inicializa y muestra una ventana SFML vacía. Nótese la estructura del programa:
	1.- Inicialización
	2.- Bucle principal

Cada iteración del bucle while presente en la linea 18 representa un fotograma, o paso, del juego. A lo largo del curso se definirán las acciones que ocurren dentro de este bucle. Por el momento, es importante observar la necesidad del mismo para mantener el programa en ejecución.


/** ejemplo-2 **/
Similar al ejemplo anterior, este ejemplo muestra una ventana. Esta vez se dibuja sobre ella un círculo blanco. Nótese el proceso seguido para mostrar el contenido de la ventana:
	1.- window.clear(...) -> Borra todo el contenido previo en la ventana
	2.- window.draw(...)  -> Dibuja el objeto pasado como parámetro
	3.- window.display()  -> Muestra el estado actual de la ventana

Se invita al lector a jugar con los colores de fondo y de la figura así como a cambiar la figura a dibujar.


/** ejemplo-3 **/
Este programa introduce un nuevo elemento al bucle principal. El bucle while interno procesará todos los eventos pendientes del usuario a cada iteración del programa. Nótese la necesidad de este proceso, pues es el mecanismo por el cual se pueden conocer las acciones del usuario y contestar a ellas.

Por el momento, el único evento procesado es el que se emite cuando el usuario hace click sobre el botón de cerrar ventana, x. Hasta ahora, el programa no respondía al usuario y debía terminarse forzosamente a través de la linea de comandos.

La documentación oficial de SFML incluye el listado y descripción de todos los eventos que la librería puede capturar.


/** ejemplo-4 **/
Se han añadido 4 eventos nuevos al cuerpo del bucle while interno que se corresponden a la acción del usuario de pulsar una de las teclas de dirección. Por ahora, se muestra un mensaje por terminal en el momento de detección del evento.