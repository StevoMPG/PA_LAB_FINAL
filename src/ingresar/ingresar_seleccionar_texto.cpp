////////////////////////////////////////////////////////////////

#include "ingresar.h"

#include "../util/util.h"
#include "../fabrica/fabrica.h"
#include "../_colecciones-genericas/String.h"

////////////////////////////////////////////////////////////////

string Ingresar::Seleccionar_Texto
(	string       const mensaje
,	IDictionary* const coleccion
){
	auto const fabrica = Fabrica::Instancia();
	auto const mostrar = fabrica->Mostrar();

	mostrar->Lista( coleccion );

	auto const cantidad = coleccion->getSize();
	auto const rango    = Rango{ .min = 1, .max = cantidad };
	auto const indice   = Ingresar::Entero( mensaje, rango );
	auto const elemento = Util::Elemento( coleccion, indice - 1 );
	auto const str      = dynamic_cast<String*>( elemento );
	auto const texto    = str->getValue();

	return texto;
}

////////////////////////////////////////////////////////////////