////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../string.h"
#include "../opcion/opcion.h"
#include "../datatypes/dt_videojuego.h"

#include "../_colecciones-genericas/interfaces/ICollection.h"
#include "../_colecciones-genericas/interfaces/IDictionary.h"

////////////////////////////////////////////////////////////////

static string const error_valor_invalido    = "Valor no valido";
static string const error_valor_usado       = "Ese valor ya esta en uso";
static string const error_minimo_caracteres = "Deber al menos 1 caracter";
static string const error_iniciar_sesion    = "Email o contrasenia incorrectos";
static string const error_nickname_existe   = "Nickname en uso";
static string const error_no_hay_genero     = "No existe ningun genero";
static string const error_no_hay_plataforma = "No existe ninguna plataforma";

////////////////////////////////////////////////////////////////

class I_Mostrar
{
	public:
		virtual void Borrar_Pantalla ()                 = 0;
		virtual void Error           ( string )         = 0;
		virtual void Titulo          ( string )         = 0;
		virtual void Opciones        ( Opcion const* )  = 0;
		virtual void Enum            ( string const* )  = 0;
		virtual void Lista           ( string* )        = 0;
		virtual void Lista           ( IDictionary* )   = 0;
		virtual void Lista           ( ICollection* )   = 0;
		virtual void Videojuego      ( Dt_Videojuego )  = 0;
};

////////////////////////////////////////////////////////////////