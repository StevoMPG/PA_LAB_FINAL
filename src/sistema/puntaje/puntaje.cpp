////////////////////////////////////////////////////////////////

#include "../clases_cpp.h"

////////////////////////////////////////////////////////////////

Puntaje::Puntaje
(	Jugador*    const jugador
,	Videojuego* const videojuego
,	Valor       const valor
){
	this->jugador    = jugador    ;
	this->videojuego = videojuego ;
	this->valor      = valor      ;
}

////////////////////////////////////////////////////////////////