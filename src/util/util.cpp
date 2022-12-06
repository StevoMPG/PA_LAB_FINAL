////////////////////////////////////////////////////////////////

#include "util.h"
#include "../string.h"
#include "../_colecciones-genericas/String.h"
#include "../_colecciones-genericas/collections/List.h"
// #include "../_colecciones-genericas/collections/OrderedDictionary.h"

////////////////////////////////////////////////////////////////

void Util::Foreach
(	IDictionary*                       const coleccion
,	std::function<void(ICollectible*)> const Funcion
){
	for
	(	auto const iter = coleccion->getIterator()
	;	           iter -> hasCurrent()
	;	           iter -> next()
	){
		auto const current = iter->getCurrent();
		Funcion( current );
	}
}

////////////////////////////////////////////////////////////////

void Util::Foreach
(	ICollection*                       const coleccion
,	std::function<void(ICollectible*)> const Funcion
){
	for
	(	auto const iter = coleccion->getIterator()
	;	           iter -> hasCurrent()
	;	           iter -> next()
	){
		auto const current = iter->getCurrent();
		Funcion( current );
	}
}

////////////////////////////////////////////////////////////////

void Util::Liberar
(	IDictionary* const coleccion
){
	auto const Liberar = [] ( ICollectible* temp ){ delete temp; };

	Util::Foreach( coleccion, Liberar );
}

////////////////////////////////////////////////////////////////

void Util::Liberar
(	ICollection* const coleccion
){
	auto const Liberar = [] ( ICollectible* temp ){ delete temp; };

	Util::Foreach( coleccion, Liberar );
}

////////////////////////////////////////////////////////////////

ICollection* Util::Transformar
(	IDictionary*                                const coleccion
,	std::function<ICollectible*(ICollectible*)> const Funcion
){
	auto const resultado = new List();

	auto const Agregar = [ & ]
	(	ICollectible* const input
	){
		auto const output = Funcion( input );
		resultado->add( output );
	};

	Util::Foreach( coleccion, Agregar );

	return resultado;
}

////////////////////////////////////////////////////////////////

ICollection* Util::Transformar
(	ICollection*                                const coleccion
,	std::function<ICollectible*(ICollectible*)> const Funcion
){
	auto const resultado = new List();

	auto const Agregar = [ & ]
	(	ICollectible* const input
	){
		auto const output = Funcion( input );
		resultado->add( output );
	};

	Util::Foreach( coleccion, Agregar );

	return resultado;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

ICollection* Util::Filtrar
(	IDictionary*                       const coleccion
,	std::function<bool(ICollectible*)> const Prueba
){
	auto const resultado = new List();

	for
	(	auto const iter = coleccion->getIterator()
	;	           iter -> hasCurrent()
	;	           iter -> next()
	){
		auto const current = iter->getCurrent();
		if( Prueba( current ) )
			resultado->add( current );
	}

	return resultado;
}

////////////////////////////////////////////////////////////////

ICollection* Util::Filtrar
(	ICollection*                       const coleccion
,	std::function<bool(ICollectible*)> const Prueba
){
	auto const resultado = new List();

	for
	(	auto const iter = coleccion->getIterator()
	;	           iter -> hasCurrent()
	;	           iter -> next()
	){
		auto const current = iter->getCurrent();
		if( Prueba( current ) )
			resultado->add( current );
	}

	return resultado;
}

////////////////////////////////////////////////////////////////

ICollectible* Util::Buscar
(	ICollection*                       const coleccion
,	std::function<bool(ICollectible*)> const Prueba
){
	for
	(	auto const iter = coleccion->getIterator()
	;	           iter -> hasCurrent()
	;	           iter -> next()
	){
		auto const current = iter->getCurrent();
		if( Prueba( current ) )
			return current;
	}
	return nullptr;
}

////////////////////////////////////////////////////////////////

ICollectible* Util::Buscar
(	IDictionary*                       const coleccion
,	std::function<bool(ICollectible*)> const Prueba
){
	for
	(	auto const iter = coleccion->getIterator()
	;	           iter -> hasCurrent()
	;	           iter -> next()
	){
		auto const current = iter->getCurrent();
		if( Prueba( current ) )
			return current;
	}
	return nullptr;
}

////////////////////////////////////////////////////////////////

ICollectible* Util::Buscar
(	ICollection* const coleccion
,	IKey*        const valor
){
	auto const Prueba = [ & ]
	(	ICollectible* const current
	){
		auto const elemento = dynamic_cast<IKey*>( current );
		return elemento->equals( valor );
	};

	return Util::Buscar( coleccion, Prueba );
}

////////////////////////////////////////////////////////////////

ICollectible* Util::Buscar
(	IDictionary* const coleccion
,	IKey*        const valor
){
	auto const Prueba = [ & ]
	(	ICollectible* const current
	){
		auto const elemento = dynamic_cast<IKey*>( current );
		return elemento->equals( valor );
	};

	return Util::Buscar( coleccion, Prueba );
}

////////////////////////////////////////////////////////////////

bool Util::Alguno
(	ICollection*                       const coleccion
,	std::function<bool(ICollectible*)> const Prueba
){
	return Util::Buscar( coleccion, Prueba ) != nullptr;
}

////////////////////////////////////////////////////////////////

bool Util::Todos
(	ICollection*                       const coleccion
,	std::function<bool(ICollectible*)> const Prueba
){
	auto const Not_Prueba = [ & ]
	(	auto const param
	){
		return not Prueba( param );
	};

	return not Util::Alguno( coleccion, Not_Prueba );
}

////////////////////////////////////////////////////////////////

bool Util::Incluye
(	ICollection* const coleccion
,	IKey*        const valor
){
	return Util::Buscar( coleccion, valor ) != nullptr;
}

////////////////////////////////////////////////////////////////

ICollectible* Util::Elemento
(	IDictionary* const coleccion
,	int          const indice
){
	int n = 0;

	for
	(	auto const iter = coleccion->getIterator()
	;	           iter->hasCurrent()
	;              iter->next()
	)
		if( n == indice )
			return iter->getCurrent();
		else
			n += 1;

	return nullptr;
}

////////////////////////////////////////////////////////////////

ICollectible* Util::Elemento
(	ICollection* const coleccion
,	int          const indice
){
	int n = 0;

	for
	(	auto const iter = coleccion->getIterator()
	;	           iter->hasCurrent()
	;              iter->next()
	)
		if( n == indice )
			return iter->getCurrent();

	return nullptr;
}

////////////////////////////////////////////////////////////////

void Util::Agregar
(	IDictionary* const coleccion
,	string       const texto
){
	auto const str = new String(texto.c_str() );

	coleccion->add( str, str );
}

////////////////////////////////////////////////////////////////

// void Util::Agregar
// (	string** const coleccion
// ,	string   const texto
// ){
// 	if( texto == "" )
// 		return;

// 	else
// 	{
// 		auto cantidad = 0;

// 		while( (*coleccion)[ cantidad ].size() != 0 )
// 			cantidad += 1;

// 		cantidad += 1;

// 		auto const resultado = (string*) realloc( *coleccion, sizeof(string) * (cantidad+1) );
// 		resultado[ cantidad - 1 ] = texto;
// 		resultado[ cantidad     ] = "";
// 	}
// }

////////////////////////////////////////////////////////////////

void Util::Agregar
(	string** const coleccion
,	string   const texto
){
	if( texto == "" )
		return;

	else
	{
		auto cantidad = 0;

		while( (*coleccion)[ cantidad ].size() != 0 )
			cantidad += 1;

		(*coleccion)[ cantidad ] = texto;
	}
}

////////////////////////////////////////////////////////////////