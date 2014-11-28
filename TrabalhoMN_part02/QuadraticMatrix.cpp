#include "QuadraticMatrix.h"


QuadraticMatrix::QuadraticMatrix(int _dimension) : dimension(_dimension)
{
	matrix = new double*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		matrix[i] = new double[dimension];
	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrix[i][j] = 0;
		}
	}
}


QuadraticMatrix::QuadraticMatrix(const QuadraticMatrix& _q_matrix) : dimension(_q_matrix.get_dimension())
{
	matrix = new double*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		matrix[i] = new double[dimension];
	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrix[i][j] = _q_matrix.get_value(i, j);
		}
	}
}


QuadraticMatrix::~QuadraticMatrix()
{
	for (int i = 0; i < dimension; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}


int QuadraticMatrix::get_dimension() const
{
	return dimension;
}


double QuadraticMatrix::get_value(int i, int j) const
{
	return matrix[i][j];
}


void QuadraticMatrix::set_value(double value, int i, int j)
{
	matrix[i][j] = value;
}


// Operators overload
QuadraticMatrix& QuadraticMatrix::operator + (const QuadraticMatrix& _q_matrix)
{
	QuadraticMatrix *q_matrix = new QuadraticMatrix(*this);

	if (_q_matrix.get_dimension() == dimension)
	{
		*q_matrix += _q_matrix;
	}

	return *q_matrix;
}


QuadraticMatrix& QuadraticMatrix::operator += (const QuadraticMatrix& _q_matrix)
{
	if (dimension == _q_matrix.get_dimension())
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				matrix[i][j] += _q_matrix.get_value(i, j);
			}
		}
	}

	return *this;
}


QuadraticMatrix& QuadraticMatrix::operator + (double scalar)
{
	QuadraticMatrix *q_matrix = new QuadraticMatrix(*this);

	*q_matrix += scalar;

	return *q_matrix;
}


QuadraticMatrix& QuadraticMatrix::operator += (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrix[i][j] += scalar;
		}
	}

	return *this;
}


QuadraticMatrix& QuadraticMatrix::operator - (const QuadraticMatrix& _q_matrix)
{
	QuadraticMatrix *q_matrix = new QuadraticMatrix(*this);

	if (_q_matrix.get_dimension() == dimension)
	{
		*q_matrix -= _q_matrix;
	}

	return *q_matrix;
}


QuadraticMatrix& QuadraticMatrix::operator -= (const QuadraticMatrix& _q_matrix)
{
	if (dimension == _q_matrix.get_dimension())
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				matrix[i][j] -= _q_matrix.get_value(i, j);
			}
		}
	}

	return *this;
}


QuadraticMatrix& QuadraticMatrix::operator - (double scalar)
{
	QuadraticMatrix *q_matrix = new QuadraticMatrix(*this);

	*q_matrix -= scalar;

	return *q_matrix;
}


QuadraticMatrix& QuadraticMatrix::operator -= (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrix[i][j] -= scalar;
		}
	}

	return *this;
}


QuadraticMatrix& QuadraticMatrix::operator * (const QuadraticMatrix& _q_matrix)
{
	QuadraticMatrix *q_matrix = new QuadraticMatrix(*this);

	*q_matrix *= _q_matrix;

	return *q_matrix;
}


QuadraticMatrix& QuadraticMatrix::operator *= (const QuadraticMatrix& _q_matrix)
{
	if (dimension == _q_matrix.get_dimension())
	{
		// Alocando a matriz que vai substituir a atual.
		double **new_matrix = new double*[dimension];
		for (int i = 0; i < dimension; i++)
		{
			new_matrix[i] = new double[dimension];
		}
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				new_matrix[i][j] = 0;
			}
		}

		// Multiplicando as matrizes
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				for (int k = 0; k < dimension; k++)
				{
					new_matrix[i][j] += matrix[i][k] * _q_matrix.get_value(k, j);
				}
			}
		}

		// Atribuindo nova matriz e desalocando anterior
		double **temp = matrix;
		matrix = new_matrix;
		for (int i = 0; i < dimension; ++i)
		{
			delete[] temp[i];
		}
		delete[] temp;
	}

	return *this;
}


QuadraticMatrix& QuadraticMatrix::operator * (double scalar)
{
	QuadraticMatrix *q_matrix = new QuadraticMatrix(*this);

	*q_matrix *= scalar;

	return *q_matrix;
}


QuadraticMatrix& QuadraticMatrix::operator *= (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrix[i][j] *= scalar;
		}
	}

	return *this;
}


QuadraticMatrix& QuadraticMatrix::operator / (double scalar)
{
	QuadraticMatrix *q_matrix = new QuadraticMatrix(*this);

	*q_matrix /= scalar;

	return *q_matrix;
}


QuadraticMatrix& QuadraticMatrix::operator /= (double scalar)
{
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			matrix[i][j] /= scalar;
		}
	}

	return *this;
}
