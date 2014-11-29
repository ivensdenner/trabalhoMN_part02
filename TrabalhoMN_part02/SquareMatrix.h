#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H


class SquareMatrix
{
public:
	SquareMatrix(int _dimension);
	SquareMatrix(const SquareMatrix& _s_matrix);
	virtual ~SquareMatrix();


	int get_dimension() const;

	double get_value(int i, int j) const;
	void set_value(double value, int i, int j);


	// Operators overload
	SquareMatrix& operator + (const SquareMatrix& _s_matrix);
	SquareMatrix& operator += (const SquareMatrix& _s_matrix);
	SquareMatrix& operator + (double scalar);
	SquareMatrix& operator += (double scalar);
	SquareMatrix& operator - (const SquareMatrix& _s_matrix);
	SquareMatrix& operator -= (const SquareMatrix& _s_matrix);
	SquareMatrix& operator - (double scalar);
	SquareMatrix& operator -= (double scalar);
	SquareMatrix& operator * (const SquareMatrix& _s_matrix);
	SquareMatrix& operator *= (const SquareMatrix& _s_matrix);
	SquareMatrix& operator * (double scalar);
	SquareMatrix& operator *= (double scalar);
	SquareMatrix& operator / (double scalar);
	SquareMatrix& operator /= (double scalar);

private:
	const int dimension;
	double **matrix;
};

#endif
