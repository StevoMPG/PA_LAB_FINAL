////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../string.h"
#include "../rango.h"
#include "../enums.h"

#include "../_colecciones-genericas/interfaces/IDictionary.h"

////////////////////////////////////////////////////////////////

class I_Ingresar
{
	public:
		virtual ~I_Ingresar () = default;

		virtual void                Enter  ()                = 0;
		virtual int                 Entero ( string, Rango ) = 0;

		virtual string              Contrasenia       () = 0;
		virtual string              Descripcion       () = 0;
		virtual string              Email             () = 0;
		virtual string              Empresa           () = 0;
		virtual string              Nombre            () = 0;

		virtual bool                Transmitida       () = 0;
		virtual bool                Cancelacion       () = 0;
		virtual bool                Confirmacion      () = 0;

		virtual double              Costo_Mensual     () = 0;
		virtual double              Costo_Trimestral  () = 0;
		virtual double              Costo_Anual       () = 0;
		virtual double              Costo_Vitalicio   () = 0;

		virtual ::Enum_Categoria    Enum_Categoria    () = 0;
		virtual ::Enum_Partida      Enum_Partida      () = 0;
		virtual ::Enum_Subscripcion Enum_Subscripcion () = 0;
		virtual ::Enum_Usuario      Enum_Usuario      () = 0;
		virtual ::Enum_Pago         Enum_Pago         () = 0;
		virtual ::Enum_Puntaje      Enum_Puntaje      () = 0;

		virtual string Nickname_Unico ( IDictionary* ) = 0;
		virtual string Nombre_Unico   ( IDictionary* ) = 0;

		virtual string       Genero     ( IDictionary* ) = 0;
		virtual string       Plataforma ( IDictionary* ) = 0;
		virtual string*      Categorias ( IDictionary* ) = 0;
		// virtual IDictionary* Categorias ( IDictionary* ) = 0;
};


////////////////////////////////////////////////////////////////