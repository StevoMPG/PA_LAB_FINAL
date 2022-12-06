////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "i_menu.h"
#include "../singleton.h"
#include "../opcion/opcion.h"

////////////////////////////////////////////////////////////////

class Menu
: public I_Menu
, public Singleton<Menu>
{
	public:
		     ~Menu     () = default;
		void Principal () override;

	private:
		Opcion::Resultado Inicial       ();
		Opcion::Resultado Desarrollador ();
		Opcion::Resultado Jugador       ();

	private:
		static void Abandonar_Partida    (); //   Partidas->Abandonar( dt );
		static void Agregar_Categoria    (); // - Categorias     ->Agregar( dt );
		static void Agregar_Partida      (); //   Partidas       ->Agregar( dt );
		static void Agregar_Puntaje      (); //   Puntajes       ->Agregar( dt );
		static void Agregar_Subscripcion (); //   Subscripciones ->Agregar( dt );
		static void Agregar_Usuario      (); // - Usuarios       ->Agregar( dt );
		static void Agregar_Videojuego   (); // - Videojuegos    ->Agregar( dt );
		static void Cambiar_Fecha        (); //   Sistema->Fecha( dt );
		static void Cargar_Datos         (); // * Sistema->Cargar_Datos();
		static void Cerrar_Sesion        (); //   Usuarios->Cerrar()
		static void Elegir_Estadisticas  (); // ?
		static void Eliminar_Videojuego  (); //   Videojuegos->Eliminar();
		static void Finalizar_Partida    (); //   Partidas->Finalizar( dt );
		static void Iniciar_Sesion       (); // - Usuarios->Sesion( dt );
		static void Salir                (); // -
		static void Ver_Estadisticas     (); // ?
		static void Ver_Videojuego       (); //   Videojuegos->Ver( dt );

	private:
		static string const titulo_abandonar_partida    ;
		static string const titulo_agregar_categoria    ;
		static string const titulo_agregar_partida      ;
		static string const titulo_agregar_puntaje      ;
		static string const titulo_agregar_subscripcion ;
		static string const titulo_agregar_usuario      ;
		static string const titulo_agregar_videojuego   ;
		static string const titulo_cambiar_fecha        ;
		static string const titulo_cargar_datos         ;
		static string const titulo_cerrar_sesion        ;
		static string const titulo_elegir_estadisticas  ;
		static string const titulo_eliminar_videojuego  ;
		static string const titulo_finalizar_partida    ;
		static string const titulo_iniciar_sesion       ;
		static string const titulo_salir                ;
		static string const titulo_ver_estadisticas     ;
		static string const titulo_ver_videojuego       ;

		static Opcion const opcion_abandonar_partida    ;
		static Opcion const opcion_agregar_categoria    ;
		static Opcion const opcion_agregar_partida      ;
		static Opcion const opcion_agregar_puntaje      ;
		static Opcion const opcion_agregar_subscripcion ;
		static Opcion const opcion_agregar_usuario      ;
		static Opcion const opcion_agregar_videojuego   ;
		static Opcion const opcion_cambiar_fecha        ;
		static Opcion const opcion_cargar_datos         ;
		static Opcion const opcion_cerrar_sesion        ;
		static Opcion const opcion_elegir_estadisticas  ;
		static Opcion const opcion_eliminar_videojuego  ;
		static Opcion const opcion_finalizar_partida    ;
		static Opcion const opcion_iniciar_sesion       ;
		static Opcion const opcion_salir                ;
		static Opcion const opcion_ver_estadisticas     ;
		static Opcion const opcion_ver_videojuego       ;

		static Opcion const opciones_inicial       [];
		static Opcion const opciones_desarrollador [];
		static Opcion const opciones_jugador       [];
};

////////////////////////////////////////////////////////////////