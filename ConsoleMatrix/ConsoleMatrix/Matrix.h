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
	Matrix* readfile(const char* name, unsigned _l, unsigned _c);	//���������� �� �����; ��� ����� ���-�� �����, ���-�� ��������
};