////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

Dt_Abandona* Crear_Lista_Dt_Abandona
(	int          const id
,	Fecha        const fecha
,	IDictionary* const unidos
){
	auto const cantidad = unidos->getSize();
	auto const abandona = new Dt_Abandona [ cantidad ];

	int n = 0;
	Util::Foreach( unidos,
		[ & ]
		(	ICollectible* const current
		){
			auto const jugador = dynamic_cast<Jugador*>( current );
			auto const email   = jugador->Email();
			auto const temp    = Dt_Abandona{ id, email, fecha };

			abandona[ n ] = temp;
			n += 1;
		}
	);

	return abandona;
}


////////////////////////////////////////////////////////////////

void Sistema::Abandonar_Unidos
(	int          const id
,	Fecha        const fecha
,	IDictionary* const unidos
){
	auto const cantidad = unidos->getSize();
	auto const abandona = Crear_Lista_Dt_Abandona( id, fecha, unidos );

	for( int n = 0; n < cantidad; n += 1 )
		Abandonar_Partida( abandona[ n ] );

	delete [] abandona;
}

////////////////////////////////////////////////////////////////

void Sistema::Finalizar_Partida
(	Dt_Finaliza const dt_finaliza
){
	auto const fecha   = dt_finaliza.fecha;
	auto const id      = dt_finaliza.partida;
	auto const partida = Buscar_Partida( id );
	auto const key     = new Integer(id );
	auto const jugador = partida->Jugador();

	if( auto const multijugador = dynamic_cast<Multijugador*>( partida ) )
	{
		Abandonar_Unidos( id, fecha, multijugador->Unidos() );
	}
	else
	if( auto const individual = dynamic_cast<Individual*>( partida ) )
	{

	}

	this->partidas     -> remove( key );
	this->individuales -> remove( key );
	this->multijugador -> remove( key );

	jugador->Iniciadas   () -> remove( key );
	jugador->Finalizadas () -> add( key, partida );

	// El sistema calcula su duración
	// en función de la fecha y hora actual del sistema
	// y la registra como finalizada.
}

////////////////////////////////////////////////////////////////