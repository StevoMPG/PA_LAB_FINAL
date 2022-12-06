////////////////////////////////////////////////////////////////

#include "../clases_cpp.h"

////////////////////////////////////////////////////////////////

Videojuego::Videojuego
(	Dt_Videojuego const dt_videojuego
,	IDictionary*  const categorias
,	Usuario*      const desarrollador
){
	this->nombre         = dt_videojuego.nombre      ;
	this->descripcion    = dt_videojuego.descripcion ;
	this->mensual        = dt_videojuego.mensual     ;
	this->trimestral     = dt_videojuego.trimestral  ;
	this->anual          = dt_videojuego.anual       ;
	this->vitalicia      = dt_videojuego.vitalicia   ;
	this->categorias     = categorias                ;
	this->desarrollador  = desarrollador             ;
	this->subscripciones = new OrderedDictionary()   ;
}

////////////////////////////////////////////////////////////////

void Videojuego::Agregar_Subscripcion
(	Subscripcion* const subscripcion
,	string        const jugador
){
	auto const key = new String( jugador.c_str() );
	this->subscripciones->add( key, subscripcion );
}

////////////////////////////////////////////////////////////////

void Videojuego::Agregar_Puntaje
(	Puntaje* const puntaje
,	string   const jugador
){
	auto const key = new String( jugador.c_str() );
	this->subscripciones->add( key, puntaje );
}

////////////////////////////////////////////////////////////////