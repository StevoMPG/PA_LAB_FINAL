////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../clases.h"

////////////////////////////////////////////////////////////////

class Videojuego : public ICollectible
{
	private:
		string       nombre         ;
		string       descripcion    ;
		double       mensual        ;
		double       trimestral     ;
		double       anual          ;
		double       vitalicia      ;
		IDictionary* categorias     ;	// Categoria*
		Usuario*     desarrollador  ;
		IDictionary* subscripciones ;	// Categoria*

	public:
		Videojuego
		(	Dt_Videojuego const dt_videojuego
		,	IDictionary*  const categorias
		,	Usuario*      const desarrollador
		);

		void Agregar_Subscripcion
		(	Subscripcion* const subscripcion
		,	string        const jugador
		);

		void Agregar_Puntaje
		(	Puntaje* const puntaje
		,	string   const jugador
		);
};

////////////////////////////////////////////////////////////////