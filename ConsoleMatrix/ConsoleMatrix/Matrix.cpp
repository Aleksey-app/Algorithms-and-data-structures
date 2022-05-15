//Релизация класса матрица
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matrix.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::vector;
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
Matrix  Matrix::readfile(const char * name, unsigned _l, unsigned _c)
{
	ifstream qmatrix(name);
	if (!qmatrix) {
		cout << "File " << name << " error!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cout << "File " << name << " open" << endl;
	}
	double key = 0.0;
	Matrix rfile(_l, _c, 0.0);
	for (unsigned i = 0; i < _l; i++) {
		for (unsigned j = 0; j < _c; j++) {
			qmatrix >> key;
			rfile.mat[i][j] = key;
		}
	}
	qmatrix.close();
	return rfile;
}
void Matrix::PrintM(const Matrix & M)
{
	for (int i = 0; i < M.line; i++) {
		for (int j = 0; j < M.column; j++) {
			cout << std::setw(12) << M(i, j) << " | ";
		}
		cout << endl;
	}
}
void Matrix::MaxMin(const Matrix & M)
{
	double min = M.mat[0][0], max = M.mat[0][0];
	for (int i = 0; i < M.line; i++) {
		for (int j = 0; j < M.column; j++) {
			if (min > M.mat[i][j]) {
				min = M.mat[i][j];
			}
			if (max < M.mat[i][j]) {
				max = M.mat[i][j];
			}
		}
	}
	cout << "Min element Matrix = " << min << endl;
	cout << "Max element Matrix = " << max << endl;
}
void Matrix::MatrixLine(const Matrix & M)
{
	unsigned key;
	while (true) {
		cout << "Enter line number	";
		cin >> key;
		if (cin.fail()) {
			cout << "It should be the number" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (key == 0) {
			cout << "Number 0 no" << endl;
			continue;
		}
		if (key > M.line) {
			cout << "Max number of line = " << M.line << endl;
			continue;
		}
		else break;
	}
	/*system("cls");*/
	cout << "Line " << key << endl;
	for (int j = 0; j < M.column; j++) {
		cout << std::setw(12) << M(key-1, j) << " | ";
	}
	cout << endl;
}
void Matrix::MatrixColumn(const Matrix & M)
{
	unsigned key;
	while (true) {
		cout << "Enter column number	";
		cin >> key;
		if (cin.fail()) {
			cout << "It should be the number" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (key == 0) {
			cout << "Number 0 no" << endl;
			continue;
		}
		if (key > M.column) {
			cout << "Max number of column = " << M.column << endl;
			continue;
		}
		else break;
	}
	/*system("cls");*/
	cout << "Column " << key << endl;
	for (int j = 0; j < M.line; j++) {
		cout << std::setw(12) << M(j, key - 1) << " | ";
		cout << endl;
	}
}
void Matrix::LocalMaxMinMatrix(const Matrix & M) {
	vector<int> max, min;	//empty vector to store points of local maxima and minima
	int MaxSum = 0, MinSum = 0;
	if (M.line >= 2 && M.column >= 2) {
		if (M.mat[0][0] > M.mat[0][1] && M.mat[0][0] > M.mat[1][1] && M.mat[0][0] > M.mat[1][0]) {	//левый верхний угол
			max.push_back(MaxSum);
			MaxSum++;
		}
		else if (M.mat[0][0] < M.mat[0][1] && M.mat[0][0] < M.mat[1][1] && M.mat[0][0] < M.mat[1][0]) {
			min.push_back(MinSum);
			MinSum++;
		}
		//правый верхний угол
		if (M.mat[0][column - 1] > M.mat[0][column - 2] && M.mat[0][column - 1] > M.mat[1][column - 2] && M.mat[0][column - 1] > M.mat[1][column - 1]) {
			max.push_back(MaxSum);
			MaxSum++;
		}
		else if (M.mat[0][column - 1] < M.mat[0][column - 2] && M.mat[0][column - 1] < M.mat[1][column - 2] && M.mat[0][column - 1] < M.mat[1][column - 1]) {
			min.push_back(MinSum);
			MinSum++;
		}
		//правый нижний угол
		if (M.mat[line - 1][column - 1] > M.mat[line - 1][column - 2] && M.mat[line - 1][column - 1] > M.mat[line - 2][column - 2] && M.mat[line - 1][column - 1] > M.mat[line - 2][column - 1]) {
			max.push_back(MaxSum);
			MaxSum++;
		}
		else if (M.mat[line - 1][column - 1] < M.mat[line - 1][column - 2] && M.mat[line - 1][column - 1] < M.mat[line - 2][column - 2] && M.mat[line - 1][column - 1] < M.mat[line - 2][column - 1]) {
			min.push_back(MinSum);
			MinSum++;
		}
		//левый нижний угол
		if (M.mat[line - 1][0] > M.mat[line - 2][0] && M.mat[line - 1][0] > M.mat[line - 2][1] && M.mat[line - 1][0] > M.mat[line - 1][1]) {
			max.push_back(MaxSum);
			MaxSum++;
		}
		else if (M.mat[line - 1][0] < M.mat[line - 2][0] && M.mat[line - 1][0] < M.mat[line - 2][1] && M.mat[line - 1][0] < M.mat[line - 1][1]) {
			min.push_back(MinSum);
			MinSum++;
		}
		////////////////////////////////
		if (max.size() > 0) {
			cout << "Points of Local maxima found " << MaxSum << " : ";
			for (int a : max) {
				cout << a << " ";
			}
			cout << endl;
		}
		else {
			cout << "There are no points of local max" << endl;
		}
		if (min.size() > 0) {
			cout << "Points of Local minima found " << MinSum << " : ";
			for (int a : min) {
				cout << a << " ";
			}
			cout << endl;
		}
		else {
			cout << "There are no points of local min" << endl;
		}
	}
	else {
		cout << "Data analysis requires a matrix, at least 2x2" << endl;
		exit(EXIT_FAILURE);
	}
}
