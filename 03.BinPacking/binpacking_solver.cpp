#include "binpacking_solver.h"




binpacking_solver::binpacking_solver(binpacking_data * ks)
{

	_ks = ks;  /* Archivo de origen*/
	_model = IloModel(_env);
	_cplex = IloCplex(_model);


	/*DEFINICION DE VARIABLES*/
	_x = IloNumVarArray(_env); //variable de posicion del articulo en el bin
	for(int i =0; i< (_ks->get_nItems())*(_ks->get_nItems()) ;i++)
	{
		_x.add(IloNumVar(_env, 0, 1, ILOINT));
	}

	_y = IloNumVarArray(_env); // variable  de numero de contenedores
	for (int i = 0; i < (_ks->get_nItems()); i++)
	{
		_y.add(IloNumVar(_env, 0, 1, ILOINT));
	}


	_obj = IloAdd(_model, IloMinimize(_env, 0)); // Agregando variable objetivo
	for (int i = 0; i < _ks->get_nItems(); i++) {
		_obj.setLinearCoef(_y[i], 1);
	}

	// Creado las restricciones

	for (int i = 0; i < _ks->get_nItems(); i++)
	{
		IloExpr exp(_env);
		IloExpr exp1(_env);
		for (int j = 0; j < _ks->get_nItems(); j++)
		{
			//Restricción no sobrepasar capacidad
			exp += _ks->get_weight(j)*_x[_ks->get_nItems()*i + j];
			// Restriccion de empacar todos los items
			exp1 += 1 * _x[(_ks->get_nItems())*j + i];
		}//fin for j
		exp -= (_ks->get_Capacity())*_y[i];

		_model.add(IloRange(_env,-IloInfinity,exp,0));
		exp.end();
		_model.add(IloRange(_env, 1, exp1, 1));
		exp1.end();
	}//fin for i

	
}

binpacking_solver::~binpacking_solver()
{
	_model.end();
	_cplex.end();
}

void binpacking_solver::solve()
{

	_cplex.solve();

	cout << endl<<"**************Resultados*******************" << endl;
	cout << "Cantidad de bins: " << _cplex.getObjValue() << endl;
	
	/*cout << "**************** Acomodo final ***********************" << endl<<endl;
	for (int i=0;i<_ks->get_nItems();i++)
	{
	 for (int j = 0; j < _ks->get_nItems(); j++)
	 {
		 cout << _cplex.getValue(_x[i*(_ks->get_nItems())+j]);

	 }
	 cout << endl;

	}*/
	
}
