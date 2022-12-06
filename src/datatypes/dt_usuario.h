////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

#include "_datatypes.h"

////////////////////////////////////////////////////////////////

struct Dt_Usuario : public ICollectible
{
	virtual ~Dt_Usuario () = 0;

	string email;
	string contrasenia;
};

////////////////////////////////////////////////////////////////

struct Dt_Desarrollador : public Dt_Usuario
{
	string empresa;

	Dt_Desarrollador () = default;
	Dt_Desarrollador
	(	string const email
	,	string const contrasenia
	,	string const empresa
	);
};

////////////////////////////////////////////////////////////////

struct Dt_Jugador : public Dt_Usuario
{
	string descripcion;
	string nickname;

	Dt_Jugador () = default;
	Dt_Jugador
	(	string const email
	,	string const contrasenia
	,	string const descripcion
	,	string const nickname
	);
};

////////////////////////////////////////////////////////////////