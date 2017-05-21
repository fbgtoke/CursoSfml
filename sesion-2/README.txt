Curso de programación de videojuegos con SFML
Sesión 2 - Mejora del bucle principal y físicas sencillas

Esta sesión tiene como objetivo crear una simulación simplificada de uno o varios cuerpos afectados por gravedad.

/** ejemplo-1 **/
Este programa añade un proceso al bucle principal que se encarga de gestionar la lógica del estado actual de la aplicación. Por el momento, se muestra por linea de comandos el tiempo total transcurrido desde el inicio de la ejecución a cada iteración del bucle.


/** ejemplo-2 **/
Nótese el creciente volumen del código. Para propiciar una gestión eficiente del programa, es aconsejable distribuirlo en diversos módulos. Por el momento, se muestran las diversas secciones funcionales de la aplicación en sendas funciones:
	1.- Inicialización     -> init()
	2.- Lógica de estado   -> update()
	3.- Lógica de dibujo   -> draw()
	4.- Gestión de eventos -> events()


/** ejemplo-3 **/
C++ es un lenguaje de programación orientado a objetos. Por tanto, es buena práctica hacer uso de las técnicas de modelado mediante objetos para estructurar el código de una aplicación. Este ejemplo toma el código de los anteriores y lo encapsula en una clase denominada Game.


/** ejemplo-4 **/
Esta ejemplo muestra una canica en movimiento dentro de la ventana. Ésta sigue el modelo de movimiento rectinileo uniformememente acelerado con ciertas simplificaciones. La simulación no es estricta y se ha implementado siguiendo un modelo muy simplificado.

Nótese el cálculo de las componentes de posición y velocidad a cada iteración del bucle principal. Cabe destacar como se utiliza una expresión dependiente del tiempo. Esta expresión computa los resultados a partir de un incremento relativo en el tiempo tomando como punto de referencia la iteración anterior.

El código del proceso de la lógica de estado incluye otras condiciones de control para evitar que el cuerpo salga del espacio de la ventana.

Se insta al lector a cambiar el valor de las constantes definidas dentro de la implementación de la clase canica y observar los resultados en el momento de la ejecución.

/** ejercicio-1 **/
Siguiendo la implementación de movimiento del ejercicio-2 de la sesión anterior y el modelo de simulación del ejemplo-4 de esta sesión, añada al programa el código necesario para implementar:
	1.- Una clase Player (jugador)
	2.- Una instancia de la clase Player debe visualizarse de algún modo (cuadrado u otra figura sencilla)
	3.- Una instancia de la clase Player debe desplazarse horizontalmente bajo demanda del usuario (como el ejercicio-2 de la sesión anterior)
	4.- Una instancia de la clase Player puede realizar la acción de saltar si se encuentra en el suelo (siguiendo el modelo implementado en el ejemplo-4)