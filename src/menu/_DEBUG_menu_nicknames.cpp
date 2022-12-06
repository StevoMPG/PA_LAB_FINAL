////////////////////////////////////////////////////////////////

#include "menu.h"

////////////////////////////////////////////////////////////////

#include "../fabrica/fabrica.h"
#include "../util/util.h"

////////////////////////////////////////////////////////////////

#include "../_colecciones-genericas/String.h"

////////////////////////////////////////////////////////////////

#include <iostream>

////////////////////////////////////////////////////////////////

void DEBUG_Nicknames ()
{
	auto const fabrica   = Fabrica::Instancia();
	auto const sistema   = fabrica->Sistema();
	auto const nicknames = sistema->Nicknames();

	auto const Test = [ & ]
	(	ICollectible* const collectible
	){
		auto const str      = dynamic_cast<String*>( collectible );
		auto const nickname = str->getValue();

		std::cout << "\t" << nickname << "\n" ;
	};

	Util::Foreach( nicknames, Test );

	delete( nicknames );
}

////////////////////////////////////////////////////////////////