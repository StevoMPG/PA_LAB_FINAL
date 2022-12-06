////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

Sistema::~Sistema ()
{
	Util::Liberar( this->usuarios );
	Util::Liberar( this->categorias );
	Util::Liberar( this->videojuegos );
	// delete this->jugadores       ;
	// delete this->desarrolladores ;
}

////////////////////////////////////////////////////////////////

void Sistema::Inicializar ()
{
	this->usuario_sesion  = nullptr;
	this->usuarios        = new OrderedDictionary();
	this->jugadores       = new OrderedDictionary();
	this->desarrolladores = new OrderedDictionary();
	this->generos         = new OrderedDictionary();
	this->categorias      = new OrderedDictionary();
	this->plataformas     = new OrderedDictionary();
	this->videojuegos     = new OrderedDictionary();

	this->partidas        = new OrderedDictionary();
	this->individuales    = new OrderedDictionary();
	this->multijugador    = new OrderedDictionary();
}

////////////////////////////////////////////////////////////////

Dt_Usuario* Sistema::Dt_Usuario_Sesion ()
{
	auto const usuario = this->usuario_sesion;

	if( usuario == nullptr )
		return nullptr;

	else
	if( auto const desarrollador = dynamic_cast<Desarrollador*>( usuario ) )
		return desarrollador->Crear_Dt();

	else
	if( auto const jugador = dynamic_cast<Jugador*>( usuario ) )
		return jugador->Crear_Dt();

	else
		return nullptr;
}

////////////////////////////////////////////////////////////////

IDictionary* Sistema::Nicknames ()
{
	auto const nicknames = new OrderedDictionary();
	auto const Agregar   = [ & ]
	(	ICollectible* current
	){
		auto const jugador  = dynamic_cast<Jugador*>( current );
		auto const nickname = jugador->Nickname();
		auto const str      = new String( nickname.c_str() );

		nicknames->add( str, str );
	};

	Util::Foreach( this->jugadores, Agregar );

	return nicknames;
}

////////////////////////////////////////////////////////////////

static
IDictionary* Nombres_Categorias
(	IDictionary* const coleccion
){
	auto const categorias = new OrderedDictionary();
	auto const Agregar   = [ & ]
	(	ICollectible* current
	){
		auto const categoria = dynamic_cast<Categoria*>( current );
		auto const nombre    = categoria->Nombre();
		auto const str       = new String( nombre.c_str() );
		categorias->add( str, str);
	};

	Util::Foreach( coleccion, Agregar );

	return categorias;
}

////////////////////////////////////////////////////////////////

IDictionary* Sistema::Categorias  () { return Nombres_Categorias( this->categorias  ); }
IDictionary* Sistema::Plataformas () { return Nombres_Categorias( this->plataformas ); }
IDictionary* Sistema::Generos     () { return Nombres_Categorias( this->generos     ); }

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Usuario
(	Dt_Usuario* const dt_usuario
){
	if( dt_usuario == nullptr )
		return;

	else
	if( auto key = String( dt_usuario->email.c_str() )
	;   this->usuarios->member( & key ) )
		return;

	else
	if( auto const dt_desarrollador = dynamic_cast<Dt_Desarrollador*>( dt_usuario ) )
	{
		auto const key = dt_usuario->email.c_str();
		auto const val = new Desarrollador( dt_desarrollador );

		this->usuarios        -> add( new String( key ), val );
		this->desarrolladores -> add( new String( key ), val );
	}

	else
	if( auto const dt_jugador = dynamic_cast<Dt_Jugador*>( dt_usuario ) )
	{
		auto const key = dt_usuario->email.c_str();
		auto const val = new Jugador( dt_jugador );

		this->usuarios  -> add( new String( key ), val );
		this->jugadores -> add( new String( key ), val );
	}
}

////////////////////////////////////////////////////////////////

IDictionary* Sistema::Dt_Usuarios ()
{
	auto const dt_usuarios         = new OrderedDictionary();
	auto const Convertir_Y_Agregar = [ & ]
	(	ICollectible* const collectible
	){
		auto const usuario = dynamic_cast<Usuario*>( collectible );
		auto const email   = usuario->Email();
		auto const val     = usuario->Crear_Dt();
		auto const key     = new String( email.c_str() );

		dt_usuarios->add( key, val );
	};

	Util::Foreach( this->usuarios, Convertir_Y_Agregar );
	return dt_usuarios;
}

////////////////////////////////////////////////////////////////

bool Sistema::Iniciar_Sesion
(	string const email
,	string const contrasenia
){
	auto const Comparar = [ & ]
	(	auto const elemento
	){
		auto const usuario = dynamic_cast<Usuario*>( elemento );

		return usuario->Email()       == email
		and    usuario->Contrasenia() == contrasenia;
	};

	auto const temp    = Util::Buscar( this->usuarios, Comparar );
	auto const usuario = dynamic_cast<Usuario*>( temp );

	this->usuario_sesion = usuario;

	return usuario != nullptr;
}
////////////////////////////////////////////////////////////////

void Sistema::Cerrar_Sesion ()
{
	this->usuario_sesion = nullptr;
}

////////////////////////////////////////////////////////////////

IDictionary* Sistema::Buscar_Categorias
(	string* const nombres
){
	auto const resultado = new OrderedDictionary();

	for( auto each = nombres; each->size(); each += 1 )
	{
		auto const key = new String( each->c_str() );
		auto const val = this->categorias->find( key );
		resultado->add( key, val );
	}

	return resultado;
}

////////////////////////////////////////////////////////////////

Partida* Sistema::Buscar_Partida
(	int const id
){
	auto       key      = Integer( id );
	auto const temp     = this->partidas->find( & key );
	auto const partidas = dynamic_cast<Partida*>( temp );

	return partidas;
}

////////////////////////////////////////////////////////////////

Individual* Sistema::Buscar_Individual
(	int const id
){
	return dynamic_cast<Individual*>( Buscar_Partida( id ) );
}

////////////////////////////////////////////////////////////////

Multijugador* Sistema::Buscar_Multijugador
(	int const id
){
	return dynamic_cast<Multijugador*>( Buscar_Partida( id ) );
}

////////////////////////////////////////////////////////////////

Usuario* Sistema::Buscar_Usuario
(	string const email
){
	auto       key     = String( email.c_str() );
	auto const temp    = this->usuarios->find( & key );
	auto const usuario = dynamic_cast<Usuario*>( temp );

	return usuario;
}

////////////////////////////////////////////////////////////////

Jugador* Sistema::Buscar_Jugador
(	string const email
){
	auto       key     = String( email.c_str() );
	auto const temp    = this->jugadores->find( & key );
	auto const jugador = dynamic_cast<Jugador*>( temp );

	return jugador;
}

////////////////////////////////////////////////////////////////

IDictionary* Sistema::Buscar_Jugadores
(	string* const emails
){
	auto const resultado = new OrderedDictionary();

	for( auto iter = emails; iter->size(); iter += 1 )
	{
		auto const jugador = Buscar_Jugador( *iter );
		if( jugador != nullptr )
		{
			auto const key = new String( iter->c_str() );
			resultado->add( key, jugador );
		}
	}

	return resultado;
}

////////////////////////////////////////////////////////////////

Videojuego* Sistema::Buscar_Videojuego
(	string const nombre
){
	auto       key        = String( nombre.c_str() );
	auto const temp       = this->videojuegos->find( & key );
	auto const videojuego = dynamic_cast<Videojuego*>( temp );

	return videojuego;
}

////////////////////////////////////////////////////////////////

// void Sistema::Eliminar_Videojuego
// (	string const nombre
// ){
// 	auto const videojuego = this->Buscar_Videojuego( nombre );

// 	this->Eliminar_Subscripciones ( videojuego );
// 	this->Eliminar_Partidas       ( videojuego );
// 	this->Eliminar_Comentarios    ( videojuego );
// 	this->Eliminar_Puntajes       ( videojuego );

// 	delete videojuego;
// }

////////////////////////////////////////////////////////////////