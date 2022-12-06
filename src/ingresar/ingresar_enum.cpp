////////////////////////////////////////////////////////////////

#include "ingresar.h"
#include "../fabrica/fabrica.h"

////////////////////////////////////////////////////////////////

static
int Cantidad_Enum
(	auto const _enum
){
	int n;
	for( n = 0; _enum[ n ] != ""; n += 1 ){}
	return n;
}

////////////////////////////////////////////////////////////////

int Ingresar::Enum
(	string const* const _enum
){
	auto const fabrica = Fabrica::Instancia();
	auto const mostrar = fabrica->Mostrar();

	mostrar->Enum( _enum );

	auto const mensaje  = "Tipo: ";
	auto const cantidad = Cantidad_Enum( _enum );
	auto const rango    = Rango{ .min = 1, .max = cantidad };
	auto const indice   = Ingresar::Entero( mensaje, rango );

	return ( indice - 1 );
}

////////////////////////////////////////////////////////////////