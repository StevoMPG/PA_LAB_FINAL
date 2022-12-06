////////////////////////////////////////////////////////////////

#include "../clases_cpp.h"

////////////////////////////////////////////////////////////////

Usuario::Usuario
(	Dt_Usuario* const dt_usuario
){
	this->subscripciones = new OrderedDictionary() ;
	this->email          = dt_usuario->email       ;
	this->contrasenia    = dt_usuario->contrasenia ;
}

////////////////////////////////////////////////////////////////

Desarrollador::Desarrollador
(	Dt_Desarrollador* const dt_desarrollador
) : Usuario( dt_desarrollador )
{
	this->empresa = dt_desarrollador->empresa;
}

////////////////////////////////////////////////////////////////

Jugador::Jugador
(	Dt_Jugador* const dt_jugador
) : Usuario( dt_jugador )
{
	this->descripcion = dt_jugador->descripcion;
	this->nickname    = dt_jugador->nickname;

	this->iniciadas   = new OrderedDictionary();
	this->finalizadas = new OrderedDictionary();
	this->unidas      = new OrderedDictionary();
}

////////////////////////////////////////////////////////////////

string       Usuario::Email       () { return this->email       ; }
string       Usuario::Contrasenia () { return this->contrasenia ; }
string Desarrollador::Empresa     () { return this->empresa     ; }
string       Jugador::Descripcion () { return this->descripcion ; }
string       Jugador::Nickname    () { return this->nickname    ; }

////////////////////////////////////////////////////////////////

IDictionary* Jugador::Iniciadas   () { return this->iniciadas ; }
IDictionary* Jugador::Finalizadas () { return this->iniciadas ; }
IDictionary* Jugador::Unidas      () { return this->unidas    ; }

////////////////////////////////////////////////////////////////

void Jugador::Agregar_Subscripcion
(	Subscripcion* const subscripcion
,	string        const videojuego
){
	auto const key = new String( videojuego.c_str() );
	this->subscripciones->add( key, subscripcion );
}

////////////////////////////////////////////////////////////////

void Jugador::Agregar_Puntaje
(	Puntaje* const puntaje
,	string   const videojuego
){
	auto const key = new String( videojuego.c_str() );
	this->subscripciones->add( key, puntaje );
}

////////////////////////////////////////////////////////////////

Dt_Usuario* Desarrollador::Crear_Dt ()
{
	auto const dt_usuario = new Dt_Desarrollador;

	dt_usuario->email       = this->Email       ();
	dt_usuario->contrasenia = this->Contrasenia ();
	dt_usuario->empresa     = this->Empresa     ();

	return dt_usuario;
}

////////////////////////////////////////////////////////////////

Dt_Usuario* Jugador::Crear_Dt ()
{
	auto const dt_usuario = new Dt_Jugador;

	dt_usuario->email       = this->Email       ();
	dt_usuario->contrasenia = this->Contrasenia ();
	dt_usuario->nickname    = this->Nickname    ();
	dt_usuario->descripcion = this->Descripcion ();

	return dt_usuario;
}

////////////////////////////////////////////////////////////////