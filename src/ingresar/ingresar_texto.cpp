////////////////////////////////////////////////////////////////

#include "ingresar.h"

////////////////////////////////////////////////////////////////

#include <iostream>

////////////////////////////////////////////////////////////////

string Ingresar::Texto
(	string const mensaje
){
	std::cout << mensaje;

	string texto;
	std::getline( std::cin, texto );

	return texto;
}

////////////////////////////////////////////////////////////////