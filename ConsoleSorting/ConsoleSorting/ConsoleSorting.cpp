// ConsoleSorting.cpp
#include <iostream>
#include <sperror.h>										// для обработки ошибок
#include <chrono>                                           // для функций времени
#include <string>											// для одноименной функции
#include <fstream>                                          // читать и писать файлы
#include <windows.h>                                        // подключает функционал ОС Windows
#include <conio.h>
#include "tree.h"											// класс бинарного дерева поиска
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
int *arr;                                                   // указатель для выделения памяти под массив
const char* name = "Best.txt";                              // имена файлов с разными скоростями сортировки Best Average Worst
int arrSize() {												// подсчёт строк в файле
	int size = 0;
	ifstream file(name);
	if (!file)
	{
		perror("name[-]");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (true)
		{
			string v;
			getline(file, v);
			if (!file.eof())
				size++;
			else
				break;
		}
		/*cin.get();*/
	}
	file.close();
	return size;
}
int arrCreation(int kol) {									// создание массива
	cout << "Upload file " << name << endl;
	ifstream file(name);
	if (!file)
	{
		perror("name[-]");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "File " << name << " open!" << endl;
	}
	arr = new int[kol]; // выделение памяти под массив
	for (int i = 0; i <= kol; i++) {
		arr[i] = 0;
		while (true)
		{
			file >> arr[i];
			if (!file)
			{
				cout << "Error!" << endl;
				return 0;
			}
			else break;
		}
	}
	file.close();
}
void qsortR(int *mas, int first, int last) {                           // быстрая сортировка; указатель на массив его начало и конец
	if (first < last) {
		int opora = mas[first], swap_index = first;
		for (int i = first + 1; i != last + 1; i++) {
			if (mas[i] <= opora) {
				swap_index++;
				std::swap(mas[i], mas[swap_index]);
			}
		}
		std::swap(mas[first], mas[swap_index]);
		qsortR(mas, first, swap_index - 1);
		qsortR(mas, swap_index + 1, last);
	}
}
void outA(int *q, int kol) {								// вывод массива в консоль
	if (kol == 0)
	{
		cout << " There are no elements in the array " << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i <= kol; i++) {
		cout << q[i] << " ";
		if (kol == 32) {
			cout << endl;
		}
	}
	cout << endl;
}
int main() {
	int size = arrSize();
	arrCreation(size);
	cout << "Created an array from " << size+1 << " elements." << endl;
	auto start = std::chrono::system_clock::now();
	qsortR(arr, 0, size);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "Sort rate of the data array = " << diff.count() << "sec." << endl;
	cout << "Sorted array:" << endl;
	outA(arr, size);
	tree T(0);												// инициализация дерева
	tree* root = NULL;										// создание корня дерева
	// ввод значений через консоль без проверки данных
	/*int t;										
	cin >> t;
	while (t--) {
		int data;
		cin >> data;
		root = T.insert(root, data);
	}*/
	// инициализация бинарного дерева заранее известными значениями и вывод значений в консоль прямым обходом 
	/*root = T.insert(root, 8);
	root = T.insert(root, 3);
	root = T.insert(root, 10);
	root = T.insert(root, 1);
	root = T.insert(root, 6);
	root = T.insert(root, 4);
	root = T.insert(root, 7);
	root = T.insert(root, 5);
	root = T.insert(root, 10);
	root = T.insert(root, 9);
	root = T.insert(root, 13);
	root = T.insert(root, 11);
	root = T.insert(root, 14);
	root = T.insert(root, 12);
	root = T.insert(root, 2);
	T.print(root);*/
	// заполнение бинарного дерева из файла и вывод значений в консоль прямым обходом 
	tree* f = T.readfile(name, root, size);
	T.print(f);
	cout << "Enter the data to find: ";
	int data;
	cin >> data;
	start = std::chrono::system_clock::now();
	tree* S = T.search(f, data);
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> diffBST = end - start;
	cout << "Find tree elements = " << diffBST.count() << "sec." << endl;
	if (S != NULL) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}