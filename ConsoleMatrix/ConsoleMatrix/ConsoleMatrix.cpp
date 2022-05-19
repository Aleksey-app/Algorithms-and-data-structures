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
	cout << "1.Создание матрицы. Задать кол-во строк и столбцов значение элементов матрицы выберется по умолчанию rand()." << endl;
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
	const char* MOne = "SadPointOne3x4.txt";
	const char* Mat = "Mat4x7.txt";
	Matrix emptil(2, 2, 2);
	setlocale(LC_ALL, "Russian");
Mem1:
	int q = menu();
	if (q == 1) {
		cout << "Задайте кол-во строк: ";
		int l = check();
		cout << endl;
		cout << "Задайте кол-во столбцов: ";
		int c = check();
		double f = (double)rand() / RAND_MAX;
		double sum = f * (2547.34 - 0.00001);
		Matrix one(l, c, sum);
		emptil = one;
		one.PrintM(emptil);
		goto Mem1;
	}
	if (q == 2) {
		Matrix two = emptil.readfile(name, 7, 7);
		emptil = two;
		two.PrintM(emptil);
		goto Mem1;
	}
	if (q == 3) {
		emptil.PrintM(emptil);
		cout << "Сумма всех элементов матрицы = ";
		double s = emptil.sumElements();
		cout << s << endl;
		goto Mem1;
	}
	if (q == 4) {
		emptil.PrintM(emptil);
		cout << "Произведение всех элементов матрицы = ";
		double m = emptil.multiElements();
		cout << m << endl;
		goto Mem1;
	}
	if (q == 5) {
		emptil.PrintM(emptil);
		emptil.MaxMin(emptil);
		goto Mem1;
	}
	if (q == 6) {
		emptil.PrintM(emptil);
		emptil.MatrixLine(emptil);
		goto Mem1;
	}
	if (q == 7) {
		emptil.PrintM(emptil);
		emptil.MatrixColumn(emptil);
		goto Mem1;
	}
	if (q == 8) {
		emptil.PrintM(emptil);
		emptil.LocalMaxMinMatrix(emptil);
		goto Mem1;
	}
	if (q == 9) {
		emptil.PrintM(emptil);
		emptil.MinLine(emptil);
		goto Mem1;
	}
	if (q == 10) {
		emptil.PrintM(emptil);
		emptil.MaxColumn(emptil);
		goto Mem1;
	}
	if (q == 11) {
		cout << "Список седловых точек." << endl;
		cout << "Далеко не все матрицы имеют седловые точки." << endl;
		cout << "Матрица сгенерированная в процессе работы алгоритма." << endl;
		emptil.SadPoint(emptil);
		cout << "Загружу подготовленный в процессе отладки пример с одной седловой точкой" << endl;
		cout << "Нажмите enter";
		getchar();
		Matrix Eleven = emptil.readfile(MOne, 3, 4);
		emptil = Eleven;
		emptil.PrintM(emptil);
		emptil.SadPoint(emptil);
		cout << "Загружу подготовленный в процессе отладки пример с несколькими точками" << endl;
		cout << "Нажмите enter";
		getchar();
		Matrix ok = emptil.readfile(Mat, 4, 7);
		emptil = ok;
		emptil.PrintM(emptil);
		emptil.SadPoint(emptil);
		goto Mem1;
	}
	if (q == 12) {
		exit(EXIT_FAILURE);
	}
	return 0;
}