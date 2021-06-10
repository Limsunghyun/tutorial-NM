


#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H

#include "myMatrix.h"

// Matrix addition
extern	Matrix	addMat(Matrix _A, Matrix _B);

// Apply back-substitution
extern	Matrix	backSub(Matrix _A, Matrix _b);

// Gauss elimination
//extern	Matrix	Gelim(Matrix _A, Matrix _B);

// LU decomposition


// Returns the parameters of the linear least square function.
extern Matrix	linearFit(Matrix _x, Matrix _y);

// Create a matrix from 1D-array
extern Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);
#endif