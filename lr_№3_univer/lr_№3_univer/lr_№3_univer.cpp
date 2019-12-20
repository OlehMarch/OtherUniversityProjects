// lr_�3_univer.cpp : Defines the entry point for the console application.
//���������� �������� ��� �����, ������ �� ��������� ����� � ����� (�����)

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
//----------------------------------------------------------------------
int strtok(char *str1, char *str2) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *    ������� ��� �������� ����������� �������������       *
	 *						������� � ������				   *
	 * ����: *str1 - ����� ������ � ������� ���������� �����   *
 	 * *str2 - ����� ������ � ������� ��������� ������� ������ *
	 * �����: count - ���������� ������� � ������              *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int count = 0;
	for (int i=0; i < 255; i++) {
		if (str1[i] == str2[0]) {
			count++;
		}
	}
	return count;
}
//----------------------------------------------------------------------
char *insertOfString(char *str) {
	/* * * * * * * * * * * * * * * * *
	 *    ������� ��� ����� ������   *
	 * ����: *str - ����� ������     *
	 * �����: str - ��������� ������ *
	 * * * * * * * * * * * * * * * * */
	cout<<"������ ��� �����:\n";
	cin.getline(str, 255);
	system("cls");
	return str;
}
//----------------------------------------------------------------------
void individualTask(char *str, int length) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *   ������� ��� ���������� ��������������� �������  *
	 * ����: *str - ����� ������                         *
	 * length - ����� ������                             *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int countOfPluses = 0, countOfMulties = 0, countOfMinuses = 0;
	for (int i=0; i < length; i++) {
		if (str[i] == '+') {
			countOfPluses++;
		}
		if (str[i] == '*') {
			countOfMulties++;
		}
		if (str[i] == '-') {
			countOfMinuses++;
		}
	}
	cout<<"ʳ������ ����� \"+\" - "<<countOfPluses<<endl;
	cout<<"ʳ������ ����� \"*\" - "<<countOfMulties<<endl;
	cout<<"�������� ������� ����� \"+\", \"-\", \"*\" - "
		<<countOfPluses+countOfMulties+countOfMinuses<<endl;
}
//----------------------------------------------------------------------
void individualTaskUsingFunctions(char *str, int length) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *    ������� ��� ���������� ��������������� �������   *
	 *  � �������������� ����������� ������������ �������  *
	 * ����: *str - ����� ������                           *
	 * length - ����� ������                               *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int countOfPluses = 0, countOfMulties = 0, countOfMinuses = 0;
	char plus[1] = {'+'}, multy[1] = {'*'}, minuse[1] = {'-'};
	
	countOfPluses = strtok((char*)str, (char*)plus);
	countOfMulties = strtok((char*)str, (char*)multy);
	countOfMinuses = strtok((char*)str, (char*)minuse);

	cout<<"ʳ������ ����� \"+\" - "<<countOfPluses<<endl;
	cout<<"ʳ������ ����� \"*\" - "<<countOfMulties<<endl;
	cout<<"�������� ������� ����� \"+\", \"-\", \"*\" - "
		<<countOfPluses+countOfMulties+countOfMinuses<<endl;
}
//----------------------------------------------------------------------
void outputOfString(char *str, int length, int choice = 0) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *                ������� ��� ������ ������                *
	 * ����: *str - ����� ������                               *
	 * length - ����� � �������� �������� ���������� �������   *
	 * choice - ����� ������� ������                           *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	float index = 0., j = 1.;
	for (int i=0; i < length; i++) {
		index = i / 50;
		if ((index >= j) && (str[i+1] == ' ')) {
			str[i+1] = '\n';
			j++;
		}
	}
	ofstream fileOut("lr_3_text.txt");
	switch(choice) {
		case 1: 
			cout<<endl<<str<<endl;
			break;
		case 2: 
			fileOut<<str;
			fileOut.close();
			break;
		default:
			cout<<"\n������� ������� ������!\n";
	}
}
//----------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {
	//������������ ������ ���������

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;
	char str[255], *string;
	
	string = insertOfString(str);

	cout<<"������ ������ ������ ������:\n";
	cout<<" 1. � �������\n";
	cout<<" 2. � ����\n";
	cout<<"��� ����: ";
	cin>>choice;

	outputOfString(string, 255, choice);
	cout<<endl<<"���� ���������� ��������� �������������� ��������\n � ������������� ������� �������"<<endl<<endl;
	individualTask(string, 255);
	cout<<endl<<"���� ���������� ��������� �������������� ��������\n � ������������� ������������ ��������� �������"<<endl<<endl;
	individualTaskUsingFunctions(string, 255);

	cout<<endl;
	system("pause");
}