////////////////////////////////////////////////////////////////

#include "dt_usuario.h"

////////////////////////////////////////////////////////////////

Dt_Usuario::~Dt_Usuario () = default;

////////////////////////////////////////////////////////////////

Dt_Jugador::Dt_Jugador
(	string const email
,	string const contrasenia
,	string const descripcion
,	string const nickname
){
	this->email       = email       ;
	this->contrasenia = contrasenia ;
	this->descripcion = descripcion ;
	this->nickname    = nickname    ;
}

////////////////////////////////////////////////////////////////

Dt_Desarrollador::Dt_Desarrollador
(	string const email
,	string const contrasenia
,	string const empresa
){
	this->email       = email       ;
	this->contrasenia = contrasenia ;
	this->empresa     = empresa     ;
}

////////////////////////////////////////////////////////////////