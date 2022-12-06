////////////////////////////////////////////////////////////////

#include "ingresar.h"

// #include "../_colecciones-genericas/collections/OrderedDictionary.h"
// #include "../_colecciones-genericas/String.h"

////////////////////////////////////////////////////////////////

// #include <malloc.h>
#include <vector>

////////////////////////////////////////////////////////////////

// IDictionary* Ingresar::Categorias
// (	IDictionary* const categorias
// ){
// 	auto resultado = new OrderedDictionary();

// 	while( Ingresar::Bool( "Agregar otra categoria? " ) )
// 	{
// 		auto const categoria = Ingresar::Categoria( categorias );
// 		auto const str       = new String( categoria.c_str() );

// 		resultado->add( str, str );
// 	}

// 	return resultado;
// }

////////////////////////////////////////////////////////////////

// string* Ingresar::Categorias
// (	IDictionary* const categorias
// ){
// 	int  cantidad  = 10;
// 	string* resultado = (string*) calloc( cantidad, sizeof string );

// 	while( Ingresar::Bool( "Agregar otra categoria? " ) )
// 	{
// 		// resultado[ cantidad - 1 ] = Ingresar::Categoria( categorias );
// 		// cantidad += 1;
// 		// resultado = (string*) realloc( resultado, sizeof(string) * cantidad );
// 	}

// 	// resultado[ cantidad - 1 ] = "";


// 	return resultado;
// }

////////////////////////////////////////////////////////////////

string* Ingresar::Categorias
(	IDictionary* const categorias
){
	std::vector<string> vector;

	// resultado.clear();

	while( Ingresar::Bool( "Agregar otra categoria? " ) )
	{
		vector.push_back( Ingresar::Categoria( categorias ) );
	}

	vector.push_back( "" );

	auto const resultado = new string [ vector.size() + 3 ] { "" };

	for( int n = 0; n < vector.size(); n += 1 )
		resultado[ n ] = vector[ n ];

	return resultado;
}

////////////////////////////////////////////////////////////////