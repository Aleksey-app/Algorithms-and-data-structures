//����������� ������ �������
#pragma once
#include <vector>
class Matrix
{
	unsigned line;			//������ 
	unsigned column;		//�������
	std::vector<std::vector <double> >mat;
public:
	unsigned get_line() const;		//�������� �������� �����
	unsigned get_column() const;	//�������� �������� ��������
	Matrix(unsigned _l, unsigned _c, const double key);		//��������������� ����������� ���������; ���-�� �����, ���-�� �������� (� �������) � �������� ��������� � �������
	double operator()(const unsigned& row, const unsigned& col) const;	//������ � ��������� �������
	double sumElements() const;			//����� ���� ���������
	double multiElements() const;		//������������ ���� ���������
	Matrix readfile(const char* name, unsigned _l, unsigned _c);	//���������� �� �����; ��� ����� ���-�� �����, ���-�� ��������
	void PrintM(const Matrix& M);		//����� ������� � ������� ��������� ���
	void MaxMin(const Matrix& M);		//����� max � min �������� �������
	void MatrixLine(const Matrix& M);	//������������������ ���������, ���������� ��� ������ �� �������
	void MatrixColumn(const Matrix& M);	//������������������ ���������, ���������� ��� ������ �� ��������
	void LocalMaxMinMatrix(const Matrix& M);	//������ ��������� ���������� ��������� 
};