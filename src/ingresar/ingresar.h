////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../singleton.h"
#include "i_ingresar.h"

////////////////////////////////////////////////////////////////

// #include "./dt/string.h"
// #include "./dt/tipo_juego.h"
// #include "./dt/fecha_hora.h"

////////////////////////////////////////////////////////////////

// #include "_datatypes.h"
// #include "_/interfaces/ICollection.h"
// #include "_/interfaces/IDictionary.h"
// #include "rango.h"
// #include "dt_categoria.h"
// #include "dt_subscripcion.h"

////////////////////////////////////////////////////////////////

// int Ingresar::Partida( ICollection* individuales, ICollection* multijugador );
// {
// 	lista todas las partidas iniciadas por dicho jugador que aún no han finalizado;

// 	Cada partida se lista mostrando
// 		su identificador,
// 		fecha de comienzo
// 		y el nombre del videojuego al que corresponde

// 		para las partidas individuales
// 			se muestra si es o no una continuación de una partida anterior,

// 		y para las multijugador,
// 			se muestra si está siendo transmitida en vivo o no,
// 			y el nickname de los jugadores que se unieron a ella;
// }

////////////////////////////////////////////////////////////////

class Ingresar
: public I_Ingresar
, public Singleton<Ingresar>
{
	private:
		Rango const rango_costo = { .min = 0, .max = 9999 };

	public:
		void   Enter  ()                override;
		int    Entero ( string, Rango ) override;
		// int    Positivo ( string, Rango ) override { return 1; };
		// string Nombre ()                override { return "" };

		string Contrasenia () override { return Ingresar::Texto( "Contrasenia: " ); }
		string Descripcion () override { return Ingresar::Texto( "Descripcion: " ); }
		string Email       () override { return Ingresar::Texto( "Email: "       ); }
		string Empresa     () override { return Ingresar::Texto( "Empresa: "     ); }
		string Nombre      () override { return Ingresar::Texto( "Nombre: "      ); }

		bool Transmitida  () override { return Ingresar::Bool( "Transmitida? " ); }
		bool Cancelacion  () override { return Ingresar::Bool(    "Cancelar? " ); }
		bool Confirmacion () override { return Ingresar::Bool( "\nConfirmar? " ); }

		double Costo_Mensual    () override { return Ingresar::Real( "Costo Mensual: "    , rango_costo ); }
		double Costo_Trimestral () override { return Ingresar::Real( "Costo Trimestral: " , rango_costo ); }
		double Costo_Anual      () override { return Ingresar::Real( "Costo Anual: "      , rango_costo ); }
		double Costo_Vitalicio  () override { return Ingresar::Real( "Costo Vitalicio: "  , rango_costo ); }

		::Enum_Categoria    Enum_Categoria    () override { return (::Enum_Categoria)    Ingresar::Enum( enum_categoria    ); }
		::Enum_Partida      Enum_Partida      () override { return (::Enum_Partida)      Ingresar::Enum( enum_partida      ); }
		::Enum_Subscripcion Enum_Subscripcion () override { return (::Enum_Subscripcion) Ingresar::Enum( enum_subscripcion ); }
		::Enum_Usuario      Enum_Usuario      () override { return (::Enum_Usuario)      Ingresar::Enum( enum_usuario      ); }
		::Enum_Pago         Enum_Pago         () override { return (::Enum_Pago)         Ingresar::Enum( enum_pago         ); }
		::Enum_Puntaje      Enum_Puntaje      () override { return (::Enum_Puntaje)      Ingresar::Enum( enum_puntaje      ); }

		string Nickname_Unico ( IDictionary* const coleccion ) override { return Ingresar::Texto_Unico( "Nickname: ", coleccion ); }
		string Nombre_Unico   ( IDictionary* const coleccion ) override { return Ingresar::Texto_Unico( "Nombre: ",   coleccion ); }

		string Seleccionar_Texto ( string, IDictionary* );

		string       Categoria  ( IDictionary* const coleccion )          { return Ingresar::Seleccionar_Texto( "Categoria: "  , coleccion ); }
		string       Genero     ( IDictionary* const coleccion ) override { return Ingresar::Seleccionar_Texto( "Genero: "     , coleccion ); }
		string       Plataforma ( IDictionary* const coleccion ) override { return Ingresar::Seleccionar_Texto( "Plataforma: " , coleccion ); }
		string*      Categorias ( IDictionary* ) override;
		// IDictionary* Categorias ( IDictionary* ) override;

	private:
		string Texto     ( string );
		bool   Bool      ( string );
		string Minuscula ( string );
		int    Enum      ( string const* );
		// double Real      ();
		// double Real      ( string );
		double Real      ( string, Rango );
		string Texto_Unico ( string, IDictionary* );

		// int     Entero        ();
		// int     Entero_Entre  ( string, int, int );
		// int     Entero_Valido ();
		// int     Natural       ( string );
		// int     Positivo      ( string );
		// int     Real          ();
		// string  Texto_Minimo  ( unsigned int );
		// string  Minuscula     ( string );
		// int     Opcion        ();
		// string  Nickname      ( string = "Nickname: " );
		// string  Contrasena    ();
		// int     Edad          ();
		// string  Nombre        ( string = "Nombre: " );
		// GENERO  Genero        ();
		// float   Duracion      ( string );
		// bool    Bool          ( string );
		// FECHA   Fecha         ( string );
		// string* Jugadores     ( int );

	public:
		// static string Texto  ();
		// static string Texto  ( string );
		// static int    Entero ();
		// static int    Entero ( string mensaje, RANGO );
	// 	static int    Entero ( RANGO );

		// static void   Enter  ();

	public:

		// string            Videojuego        ( ICollection*  );  // mostrar nombre y descripcion
		// string            Videojuego        ( ICollection*, ICollection* );  // mostrar nombre y precios, activos, inactivos




	// 	static ICollection*      Jugadores         ( ICollection* );
	// 	static ICollection*      Categorias        ( ICollection* );
		// static string            Categoria         ( IDictionary* );
	// 	static string            Genero            ( ICollection* );
	// 	static string            Plataforma        ( ICollection* );

	// 	static int               Partida              ( ICollection* ); // selecciona id
	// 	static int               Partida_Individual   ( ICollection* ); // selecciona id
	// 	static int               Partida_Multijugador ( ICollection* ); // selecciona id
	// 	static int               Partida              ( ICollection* individuales, ICollection* multijugador );


};

////////////////////////////////////////////////////////////////