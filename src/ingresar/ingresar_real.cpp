////////////////////////////////////////////////////////////////

#include "ingresar.h"
#include "../fabrica/fabrica.h"

////////////////////////////////////////////////////////////////

#include <stdexcept>

////////////////////////////////////////////////////////////////

double Ingresar::Real
(	string const mensaje
,	Rango  const rango
){
	while( true )
	{
		try
		{
			size_t       largo  = 0;
			string const texto  = Ingresar::Texto( mensaje );
			int    const numero = std::stod( texto, & largo );

			if( largo == texto.size()
			and rango.Dentro( numero ) )
				return numero;
			else
				throw std::invalid_argument( "" );
		}
		catch( std::invalid_argument exception )
		{
			auto const fabrica = Fabrica::Instancia ();
			auto const mostrar = fabrica->Mostrar   ();

			mostrar->Error( error_valor_invalido );
		}
	}
}

////////////////////////////////////////////////////////////////