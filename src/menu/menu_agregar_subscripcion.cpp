////////////////////////////////////////////////////////////////

#include "menu.h"

////////////////////////////////////////////////////////////////

void Menu::Agregar_Subscripcion ()
{
	// mostrando en listas separadas
	// 	el nombre y costo por tipo de suscripción

	// auto const activos    = Sistema::Subscripciones_Activos();
	// auto const inactivos  = Sistema::Subscripciones_Inactivos();
	// auto const videojuego = Ingresar::Videojuego( activos, inactivos );
	// auto const activa     = Sistema::Subscripcion_Activa( videojuego );

	// if( activa == nullptr
	// or  (   activa->tipo != vitalicia
	// 	and Ingresar::Confirmacion( "Reemplazar?" )
	//     )
	// ){
	// 	auto const subscripcion = Dt_Subscripcion
	// 	{	.jugador    = sistema->Usuario_Sesion().email
	// 	,	.videojuego = videojuego
	// 	,	.tipo       = Ingresar::Tipo_Subscripcion()
	// 	,	.pago       = Ingresar::Metodo_Pago()  // tarjeta / paypal
	//  ,	.fecha      = sistema->Fecha()
	// 	};

	// 	if( Ingresar::Confirmacion() )
	// 		Sistema::Agregar_Subscripcion( subscripcion );
	// }

	// delete inactivos;
	// delete activos;
	// delete activa;
}

////////////////////////////////////////////////////////////////