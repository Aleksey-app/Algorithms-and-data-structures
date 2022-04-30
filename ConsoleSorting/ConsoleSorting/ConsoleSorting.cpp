// ConsoleSorting.cpp
#include <iostream>
#include <iomanip>
#include <sperror.h>										// для обработки ошибок
#include <string>											// для одноименной функции
#include <chrono>                                           // для функций времени
#include <fstream>                                          // читать и писать файлы
#include <windows.h>                                        // подключает функционал ОС Windows
#include <conio.h>
using namespace std;
struct BinaryT {											// структура для дерева 
	int data;												// данные
	BinaryT* l;												// левая часть дерева
	BinaryT* r;												// правая часть дерева
};
BinaryT* tree = NULL;										// создание корня дерева
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
	cout << "Загрузка файла " << name << endl;
	ifstream file(name);
	if (!file)
	{
		perror("name[-]");
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << "Файл " << name << " открыт!" << endl;
	}
	arr = new int[kol]; // выделение памяти под массив
	for (int i = 0; i <= kol; i++) {
		arr[i] = 0;
		while (true)
		{
			file >> arr[i];
			if (!file)
			{
				cout << "Ошибка чтения, проверьте данные в файле." << endl;
				return 0;
			}
			else break;
		}
	}
	file.close();
}
void qsortR(int *mas, int size) {                           // быстрая сортировка; указатель на массив и его размер
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];                                // центральный элемент массива опорный элемент
	do {                                                    // делию массив; ищем которые нужно перекинуть в другую часть
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {                               // в правой части пропускаем элементы которые больше центрального
			j--;
		}
		if (i <= j) {                                       // меняем элементы местами
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
															 // рекурсивные вызовы если осталось что сортировать
	if (j > 0) {                                             // левый кусок
		qsortR(mas, j + 1);
	}
	if (i < size) {                                         // првый кусок
		qsortR(&mas[i], size - i);
	}
}
void outA(int *q, int kol) {								// вывод массива в консоль
	if (kol == 0)
	{
		cout << " В массиве нет элементов " << endl;
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
void treeCreation(int a, BinaryT ** x) {					// создание дерева
	if ((*x) == NULL)										// если дерева не существует
	{
		(*x) = new BinaryT;                                 // выделяем память
		(*x)->data = a;										// кладем в выделенное место аргумент 
		(*x)->l = (*x)->r = NULL;                           // очищаем память для следующего роста
		return;
	}
	if (a > (*x)->data) treeCreation(a, &(*x)->r);			// если аргумент а больше чем текущий элемент, кладем его вправо
	else treeCreation(a, &(*x)->l);							// иначе кладем его влево
}
void readTreee(BinaryT* x) {								// заполнение дерева элементами
	cout << "Загрузка файла " << name << endl;
	ifstream file(name);
	if (!file){
		perror("name[-]");
		exit(EXIT_FAILURE);
	}
	else {
		cout << "Файл " << name << " открыт!" << endl;
		treeCreation(,&tree)
	}
}
void outT(BinaryT* x, int size) {
	if (x == NULL) {										// если дерево пустое, то отображать нечего, выходим
		perror("TreeOut[-]");
		exit(EXIT_FAILURE);
	}
	else {
		outT(x->l, ++size);									// рекурсия левое поддерево
		for (int i = 0; i <= size; ++i) cout << "|";
		cout << x->data << endl;
		size--;
	}
	outT(x->r, ++size);									    // рекурсия правое поддерево
}
int main() {
	setlocale(LC_ALL, "Russian");
	int size = arrSize();
	arrCreation(size);
	cout << "Создан массив из " << size+1 << " элементов." << endl;
	auto start = chrono::system_clock::now();
	qsortR(arr, size);
	auto end = chrono::system_clock::now();
	chrono::duration<double> diff = end - start;
	cout << "Скорость сортировки массива данных = " << diff.count() << "сек." << endl;
	cout << " Отсортированный массив" << endl;
	outA(arr, size);


	return 0;
}