#pragma once
#include "binpacking_data.h"
#include <ilconcert/iloenv.h>
#include <ilcplex/ilocplex.h>


class binpacking_solver
{
private:
	binpacking_data *_ks;
	IloEnv _env;
	IloCplex _cplex;
	IloModel _model;
	IloObjective _obj;
	IloRange _cap;
	IloNumVarArray _x;
	IloNumVarArray _y;

public:
	binpacking_solver(binpacking_data *ks);
	~binpacking_solver();
	void solve();
};

