// ConsoleMatrix.cpp: Линейные структуры данных. Разреженные матрицы.
#include <iostream>
#include <windows.h>		//для меню
#include "Matrix.h"
using std::endl;
using std::cout;
using std::cin;
int check() {
	int qwe;
	while (true)
	{
		cout << "Выберите необходимые действия:" << endl;
		cin >> qwe;
		if (cin.fail())
		{
			cout << "Это должно быть число" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (qwe <= 0)
		{
			cout << " Значение должно быть положительным" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		if (qwe > 12)
		{
			cout << " Возможное значение <В диапозоне от 1-12>" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		else break;
	}
	system("cls");
	cin.clear();
	cin.ignore(32767, '\n');
	return qwe;
}
int menu() {
	int one = 0;
	HANDLE O = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(O, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << endl << "#####*****@@@@@*****#####" << endl;
	cout << "ОСНОВНОЕ МЕНЮ ВВОД ДАННЫХ С КЛАВИАТУРЫ." << endl;
	SetConsoleTextAttribute(O, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "1.Создание матрицы. Задать кол-во строк и столбцов и значение элементов матрицы. (значение будут одинаковые)" << endl;
	cout << "2.Создание матрицы из файла." << endl;
	cout << "3.Сумма всех элементов." << endl;
	cout << "4.Произведение всех элементов." << endl;
	cout << "5.Максимальный и минимальный элементы." << endl;
	cout << "6.Последовательность элементов, полученную при обходе по строкам" << endl;
	cout << "7.Последовательность элементов, полученную при обходе по столбцам" << endl;
	cout << "8.Список локальных максимумов (минимумов)." << endl;
	cout << "9.Минимум из максимальных элементов строк." << endl;
	cout << "10.Максимум из минимальных элементов столбцов." << endl;
	cout << "11.Список седловых точек." << endl;
	cout << "12.Выход." << endl;
	one = check();
	return one;
}
int main()
{
	const char* name = "Example.txt";
	const char* n = "SadPointOne3x4.txt";
	const char* Mat = "Mat4x12.txt";
	setlocale(LC_ALL, "Russian");
Mem1:
	int q = menu();
	if (q == 1) {
		
		goto Mem1;
	}
	if (q == 2) {

		goto Mem1;
	}
	if (q = 12) {
		exit(EXIT_FAILURE);
	}
	/*Matrix M(2, 2, 16.23);
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
	M.MatrixLine(Q);
	M.MatrixColumn(Q);
	M.LocalMaxMinMatrix(Q);
	M.MinLine(Q);
	M.MaxColumn(Q);
	Matrix One = M.readfile(Mat, 4, 4);
	M.PrintM(One);
	M.SadPoint(One);*/
	return 0;
}