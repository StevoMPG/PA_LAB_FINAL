////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../string.h"

#include "../_colecciones-genericas/interfaces/IDictionary.h"
#include "../_colecciones-genericas/interfaces/ICollection.h"

////////////////////////////////////////////////////////////////

#include <functional>

////////////////////////////////////////////////////////////////

class Util
{
	public:
		static void Foreach
		(	IDictionary* const coleccion
		,	std::function<void(ICollectible*)> const Function
		);
		static void Foreach
		(	ICollection* const coleccion
		,	std::function<void(ICollectible*)> const Function
		);

		static void Liberar
		(	IDictionary* const coleccion
		);

		static void Liberar
		(	ICollection* const coleccion
		);

		static ICollection* Transformar
		(	IDictionary*                                const coleccion
		,	std::function<ICollectible*(ICollectible*)> const Funcion
		);
		static ICollection* Transformar
		(	ICollection*                                const coleccion
		,	std::function<ICollectible*(ICollectible*)> const Funcion
		);

		static ICollection* Filtrar
		(	IDictionary*                       const coleccion
		,	std::function<bool(ICollectible*)> const Prueba
		);
		static ICollection* Filtrar
		(	ICollection*                       const coleccion
		,	std::function<bool(ICollectible*)> const Prueba
		);

		static ICollectible* Buscar ( IDictionary*, std::function<bool(ICollectible*)> );
		static ICollectible* Buscar ( ICollection*, std::function<bool(ICollectible*)> );
		static ICollectible* Buscar ( IDictionary*, IKey* );
		static ICollectible* Buscar ( ICollection*, IKey* );

		static bool Incluye ( ICollection*, IKey* );
		static bool Alguno  ( ICollection*, std::function<bool(ICollectible*)> );
		static bool Todos   ( ICollection*, std::function<bool(ICollectible*)> );

		static ICollectible* Elemento (	IDictionary*, int );
		static ICollectible* Elemento (	ICollection*, int );

		static void Agregar ( IDictionary*, string );
		static void Agregar ( string**, string );
};

////////////////////////////////////////////////////////////////