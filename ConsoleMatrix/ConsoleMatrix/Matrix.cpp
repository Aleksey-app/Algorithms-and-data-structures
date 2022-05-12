//��������� ������ �������
#include "Matrix.h"

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
		mat[i].resize(_c, key);		//����� resize ����� ��������� �������������� ��������, ������� �������������� ��� �������� ���� (key) ���������
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
	Matrix
		return nullptr;
}