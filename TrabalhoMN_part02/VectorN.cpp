#include "VectorN.h"


VectorN::VectorN(int _dimension) : dimension(_dimension)
{
	vector = new double[dimension];

	for (int i = 0; i < dimension; i++)
	{
		vector[i] = 0;
	}
}


VectorN::VectorN(const VectorN& _vector) : dimension(_vector.get_dimension())
{
	vector = new double[dimension];

	for (int i = 0; i < dimension; i++)
	{
		vector[i] = _vector.get_value(i);
	}
}


VectorN::~VectorN()
{
	delete[] vector;
}


int VectorN::get_dimension() const
{
	return dimension;
}


double VectorN::get_value(int i) const
{
	if (i >= 0 && i < dimension)
	{
		return vector[i];
	}
}


void VectorN::set_value(double value, int i)
{
	if (i >= 0 && i < dimension)
	{
		vector[i] = value;
	}
}
