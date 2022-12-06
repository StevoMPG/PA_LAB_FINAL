////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../clases.h"

////////////////////////////////////////////////////////////////

class Subscripcion : public ICollectible
{
	private:
		using Tipo = Enum_Subscripcion ;
		using Pago = Enum_Pago         ;

		Usuario*    jugador    ;
		Videojuego* videojuego ;
		Tipo        tipo       ;
		Pago        pago       ;
		Fecha       fecha      ;

	public:
		Subscripcion
		(	Usuario*    const jugador
		,	Videojuego* const videojuego
		,	Tipo        const tipo
		,	Pago        const pago
		,	Fecha       const fecha
		);
};

////////////////////////////////////////////////////////////////