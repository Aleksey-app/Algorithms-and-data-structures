// ConsoleSorting.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>                                           // для функций времени
#include <fstream>                                          // читать и писать файлы
#include <windows.h>                                        // подключает функционал ОС Windows
using namespace std;
int *arr;                                                   // указатель для выделения памяти под массив
const char* name = "Best.txt";                              // имена файлов с разными скоростями сортировки Best Average Worst
int CreateArr() {                                           // функция создание массива
	cout << "\n Загрузка файла " << name << endl;
	int size = 0;
	ifstream file(name);
	if (!file)
	{
		cout << "Файл не открыт!!!" << endl;
		return 0;
	}
	else {
		while (true)
		{
			string v;
			getline(file, v);
			if (!file.eof())
				size++;
			else
				break;
		}
		cin.get();
		cout << "Всё работает. Файл открыт!" << endl;
	}
	arr = new int[size];                                       // выделение памяти под массив
	for (int i = 0; i < size; i++) {
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
	return size;
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
int main() {

	return 0;
}
