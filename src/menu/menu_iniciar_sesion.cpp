////////////////////////////////////////////////////////////////

#include "menu.h"

#include "../fabrica/fabrica.h"

////////////////////////////////////////////////////////////////

void Menu::Iniciar_Sesion ()
{
	auto const fabrica  = Fabrica :: Instancia ();
	auto const mostrar  = fabrica -> Mostrar   ();
	auto const ingresar = fabrica -> Ingresar  ();
	auto const sistema  = fabrica -> Sistema   ();

	for( bool finalizado = false; not finalizado; )
	{
		auto const email       = ingresar->Email();
		auto const contrasenia = ingresar->Contrasenia();

		if( sistema->Iniciar_Sesion( email, contrasenia ) )
			finalizado = true;

		else
		{
			mostrar->Error( error_iniciar_sesion );
			finalizado = ingresar->Cancelacion();
		}
	}
}

////////////////////////////////////////////////////////////////