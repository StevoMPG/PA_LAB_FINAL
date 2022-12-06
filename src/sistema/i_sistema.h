////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "../datatypes/datatypes.h"
#include "../_colecciones-genericas/interfaces/IDictionary.h"

////////////////////////////////////////////////////////////////

class I_Sistema
{
	public:
		virtual Dt_Usuario*  Dt_Usuario_Sesion () = 0;
		virtual IDictionary* Nicknames         () = 0;
		virtual IDictionary* Dt_Usuarios       () = 0;
		virtual IDictionary* Categorias        () = 0;
		virtual IDictionary* Plataformas       () = 0;
		virtual IDictionary* Generos           () = 0;

		virtual void         Agregar_Usuario      ( Dt_Usuario* )     = 0;
		virtual void         Agregar_Categoria    ( Dt_Categoria )    = 0;
		virtual void         Agregar_Videojuego   ( Dt_Videojuego )   = 0;
		virtual void         Agregar_Subscripcion ( Dt_Subscripcion ) = 0;
		virtual void         Agregar_Partida      ( Dt_Partida* )     = 0;
		virtual void         Agregar_Puntaje      ( Dt_Puntaje )      = 0;
		virtual bool         Iniciar_Sesion       ( string, string )  = 0;
		virtual void         Cerrar_Sesion        ()                  = 0;
		virtual void         Abandonar_Partida    (	Dt_Abandona )     = 0;
		virtual void         Finalizar_Partida    (	Dt_Finaliza )     = 0;
		virtual void         Cargar_Datos         ()                  = 0;
};

////////////////////////////////////////////////////////////////