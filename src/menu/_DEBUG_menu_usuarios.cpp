////////////////////////////////////////////////////////////////

#include "menu.h"

////////////////////////////////////////////////////////////////

#include "../fabrica/fabrica.h"
#include "../util/util.h"

////////////////////////////////////////////////////////////////

#include <iostream>

////////////////////////////////////////////////////////////////

void DEBUG_Usuarios ()
{
	auto const fabrica     = Fabrica::Instancia();
	auto const sistema     = fabrica->Sistema();
	auto const dt_usuarios = sistema->Dt_Usuarios();

	auto const Test = [ & ]
	(	ICollectible* const collectible
	){
		auto const dt_usuario = dynamic_cast<Dt_Usuario*>( collectible );
		auto const email      = dt_usuario->email;

		std::cout << "\t" << email << "\n" ;
	};

	Util::Foreach( dt_usuarios, Test );
	Util::Liberar( dt_usuarios );
}

////////////////////////////////////////////////////////////////