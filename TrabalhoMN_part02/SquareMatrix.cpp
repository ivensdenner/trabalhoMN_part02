#include "SquareMatrix.h"


SquareMatrix::SquareMatrix(int _dimension) : dimension(_dimension)
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


SquareMatrix::SquareMatrix(const SquareMatrix& _s_matrix) : dimension(_s_matrix.get_dimension())
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
			matrix[i][j] = _s_matrix.get_value(i, j);
		}
	}
}


SquareMatrix::~SquareMatrix()
{
	for (int i = 0; i < dimension; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}


int SquareMatrix::get_dimension() const
{
	return dimension;
}


double SquareMatrix::get_value(int i, int j) const
{
	if (i >= 0 && i < dimension && j >= 0 && j < dimension)
	{
		return matrix[i][j];
	}
	else
	{
		return 0;
	}
}


void SquareMatrix::set_value(double value, int i, int j)
{
	if (i >= 0 && i < dimension && j >= 0 && j < dimension)
	{
		matrix[i][j] = value;
	}
}


// Operators overload
SquareMatrix& SquareMatrix::operator + (const SquareMatrix& _s_matrix)
{
	SquareMatrix *s_matrix = new SquareMatrix(*this);
    
	if (_s_matrix.get_dimension() == dimension)
	{
		*s_matrix += _s_matrix;
	}
    
	return *s_matrix;
}


SquareMatrix& SquareMatrix::operator += (const SquareMatrix& _s_matrix)
{
	if (dimension == _s_matrix.get_dimension())
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				matrix[i][j] += _s_matrix.get_value(i, j);
			}
		}
	}
    
	return *this;
}


SquareMatrix& SquareMatrix::operator + (double scalar)
{
	SquareMatrix *s_matrix = new SquareMatrix(*this);
    
	*s_matrix += scalar;
    
	return *s_matrix;
}


SquareMatrix& SquareMatrix::operator += (double scalar)
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


SquareMatrix& SquareMatrix::operator - (const SquareMatrix& _s_matrix)
{
	SquareMatrix *s_matrix = new SquareMatrix(*this);
    
	if (_s_matrix.get_dimension() == dimension)
	{
		*s_matrix -= _s_matrix;
	}
    
	return *s_matrix;
}


SquareMatrix& SquareMatrix::operator -= (const SquareMatrix& _s_matrix)
{
	if (dimension == _s_matrix.get_dimension())
	{
		for (int i = 0; i < dimension; i++)
		{
			for (int j = 0; j < dimension; j++)
			{
				matrix[i][j] -= _s_matrix.get_value(i, j);
			}
		}
	}
    
	return *this;
}


SquareMatrix& SquareMatrix::operator - (double scalar)
{
	SquareMatrix *s_matrix = new SquareMatrix(*this);
    
	*s_matrix -= scalar;
    
	return *s_matrix;
}


SquareMatrix& SquareMatrix::operator -= (double scalar)
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


SquareMatrix& SquareMatrix::operator * (const SquareMatrix& _s_matrix)
{
	SquareMatrix *s_matrix = new SquareMatrix(*this);
    
	*s_matrix *= _s_matrix;
    
	return *s_matrix;
}


SquareMatrix& SquareMatrix::operator *= (const SquareMatrix& _s_matrix)
{
	if (dimension == _s_matrix.get_dimension())
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
					new_matrix[i][j] += matrix[i][k] * _s_matrix.get_value(k, j);
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


SquareMatrix& SquareMatrix::operator * (double scalar)
{
	SquareMatrix *s_matrix = new SquareMatrix(*this);
    
	*s_matrix *= scalar;
    
	return *s_matrix;
}


SquareMatrix& SquareMatrix::operator *= (double scalar)
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


SquareMatrix& SquareMatrix::operator / (double scalar)
{
	SquareMatrix *s_matrix = new SquareMatrix(*this);
    
	*s_matrix /= scalar;
    
	return *s_matrix;
}


SquareMatrix& SquareMatrix::operator /= (double scalar)
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
