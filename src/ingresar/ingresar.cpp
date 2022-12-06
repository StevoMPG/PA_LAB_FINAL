////////////////////////////////////////////////////////////////

#include <iostream>

////////////////////////////////////////////////////////////////

// #include "../_/String.h"
#include "ingresar.h"

////////////////////////////////////////////////////////////////

// DT_CATEGORIA Ingresar::Categoria
// (	ICollection const categorias
// ){
// 	Mostrar_Categorias( categorias );  // nombre y descripcion

// 	auto const rango     = { .min = 1, .max = size( categorias ) };
// 	auto const categoria = Ingresar::Entero( rango );

// 	return categoria;
// }

////////////////////////////////////////////////////////////////

// string Ingresar :: Email ()
// {
// 	std::cout << "Email: ";
// 	return Ingresar::Texto();
// }

////////////////////////////////////////////////////////////////
// double Ingresar :: Real ()
// {
// 	try
// 	{
// 		size_t       largo;
// 		string const texto  = Ingresar::Texto();
// 		double const numero = std::stod( texto, &largo );

// 		if( largo != texto.size() )
// 			throw std::invalid_argument( "valor invalido" );
// 		else
// 			return numero;
// 	}
// 	catch( std::exception exception )
// 	{
// 		throw std::invalid_argument( "valor invalido" );
// 	}
// }

////////////////////////////////////////////////////////////////

// double Ingresar :: Real (
// 	string const mensaje
// ){
// 	while( true )
// 	{
// 		try
// 		{
// 			std::cout << mensaje ;

// 			double const numero = Ingresar::Real();

// 			return numero;
// 		}
// 		catch( std::invalid_argument exception )
// 		{
// 			std::cout << "Error: " << exception.what() << "!\n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// FECHA Ingresar::Fecha (
// 	string const mensaje = "Fecha: "
// ){
// 	RANGO const rango_anio   = { .min = 1990, .max = 3000 };
// 	RANGO const rango_mes    = { .min =    1, .max =   12 };
// 	RANGO const rango_dia    = { .min =    1, .max =   31 };
// 	RANGO const rango_hora   = { .min =    0, .max =   23 };
// 	RANGO const rango_minuto = { .min =    0, .max =   59 };

// 	int const anio   = Ingresar::Entero( "(Fecha) Año:  ", rango_anio   );
// 	int const mes    = Ingresar::Entero( "(Fecha) Mes:  ", rango_mes    );
// 	int const dia    = Ingresar::Entero( "(Fecha) Dia:  ", rango_dia    );
// 	int const hora   = Ingresar::Entero( "(Fecha) Hora: ", rango_hora   );
// 	int const minuto = Ingresar::Entero( "(Fecha) Min:  ", rango_minuto );

// 	return FECHA
// 	{
// 		.dia    = dia,
// 		.mes    = mes,
// 		.anio   = anio,
// 		.hora   = hora,
// 		.minuto = minuto
// 	};
// }

////////////////////////////////////////////////////////////////