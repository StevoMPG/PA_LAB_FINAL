////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "i_mostrar.h"
#include "../singleton.h"

////////////////////////////////////////////////////////////////

// #include "_/interfaces/ICollection.h"
// #include "_/interfaces/IDictionary.h"

////////////////////////////////////////////////////////////////

// #include "_datatypes.h"
// #include "mostrar/mensaje_error.h"

////////////////////////////////////////////////////////////////

class Mostrar
: public I_Mostrar
, public Singleton<Mostrar>
{
	public:
		void Borrar_Pantalla ()                 override;
		void Error           ( string )         override;
		void Titulo          ( string )         override;
		void Opciones        ( Opcion const* )  override;
		void Enum            ( string const* )  override;
		void Lista           ( string* )        override;
		void Lista           ( IDictionary* )   override;
		void Lista           ( ICollection* )   override;
		void Videojuego      ( Dt_Videojuego )  override;

		// void Subscripciones ( ICollection*  ) override;
		// void Partidas       ( ICollection*  ) override;
			// orden cronológico
			// id | fecha | hora | duracion

		// void Partidas_Multijugador ( ICollection* ) override;
			// id, fecha, videojuego, transmitida, creador, unidos

};

////////////////////////////////////////////////////////////////