////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../string.h"

////////////////////////////////////////////////////////////////

class Opcion
{
	public:
		using Funcion = void(*)();

		enum Resultado
		{	salir
		,	volver
		,	continuar
		};

		Funcion   funcion   ;
		string    titulo    ;
		Resultado resultado ;

		void             Manejar  ()                const ;
		Resultado static Manejar  ( Opcion const* )       ;
		int       static Cantidad ( Opcion const* )       ;
};

////////////////////////////////////////////////////////////////