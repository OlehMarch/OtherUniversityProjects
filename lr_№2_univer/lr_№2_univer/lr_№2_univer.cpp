// lr_№2_univer.cpp : Defines the entry point for the console application.
// Програма призначена для вводу, сортування та виводу масиву

#include "stdafx.h"
#include "iostream"
#include "cmath"
#include <windows.h>
using namespace std;

int insertOfArray(int choice, int index) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *        Функция для ввода элементов массива              *
	 * Ввод: choice - выбор способа ввода                      *
	 * index - номер элемента массива                          *
	 * Вывод: temp - переменная для временного хранения данных *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int temp=0;
	switch(choice) {
		case 1:
			cout<<"Введіть елемент масиву: Array["<<index<<"] = ";
			cin>>temp;
			return temp;
			break;
		case 2:
			temp = rand() % 20 +-10;
			return temp;
			break;
		default: 
			cout<<endl<<"Введено невірний символ"<<endl<<endl;
			return 0;
	}
}
//--------------------------------------------------------------------------------------------------
int sortOfArray(int *Array, int index=0) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *     Функция для сортировки массива методом выбора     *
	 * Ввод: Array - название массива                        *
	 * index - номер с которого начнется сортировка массива  *
	 * Вывод: Array (уже сортированого)                      *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int temp=0, i=0, j=0;
	for (j= index + 0; j < 9; j++) {
		//цыкл для сдвига указателя
		for (i= j + 1; i < 10; i++) {
			//цыкл для перебора элементов
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
	//сортировка пузырьком
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
	 *        Функция для установления точки начала сортировки массива       *
	 * Ввод: Array - название массива                                        *
	 * index - номер с которого начнется сортировка массива                  *
	 * choice - выбор способа сортировки                                     *
	 * Вывод: Array (уже сортированого в зависимости от выбора)              *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int index=0;
	switch(choice) {
		case 1:
			sortOfArray(Array);
			break;
		case 2:
			cout<<"Введіть з якого номеру починати сортування: ";
			cin>>index;
			if ((index < 10) && (index >= 0)) {
				sortOfArray(Array, index);
			}
			else {
				cout<<endl<<"Введено невірний символ"<<endl<<endl;
			}
			break;
		default:
			cout<<endl<<"Введено невірний символ"<<endl<<endl;
	}
}
//--------------------------------------------------------------------------------------------------
void outputOfArray(int *Array) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *               Функция для вывода массива              *
	 * Ввод: Array - название массива                        *
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
	//демонстрация сортировки массива
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int Array[10], choice=0, i=0;

	cout<<"Оберіть спосіб вводу масиву: вручну, або за допомогою функції rand() (1/2): ";
	cin>>choice;

	//ввод массива
	for (i = 0; i < 10; i++) {
		Array[i] = insertOfArray(choice, i);
	}

	cout<<endl<<"Вивід масива до сортування:\n";
	outputOfArray(Array);

	/*cout<<endl<<"Як виконувати сортування?\n";
	cout<<" 1. За змовчуванням (починаючи з першого елемента)\n";
	cout<<" 2. Починаючи з вказаного номера елемента\n";
	cout<<"Ваш вибір: ";
	cin>>choice;
	placeOfSort(choice, Array);*/
	sortOfArray2(Array);

	cout<<endl<<"Вивід масива після сортування:\n";
	outputOfArray(Array);
	cout<<endl;

	system("pause");
}