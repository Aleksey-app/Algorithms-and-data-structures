// ConsoleMatrix.cpp: Линейные структуры данных. Разреженные матрицы.
#include <iostream>
#include "Matrix.h"
using std::endl;
using std::cout;
int main()
{
	const char* name = "Example.txt";
	Matrix M(4, 6, 16.23);
	M.PrintM(M);
	double s = M.sumElements();
	cout << s << endl;
	double q = M.multiElements();
	cout << q << endl;
	Matrix Q = M.readfile(name, 4, 6);
	M.PrintM(Q);
	s = 0;
	s = Q.sumElements();
	cout << s << endl;
	M.MaxMin(Q);
	return 0;
}