#ifndef QUADRATIC_MATRIX_H
#define QUADRATIC_MATRIX_H


class QuadraticMatrix
{
public:
	QuadraticMatrix(int _dimension);
	QuadraticMatrix(const QuadraticMatrix& _q_matrix);
	virtual ~QuadraticMatrix();


	int get_dimension() const;

	double get_value(int i, int j) const;
	void set_value(double value, int i, int j);


	// Operators overload
	QuadraticMatrix& operator + (const QuadraticMatrix& _q_matrix);
	QuadraticMatrix& operator += (const QuadraticMatrix& _q_matrix);
	QuadraticMatrix& operator + (double scalar);
	QuadraticMatrix& operator += (double scalar);
	QuadraticMatrix& operator - (const QuadraticMatrix& _q_matrix);
	QuadraticMatrix& operator -= (const QuadraticMatrix& _q_matrix);
	QuadraticMatrix& operator - (double scalar);
	QuadraticMatrix& operator -= (double scalar);
	QuadraticMatrix& operator * (const QuadraticMatrix& _q_matrix);
	QuadraticMatrix& operator *= (const QuadraticMatrix& _q_matrix);
	QuadraticMatrix& operator * (double scalar);
	QuadraticMatrix& operator *= (double scalar);
	QuadraticMatrix& operator / (double scalar);
	QuadraticMatrix& operator /= (double scalar);

private:
	const int dimension;
	double **matrix;
};

#endif
