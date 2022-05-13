//Релизация класса матрица
#include <iostream>
#include <fstream>
#include "Matrix.h"
using std::cout;
using std::endl;
using std::ifstream;
unsigned Matrix::get_line() const
{
	return this->line;
}
unsigned Matrix::get_column() const
{
	return this->column;
}
Matrix::Matrix(unsigned _l, unsigned _c, const double key)
{
	mat.resize(_l);
	for (int i = 0; i < mat.size(); i++) {
		mat[i].resize(_c, key);		//метод resize может принимать необязательный аргумент, который инициализирует все элементы этим (key) значением
	}
	line = _l;
	column = _c;
}
double Matrix::operator()(const unsigned & row, const unsigned & col) const
{
	return this->mat[row][col];
}
double Matrix::sumElements() const
{
	double sum = 0;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			sum += this->mat[i][j];
		}
	}
	return sum;
}
double Matrix::multiElements() const
{
	double multiplication = 1;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++) {
			multiplication *= this->mat[i][j];
		}
	}
	return multiplication;
}
Matrix * Matrix::readfile(const char * name, unsigned _l, unsigned _c)
{
	ifstream qmatrix(name);
	if (!qmatrix) {
		cout << "File " << name << " error!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cout << "File " << name << " open" << endl;
	}
	Matrix* rfile(_l, _c, 0.0);
		return nullptr;
}