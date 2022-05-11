//реализация 
#include <iostream>
#include <fstream>                                          // читать и писать файлы
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
	if (root->data < key)			//ключ больше чем корень
		return search(root->r, key);
	return search(root->l, key);	//ключ меньше чем корень
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
	if (root->l == NULL) {			// если удаляемый элемент лист
		tree* temp = root->r;
		delete root;
		return temp;
	}
	else if (root->r == NULL) {
		tree* temp = root->l;
		delete root;
		return temp;
	}
	else {						// если удаляем корень или родителя 
		tree* Parent = root;
		tree *succ = root->r;
		while (succ->l != NULL) {	// кто станет корнем или родителем поиск
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
