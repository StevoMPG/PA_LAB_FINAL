////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

static
IDictionary* Determinar_Coleccion
(	Dt_Categoria const categoria
,	IDictionary* const plataformas
,	IDictionary* const generos
){
	     if( categoria.tipo == plataforma ) return plataformas ;
	else if( categoria.tipo == genero     ) return generos     ;
	else                                    return nullptr     ;
}

////////////////////////////////////////////////////////////////

static
Categoria* Instanciar_Categoria
(	Dt_Categoria const categoria
){
	     if( categoria.tipo == plataforma ) return new Plataforma ( categoria );
	else if( categoria.tipo == genero     ) return new Genero     ( categoria );
	else                                    return new Otro       ( categoria );
}

////////////////////////////////////////////////////////////////

void Sistema::Agregar_Categoria
(	Dt_Categoria const categoria
){
	auto const categorias          = this->categorias;
	auto const instancia_categoria = Instanciar_Categoria( categoria );
	auto const nombre              = categoria.nombre.c_str();
	auto const coleccion           = Determinar_Coleccion
	(	categoria
	,	this->plataformas
	,	this->generos
	);

	this->categorias->add
	(	new String( nombre )
	,	instancia_categoria
	);

	if( coleccion != nullptr )
		coleccion->add
		(	new String( nombre )
		,	instancia_categoria
		);
}

////////////////////////////////////////////////////////////////