////////////////////////////////////////////////////////////////

#include "menu.h"
#include "../fabrica/fabrica.h"
#include "../datatypes/datatypes.h"

////////////////////////////////////////////////////////////////

void Menu::Principal ()
{
	auto const fabrica = Fabrica::Instancia();
	auto const sistema = fabrica->Sistema();
	auto const mostrar = fabrica->Mostrar();

	Opcion::Resultado resutaldo = Opcion::continuar;
	while( resutaldo != Opcion::salir )
	{
		auto const usuario = sistema->Dt_Usuario_Sesion();

		if( nullptr == usuario )
			resutaldo = Menu::Inicial();

		else
		if( dynamic_cast<Dt_Desarrollador*>( usuario ) )
			resutaldo = Menu::Desarrollador();

		else
		if( dynamic_cast<Dt_Jugador*>( usuario ) )
			resutaldo = Menu::Jugador();
	}

	mostrar->Borrar_Pantalla();
}

////////////////////////////////////////////////////////////////

Opcion::Resultado Menu::Inicial       (){ return Opcion::Manejar( opciones_inicial       ); }
Opcion::Resultado Menu::Desarrollador (){ return Opcion::Manejar( opciones_desarrollador ); }
Opcion::Resultado Menu::Jugador       (){ return Opcion::Manejar( opciones_jugador       ); }

////////////////////////////////////////////////////////////////

string const Menu::titulo_agregar_usuario      = "Alta De Usuario"        ;
string const Menu::titulo_iniciar_sesion       = "Iniciar Sesion"         ;
string const Menu::titulo_cargar_datos         = "Cargar Datos De Prueba" ;
string const Menu::titulo_salir                = "Salir"                  ;

string const Menu::titulo_agregar_categoria    = "Agregar Categoria"             ;
string const Menu::titulo_agregar_videojuego   = "Publicar Videojuego"           ;
string const Menu::titulo_eliminar_videojuego  = "Eliminar Videojuego"           ;
string const Menu::titulo_elegir_estadisticas  = "Seleccionar Estadisticas"      ;
string const Menu::titulo_ver_estadisticas     = "Consultar Estadisticas"        ;

string const Menu::titulo_agregar_subscripcion = "Suscribirse A Videojuego"       ;
string const Menu::titulo_agregar_puntaje      = "Asignar Puntaje A Videojuego"   ;
string const Menu::titulo_agregar_partida      = "Iniciar Partida"                ;
string const Menu::titulo_abandonar_partida    = "Abandonar Partida Multijugador" ;
string const Menu::titulo_finalizar_partida    = "Finalizar Partida"              ;

string const Menu::titulo_ver_videojuego       = "Ver Informacion De Videojuego" ;
string const Menu::titulo_cambiar_fecha        = "Modificar Fecha Del Sistema"   ;
string const Menu::titulo_cerrar_sesion        = "Cerrar Sesion";

////////////////////////////////////////////////////////////////

Opcion const Menu::opcion_abandonar_partida    = { Menu::Abandonar_Partida,    Menu::titulo_abandonar_partida,   Opcion::continuar  };
Opcion const Menu::opcion_agregar_categoria    = { Menu::Agregar_Categoria,    Menu::titulo_agregar_categoria,   Opcion::continuar  };
Opcion const Menu::opcion_agregar_partida      = { Menu::Agregar_Partida,      Menu::titulo_agregar_partida,     Opcion::continuar  };
Opcion const Menu::opcion_agregar_puntaje      = { Menu::Agregar_Puntaje,      Menu::titulo_agregar_puntaje,     Opcion::continuar  };
Opcion const Menu::opcion_agregar_subscripcion = { Menu::Agregar_Subscripcion, Menu::titulo_agregar_subscripcion,Opcion::continuar  };
Opcion const Menu::opcion_agregar_usuario      = { Menu::Agregar_Usuario,      Menu::titulo_agregar_usuario,     Opcion::continuar  };
Opcion const Menu::opcion_agregar_videojuego   = { Menu::Agregar_Videojuego,   Menu::titulo_agregar_videojuego,  Opcion::continuar  };
Opcion const Menu::opcion_cambiar_fecha        = { Menu::Cambiar_Fecha,        Menu::titulo_cambiar_fecha,       Opcion::continuar  };
Opcion const Menu::opcion_cargar_datos         = { Menu::Cargar_Datos,         Menu::titulo_cargar_datos,        Opcion::continuar  };
Opcion const Menu::opcion_cerrar_sesion        = { Menu::Cerrar_Sesion,        Menu::titulo_cerrar_sesion,       Opcion::volver     };
Opcion const Menu::opcion_elegir_estadisticas  = { Menu::Elegir_Estadisticas,  Menu::titulo_elegir_estadisticas, Opcion::continuar  };
Opcion const Menu::opcion_eliminar_videojuego  = { Menu::Eliminar_Videojuego,  Menu::titulo_eliminar_videojuego, Opcion::continuar  };
Opcion const Menu::opcion_finalizar_partida    = { Menu::Finalizar_Partida,    Menu::titulo_finalizar_partida,   Opcion::continuar  };
Opcion const Menu::opcion_iniciar_sesion       = { Menu::Iniciar_Sesion,       Menu::titulo_iniciar_sesion,      Opcion::volver     };
Opcion const Menu::opcion_salir                = { Menu::Salir,                Menu::titulo_salir,               Opcion::salir      };
Opcion const Menu::opcion_ver_estadisticas     = { Menu::Ver_Estadisticas,     Menu::titulo_ver_estadisticas,    Opcion::continuar  };
Opcion const Menu::opcion_ver_videojuego       = { Menu::Ver_Videojuego,       Menu::titulo_ver_videojuego,      Opcion::continuar  };

////////////////////////////////////////////////////////////////

void DEBUG_Usuarios  ();
void DEBUG_Nicknames ();

////////////////////////////////////////////////////////////////

Opcion const Menu::opciones_inicial [] =
{	opcion_agregar_usuario
,	opcion_iniciar_sesion
,	opcion_cargar_datos
,	opcion_salir
// ,	{ DEBUG_Usuarios,  "DEBUG Usuarios",  Opcion::continuar }
// ,	{ DEBUG_Nicknames, "DEBUG Nicknames", Opcion::continuar }
,	{ nullptr }
};

////////////////////////////////////////////////////////////////

Opcion const Menu::opciones_desarrollador [] =
{	opcion_agregar_categoria
,	opcion_agregar_videojuego
,	opcion_eliminar_videojuego
,	opcion_elegir_estadisticas
,	opcion_ver_estadisticas
,	opcion_ver_videojuego
,	opcion_cambiar_fecha
,	opcion_cerrar_sesion
,	{ nullptr }
};

////////////////////////////////////////////////////////////////

Opcion const Menu::opciones_jugador [] =
{	opcion_agregar_subscripcion
,	opcion_agregar_puntaje
,	opcion_agregar_partida
,	opcion_abandonar_partida
,	opcion_finalizar_partida
,	opcion_ver_videojuego
,	opcion_cambiar_fecha
,	opcion_cerrar_sesion
,	{ nullptr }
};

////////////////////////////////////////////////////////////////