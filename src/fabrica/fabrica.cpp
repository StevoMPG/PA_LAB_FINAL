////////////////////////////////////////////////////////////////

#include "fabrica.h"

#include "../menu/menu.h"
#include "../mostrar/mostrar.h"
#include "../ingresar/ingresar.h"
#include "../sistema/sistema.h"

////////////////////////////////////////////////////////////////

Fabrica::~Fabrica ()
{
	delete     Menu::Instancia();
	delete Ingresar::Instancia();
	delete  Sistema::Instancia();
}

////////////////////////////////////////////////////////////////

I_Menu*     Fabrica::Menu     () { return     Menu::Instancia(); }
I_Mostrar*  Fabrica::Mostrar  () { return  Mostrar::Instancia(); }
I_Ingresar* Fabrica::Ingresar () { return Ingresar::Instancia(); }
I_Sistema*  Fabrica::Sistema  () { return  Sistema::Instancia(); }

////////////////////////////////////////////////////////////////