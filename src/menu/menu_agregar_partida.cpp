////////////////////////////////////////////////////////////////

#include "menu.h"

////////////////////////////////////////////////////////////////

void Menu::Agregar_Partida ()
{
	// auto const videojuegos = Sistema::Subscripciones_Activos();
	// auto const videojuego  = Ingresar::Videojuego( videojuegos );
	// auto const tipo        = Ingresar::Tipo_Partida();  // individual, multijugador
	// auto const partida     = Completar_Dt_Partida( videojuego, tipo );

	// if( Ingresar::Confirmacion() )
	// 	Sistema::Agregar_Partida( partida );
	// 	// asignar id autogenerado
	// 	// y fecha y hora actual

	// delete videojuegos;
}

////////////////////////////////////////////////////////////////


// DT_PARTIDA_MULTIJUGADOR* Completar_Dt_Partida_Multijugador
// (	auto const videojuego
// ){
// 	// el sistema lista los nicknames de todos los demás jugadores
// 		// que cuentan también con una suscripción activa,
// 		// y luego el jugador ingresa los nicknames
// 		// de aquellos que se unirán a la partida.
// 	auto const jugadores   = Sistema::Otros_Subscriptos( videojuego );
// 	auto const transmitida = Ingresar::Transmitida();  // si / no
// 	auto const unidos      = Ingresar::Jugadores( jugadores );
// 	auto const partida     = new DT_PARTIDA_MULTIJUGADOR;

// 	partida->videojuego  = videojuego  ;
// 	partida->transmitida = transmitida ;
// 	partida->unidos      = unidos      ;

// 	delete jugadores;
// 	// delete unidos;

// 	return partida;
// }

////////////////////////////////////////////////////////////////

// DT_PARTIDA_INDIVIDUAL* Completar_Dt_Partida_Individual
// (	auto const videojuego
// ){
// 	auto const partida = new DT_PARTIDA_INDIVIDUAL();

// 	partida->videojuego = videojuego;

// 	if( Ingresar::Confirmacion( "Continua partida anterior?" ) )
// 	{
// 		auto const partidas = Sistema::Partidas_Individuales_Finalizadas();

// 		partida->anterior = Ingresar::Partida_Individual( partidas );

// 		delete partidas;
// 	}

// 	return partida;
// }

////////////////////////////////////////////////////////////////

// DT_PARTIDA* Completar_Dt_Partida
// (	auto const videojuego
// ,	auto const tipo
// ){
// 	if( tipo == multijugador )
// 		return Completar_Dt_Partida_Multijugador( videojuego );
// 	else
// 		return Completar_Dt_Partida_Individual( videojuego );
// }

////////////////////////////////////////////////////////////////