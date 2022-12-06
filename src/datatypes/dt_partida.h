////////////////////////////////////////////////////////////////

#include "_datatypes.h"

////////////////////////////////////////////////////////////////

struct Dt_Partida
{
	string  jugador    ;
	string  videojuego ;
	Fecha   fecha      ;

	virtual ~Dt_Partida () = default;

	Dt_Partida
	(	string const jugador
	,	string const videojuego
	,	Fecha  const fecha
	){
		this->jugador    = jugador    ;
		this->videojuego = videojuego ;
		this->fecha      = fecha      ;
	}
};

////////////////////////////////////////////////////////////////

struct Dt_Individual : public Dt_Partida
{
	int continua;

	Dt_Individual
	(	string const jugador
	,	string const videojuego
	,	Fecha  const fecha
	,	int    const continua
	) : Dt_Partida( jugador, videojuego, fecha )
	{
		this->continua = continua;
	}
};

////////////////////////////////////////////////////////////////

struct Dt_Multijugador : public Dt_Partida
{
	bool    transmitida ;
	string* unidos      ;

	Dt_Multijugador
	(	string  const jugador
	,	string  const videojuego
	,	Fecha   const fecha
	,	bool    const transmitida
	,	string* const unidos
	) : Dt_Partida( jugador, videojuego, fecha )
	{
		this->transmitida = transmitida ;
		this->unidos      = unidos      ;
	}
};

////////////////////////////////////////////////////////////////

struct Dt_Abandona
{
	int    partida ;
	string jugador ;
	Fecha  fecha   ;
};

////////////////////////////////////////////////////////////////

struct Dt_Finaliza
{
	int   partida ;
	Fecha fecha   ;
};

////////////////////////////////////////////////////////////////