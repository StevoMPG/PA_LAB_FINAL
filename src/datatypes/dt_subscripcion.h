////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "_datatypes.h"

////////////////////////////////////////////////////////////////

struct Dt_Subscripcion
{
	using Tipo = Enum_Subscripcion ;
	using Pago = Enum_Pago         ;

	string jugador    ;
	string videojuego ;
	Tipo   tipo       ;
	Pago   pago       ;
	Fecha  fecha      ;
};

////////////////////////////////////////////////////////////////