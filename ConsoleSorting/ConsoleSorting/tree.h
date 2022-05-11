//����������� ������ �������� ������ ������
#pragma once
#include <iostream>
class tree
{
	int data;			// ������
	tree* l;			// ��������� �� ����� ���������
	tree* r;			// ��������� �� ������ ���������
public:
	tree(int d);				// �����������
	tree* search(tree* root, int key);			// ����� �� ��������
	tree* insert(tree* root, int data);			// �������� �������� � ������; �������� ������
	tree* deletetree(tree* root, int key);		// �������� ���� � �������� ������; 
	void print(tree* root);						// ������ �����
	tree* readfile(const char* name, tree* root, int num);	// ���������� �� �����
};

