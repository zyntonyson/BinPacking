#include "binpacking_data.h"
#include "binpacking_solver.h"


int main()
{
	binpacking_data *ejemplo;
	ejemplo = new binpacking_data("binpack3.dat");

	binpacking_solver *solucion;
	solucion = new binpacking_solver(ejemplo);
	solucion->solve();
	
	delete ejemplo;
	delete solucion;
	system("pause");
	return 0;
}