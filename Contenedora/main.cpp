#include <iostream>
#include "Contenedor.h"



int main()
{
	double arrar[3]{ 32.3,23.3,45.3 };

	contenedor::Contenedor con{ arrar,3 };
	
	con.mostrarDatos();

	std::size_t num{ 3 };
	
	auto obje = contenedor::validacionObjContenedor(nullptr, num);

	if (obje)
	{
		obje->mostrarDatos();
	}
	else
	{
		std::cout << "error";
	}

	return 0;
}