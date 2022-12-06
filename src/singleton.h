////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

template< typename TIPO >
class Singleton
{
	protected :                 Singleton  () = default;
	public    : virtual        ~Singleton  () = default;
	protected : virtual  void  Inicializar () {}
	public    : static   TIPO* Instancia   ()
	{
		static TIPO* instancia = nullptr;

		if( instancia == nullptr )
		{
			instancia = new TIPO();

			Singleton* const singleton = instancia;
			singleton -> Inicializar();
		}

		return instancia;
	}
};

////////////////////////////////////////////////////////////////