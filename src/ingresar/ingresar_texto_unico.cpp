////////////////////////////////////////////////////////////////

#include "ingresar.h"
#include "../fabrica/fabrica.h"

////////////////////////////////////////////////////////////////

#include "../_colecciones-genericas/String.h"

////////////////////////////////////////////////////////////////

string Ingresar::Texto_Unico
(	string       const mensaje
,	IDictionary* const coleccion
){
	auto const fabrica  = Fabrica :: Instancia ();
	auto const mostrar  = fabrica -> Mostrar   ();

	while( true )
	{
		auto const texto  = Ingresar::Texto( mensaje );
		auto       str    = String( texto.c_str() );
		auto const existe = coleccion->member( & str );

		if( texto.size() < 1 )
			mostrar->Error( error_minimo_caracteres );

		else
		if( existe )
		{
			mostrar->Error( error_valor_usado );
			if( Ingresar::Cancelacion() )
				return "";

			else
				continue;
		}

		else
			return texto;
	}
}

////////////////////////////////////////////////////////////////