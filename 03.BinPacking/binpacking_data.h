#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class binpacking_data
{
private:
	int _nItems;
	int _Capacity;
	int *_weights;
	string _file;

public:
	binpacking_data(string filedata);
	~binpacking_data();
	void print_data();
	int get_Capacity() { return _Capacity; };
	int get_nItems() { return _nItems; };
	int get_weight(int obj) { return _weights[obj]; };
};

