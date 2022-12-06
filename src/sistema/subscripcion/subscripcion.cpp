////////////////////////////////////////////////////////////////

#include "../clases_cpp.h"

////////////////////////////////////////////////////////////////

Subscripcion::Subscripcion
(	Usuario*    const jugador
,	Videojuego* const videojuego
,	Tipo        const tipo
,	Pago        const pago
,	Fecha       const fecha
){
	this->jugador    = jugador    ;
	this->videojuego = videojuego ;
	this->tipo       = tipo       ;
	this->pago       = pago       ;
	this->fecha      = fecha      ;
}

////////////////////////////////////////////////////////////////