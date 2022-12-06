////////////////////////////////////////////////////////////////

#include "sistema_cpp.h"

////////////////////////////////////////////////////////////////

void Sistema::Cargar_Datos ()
{
	Dt_Desarrollador const desarrolladores [] =
	{	{ "ironhide@mail.com" , "123" , "Ironhide Game Studio" }
	,	{ "epic@mail.com"     , "123" , "Epic Games"           }
	,	{ "mojang@mail.com"   , "123" , "Mojang Studios"       }
	,	{ "ea@mail.com"       , "123" , "EA Sports"            }
	};

	Dt_Jugador const jugadores [] =
	{	{ "gamer@mail.com"  , "123" , "" , "gamer"  }
	,	{ "ari@mail.com"    , "123" , "" , "ari"    }
	,	{ "ibai@mail.com"   , "123" , "" , "ibai"   }
	,	{ "camila@mail.com" , "123" , "" , "camila" }
	};

	Dt_Categoria const categorias [] =
	{	/*  1 */ { "PC",            ""                                                             , plataforma }
	,	/*  2 */ { "PS4",           ""                                                             , plataforma }
	,	/*  3 */ { "Xbox One",      ""                                                             , plataforma }
	,	/*  4 */ { "Switch",        ""                                                             , plataforma }
	,	/*  5 */ { "Xbox X",        ""                                                             , plataforma }
	,	/*  6 */ { "PS5",           ""                                                             , plataforma }
	,	/*  7 */ { "Deporte",       ""                                                             , genero     }
	,	/*  8 */ { "Supervivencia", ""                                                             , genero     }
	,	/*  9 */ { "Estrategia",    ""                                                             , genero     }
	,	/* 10 */ { "Accion",        ""                                                             , genero     }
	,	/* 11 */ { "Aventura",      ""                                                             , genero     }
	,	/* 12 */ { "Teen",          "Su contenido esta dirigido a jovenes de 13 anios en adelante" , otro       }
	,	/* 13 */ { "E",             "Su contenido esta dirigido para todo publico"                 , otro       }
	};

	string categorias_videojuego [4][6] =
	{	{ "PC" , "PS4"    , "PS5"           , "Supervivencia"            , "" }
	,	{ "PC" , "PS4"    , "Xbox One"      , "Xbox X" , "Deporte"       , "" }
	,	{ "PC" , "Xbox X" , "Supervivencia"                              , "" }
	,	{ "PC" , "PS4"    , "Xbox One"      , "Switch" , "Supervivencia" , "" }
	};

	Dt_Videojuego const videojuegos [] =
	{	{ "ironhide@mail.com" , "KingdomRush" , "" , 1.0 , 2.0 ,  7.0 , 14.0 , "" , "" , categorias_videojuego[0] }
	,	{ "epic@mail.com"     , "Fortnite"    , "" , 3.0 , 8.0 , 30.0 , 60.0 , "" , "" , categorias_videojuego[1] }
	,	{ "mojang@mail.com"   , "Minecraft"   , "" , 2.0 , 5.0 , 20.0 , 40.0 , "" , "" , categorias_videojuego[2] }
	,	{ "ea@mail.com"       , "FIFA 21"     , "" , 3.0 , 8.0 , 28.0 , 50.0 , "" , "" , categorias_videojuego[3] }
	};

	Dt_Subscripcion const subscripciones [] =
	{	{ "gamer@mail.com" , "KingdomRush" , trimestral , paypal  , Fecha{ .anio = 2021, .mes =  6, .dia =  1, .hora =  9, .minuto =  0 } }
	,	{ "gamer@mail.com" , "Fortnite"    , trimestral , tarjeta , Fecha{ .anio = 2021, .mes =  6, .dia =  2, .hora = 11, .minuto =  0 } }
	,	{ "ari@mail.com"   , "Fortnite"    , mensual    , paypal  , Fecha{ .anio = 2021, .mes =  6, .dia =  4, .hora =  9, .minuto =  0 } }
	,	{ "ari@mail.com"   , "Minecraft"   , anual      , tarjeta , Fecha{ .anio = 2021, .mes =  6, .dia = 11, .hora =  9, .minuto =  0 } }
	,	{ "ibai@mail.com"  , "Fortnite"    , mensual    , tarjeta , Fecha{ .anio = 2021, .mes =  6, .dia =  3, .hora =  7, .minuto =  0 } }
	,	{ "ibai@mail.com"  , "Minecraft"   , vitalicia  , tarjeta , Fecha{ .anio = 2020, .mes = 12, .dia = 21, .hora = 13, .minuto =  0 } }
	};

	////////////////////////////////////////////////////////////

	Dt_Puntaje const puntajes [] =
	{	{ "gamer@mail.com" , "KingdomRush" , cuatro }
	,	{ "gamer@mail.com" , "Fortnite"    , cinco  }
	,	{ "ari@mail.com"   , "Fortnite"    , cinco  }
	,	{ "ari@mail.com"   , "Minecraft"   , tres   }
	};

	////////////////////////////////////////////////////////////////

	Dt_Individual const individuales [] =
	{	/* 1 */ { "gamer@mail.com" , "KingdomRush" , Fecha{ .anio = 2021, .mes =  6, .dia =  2, .hora =  9, .minuto =  0 } , -1 }
	,	/* 2 */ { "gamer@mail.com" , "KingdomRush" , Fecha{ .anio = 2021, .mes =  6, .dia =  3, .hora = 15, .minuto =  0 } ,  1 }
	,	/* 3 */ { "ari@mail.com"   , "Minecraft"   , Fecha{ .anio = 2021, .mes =  6, .dia = 12, .hora = 16, .minuto =  0 } , -1 }
	};

	////////////////////////////////////////////////////////////////

	string unidos [3][3] =
	{	{ "ari@mail.com", "ibai@mail.com", "" }
	,	{ "ari@mail.com", "ibai@mail.com", "" }
	,	{ "ibai@mail.com",                 "" }
	};

	Dt_Multijugador const multijugador [] =
	{	/* 4 */ { "gamer@mail.com" , "Fortnite"  , Fecha{ .anio = 21, .mes =  6, .dia =  5, .hora = 17, .minuto =  0 },  true  , unidos[0] }
	,	/* 5 */ { "gamer@mail.com" , "Fortnite"  , Fecha{ .anio = 21, .mes =  6, .dia =  6, .hora = 17, .minuto =  0 },  true  , unidos[1] }
	,	/* 6 */ { "ari@mail.com"   , "Minecraft" , Fecha{ .anio = 21, .mes =  6, .dia = 12, .hora = 20, .minuto =  0 },  false , unidos[2] }
	};

	////////////////////////////////////////////////////////////////

	Dt_Abandona const abandona [] =
	{
		{ 4, "ari@mail.com", Fecha{ .anio = 2021, .mes =  6, .dia =  5, .hora = 18, .minuto =  0 } },
		{ 5, "ari@mail.com", Fecha{ .anio = 2021, .mes =  6, .dia =  6, .hora = 17, .minuto = 30 } }
	};

	////////////////////////////////////////////////////////////////

	Dt_Finaliza const finaliza [] =
	{	{ 1, Fecha{ .anio = 2021, .mes =  6, .dia =  2, .hora = 10, .minuto =  0 } }
	,	{ 2, Fecha{ .anio = 2021, .mes =  6, .dia =  3, .hora = 16, .minuto =  0 } }
	,	{ 4, Fecha{ .anio = 2021, .mes =  6, .dia =  5, .hora = 19, .minuto =  0 } }
	,	{ 5, Fecha{ .anio = 2021, .mes =  6, .dia =  6, .hora = 19, .minuto =  0 } }
	};

	////////////////////////////////////////////////////////////

	for( auto each : desarrolladores ) Sistema::Agregar_Usuario      ( & each );
	for( auto each : jugadores )       Sistema::Agregar_Usuario      ( & each );
	for( auto each : categorias )      Sistema::Agregar_Categoria    (   each );
	for( auto each : videojuegos )     Sistema::Agregar_Videojuego   (   each );
	for( auto each : subscripciones )  Sistema::Agregar_Subscripcion (   each );
	for( auto each : puntajes )        Sistema::Agregar_Puntaje      (   each );
	for( auto each : individuales )    Sistema::Agregar_Partida      ( & each );
	for( auto each : multijugador )    Sistema::Agregar_Partida      ( & each );
	for( auto each : abandona )        Sistema::Abandonar_Partida    (   each );
	for( auto each : finaliza )        Sistema::Finalizar_Partida    (   each );
 }

////////////////////////////////////////////////////////////////