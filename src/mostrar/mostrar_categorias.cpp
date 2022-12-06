////////////////////////////////////////////////////////////////

#include "mostrar.h"

#include "../util/util.h"

#include "../_colecciones-genericas/String.h"

////////////////////////////////////////////////////////////////

#include <iostream>

////////////////////////////////////////////////////////////////

void Mostrar::Lista
(	string* const coleccion
){
	int n = 1;

	for( auto each = coleccion; each->size(); each += 1 )
	{
		std::cout << "\t" << n << ". " << *each << "\n";
		n += 1;
	}
}

////////////////////////////////////////////////////////////////

void Mostrar::Lista
(	IDictionary* const coleccion
){
	int n = 1;

	Util::Foreach
	(	coleccion
	,	[ & ]
		(	ICollectible* const current
		){
			auto const str   = dynamic_cast<String*>( current );
			auto const texto = str->getValue();

			std::cout << "\t" << n << ". " << texto << "\n";

			n += 1;
		}
	);
}

////////////////////////////////////////////////////////////////

void Mostrar::Lista
(	ICollection* const coleccion
){
	int n = 1;

	Util::Foreach
	(	coleccion
	,	[ & ]
		(	ICollectible* const current
		){
			auto const str   = dynamic_cast<String*>( current );
			auto const texto = str->getValue();

			std::cout << "\t" << n << ". " << texto << "\n";

			n += 1;
		}
	);
}

////////////////////////////////////////////////////////////////