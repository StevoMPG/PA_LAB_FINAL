////////////////////////////////////////////////////////////////

#include "menu.h"

#include "../fabrica/fabrica.h"
#include "../datatypes/dt_videojuego.h"

////////////////////////////////////////////////////////////////

void Menu::Agregar_Videojuego ()
{
	auto const fabrica     = Fabrica::Instancia   ();
	auto const sistema     = fabrica->Sistema     ();
	auto const mostrar     = fabrica->Mostrar     ();
	auto const ingresar    = fabrica->Ingresar    ();
	auto const generos     = sistema->Generos     ();
	auto const plataformas = sistema->Plataformas ();
	auto const categorias  = sistema->Categorias  ();

	if( generos->isEmpty() )
		mostrar->Error( error_no_hay_genero );

	else
	if( plataformas->isEmpty() )
		mostrar->Error( error_no_hay_plataforma );

	else
	{
		auto const dt_usuario    = sistema->Dt_Usuario_Sesion();
		auto const dt_videojuego = Dt_Videojuego
		{	.desarrollador = dt_usuario->email
		,	.nombre        = ingresar->Nombre           ()
		,	.descripcion   = ingresar->Descripcion      ()
		,	.mensual       = ingresar->Costo_Mensual    ()
		,	.trimestral    = ingresar->Costo_Trimestral ()
		,	.anual         = ingresar->Costo_Anual      ()
		,	.vitalicia     = ingresar->Costo_Vitalicio  ()
		,	.genero        = ingresar->Genero     ( generos     )
		,	.plataforma    = ingresar->Plataforma ( plataformas )
		,	.categorias    = ingresar->Categorias ( categorias  )
		};

		mostrar->Videojuego( dt_videojuego );

		if( ingresar->Confirmacion() )
			sistema->Agregar_Videojuego( dt_videojuego );

		// free( dt_videojuego.categorias );
		// delete dt_videojuego.categorias;
	}
}

////////////////////////////////////////////////////////////////