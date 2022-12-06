////////////////////////////////////////////////////////////////

#include "menu.h"
#include "../fabrica/fabrica.h"

////////////////////////////////////////////////////////////////

static
Dt_Desarrollador* Completar_Dt_Desarrollador
(	auto const email
,	auto const contrasenia
){
	auto const fabrica    = Fabrica  :: Instancia ();
	auto const ingresar   = fabrica  -> Ingresar  ();
	auto const empresa    = ingresar -> Empresa   ();
	auto const dt_usuario = new Dt_Desarrollador;

	dt_usuario->email       = email       ;
	dt_usuario->contrasenia = contrasenia ;
	dt_usuario->empresa     = empresa     ;

	return dt_usuario;
}

////////////////////////////////////////////////////////////////

static
Dt_Jugador* Completar_Dt_Jugador
(	auto const email
,	auto const contrasenia
){
	auto const fabrica     = Fabrica  :: Instancia   ();
	auto const sistema     = fabrica  -> Sistema     ();
	auto const ingresar    = fabrica  -> Ingresar    ();
	auto const nicknames   = sistema  -> Nicknames   ();
	auto const descripcion = ingresar -> Descripcion ();
	auto const nickname    = ingresar -> Nickname_Unico( nicknames );

	delete( nicknames );

	if( nickname == "" )
		return nullptr;

	else
	{
		auto const dt_usuario = new Dt_Jugador;

		dt_usuario->email       = email       ;
		dt_usuario->contrasenia = contrasenia ;
		dt_usuario->nickname    = nickname    ;
		dt_usuario->descripcion = descripcion ;

		return dt_usuario;
	}
}

////////////////////////////////////////////////////////////////

static
Dt_Usuario* Completar_Dt_Usuario
(	auto const email
,	auto const contrasenia
,	auto const tipo
){
	if( tipo == desarrollador )
		return Completar_Dt_Desarrollador( email, contrasenia );

	else
	if( tipo == jugador )
		return Completar_Dt_Jugador( email, contrasenia );

	else
		return nullptr;
}

////////////////////////////////////////////////////////////////

void Menu::Agregar_Usuario ()
{
	auto const fabrica     = Fabrica  :: Instancia    ();
	auto const sistema     = fabrica  -> Sistema      ();
	auto const ingresar    = fabrica  -> Ingresar     ();
	auto const email       = ingresar -> Email        ();
	auto const contrasenia = ingresar -> Contrasenia  ();
	auto const tipo        = ingresar -> Enum_Usuario ();
	auto const dt_usuario  = Completar_Dt_Usuario
	(	email
	,	contrasenia
	,	tipo
	);

	if( dt_usuario != nullptr
	and ingresar->Confirmacion() )
		sistema->Agregar_Usuario( dt_usuario );

	delete dt_usuario;
}

////////////////////////////////////////////////////////////////