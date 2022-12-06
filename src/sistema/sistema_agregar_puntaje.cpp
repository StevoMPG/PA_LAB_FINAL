////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Puntaje
(	Dt_Puntaje const dt_puntaje
){
	auto const jugador    = Buscar_Jugador    ( dt_puntaje.jugador    );
	auto const videojuego = Buscar_Videojuego ( dt_puntaje.videojuego );
	auto const valor      = dt_puntaje.valor;
	auto const puntaje    = new Puntaje( jugador, videojuego, valor );

	jugador    -> Agregar_Puntaje( puntaje, dt_puntaje.videojuego );
	videojuego -> Agregar_Puntaje( puntaje, dt_puntaje.jugador    );
}

////////////////////////////////////////////////////////////////