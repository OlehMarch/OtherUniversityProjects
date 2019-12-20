// lr_№6_univer.cpp : Defines the entry point for the console application.
//Работа с деревом

#include "stdafx.h"
#include "iostream"
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
//------------------------------------------------------------------------
struct Tree {
	int value;
	Tree *left;
	Tree *right;
};
//------------------------------------------------------------------------
void output(Tree *u) {
	//фугкция вывода элементов дерева
	if (u) {
		output(u->right);
		cout<<u->value<<" ";;
		output(u->left);
	}
}
//------------------------------------------------------------------------
Tree* deleteElements(Tree *u, int value) {
	//функция удаления элеметов дерева и всех их потомков
	if (u == NULL) {
		return NULL;
	}
	if (value == u->left->value) {
		u->left = NULL;
		return u;
	}
	if (value == u->right->value) {
		u->right = NULL;
		return u;
	}
	if (value < u->value) {
		return deleteElements(u->left, value);
	}
	return deleteElements(u->right, value);
}
//------------------------------------------------------------------------
Tree* dtree(Tree *u, int value) {
	//функция удаления элеметов дерева
	Tree *p,*p2;

	if(!u) {
		return u;
	}
	if(u->value == value) {
		if(u->left == u->right){
			free(u);
			return NULL;
		}
    /* или если одно из поддеревьев пустое */
		else if(u->left == NULL) {
			p = u->right;
			free(u);
			return p;
		}
		else if(u->right == NULL) {
			p = u->left;
			free(u);
			return p;
		}
    /* или есть оба поддерева */
		else {
			p2 = u->right;
			p = u->right;
			while(p->left) {
				p = p->left;
			}
			p->left = u->left;
			free(u);
			return p2;
		}
	}
	if(u->value < value) {
		u->right = dtree(u->right, value);
	}
	else {
		u->left = dtree(u->left, value);
	}
	return u;
}
//------------------------------------------------------------------------
Tree* addElements(Tree *u, int x) {
	//функция добавления элеметов дерева
	if (u == NULL) {
		u = new Tree;
		u->left = NULL;
		u->right = NULL;
		u->value = x;
		return u;
	}
	if (x < u->value) {
		u->left = addElements(u->left, x);
	}
	else {
		u->right = addElements(u->right, x);
	}
	return u;
}
//------------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	int value = 0, length = 0;
	Tree *u = NULL;
	u = new Tree;

	cout<<"Insert count of elements of a tree: ";
	cin>>length;

	//Создание первого элемента списка
	cout<<"Insert data: ";
	cin>>u->value;
	u->left = NULL;
	u->right = NULL;

	//Создание разветвления дерева
	for (int i = 0; i < length; i++) {
		cout<<"Insert data: ";
		cin>>value;
		addElements(u, value);
	}

	cout<<"\nOutput of the elements of a tree: ";
	output(u);

	/*cout<<"\n\nU = "<<u->value<<endl;
	cout<<"U->right = "<<u->right->value<<endl;
	cout<<"U->left = "<<u->left->value<<endl;
	cout<<"U->left->left = "<<u->left->left->value<<endl;
	cout<<"U->right->right = "<<u->right->right->value<<endl;
	cout<<"U->right->left = "<<u->right->left->value<<endl;
	cout<<"U->right->left->left = "<<u->right->left->left->value<<endl;*/

	cout<<"\n\nInsert value that you wanna delete: ";
	cin>>value;
	dtree(u, value);

	cout<<"\nOutput of the elements of a tree: ";
	output(u);

	cout<<"\n\nPress any key to continue...";
	_getch();
}