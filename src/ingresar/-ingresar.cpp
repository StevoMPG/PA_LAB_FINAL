////////////////////////////////////////////////////////////////

// #include <iostream>

////////////////////////////////////////////////////////////////

// #include "-ingresar.h"

////////////////////////////////////////////////////////////////

// string Ingresar :: Texto ()
// {
// 	string texto;
// 	std::getline( std::cin, texto );
// 	return texto;
// }

////////////////////////////////////////////////////////////////

// int Ingresar :: Entero ()
// {
// 	try
// 	{
// 		size_t       largo;
// 		string const texto  = Ingresar::Texto();
// 		int    const numero = std::stoi( texto, &largo );

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

// int Ingresar :: Entero_Entre (
// 	string const mensaje,
// 	int    const min,
// 	int    const max
// ){
// 	while( true )
// 	{
// 		try
// 		{
// 			std::cout << mensaje ;

// 			int const numero = Ingresar::Entero();

// 			if( numero < min
// 			or  numero > max )
// 				throw std::invalid_argument( "valor invalido" );
// 			else
// 				return numero;
// 		}
// 		catch( std::invalid_argument exception )
// 		{
// 			std::cout << "Error: " << exception.what() << "!\n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// int Ingresar::Opcion ()
// {
// 	try
// 	{
// 		return Ingresar::Entero();
// 	}
// 	catch( std::invalid_argument exception )
// 	{
// 		return - 1;
// 	}
// }

////////////////////////////////////////////////////////////////

// int Ingresar::Entero_Valido ()
// {
// 	while( true )
// 		try
// 		{
// 			return Ingresar::Entero();
// 		}
// 		catch( std::exception exception )
// 		{
// 			std::cout << "Error: numero invalido!\n";
// 		}
// }

////////////////////////////////////////////////////////////////

// int Ingresar::Positivo(
// 	string const mensaje = ""
// ){
// 	std::cout << mensaje ;

// 	int const numero = Ingresar::Entero();

// 	if( numero < 0 )
// 		throw std::invalid_argument( "" );
// 	else
// 		return numero;
// }

////////////////////////////////////////////////////////////////

// int Ingresar::Natural (
// 	string const mensaje
// ){
// 	while( true )
// 		try
// 		{
// 			std::cout << mensaje ;

// 			int const numero = Ingresar::Entero();

// 			if( numero < 1 )
// 				throw std::invalid_argument( "" );
// 			else
// 				return numero;
// 		}
// 		catch( std::exception exception )
// 		{
// 			std::cout << "Error: numero invalido!\n";
// 		}
// }

////////////////////////////////////////////////////////////////

// string Ingresar::Texto_Minimo (
// 	unsigned int const minimo
// ){
// 	string const texto = Ingresar::Texto();

// 	string const mensaje_error
// 		= "minimo "
// 		+ std::to_string( minimo )
// 		+ " caracteres";

// 	if( texto.size() < minimo )
// 		throw std::invalid_argument( mensaje_error );

// 	return texto;
// }

////////////////////////////////////////////////////////////////

// string Ingresar::Nickname(
// 	string const mensaje
// ){
// 	while( true )
// 	{
// 		try
// 		{
// 			std::cout << mensaje ;
// 			return Ingresar::Texto_Minimo( 3 );
// 		}
// 		catch( std::invalid_argument exception )
// 		{
// 			std::cout << "Error: " << exception.what() << "! \n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// string Ingresar::Contrasena ()
// {
// 	while( true )
// 	{
// 		try
// 		{
// 			std::cout << "Contraseña: ";
// 			return Ingresar::Texto_Minimo( 3 );
// 		}
// 		catch( std::invalid_argument exception )
// 		{
// 			std::cout << "Error: " << exception.what() << "! \n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// int Ingresar::Edad ()
// {
// 	while( true )
// 	{
// 		try
// 		{
// 			std::cout << "Edad: ";
// 			int edad = Ingresar::Positivo();
// 			return edad;
// 		}
// 		catch( std::exception exception )
// 		{
// 			std::cout << "Error: edad invalida!\n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// string Ingresar::Nombre (
// 	string const mensaje
// ){
// 	while( true )
// 	{
// 		try
// 		{
// 			std::cout << mensaje ;
// 			return Ingresar::Texto_Minimo( 1 );
// 		}
// 		catch( std::invalid_argument exception )
// 		{
// 			std::cout << "Error: " << exception.what() << "! \n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// string Ingresar::Minuscula (
// 	string texto
// ){
// 	for( char& each : texto )
// 	{
// 		each = tolower( each );
// 	}
// 	return texto;
// }

////////////////////////////////////////////////////////////////

// TipoJuego Ingresar::Genero ()
// {
// 	while( true )
// 	{
// 		Mostrar_Generos();

// 		std::cout << "Genero: ";

// 		string const texto     = Ingresar::Texto();
// 		string const minuscula = Ingresar::Minuscula( texto );
// 		try
// 		{
// 			for( int i = 0; i < sizeof(generos)/sizeof(char*); i += 1 )
// 				if( generos[ i ] == minuscula )
// 					return TipoJuego( i );

// 			throw std::invalid_argument( "genero desconocido" );
// 		}
// 		catch( std::invalid_argument exception )
// 		{
// 			std::cout << "Error: " << exception.what() << "! \n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// float Ingresar::Duracion (
// 	string const mensaje = "Duracion: "
// ){
// 	while( true )
// 	{
// 		try
// 		{
// 			std::cout << mensaje ;

// 			float const duracion  = Ingresar::Real();

// 			if( duracion < 0 )
// 				throw std::invalid_argument( "valor invalido" );
// 			else
// 				return duracion;
// 		}
// 		catch( std::invalid_argument exception )
// 		{
// 			std::cout << "Error: " << exception.what() << "!\n";
// 		}
// 	}
// }

////////////////////////////////////////////////////////////////

// string* Ingresar::Jugadores (
// 	int const cantidad
// ){
// 	string const mensaje = "Nickname jugador unido: ";
// 	string* jugadores = new string [ cantidad ];

// 	for( int i = 0; i < cantidad; i += 1 )
// 		jugadores[ i ] = Ingresar::Nickname( mensaje );

// 	return jugadores;
// }

////////////////////////////////////////////////////////////////