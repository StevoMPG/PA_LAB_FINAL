////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Partida_Individual
(	Dt_Individual* const dt_individual
){
	auto const jugador    = Buscar_Jugador    ( dt_individual->jugador    );
	auto const videojuego = Buscar_Videojuego ( dt_individual->videojuego );
	auto const continua   = Buscar_Individual ( dt_individual->continua   );
	auto const fecha      = dt_individual->fecha;
	auto const partida    = new Individual( jugador, videojuego, fecha, continua );
	auto const id         = partida->Id();

	this->partidas       -> add( new Integer( id ), partida );
	this->individuales   -> add( new Integer( id ), partida );
	jugador->Iniciadas() -> add( new Integer( id ), partida );
}

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Partida_Multijugador
(	Dt_Multijugador* const dt_multijugador
){
	auto const jugador     = Buscar_Jugador    ( dt_multijugador->jugador    );
	auto const videojuego  = Buscar_Videojuego ( dt_multijugador->videojuego );
	auto const unidos      = Buscar_Jugadores  ( dt_multijugador->unidos       );
	auto const fecha       = dt_multijugador->fecha;
	auto const transmitida = dt_multijugador->transmitida;
	auto const partida     = new Multijugador( jugador, videojuego, fecha, transmitida, unidos );
	auto const id          = partida->Id();

	this->partidas       -> add( new Integer( id ), partida );
	this->multijugador   -> add( new Integer( id ), partida );
	jugador->Iniciadas() -> add( new Integer( id ), partida );

	Util::Foreach( unidos,
		[ & ] ( ICollectible* const current )
		{
			auto const jugador = dynamic_cast<Jugador*>( current );
			jugador->Unidas()->add( new Integer( id ), partida );
		}
	);
}

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Partida
(	Dt_Partida* const dt_partida
){
	if( auto const dt_individual = dynamic_cast<Dt_Individual*>( dt_partida ) )
		Agregar_Partida_Individual( dt_individual );
	else
	if( auto const dt_multijugador = dynamic_cast<Dt_Multijugador*>( dt_partida ) )
		Agregar_Partida_Multijugador( dt_multijugador );
}

////////////////////////////////////////////////////////////////