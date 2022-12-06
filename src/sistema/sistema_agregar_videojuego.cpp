////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Videojuego
(	Dt_Videojuego dt_videojuego
){
	auto const nombre = dt_videojuego.nombre.c_str();
	auto const key    = new String( nombre );
	auto const existe = this->videojuegos->member( key );

	if( not existe )
	{
		Util::Agregar( & dt_videojuego.categorias, dt_videojuego.genero     );
		Util::Agregar( & dt_videojuego.categorias, dt_videojuego.plataforma );
		auto const categorias    = Buscar_Categorias( dt_videojuego.categorias );
		auto const desarrollador = Buscar_Usuario( dt_videojuego.desarrollador );
		auto const videojuego    = new Videojuego
		(	dt_videojuego
		,	categorias
		,	desarrollador
		);

		this->videojuegos->add( key, videojuego );
	}
	else
		delete key;
}

////////////////////////////////////////////////////////////////