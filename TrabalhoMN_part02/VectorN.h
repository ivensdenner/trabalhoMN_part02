#ifndef VECTOR_N_H
#define VECTOR_N_H


class VectorN
{
public:
	VectorN(int _dimension);
	VectorN(const VectorN& _vector);
	virtual ~VectorN();

	int get_dimension() const;

	double get_value(int i) const;
	void set_value(double value, int i);


private:
	const int dimension;
	double* vector;
};

#endif
