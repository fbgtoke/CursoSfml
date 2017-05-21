Curso de programación de videojuegos con SFML
Sesión 5 - Gestión de escenas

El objetivo de esta sesión es crear una aplicación con diversas escenas entre las que el usuario puede transicionar.

/** ejemplo-1 **/
Este ejemplo muestra una escena con un menú principal. El menú consta de 3 opciones:
	1.- Comenzar a jugar
	2.- Sobre el autor
	3.- Salir de la aplicación

Por el momento, solo la última opción es funcional.

Nótese que, de querer implementar el resto de la aplicación (las opciones 1 y 2 mencionadas), el volumen del código crecería mucho dentro de la clase Game. Por tanto, es aconsejable distribuir los diversos bloques funcionales de la aplicación en sendas clases.


/** ejemplo-2 **/
Este ejemplo extiende el concepto abordado en el ejemplo-1. Se ha distribuído la carga de código en diversos módulos denominados escenas (Scene). La clase Game gestiona la escena activa y permite mantener una escena pausada. Esto puede ser útil para juegos donde se cambia de escena continuamente entre la escena principal y un menú auxiliar.

Las opciones 1 y 2 de la escena de menú principal conducen a las escenas test1 y test2 respectivamente. Al realizar la transición, la escena de menú principal queda pausada y se instancia la escena correspondiente. Aparecen en la linea de comandos algunos mensajes indicativos al realizarse las transiciones.

Exeprimente con diversas escenas y transiciones entre ellas.


/** ejercicio-1 **/
Implemente una aplicación SFML con 2 escenas cuya funcionalidad se describe a continuación:
	1.- Escena de menú principal con las opciones "Jugar" y "Salir" (o similar). Al seleccionar "Jugar", la aplicación debe cambiar de escena a la escena 2. Al seleccionar "Salir", la aplicación debe terminar.

	2.- Escena de juego. Esta escena es la recreación de la aplicación diseñada en el ejemplo-3 de la sesión 3, donde un personaje aparecía en pantalla y se desplazaba horizontalmente según las acciones del usuario (Quote).