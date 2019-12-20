// lr_�2_univer.cpp : Defines the entry point for the console application.
// �������� ���������� ��� �����, ���������� �� ������ ������

#include "stdafx.h"
#include "iostream"
#include "cmath"
#include <windows.h>
using namespace std;

int insertOfArray(int choice, int index) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *        ������� ��� ����� ��������� �������              *
	 * ����: choice - ����� ������� �����                      *
	 * index - ����� �������� �������                          *
	 * �����: temp - ���������� ��� ���������� �������� ������ *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int temp=0;
	switch(choice) {
		case 1:
			cout<<"������ ������� ������: Array["<<index<<"] = ";
			cin>>temp;
			return temp;
			break;
		case 2:
			temp = rand() % 20 +-10;
			return temp;
			break;
		default: 
			cout<<endl<<"������� ������� ������"<<endl<<endl;
			return 0;
	}
}
//--------------------------------------------------------------------------------------------------
int sortOfArray(int *Array, int index=0) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *     ������� ��� ���������� ������� ������� ������     *
	 * ����: Array - �������� �������                        *
	 * index - ����� � �������� �������� ���������� �������  *
	 * �����: Array (��� �������������)                      *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int temp=0, i=0, j=0;
	for (j= index + 0; j < 9; j++) {
		//���� ��� ������ ���������
		for (i= j + 1; i < 10; i++) {
			//���� ��� �������� ���������
			if (Array[j] > Array[i]) {
				temp = Array[j];
				Array[j] = Array[i];
				Array[i] = temp;
			}
		}
	}
	return *Array;
}
//--------------------------------------------------------------------------------------------------
int sortOfArray2(int *Array) {
	//���������� ���������
	int temp=0, i=0, j=0;
	for (j= 0; j < 6; j++) {
		for (i= 0; i < 10 - j; i++) {
			if (Array[i] < Array[i+1]) {
				temp = Array[i];
				Array[i] = Array[i+1];
				Array[i+1] = temp;
			}
		}
		for (i= 0; i < 10; i++) {
			cout<<Array[i];
		}
		cout<<endl;
	}
	return *Array;
}
//--------------------------------------------------------------------------------------------------
void placeOfSort(int choice, int *Array) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *        ������� ��� ������������ ����� ������ ���������� �������       *
	 * ����: Array - �������� �������                                        *
	 * index - ����� � �������� �������� ���������� �������                  *
	 * choice - ����� ������� ����������                                     *
	 * �����: Array (��� ������������� � ����������� �� ������)              *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int index=0;
	switch(choice) {
		case 1:
			sortOfArray(Array);
			break;
		case 2:
			cout<<"������ � ����� ������ �������� ����������: ";
			cin>>index;
			if ((index < 10) && (index >= 0)) {
				sortOfArray(Array, index);
			}
			else {
				cout<<endl<<"������� ������� ������"<<endl<<endl;
			}
			break;
		default:
			cout<<endl<<"������� ������� ������"<<endl<<endl;
	}
}
//--------------------------------------------------------------------------------------------------
void outputOfArray(int *Array) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *               ������� ��� ������ �������              *
	 * ����: Array - �������� �������                        *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	cout<<" _______________________________________________\n";
	cout<<"|       | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |\n";
	cout<<"|-------|---|---|---|---|---|---|---|---|---|---|\n";
	cout<<"| Array |";
	for (int i=0; i < 10; i++) {
		cout.width(3);cout<<Array[i]<<"|";
	}
	cout<<"\n";
	cout<<"|_______|___|___|___|___|___|___|___|___|___|___|\n";
}
//--------------------------------------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {
	//������������ ���������� �������
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int Array[10], choice=0, i=0;

	cout<<"������ ����� ����� ������: ������, ��� �� ��������� ������� rand() (1/2): ";
	cin>>choice;

	//���� �������
	for (i = 0; i < 10; i++) {
		Array[i] = insertOfArray(choice, i);
	}

	cout<<endl<<"���� ������ �� ����������:\n";
	outputOfArray(Array);

	/*cout<<endl<<"�� ���������� ����������?\n";
	cout<<" 1. �� ������������ (��������� � ������� ��������)\n";
	cout<<" 2. ��������� � ��������� ������ ��������\n";
	cout<<"��� ����: ";
	cin>>choice;
	placeOfSort(choice, Array);*/
	sortOfArray2(Array);

	cout<<endl<<"���� ������ ���� ����������:\n";
	outputOfArray(Array);
	cout<<endl;

	system("pause");
}