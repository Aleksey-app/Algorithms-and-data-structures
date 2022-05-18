// ConsoleMatrix.cpp: Линейные структуры данных. Разреженные матрицы.
#include <iostream>
#include "Matrix.h"
using std::endl;
using std::cout;
int main()
{
	const char* name = "Example.txt";
	const char* n = "SadPoint.txt";
	Matrix M(2, 2, 16.23);
	M.PrintM(M);
	double s = M.sumElements();
	cout << s << endl;
	Matrix Q = M.readfile(name, 4, 6);
	M.PrintM(Q);
	s = 0;
	s = Q.sumElements();
	cout << s << endl;
	double q = Q.multiElements();
	cout << q << endl;
	M.MaxMin(Q);
	/*M.MatrixLine(Q);
	M.MatrixColumn(Q);*/
	M.LocalMaxMinMatrix(Q);
	M.MinLine(Q);
	M.MaxColumn(Q);
	Matrix One = M.readfile(n, 3, 4);
	M.PrintM(One);
	M.SadPoint(One);
	return 0;
}