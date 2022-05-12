// ConsoleMatrix.cpp: Линейные структуры данных. Разреженные матрицы.
#include <iostream>
#include "Matrix.h"
using std::endl;
using std::cout;
int main()
{
	Matrix M(4, 6, 16.23);
	for (int i = 0; i < M.get_line(); i++) {
		for (int j = 0; j < M.get_column(); j++) {
			cout << M(i, j) << " | ";
		}
		cout << endl;
	}
	double s = M.sumElements();
	cout << s << endl;
	double q = M.multiElements();
	cout << q << endl;
	return 0;
}