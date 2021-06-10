


#include "myNM.h"


// Matrix addition
Matrix	addMat(Matrix _A, Matrix _B)
{
	if (_A.rows != _B.rows || _A.cols != _B.cols) {
		printf("\n*************************************************");
		printf("\n  ERROR!!: dimension error at 'addMat' function");
		printf("\n*************************************************\n");
		return createMat(0, 0);
	}

	Matrix Out = createMat(_A.rows, _B.cols);
	for (int i = 0; i < _A.rows; i++)
		for (int j = 0; j < _B.cols; j++)
			Out.at[i][j] = _A.at[i][j] + _B.at[i][j];

	return Out;
}

// Apply back-substitution
Matrix	backSub(Matrix _A, Matrix _b)
{
	Matrix Out = createMat(_b.rows, 1);

	// error check: whether _A is a triangular matrix

	//for (int i = _A.rows; i > 0; i--) {
	//	double temp = 0;
	//	for (int j = i + 1; j <= _A.cols; j++)
	//		temp += _A.at[i - 1][j - 1] * Out.at[j - 1][0];
	//	Out.at[i - 1][0] = (_b.at[i - 1][0] - temp) / _A.at[i - 1][i - 1];
	//}

	for (int i = _A.rows-1; i >= 0; i--) {
		double temp = 0;
		for (int j = i + 1; j < _A.cols; j++)
			temp += _A.at[i][j] * Out.at[j][0];
		Out.at[i][0] = (_b.at[i][0] - temp) / _A.at[i][i];
	}

	return Out;
}

Matrix	linearFit(Matrix _x, Matrix _y) {
	int mx = _x.rows;
	int my = _y.rows;

	double a1 = 0;
	double a0 = 0;

	if ((mx != my) || (mx == 1))
		printf("error: Length must be equal and more than 2");
	else
	{
		// initialize
		double sx = 0;
		double sxx = 0;
		double sxy = 0;
		double sy = 0;
		double m = mx;


		for (int k = 0; k < m; k++)
		{
			sx = sx + _x.at[k][0];
			sxx = sxx + _x.at[k][0] * _x.at[k][0];
			sxy = sxy + _x.at[k][0] * _y.at[k][0];
			sy = sy + _y.at[k][0];
		}

		double DEN = (m * sxx - sx * sx);
		a1 = (m * sxy - sx * sy) / DEN;
		a0 = (sxx * sy - sxy * sx) / DEN;

	}
	double z_array[] = { a1, a0 };
	return arr2Mat(z_array, 2, 1);
}

// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols)
{
	Matrix Output = createMat(_rows, _cols);

	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			Output.at[i][j] = _1Darray[i * _cols + j];

	return Output;
}
