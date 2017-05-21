#include "ejemplo-4-game.hpp"

/**
  Ejemplo 4 - Canica
  Muestra una canica en movimiento
  El objeto se desplaza siguiendo el modelo de movimiento rectinileo 
  uniformemente acelerado
  A modo de simplificacion, la simulacion no incluye el calculo de friccion con 
  el aire y los choques contra los bordes de la ventana provocan que pierda 
  aceleracion de manera estatica mediante una constante definida
*/
int main(int arg, char* argv[]) {
  Game game;
  game.run();

  return 0;
}
