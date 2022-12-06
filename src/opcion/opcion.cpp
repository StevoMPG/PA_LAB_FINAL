////////////////////////////////////////////////////////////////

#include "opcion.h"
#include "../fabrica/fabrica.h"

////////////////////////////////////////////////////////////////

void Opcion::Manejar () const
{
	auto const fabrica  = Fabrica::Instancia ();
	auto const mostrar  = fabrica->Mostrar   ();
	auto const ingresar = fabrica->Ingresar  ();

	if( this->resultado != salir )
	{
		mostrar->Borrar_Pantalla();
		mostrar->Titulo( this->titulo );

		this->funcion();

		ingresar->Enter();
	}
}

////////////////////////////////////////////////////////////////

Opcion::Resultado Opcion::Manejar
(	Opcion const* const opciones
){
	auto const fabrica  = Fabrica::Instancia ();
	auto const mostrar  = fabrica->Mostrar   ();
	auto const ingresar = fabrica->Ingresar  ();

	Rango const rango =
	{	.min = 1
	,	.max = Cantidad( opciones )
	};

	Resultado resultado = continuar;
	while( resultado == continuar )
	{
		mostrar->Borrar_Pantalla();
		mostrar->Titulo( "Menu" );
		mostrar->Opciones( opciones );

		auto const numero = ingresar->Entero( "\n", rango );
		auto const opcion = opciones[ numero - 1 ];

		opcion.Manejar();

		resultado = opcion.resultado;
	}

	return resultado;
}

////////////////////////////////////////////////////////////////

int Opcion::Cantidad
(	Opcion const* opciones
){
	int cantidad = 0;

	for
	(	auto opcion             = opciones
	;	     opcion -> funcion != nullptr
	;	     opcion            += 1
	)
		cantidad += 1;

	return cantidad;
}

////////////////////////////////////////////////////////////////