////////////////////////////////////////////////////////////////

#include "../clases_cpp.h"

////////////////////////////////////////////////////////////////

Categoria::Categoria
(	Dt_Categoria const categoria
){
	this->nombre      = categoria.nombre      ;
	this->descripcion = categoria.descripcion ;
}

////////////////////////////////////////////////////////////////

string Categoria::Nombre      () const { return this->nombre      ; }
string Categoria::Descripcion () const { return this->descripcion ; }

////////////////////////////////////////////////////////////////

Plataforma::Plataforma ( Dt_Categoria const categoria ) : Categoria( categoria ) {}
    Genero::Genero     ( Dt_Categoria const categoria ) : Categoria( categoria ) {}
      Otro::Otro       ( Dt_Categoria const categoria ) : Categoria( categoria ) {}

////////////////////////////////////////////////////////////////