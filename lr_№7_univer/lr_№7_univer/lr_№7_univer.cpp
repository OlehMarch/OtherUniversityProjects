// lr_¹7_univer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include <windows.h>
using namespace std;
//------------------------------------------------------------------------
bool checkValue(int value) {
	return ((value < 13) && (value > 3)) ? true : false;
}
//------------------------------------------------------------------------
void constrOfTable() {
	for (int i = 0; i < 3; i++) {
		system("cls");
		cout<<"Table under construction\nPlease wait.";
		Sleep(300);
		system("cls");
		cout<<"Table under construction\nPlease wait..";
		Sleep(300);
		system("cls");
		cout<<"Table under construction\nPlease wait...";
		Sleep(300);
	}
	system("cls");
}
//------------------------------------------------------------------------
void outputOfTable(int **Array, int countOfPeople) {
	cout<<" ___";
	for (int i = 0; i < countOfPeople; i++) {
		cout<<"______";
	}
	cout<<" \n|   |";
	for (int i = 0; i < countOfPeople; i++) {
		cout<<"  ";
		if (i+1 > 9) {
			cout.width(2);
			cout<<i+1;
			cout<<" |";
		}
		if (i+1 < 10) {
			cout<<i+1<<"  |";
		}
	}
	cout<<"\n|---|";
	for (int i = 0; i < countOfPeople; i++) {
		cout<<"-----|";
	}
	cout<<"\n";
	for (int i = 0; i < countOfPeople; i++) {
		cout<<"| ";
		if (i+1 > 9) {
			cout.width(2);
			cout<<i+1;
			cout<<"|";
		}
		if (i+1 < 10) {
			cout<<i+1<<" |";
		}		
		for (int j = 0; j < countOfPeople; j++) {
			if (i == j) {
				cout<<"  -  |";
			} else {
				cout<<"  "<<Array[i][j]<<"  |";
			}
		}
		cout<<"\n";
	}
	cout<<"|___|";
	for (int i = 0; i < countOfPeople; i++) {
		cout<<"_____|";
	}
	cout<<"\n";
}
//------------------------------------------------------------------------
int** friendMaking(int **Array, int countOfPeople, int *Group1, int *Group2) {
	int num1 = 0, num2 = -1;
	for (int i = 0; (i < countOfPeople) && (num1 != num2); i++) {
		outputOfTable(Array, countOfPeople);
		cout<<"\n\nTo exit from this menu insert equal numbers\n";
		cout<<"\nInsert two number to make them friends: ";
		cin>>num1>>num2;
		Array[num1-1][num2-1] = Array[num2-1][num1-1] = 1;
		Group1[i] = num1;
		Group2[i] = num2;
		system("cls");
	}
	return Array;
}
//------------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	int **Array = NULL, countOfPeople = NULL;
	int *Group1 = NULL, *Group2 = NULL;
	int n = 0, m = 0;	

	cout<<"Insert count of people: ";
	cin>>countOfPeople;

	if (!checkValue(countOfPeople)) {
		cout<<"\nIncorrect iserted data!";
		goto stop;
	}

	Array = new int*[countOfPeople];
	for (int i = 0; i < countOfPeople; i++) {
		Array[i] = new int[countOfPeople];
		for (int j = 0; j < countOfPeople; j++) {
			Array[i][j] = 0;
		}
	}
	Group1 = new int[countOfPeople];
	Group2 = new int[countOfPeople];
	for (int i = 0; i < countOfPeople; i++) {
		Group1[i] = NULL;
		Group2[i] = NULL;
	}

	constrOfTable(); 
	friendMaking(Array, countOfPeople, Group1, Group2);
	outputOfTable(Array, countOfPeople);

	cout<<"Group1 -";
	for (int i = 0; i < countOfPeople-2; i++) {
		if (Group1[i] != Group2[i]) {
			cout<<" "<<Group1[i];
		}
	}
	cout<<"\nGroup2 -";
	for (int i = 0; i < countOfPeople-2; i++) {
		if (Group1[i] != Group2[i]) {
			cout<<" "<<Group2[i];
		}
	}

stop:
	cout<<"\n\nPress any key to continue...";
	_getch();
}