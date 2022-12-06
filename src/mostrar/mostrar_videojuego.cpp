////////////////////////////////////////////////////////////////

#include "mostrar.h"

#include <iostream>

////////////////////////////////////////////////////////////////

void Mostrar::Videojuego
(	Dt_Videojuego const dt_videojuego
){
	std::cout
		<< "Nombre:           " << dt_videojuego.nombre      << "\n"
		<< "Descripcion:      " << dt_videojuego.descripcion << "\n"
		<< "Costo Mensual:    " << dt_videojuego.mensual     << "\n"
		<< "Costo trimestral: " << dt_videojuego.trimestral  << "\n"
		<< "Costo Anual:      " << dt_videojuego.anual       << "\n"
		<< "Costo Vitalicio:  " << dt_videojuego.vitalicia   << "\n"
		<< "Plataforma        " << dt_videojuego.plataforma  << "\n"
		<< "Genero:           " << dt_videojuego.genero      << "\n"
		<< "Categorias: \n";

	Mostrar::Lista( dt_videojuego.categorias );
}

////////////////////////////////////////////////////////////////