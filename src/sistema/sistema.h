////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../singleton.h"
#include "i_sistema.h"
#include "clases.h"

////////////////////////////////////////////////////////////////

class Sistema
: public I_Sistema
, public Singleton<Sistema>
{
	private:
		Usuario*     usuario_sesion;

		IDictionary* usuarios        ;
		IDictionary* jugadores       ;
		IDictionary* desarrolladores ;

		IDictionary* generos     ;
		IDictionary* categorias  ;
		IDictionary* plataformas ;

		IDictionary* videojuegos ;

		IDictionary* partidas     ;
		IDictionary* individuales ;
		IDictionary* multijugador ;

		void Inicializar () override;

		// IDictionary* Buscar_Categorias ( IDictionary* );
		IDictionary*  Buscar_Categorias   ( string* );
		Usuario*      Buscar_Usuario      ( string  );
		Jugador*      Buscar_Jugador      ( string  );
		IDictionary*  Buscar_Jugadores    ( string* );
		Videojuego*   Buscar_Videojuego   ( string  );
		Partida*      Buscar_Partida      ( int     );
		Individual*   Buscar_Individual   ( int     );
		Multijugador* Buscar_Multijugador ( int     );

		void Agregar_Partida_Individual   ( Dt_Individual*   );
		void Agregar_Partida_Multijugador (	Dt_Multijugador* );
		void Abandonar_Unidos             ( int, Fecha, IDictionary* );


	public:
		              ~Sistema          ();

		Dt_Usuario*  Dt_Usuario_Sesion    () override;
		IDictionary* Nicknames            () override;
		IDictionary* Dt_Usuarios          () override;
		IDictionary* Categorias           () override;
		IDictionary* Plataformas          () override;
		IDictionary* Generos              () override;
		void         Agregar_Usuario      ( Dt_Usuario* )     override;
		void         Agregar_Categoria    ( Dt_Categoria )    override;
		void         Agregar_Videojuego   ( Dt_Videojuego )   override;
		void         Agregar_Subscripcion ( Dt_Subscripcion ) override;
		void         Agregar_Partida      ( Dt_Partida* )     override;
		void         Agregar_Puntaje      ( Dt_Puntaje )      override;
		bool         Iniciar_Sesion       ( string, string )  override;
		void         Cerrar_Sesion        ()                  override;
		void         Abandonar_Partida    (	Dt_Abandona )     override;
		void         Finalizar_Partida    (	Dt_Finaliza )     override;
		void         Cargar_Datos         ()                  override;
};

////////////////////////////////////////////////////////////////