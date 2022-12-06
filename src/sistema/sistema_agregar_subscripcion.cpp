////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Subscripcion
(	Dt_Subscripcion const dt_subscripcion
){
	auto const jugador      = Buscar_Jugador    ( dt_subscripcion.jugador    );
	auto const videojuego   = Buscar_Videojuego ( dt_subscripcion.videojuego );
	auto const subscripcion = new Subscripcion
	(	jugador
	,	videojuego
	,	dt_subscripcion.tipo
	,	dt_subscripcion.pago
	,	dt_subscripcion.fecha
	);

	jugador    -> Agregar_Subscripcion( subscripcion, dt_subscripcion.videojuego );
	videojuego -> Agregar_Subscripcion( subscripcion, dt_subscripcion.jugador    );
}

////////////////////////////////////////////////////////////////