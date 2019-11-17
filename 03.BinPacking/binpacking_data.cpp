#include "binpacking_data.h"


binpacking_data::binpacking_data(string filedata)
{
	_file = filedata;
	ifstream ifile(filedata.c_str(), ios::in);
	if (ifile.fail()) {
		cout << "Error en archivo: " << filedata << endl;
		system("pause");
		exit(0);
	}

	
	ifile >> _Capacity;
	ifile >> _nItems;

	
	_weights = new int[_nItems];
	for (int i = 0; i < _nItems; i++) {
		ifile >> _weights[i];
	}
	print_data();
	ifile.close();


}


binpacking_data::~binpacking_data()
{
	delete _weights;
}

void binpacking_data::print_data() {
	cout << "Archivo: " << _file << endl;
	cout << "Numero de objetos: " << _nItems << endl;
	cout << "Capacidad del contenedor: " << _Capacity << endl;

	cout << "Objeto \t Volumen  \t" << endl;

	for (int i = 0; i < _nItems; i++) {
		cout << i + 1 << "\t" << _weights[i] << endl;
	}

}
