////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

void Sistema::Abandonar_Partida
(	Dt_Abandona const dt_abandona
){
	auto const jugador     = Buscar_Jugador      ( dt_abandona.jugador ) ;
	auto const partida     = Buscar_Multijugador ( dt_abandona.partida ) ;
	auto const email       = dt_abandona.jugador                         ;
	auto const fecha       = dt_abandona.fecha                           ;
	auto const abandona    = new Abandona ( jugador, fecha )             ;
	auto const key_jugador = new String   ( email.c_str() )              ;
	auto       key_partida =     Integer  ( dt_abandona.partida )        ;

	jugador->Unidas   ()->remove ( & key_partida )           ;
	partida->Unidos   ()->remove (   key_jugador )           ;
	partida->Abandona ()->add    (   key_jugador, abandona ) ;
}

////////////////////////////////////////////////////////////////