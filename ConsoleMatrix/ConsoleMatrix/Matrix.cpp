//��������� ������ �������
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
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
		mat[i].resize(_c, key);		//����� resize ����� ��������� �������������� ��������, ������� �������������� ��� �������� ���� (key) ���������
	}
	line = _l;
	column = _c;
}
double Matrix::operator()(const unsigned & row, const unsigned & col) const
{
	return this->mat[row][col];
}
Matrix Matrix::operator=(const Matrix & rhs)
{
	if (&rhs == this) {
		return *this;
	}
	unsigned new_rows = rhs.get_line();
	unsigned new_cols = rhs.get_column();
	mat.resize(new_rows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(new_cols);
	}
	for (unsigned i = 0; i < new_rows; i++) {
		for (unsigned j = 0; j < new_cols; j++) {
			mat[i][j] = rhs(i, j);
		}
	}
	line = new_rows;
	column = new_cols;
	return *this;
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
	vector<double> max, min;	//empty vector to store points of local maxima and minima
	int MaxSum = 0, MinSum = 0;
	if (M.line >= 2 && M.column >= 2) {
		if (M.mat[0][0] > M.mat[0][1] && M.mat[0][0] > M.mat[1][1] && M.mat[0][0] > M.mat[1][0]) {	//����� ������� ����
			max.push_back(M.mat[0][0]);
			MaxSum++;
		}
		else if (M.mat[0][0] < M.mat[0][1] && M.mat[0][0] < M.mat[1][1] && M.mat[0][0] < M.mat[1][0]) {
			min.push_back(M.mat[0][0]);
			MinSum++;
		}
		//������ ������� ����
		if (M.mat[0][column - 1] > M.mat[0][column - 2] && M.mat[0][column - 1] > M.mat[1][column - 2] && M.mat[0][column - 1] > M.mat[1][column - 1]) {
			max.push_back(M.mat[0][column-1]);
			MaxSum++;
		}
		else if (M.mat[0][column - 1] < M.mat[0][column - 2] && M.mat[0][column - 1] < M.mat[1][column - 2] && M.mat[0][column - 1] < M.mat[1][column - 1]) {
			min.push_back(M.mat[0][column-1]);
			MinSum++;
		}
		//������ ������ ����
		if (M.mat[line - 1][column - 1] > M.mat[line - 1][column - 2] && M.mat[line - 1][column - 1] > M.mat[line - 2][column - 2] && M.mat[line - 1][column - 1] > M.mat[line - 2][column - 1]) {
			max.push_back(M.mat[line-1][column-1]);
			MaxSum++;
		}
		else if (M.mat[line - 1][column - 1] < M.mat[line - 1][column - 2] && M.mat[line - 1][column - 1] < M.mat[line - 2][column - 2] && M.mat[line - 1][column - 1] < M.mat[line - 2][column - 1]) {
			min.push_back(M.mat[line-1][column-1]);
			MinSum++;
		}
		//����� ������ ����
		if (M.mat[line - 1][0] > M.mat[line - 2][0] && M.mat[line - 1][0] > M.mat[line - 2][1] && M.mat[line - 1][0] > M.mat[line - 1][1]) {
			max.push_back(M.mat[line-1][0]);
			MaxSum++;
		}
		else if (M.mat[line - 1][0] < M.mat[line - 2][0] && M.mat[line - 1][0] < M.mat[line - 2][1] && M.mat[line - 1][0] < M.mat[line - 1][1]) {
			min.push_back(M.mat[line-1][0]);
			MinSum++;
		}
		//������� �������
		if (M.column > 2) {
			for (int j = 1; j < M.column - 1; j++) {
				if (M.mat[0][j] > M.mat[0][j - 1] && M.mat[0][j] > M.mat[1][j - 1] && M.mat[0][j] > M.mat[1][j] && M.mat[0][j] > M.mat[1][j + 1] && M.mat[0][j] > M.mat[0][j + 1]) {
					max.push_back(M.mat[0][j]);
					MaxSum++;
				}
				if (M.mat[0][j] < M.mat[0][j - 1] && M.mat[0][j] < M.mat[1][j - 1] && M.mat[0][j] < M.mat[1][j] && M.mat[0][j] < M.mat[1][j + 1] && M.mat[0][j] < M.mat[0][j + 1]) {
					min.push_back(M.mat[0][j]);
					MinSum++;
				}
			}
		}
		//������ ������� �������
		if (M.line > 2) {
			for (int i = 1; i < M.line - 1; i++) {
				if (M.mat[i][column - 1] > M.mat[i - 1][column - 1] && M.mat[i][column - 1] > M.mat[i - 1][column - 2] && M.mat[i][column - 1] > M.mat[i][column - 2] && M.mat[i][column - 1] > M.mat[i + 1][column - 2] && M.mat[i][column - 1] > M.mat[i + 1][column - 1]) {
					max.push_back(M.mat[i][column-1]);
					MaxSum++;
				}
				if (M.mat[i][column - 1] < M.mat[i - 1][column - 1] && M.mat[i][column - 1] < M.mat[i - 1][column - 2] && M.mat[i][column - 1] < M.mat[i][column - 2] && M.mat[i][column - 1] < M.mat[i + 1][column - 2] && M.mat[i][column - 1] < M.mat[i + 1][column - 1]) {
					min.push_back(M.mat[i][column-1]);
					MinSum++;
				}
			}
		}
		//������ ������ �������
		if (M.column > 2) {
			for (int j = 1; j < M.column - 1; j++) {
				if (M.mat[line - 1][j] > M.mat[line - 1][j - 1] && M.mat[line - 1][j] > M.mat[line - 2][j - 1] && M.mat[line - 1][j] > M.mat[line - 2][j] && M.mat[line - 1][j] > M.mat[line - 2][j + 1] && M.mat[line - 1][j] > M.mat[line - 1][j + 1]) {
					max.push_back(M.mat[line-1][j]);
					MaxSum++;
				}
				if (M.mat[line - 1][j] < M.mat[line - 1][j - 1] && M.mat[line - 1][j] < M.mat[line - 2][j - 1] && M.mat[line - 1][j] < M.mat[line - 2][j] && M.mat[line - 1][j] < M.mat[line - 2][j + 1] && M.mat[line - 1][j] < M.mat[line - 1][j + 1]) {
					min.push_back(M.mat[line-1][j]);
					MinSum++;
				}
			}
		}
		//����� ������� �������
		if (M.line > 2) {
			for (int i = 1; i < M.line - 1; i++) {
				if (M.mat[i][0] > M.mat[i - 1][0] && M.mat[i][0] > M.mat[i - 1][1] && M.mat[i][0] > M.mat[i][1] && M.mat[i][0] > M.mat[i + 1][1] && M.mat[i][0] > M.mat[i + 1][0]) {
					max.push_back(M.mat[i][0]);
					MaxSum++;
				}
				if (M.mat[i][0] < M.mat[i - 1][0] && M.mat[i][0] < M.mat[i - 1][1] && M.mat[i][0] < M.mat[i][1] && M.mat[i][0] < M.mat[i + 1][1] && M.mat[i][0] < M.mat[i + 1][0]) {
					min.push_back(M.mat[i][0]);
					MinSum++;
				}
			}
		}
		//�������� �������
		if (M.line >= 3 && M.column >= 3) {
			for (int i = 1; i < M.line-1; i++) {
				for (int j = 1; j < M.column-1; j++) {
					if (M.mat[i][j] > M.mat[i][j - 1] && M.mat[i][j] > M.mat[i - 1][j - 1] && M.mat[i][j] > M.mat[i - 1][j] && M.mat[i][j] > M.mat[i - 1][j + 1] && M.mat[i][j] > M.mat[i][j + 1]
						&& M.mat[i][j] > M.mat[i + 1][j + 1] && M.mat[i][j] > M.mat[i + 1][j] && M.mat[i][j] > M.mat[i + 1][j - 1]) {
						max.push_back(M.mat[i][j]);
						MaxSum++;
					}
					if (M.mat[i][j] < M.mat[i][j - 1] && M.mat[i][j] < M.mat[i - 1][j - 1] && M.mat[i][j] < M.mat[i - 1][j] && M.mat[i][j] < M.mat[i - 1][j + 1] && M.mat[i][j] < M.mat[i][j + 1]
						&& M.mat[i][j] < M.mat[i + 1][j + 1] && M.mat[i][j] < M.mat[i + 1][j] && M.mat[i][j] < M.mat[i + 1][j - 1]) {
						min.push_back(M.mat[i][j]);
						MinSum++;
					}
				}
			}
		}
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
void Matrix::MinLine(const Matrix & M)
{
	vector<double> sum;
	for (int i = 0; i < M.line; i++) {
		double max = M.mat[i][0];
		for (int j = 0; j < M.column; j++) {
			if (max < M.mat[i][j]) {
				max = M.mat[i][j];
			}
		}
		sum.push_back(max);
	}
	std::sort(sum.begin(), sum.end());
	cout << "Min " << sum[0] << endl;
}
void Matrix::MaxColumn(const Matrix & M)
{
	vector<double> sum;
	int one = 0;
	for (int i = 0; i < M.column; i++) {
		double min = M.mat[0][i];
		for (int j = 0; j < M.line; j++) {
			if (min > M.mat[j][i]) {
				min = M.mat[j][i];
			}
		}
		sum.push_back(min);
		one++;
	}
	std::sort(sum.begin(), sum.end());
	cout << "Max " << sum[one-1] << endl;
}
void Matrix::SadPoint(const Matrix & M)
{
	vector<double> Aline, Bcolumn, Happens;
	unsigned sum = 0;
	for (int i = 0; i < M.line; i++) {
		double min = M.mat[i][0];
		for (int j = 0; j < M.column; j++) {
			if (min > M.mat[i][j]) {
				min = M.mat[i][j];
			}
			else if (min == M.mat[i][j]) {
				Happens.push_back(min);
				sum++;
			}
		}
		Aline.push_back(min);
	}
	for (int i = 0; i < M.column; i++) {
		double max = M.mat[0][i];
		for (int j = 0; j < M.line; j++) {
			if (max < M.mat[j][i]) {
				max = M.mat[j][i];
			}
			else if (max == M.mat[j][i]) {
				Happens.push_back(max);
				sum++;
			}
		}
		Bcolumn.push_back(max);
	}
	std::sort(Aline.begin(), Aline.end());
	std::sort(Bcolumn.begin(), Bcolumn.end());
	if (Aline[Aline.size() - 1] < Bcolumn[0]) {
		cout << "There are no saddle points in the matrix" << endl;
	}
	else if (sum / 2 == M.column*M.line) {
		cout << "All elements" << sum / 2 << endl;
		cout << "All elements of the matrix are equal " << Happens[0] << endl;
	}
	else if (Aline[Aline.size() - 1] == Bcolumn[0] && sum / 2 != M.column*M.line) {
		vector<double> number;
		for (double sumA : Aline) {
			for (double sumB : Bcolumn) {
				if (sumA == sumB) {
					number.push_back(sumB);
				}
			}
		}
		cout << "All elements[-] ";
		for (double n : number) {
			cout << n << " | ";
		}
		cout << endl;
	}
}