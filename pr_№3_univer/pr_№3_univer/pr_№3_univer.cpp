// pr_№3_univer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include <windows.h>
using namespace std;
//--------------------------------------------------------------------
bool checkError(int value) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * *
	 *   Функция для проверки вводимых длин массивов   *
	 * Ввод: value - длина строки или столбца массива  *
	 *      отправляемых для проверки                  *
	 * * * * * * * * * * * * * * * * * * * * * * * * * */
	if ((value <= 2) || (value > 5)) {
		return false;
	}
	else {
		return true;
	}		
}
//--------------------------------------------------------------------
int insertOfArray(int countOfStrings, int countOfColumns, int **Array) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * *
	 *             Функция для вода массива            *
	 * Ввод: countOfStrings - количество строк         *
	 * countOfColumns - количество колонок             *
	 * **Array - указатель на двумерный массив         *
	 * Вывод: **Array - указатель на двумерный массив  *
	 * * * * * * * * * * * * * * * * * * * * * * * * * */
	int *temp = NULL, dec = 4;
	temp = new int[countOfStrings];

	if ((countOfStrings % 2 == 0) && (countOfColumns % 2 == 0)) {
		dec++;
	}

	//цикл для создания случайных индексов для нулевых элементов
	for (int i = 0; i < countOfStrings; i++) {
		temp[i] = rand() % countOfColumns;
		for (int j = i - 1; j >= 0; j--) {
			if (temp[i] == temp[j]) {
				if (abs(countOfColumns - dec) < countOfColumns){
					temp[i] -= abs(countOfColumns - dec);
					j = 0;
				}
				else {
					temp[i] += 1;
					j = 0;
				}
			}
		}
	} //конец цикла

	//цикл для присваивания ненулевым элементам массива сучайных значений
	for (int i = 0; i < countOfStrings; i++) {
		for (int j = 0; j < countOfColumns; j++) {
			Array[i][temp[i]] = 0;
			if (Array[i][j] != 0) {
				Array[i][j] = rand() % 10 + 1;
			}
		}
	} //конец цикла

	return **Array;
}
//--------------------------------------------------------------------
void outputOfArray(int countOfStrings, int countOfColumns, int **Array) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * *
	 *            Функция для Вывода массива           *
	 * Ввод: countOfStrings - количество строк         *
	 * countOfColumns - количество колонок             *
	 * **Array - указатель на двумерный массив         *
	 * * * * * * * * * * * * * * * * * * * * * * * * * */
	int i, j;
	for (i = 0; i < countOfStrings; i++) {
		for (j = 0; j < countOfColumns; j++) {
			cout.width(4);
			cout<<Array[i][j];
		}
		Sleep(700);
		cout<<endl<<endl;
	}
}
//--------------------------------------------------------------------
void sortOfArray(int countOfStrings, int countOfColumns, int **Array) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * *
	 *         Функция для сортировки массива          *
	 * Ввод: countOfStrings - количество строк         *
	 * countOfColumns - количество колонок             *
	 * **Array - указатель на двумерный массив         *
	 * * * * * * * * * * * * * * * * * * * * * * * * * */
	//сортировка пузырьком
	for (int i = 0, n = 0, m = 0; i < countOfStrings; i++) {
		for (int j = 0; j < countOfColumns; j++) {
			if (Array[i][j] == 0) {
				Array[i][j] = Array[n][m];
				m++;
			}
		}
		n = m;
	} //конец цикла

	//цикл присваивания нолей главной диагоноали
	for (int i = 0, j = 0; i < countOfStrings; i++, j++) {
		Array[i][j] = 0;
	} //конец цикла
}
//--------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {

	int countOfStrings = 0, countOfColumns = 0; //количество строк, количество столбцов 
	int **Array = NULL;

	cout<<"The maximum size of the array must be within the framework\n from 3 to 5 inclusively\n\n";
	cout<<"Press any key to continue...";
	getch();
	system("cls");

	//проверка массива на корректность вводимых данных
	cout<<"Insert count of strings of array - ";
	cin>>countOfStrings;
	if (!checkError(countOfStrings)) {
		cout<<"\nIncorrect count of elements of array!\n\n";
		goto finish;
	}
	cout<<"Insert count of columns of array - ";
	cin>>countOfColumns;
	if (!checkError(countOfColumns)) {
		cout<<"\nIncorrect count of elements of array!\n\n";
		goto finish;
	}
	cout<<endl;
	//конец проверки

	//создание двумерного динамического массива
	Array = new int*[countOfStrings];
	for (int i = 0; i < countOfStrings; i++) {
		Array[i] = new int[countOfColumns];
	}
	//конец создания массива

	insertOfArray(countOfStrings, countOfColumns, Array);
	cout<<"Outpup of basic two-dimensional array:\n\n";
	outputOfArray(countOfStrings, countOfColumns, Array);

	sortOfArray(countOfStrings, countOfColumns, Array);

	cout<<"Outpup of modified two-dimensional array:\n\n";
	outputOfArray(countOfStrings, countOfColumns, Array);

	finish: 
	cout<<"Press any key to continue...";
	getch();
}//конец main'а