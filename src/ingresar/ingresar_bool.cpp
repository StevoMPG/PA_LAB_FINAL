////////////////////////////////////////////////////////////////

#include "ingresar.h"
#include "../fabrica/fabrica.h"

////////////////////////////////////////////////////////////////

bool Ingresar::Bool (
	string const mensaje
){
	auto const fabrica = Fabrica::Instancia();
	auto const mostrar = fabrica->Mostrar();

	while( true )
	{
		string const texto     = Ingresar::Texto( mensaje + "(s/n): " );
		string const minuscula = Ingresar::Minuscula( texto );

		if( minuscula == "si"
		or  minuscula == "s" )
			return true;
		else
		if( minuscula == "no"
		or  minuscula == "n" )
			return false;
		else
			mostrar->Error( error_valor_invalido );
	}
}

////////////////////////////////////////////////////////////////