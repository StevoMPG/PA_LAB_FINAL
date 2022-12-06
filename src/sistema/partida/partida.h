////////////////////////////////////////////////////////////////

#include "../clases.h"

////////////////////////////////////////////////////////////////

class Partida : public ICollectible
{
	private:
		int         id         ;
		::Jugador*  jugador    ;
		Videojuego* videojuego ;
		Fecha       fecha      ;

	public:
		Partida
		(	::Jugador*  const jugador
		,	Videojuego* const videojuego
		,	Fecha       const fecha
		);

		::Jugador* Jugador ();
		int Id ();
};

////////////////////////////////////////////////////////////////

class Individual : public Partida
{
	private:
		Individual* continua;

	public:
		Individual
		(	::Jugador*  const jugador
		,	Videojuego* const videojuego
		,	Fecha       const fecha
		,	Individual* const continua
		);
};

////////////////////////////////////////////////////////////////

class Multijugador : public Partida
{
	private:
		bool         transmitida ;
		IDictionary* unidos      ;
		IDictionary* abandona    ;

	public:
		Multijugador
		(	::Jugador*   const jugador
		,	Videojuego*  const videojuego
		,	Fecha        const fecha
		,	bool         const transmitida
		,	IDictionary* const unidos
		);

		IDictionary* Abandona ();
		IDictionary* Unidos   ();
};

////////////////////////////////////////////////////////////////

struct Abandona : public ICollectible
{
	Jugador* jugador ;
	Fecha    fecha   ;

	Abandona
	(	Jugador* const jugador
	,	Fecha    const fecha
	);
};

////////////////////////////////////////////////////////////////