// lr_�4_univer.cpp : Defines the entry point for the console application.
// ��������� ��� ���������� � �������� ������������� �������� � ����� � ����������� ������� � ������ ����

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
#include <windows.h>
using namespace std;
//----------------------------------------------------------------------
bool checkError(char *value) {
	/* * * * * * * * * * * * * * * * * * * * * * *
	 * ������� ��� �������� ������������� �����  *
	 * ����: value - ��� ������������ �����      *
	 * * * * * * * * * * * * * * * * * * * * * * */
	FILE *file = fopen(value, "r");
	if (!file) {
		cout<<"File doesn't exist!\n";
		return false;
	}
	return true;
}
//----------------------------------------------------------------------
void fileOpen(char *str, char *fileName1) {
	/* * * * * * * * * * * * * * * * * * * * * * *
	 *          ������� ��� ����� �����          *
	 * ����: fileName1 - ��� �����               *
	 * str - ���������� �� ����� � ��� ������    *
	 * * * * * * * * * * * * * * * * * * * * * * */
	cout<<"Insert the name of the first file: ";
	cin>>fileName1;
	ifstream fin(fileName1);
	fin>>str;
	fin.close();
}
//----------------------------------------------------------------------
void fileOutput(char *str, char *fileName2) {
	/* * * * * * * * * * * * * * * * * * * * * * *
	 *          ������� ��� ������ �����         *
	 * ����: fileName2 - ��� �����               *
	 * str - ������ ���� ������ � ����           *
	 * * * * * * * * * * * * * * * * * * * * * * */
	cout<<"Insert the name of the second file: ";
	cin>>fileName2;
	ofstream fout(fileName2);
	fout<<str;
	fout.close();
}
//----------------------------------------------------------------------
void truncOfMaxElement(char *str) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * ������� ��� �������� ������������� �������� � ����� *
	 * ����: str - ��������� ������ �� ������� �����       *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	atoi(str);
	int max = str[0], indexOfMax = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (max < str[i]) {
			max = str[i];
			indexOfMax = i;
		}
	}
	for (int i = indexOfMax; i < strlen(str); i++) {
		str[i] = str[i + 1];
	}
}
//----------------------------------------------------------------------
void waitFunc() {
	/*������� ��������� ��������*/
	Sleep(1000);
	cout<<".";
	Sleep(1000);
	cout<<".\n";
	Sleep(1000);
}
//----------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char *fileName1 = NULL;
	fileName1 = new char[10];
	char *fileName2 = NULL;
	fileName2 = new char[10];
	char *str = NULL;
	str = new char[32];
	
	fileOpen(str, fileName1);

	if (!checkError(fileName1)) {
		goto finish;
	}

	cout<<"Reading from file 1.";
	waitFunc();

	cout<<"\nstr = {"<<str<<"}\n\n";

	cout<<"Finding and deleting maximal element.";
	waitFunc();

	truncOfMaxElement(str);

	cout<<"\nstr = {"<<str<<"}\n\n";
	
	fileOutput(str, fileName2);

	cout<<"Loading string to file 2.";
	waitFunc();
	
	finish:
	cout<<"Press any key to continue...";
	getch();
}