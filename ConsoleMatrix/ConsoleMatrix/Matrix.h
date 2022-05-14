//Определение класса матрица
#pragma once
#include <vector>
class Matrix
{
	unsigned line;			//строки 
	unsigned column;		//столбцы
	std::vector<std::vector <double> >mat;
public:
	unsigned get_line() const;		//получить значение строк
	unsigned get_column() const;	//получить значение столбцов
	Matrix(unsigned _l, unsigned _c, const double key);		//параметрический конструктор аргументы; кол-во строк, кол-во столбцов (в матрице) и значение элементов в матрице
	double operator()(const unsigned& row, const unsigned& col) const;	//доступ к элементам матрицы
	double sumElements() const;			//сумма всех элементов
	double multiElements() const;		//произвидение всех элементов
	Matrix readfile(const char* name, unsigned _l, unsigned _c);	//заполнение из файла; имя файла кол-во строк, кол-во столбцов
	void PrintM(const Matrix& M);		//вывод матрицы в консоль табличный вид
	void MaxMin(const Matrix& M);		//поиск max и min элемента матрицы
	void MatrixLine(const Matrix& M);	//последовательность элементов, полученную при обходе по строкам
	void MatrixColumn(const Matrix& M);	//последовательность элементов, полученную при обходе по столбцам
	void LocalMaxMinMatrix(const Matrix& M);	//список локальных максимумов минимумов 
};