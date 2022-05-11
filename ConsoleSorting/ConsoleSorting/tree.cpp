//���������� 
#include <iostream>
#include <fstream>                                          // ������ � ������ �����
#include "tree.h"
using std::cout;
using std::endl;
using std::ifstream;
tree::tree(int d)
{
	data = d;
	l = NULL;
	r = NULL;
}
tree * tree::search(tree * root, int key)
{
	if (root == NULL || root->data == key)
		return root;
	if (root->data < key)			//���� ������ ��� ������
		return search(root->r, key);
	return search(root->l, key);	//���� ������ ��� ������
}
tree * tree::insert(tree * root, int data)
{
	if (root == NULL) {
		return new tree(data);
	}
	else {
		tree* cur;
		if (data <= root->data) {
			cur = insert(root->l, data);
			root->l = cur;
		}
		else {
			cur = insert(root->r, data);
			root->r = cur;
		}
		return root;
	}
}
tree * tree::deletetree(tree * root, int key)
{
	if (root == NULL)
		return root;
	if (root->data > key) {
		root->l = deletetree(root->l, key);
		return root;
	}
	else if (root->data < key) {
		root->r = deletetree(root->r, key);
		return root;
	}
	if (root->l == NULL) {			// ���� ��������� ������� ����
		tree* temp = root->r;
		delete root;
		return temp;
	}
	else if (root->r == NULL) {
		tree* temp = root->l;
		delete root;
		return temp;
	}
	else {						// ���� ������� ������ ��� �������� 
		tree* Parent = root;
		tree *succ = root->r;
		while (succ->l != NULL) {	// ��� ������ ������ ��� ��������� �����
			Parent = succ;
			succ = succ->l;
		}
		if (Parent != root)
			Parent->l = succ->r;
		else
			Parent->r = succ->r;
		root->data = succ->data;
		delete succ;
		return root;
	}
}
void tree::print(tree * root)
{
	if (root == NULL) {
		return;
	}
	else {
		cout << root->data << " ";
		print(root->l);
		print(root->r);
	}
}
tree * tree::readfile(const char * name, tree * root, int num)
{
	cout << "Upload file " << name << endl;
	ifstream file(name);
	if (!file)
	{
		cout << "File " << name << " error!!!" << endl;
	}
	else
	{
		cout << "File " << name << " open!" << endl;
	}
	int key;
	for (int i = 0; i <= num; i++)
	{
		file >>  key;
		root = insert(root, key);
	}
	file.close();
	return root;
}
