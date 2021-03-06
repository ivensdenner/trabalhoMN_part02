#ifndef VECTOR_N_H
#define VECTOR_N_H


class VectorN
{
public:
	VectorN(int _dimension);
	VectorN(const VectorN& _vectorN);
	virtual ~VectorN();
    
	int get_dimension() const;
    
	double get_value(int i) const;
	void set_value(double value, int i);
    
    
	// Operators overload
	VectorN& operator + (const VectorN& _vectorN);
	VectorN& operator += (const VectorN& _vectorN);
	VectorN& operator + (double scalar);
	VectorN& operator += (double scalar);
    
	VectorN& operator - (const VectorN& _vectorN);
	VectorN& operator -= (const VectorN& _vectorN);
	VectorN& operator - (double scalar);
	VectorN& operator -= (double scalar);
    
	double operator * (const VectorN& _vectorN);
	VectorN& operator * (double scalar);
	VectorN& operator *= (double scalar);
    
	VectorN& operator / (double scalar);
	VectorN& operator /= (double scalar);
    
private:
	const int dimension;
	double* vector;
};

#endif
