#include "VectorN.h"


VectorN::VectorN(int _dimension) : dimension(_dimension)
{
	vector = new double[dimension];

	for (int i = 0; i < dimension; i++)
	{
		vector[i] = 0;
	}
}


VectorN::VectorN(const VectorN& _vectorN) : dimension(_vectorN.get_dimension())
{
	vector = new double[dimension];

	for (int i = 0; i < dimension; i++)
	{
		vector[i] = _vectorN.get_value(i);
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


VectorN& VectorN::operator + (const VectorN& _vectorN)
{
	VectorN *vectorN = new VectorN(*this);

	if (dimension == _vectorN.get_dimension())
	{
		*vectorN += _vectorN;
	}

	return *vectorN;
}


VectorN& VectorN::operator += (const VectorN& _vectorN)
{
	if (dimension == _vectorN.get_dimension())
	{
		for (int i = 0; i < dimension; i++)
		{
			vector[i] += _vectorN.get_value(i);
		}
	}

	return *this;
}


VectorN& VectorN::operator + (double scalar)
{
	VectorN *vectorN = new VectorN(*this);

	*vectorN += scalar;

	return *vectorN;
}


VectorN& VectorN::operator += (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		vector[i] += scalar;
	}

	return *this;
}


VectorN& VectorN::operator - (const VectorN& _vectorN)
{
	VectorN *vectorN = new VectorN(*this);

	if (dimension == _vectorN.get_dimension())
	{
		*vectorN -= _vectorN;
	}

	return *vectorN;
}


VectorN& VectorN::operator -= (const VectorN& _vectorN)
{
	if (dimension == _vectorN.get_dimension())
	{
		for (int i = 0; i < dimension; i++)
		{
			vector[i] -= _vectorN.get_value(i);
		}
	}

	return *this;
}


VectorN& VectorN::operator - (double scalar)
{
	VectorN *vectorN = new VectorN(*this);

	*vectorN -= scalar;

	return *vectorN;
}


VectorN& VectorN::operator -= (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		vector[i] -= scalar;
	}

	return *this;
}


double VectorN::operator * (const VectorN& _vectorN)
{
	double result = 0;

	if (dimension == _vectorN.get_dimension())
	{
		for (int i = 0; i < dimension; i++)
		{
			result += vector[i] * _vectorN.get_value(i);
		}
	}

	return result;
}


VectorN& VectorN::operator * (double scalar)
{
	VectorN *vectorN = new VectorN(*this);

	*vectorN *= scalar;

	return *vectorN;
}


VectorN& VectorN::operator *= (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		vector[i] *= scalar;
	}

	return *this;
}


VectorN& VectorN::operator / (double scalar)
{
	VectorN *vectorN = new VectorN(*this);

	*vectorN /= scalar;

	return *vectorN;
}


VectorN& VectorN::operator /= (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		vector[i] /= scalar;
	}

	return *this;
}
