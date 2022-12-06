////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../clases.h"

////////////////////////////////////////////////////////////////

class Usuario : public ICollectible
{
	protected:
		string       email          ;
		string       contrasenia    ;
		IDictionary* subscripciones ;

	public:
	                         Usuario ( Dt_Usuario* ) ;
		virtual             ~Usuario () = default    ;
		virtual Dt_Usuario* Crear_Dt () = 0          ;

		string Email       () ;
		string Contrasenia () ;
};

////////////////////////////////////////////////////////////////

class Desarrollador : public Usuario
{
	private:
		string empresa;

	public:
		            Desarrollador ( Dt_Desarrollador* );
		string      Empresa       ();
		Dt_Usuario* Crear_Dt      () override;
};

////////////////////////////////////////////////////////////////

class Jugador : public Usuario
{
	private:
		string       descripcion ;
		string       nickname    ;
		IDictionary* iniciadas   ;	// partida
		IDictionary* finalizadas ;	// partida
		IDictionary* unidas      ;	// partida

	public:
		             Jugador     ( Dt_Jugador* );
		string       Descripcion ();
		string       Nickname    ();
		IDictionary* Iniciadas   ();
		IDictionary* Finalizadas ();
		IDictionary* Unidas      ();
		Dt_Usuario*  Crear_Dt    () override;
		void         Agregar_Subscripcion ( Subscripcion*, string ) ;
		void         Agregar_Puntaje      ( Puntaje*,      string ) ;
};

////////////////////////////////////////////////////////////////