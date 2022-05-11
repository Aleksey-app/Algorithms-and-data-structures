//Определение класса бинарное дерево поиска
#pragma once
#include <iostream>
class tree
{
	int data;			// данные
	tree* l;			// указатель на левое поддерево
	tree* r;			// указатель на правое поддерево
public:
	tree(int d);				// конструктор
	tree* search(tree* root, int key);			// поиск по значению
	tree* insert(tree* root, int data);			// вставить значение в дерево; создание дерева
	tree* deletetree(tree* root, int key);		// удаление узла в бинарном дереве; 
	void print(tree* root);						// прямой обход
	tree* readfile(const char* name, tree* root, int num);	// заполнение из файла
};

