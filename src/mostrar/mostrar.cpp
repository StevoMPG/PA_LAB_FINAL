////////////////////////////////////////////////////////////////

// #include "mostrar.h"

////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <iomanip>

////////////////////////////////////////////////////////////////

// #include "../_/String.h"

////////////////////////////////////////////////////////////////

// void Mostrar::Subscripciones
// (	ICollection* const videojuegos
// ){	//            0123456789   0123456   0123456789   01234   012345678
// 	std::cout << "videojuego | mensual | trimestral | anual | vitalicia \n";
// 	for
// 	(	auto iter = videojuegos->getIterator()
// 	;	     iter->hasCurrent()
// 	;	     iter->next()
// 	){
// 		auto const videojuego = dynamic_cast<DT_VIDEOJUEGO*>( iter->getCurrent() );

// 		std::cout
// 			<< std::left  << std::setw( 10 ) << videojuego->nombre     << " | "
// 			<< std::right << std::setw(  7 ) << videojuego->mensual    << " | "
// 			<< std::right << std::setw( 10 ) << videojuego->trimestral << " | "
// 			<< std::right << std::setw(  5 ) << videojuego->anual      << " | "
// 			<< std::right << std::setw(  9 ) << videojuego->vitalicia  << "\n";
// 	}
// }

////////////////////////////////////////////////////////////////

// void Mostrar_Categorias
// (	auto const categorias
// ){
// 	int n = 0;
// 	for
// 	(	auto const iter = categorias->getIterator()
// 	;	           iter->hasCurrent()
// 	;              iter->next()
// 	){
// 		if( auto const str = dynamic_cast<String*>( iter->getCurrent() )  )
// 		{
// 			auto const texto = str->getValue();
// 			std::cout << "\t" << ( n + 1 ) << ". " << texto << "\n";
// 		}

// 		n += 1;
// 	}
// }

////////////////////////////////////////////////////////////////

// void Mostrar_Generos ()
// {
// 	int const cantidad_generos = sizeof(generos) / sizeof(char*);

// 	std::cout << "( ";

// 	int i = 0;
// 	while( i < cantidad_generos )
// 		std::cout << generos[ i ] << ", ";

// 	std::cout << generos[ i ];
// 	std::cout << " )";
// }

////////////////////////////////////////////////////////////////