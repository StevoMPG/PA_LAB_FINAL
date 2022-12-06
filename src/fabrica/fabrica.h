////////////////////////////////////////////////////////////////

#include "../singleton.h"

////////////////////////////////////////////////////////////////

#include "../ingresar/i_ingresar.h"
#include "../sistema/i_sistema.h"
#include "../mostrar/i_mostrar.h"
#include "../menu/i_menu.h"

////////////////////////////////////////////////////////////////

class Fabrica : public Singleton<Fabrica>
{
	public:
		            ~Fabrica ();
		I_Ingresar* Ingresar ();
		I_Menu*     Menu     ();
		I_Mostrar*  Mostrar  ();

		I_Sistema*  Sistema  ();
};

////////////////////////////////////////////////////////////////