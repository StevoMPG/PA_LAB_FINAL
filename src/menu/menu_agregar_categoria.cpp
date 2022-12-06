////////////////////////////////////////////////////////////////

#include "menu.h"
#include "../util/util.h"
#include "../fabrica/fabrica.h"
#include "../datatypes/dt_categoria.h"

////////////////////////////////////////////////////////////////

void Menu::Agregar_Categoria ()
{
	auto const fabrica    = Fabrica::Instancia  ();
	auto const sistema    = fabrica->Sistema    ();
	auto const mostrar    = fabrica->Mostrar    ();
	auto const ingresar   = fabrica->Ingresar   ();
	auto const categorias = sistema->Categorias ();

	mostrar->Lista( categorias );

	auto const categoria = Dt_Categoria
	{	.nombre      = ingresar->Nombre_Unico   ( categorias )
	,	.descripcion = ingresar->Descripcion    ()
	,	.tipo        = ingresar->Enum_Categoria ()
	};

	if( ingresar->Confirmacion() )
		sistema->Agregar_Categoria( categoria );

	delete( categorias );
}

////////////////////////////////////////////////////////////////