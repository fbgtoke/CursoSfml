Curso de programación de videojuegos con SFML
Sesión 3 - Texturas, animaciones y otros recursos

Esta sesión tiene como objetivo crear una aplicación que cargue recursos como texturas o sonidos desde un sistema de ficheros. Además, se añadirá a la aplicación el control necesario para encadenar diversas texturas de manera que formen una animación.

/** ejemplo-1 **/
La librería SFML permite la gestión de recursos como texturas y pistas de audio. En este ejemplo se observa el procedimiento para cargar una textura y un audio desde el sistema de ficheros. Es importante notar:
	1.- La clase Texture representa la textura pero no el objeto a mostrar
	2.- El objeto que se muestra en pantalla pertenece a la clase Sprite. Sobre este objeto se pueden aplicar transformaciones
	3.- La instancia de la clase Sprite guarda una referencia a la textura que tiene asociada por lo que ésta debe permanecer en memoria y a la vista hasta que la instancia de la clase Sprite se destruya o cambie de textura
	4.- La ruta hacia los archivos de los recursos es relativa al directorio desde el que se ejecuta la aplicación


/** ejemplo-2 **/
Este ejemplo introduce una clase denominada AnimatedSprite. Su función es extender la clase Sprite de la librería SFML para hacer más fácil el uso de animaciones. El programa muestra una sencilla animación compuesta por 2 fotogramas.


/** ejemplo-3 **/
Se ha encapsulado todo el código referente al personaje mostrado en el ejemplo-2 en una clase denominada Quote. Además, se procesan ciertas acciones del usuario para permitir el movimiento del personaje a izquierda y derecha.

/** ejercicio-1 **/
Añada el código necesario a la clase Quote para implementar las siguientes funcionalidades:
	1.- El personaje tendrá dos velocidades de movimiento. La primera, igual a la del ejemplo-3. La segunda será más rápida y se activará mientras el usuario mantenga pulsada una tecla
	2.- La velocidad de la animación deberá cambiar de velocidad acorde con el movimiento del personaje

/** ejercicio-2 **/
Diseñe y cree una aplicación SFML de las siguientes características:
	1.- Ventana de tamaño predefinido
	2.- Aparece un personaje que puede moverse en las 4 direcciones cardinales
	3.- El usuario presiona las teclas direccionales para determinar hacia donde se mueve el personaje

Utilice la textura ethan.png u otra similar. Implemente las funcionalidades siguiendo los pasos vistos a lo largo de la sesión 3.