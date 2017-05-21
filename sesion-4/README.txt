Curso de programación de videojuegos con SFML
Sesión 4 - Eventos de teclado y menús

Esta sesión tiene como objetivo desarrollar pantallas de menú para un juego. Se utilizan los eventos de la librería SFML para ello.

/** ejemplo-1 **/
Este ejemplo muestra la funcionalidad básica que ofrece SFML para procesar eventos de ratón. La aplicación muestra por linea de comandos el botón del ratón que se ha pulsado y su posición relativa al origen de la ventana.


/** ejemplo-2 **/
El programa muestra un rectángulo verde en pantalla. Cuando el usuario hace click izquerdo sobre él, aparece un mensaje por linea de comandos.


/** ejercicio-1 **/
Diseñe y cree una aplicación con las siguientes funcionalidades:
	1.- Ventana de tamaño predefinido
	2.- Aparece un personaje que puede moverse a derecha e izquierda. Utilice la textura quote-2.png.
	3.- La animación del personaje debe ser acorde con su movimiento
	4.- Aparecen dos botones en la parte inferior de la ventana. Utilice la textura arrows.png.
	5.- El usuario hace click sobre los botones para hacer que el personaje comience a desplazarse en la dirección respectiva.

Puede utilizar el código del ejemplo-3 de la sesión 3 como soporte para implementar el movimiento del personaje.


/** ejemplo-3 **/
Este ejemplo muestra una escena con algunos elementos interactuables. Al hacer click sobre estos elementos, desaparecen y se añade un punto a la puntuación del jugador. La puntuación aparece en la esquina inferior iquierda.


/** ejercicio-2 **/
Diseñe y cree una aplicación con las siguientes funcionalidades:
	1.- Ventana de tamaña predefinido
	2.- Aparece una instancia de la clase Tilemap con un tamaño predefinido
	3.- Aparece una paleta de tiles a un lado de la ventana
	4.- El usuario selecciona una tile de la paleta haciendo click sobre ella
	5.- Una vez seleccionada, el usuario hace click sobre un lugar del mapa y se aplica la tile sobre el lugar seleccionado