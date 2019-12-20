// lr_№5_univer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include <windows.h>
#include "struct.h"
using namespace std;

void _tmain(int argc, _TCHAR* argv[]){

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int listLength = 0, iValue = 0, choice = 0;
	List *u = NULL;
	u = new List;

	cout<<"Insert length of list: ";
	cin>>listLength;

	//Создание первого элемента списка
	cout<<"Insert data: ";
	cin>>u->value;
	u->next = NULL;
//------------------------------------------------------------------------------------------------------//
	cout<<"Choose type of adding of elements:\n";
	cout<<"	1. Adding to begining\n";
	cout<<"	2. Adding to the end\n";
	cout<<"Your choice: ";
	cin>>choice;
	switch(choice) {
		case 1:
			for (int i = 0; i < listLength; i++) {
				u = addB(i, u);
			}
			break;
		case 2:
			for (int i = 0; i < listLength; i++) {
				u = addE(i, u);
			}
			break;
		default: 
			cout<<"Incorrect inserted value\n\n";
			goto stop;
	}
	cout<<endl<<"Original ";
	Print(u); //вывод списка
//------------------------------------------------------------------------------------------------------//
	cout<<"\nChoose where you wonna add element:\n";
	cout<<"	1. Adding after inserted value\n";
	cout<<"	2. Adding before inserted value\n";
	cout<<"Your choice: ";
	cin>>choice;
	switch(choice) {
		case 1:
			cout<<"Insert value of the element after which new element will be added: ";
			cin>>iValue;
			addAfter(iValue, u);
			cout<<endl;
			Print(u);//вывод списка с вставленым елементом после елемента со значением iValue
			break;
		case 2:
			cout<<"Insert value of the element before which new element will be added: ";
			cin>>iValue;
			addBefore(iValue, u);
			cout<<endl;
			Print(u);//вывод списка с вставленым елементом до елемента со значением iValue
			break;
		default: cout<<"Incorrect inserted value\n\n";
			goto stop;
	}
	cout<<endl;
//------------------------------------------------------------------------------------------------------//
	cout<<"Choose type of printing of the element:\n";
	cout<<"	1. Printing by sequence number\n";
	cout<<"	2. Printing by value\n";
	cout<<"Your choice: ";
	cin>>choice;
	switch(choice) {
		case 1:
			cout<<"Insert sequence number to print element with this number: ";
			cin>>iValue;
			printElementBySequenceNumber(iValue, u);
			cout<<endl<<endl;
			break;
		case 2:
			cout<<"Insert value to print sequence number of this element: ";
			cin>>iValue;
			printElementByValueFromBeginig(iValue, u);
			cout<<endl<<endl;
			break;
		default: 
			cout<<"Incorrect inserted value\n\n";
			goto stop;
	}
//------------------------------------------------------------------------------------------------------//
	cout<<"Choose type of deleting of the element:\n";
	cout<<"	1. Deleting of the first element\n";
	cout<<"	2. Deleting of the last element\n";
	cout<<"	3. Deleting by value\n";
	cout<<"	4. Deleting by sequence number\n";
	cout<<"Your choice: ";
	cin>>choice;
	switch(choice) {
		case 1:
			//удаление первого элемента списка
			u = delFirstElement(u);
			cout<<endl<<"Without first element ";
			Print(u);//вывод списка без первого элемента
			break;
		case 2:
			//удаление последнего элемента списка
			u = delLastElement(u);
			cout<<endl<<"Without last element ";
			Print(u);//вывод списка без последнего элемента
			break;
		case 3:
			cout<<"Insert value to delete element with this value: ";
			cin>>iValue;
			delElementByValue(iValue, u);
			cout<<endl;
			Print(u);
			break;
		case 4:
			cout<<"Insert sequence number to delete element with this number: ";
			cin>>iValue;
			delElementBySequenceNumber(iValue, u);
			cout<<endl;
			Print(u);
			break;
		default: 
			cout<<"Incorrect inserted value\n\n";
			goto stop;
	}
	cout<<endl;
//------------------------------------------------------------------------------------------------------//
stop:
	cout<<"Press any key to continue...";
	getch();
}