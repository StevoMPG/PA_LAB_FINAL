////////////////////////////////////////////////////////////////

#include "../clases_cpp.h"

////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////

#include "../clases.h"

////////////////////////////////////////////////////////////////

Partida::Partida
(	::Jugador*  const jugador
,	Videojuego* const videojuego
,	Fecha       const fecha
){
	this->id         = Generar_Id<Partida>()  ;
	this->jugador    = jugador                ;
	this->videojuego = videojuego             ;
	this->fecha      = fecha                  ;
}

::Jugador* Partida::Jugador () { return this->jugador; }

int Partida::Id () { return id; }

////////////////////////////////////////////////////////////////

Individual::Individual
(	::Jugador*  const jugador
,	Videojuego* const videojuego
,	Fecha       const fecha
,	Individual* const continua
) : Partida( jugador, videojuego, fecha )
{
	this->continua = continua;
}

////////////////////////////////////////////////////////////////

Multijugador::Multijugador
(	::Jugador*   const jugador
,	Videojuego*  const videojuego
,	Fecha        const fecha
,	bool         const transmitida
,	IDictionary* const unidos
) : Partida( jugador, videojuego, fecha )
{
	this->transmitida = transmitida             ;
	this->unidos      = unidos                  ;
	this->abandona    = new OrderedDictionary() ;
}

IDictionary* Multijugador::Abandona () { return this->abandona ; }
IDictionary* Multijugador::Unidos   () { return this->unidos   ; }

////////////////////////////////////////////////////////////////

Abandona::Abandona
(	Jugador* const jugador
,	Fecha    const fecha
){
	this->jugador = jugador ;
	this->fecha   = fecha   ;
}

////////////////////////////////////////////////////////////////