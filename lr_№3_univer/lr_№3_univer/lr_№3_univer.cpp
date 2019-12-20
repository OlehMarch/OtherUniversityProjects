// lr_№3_univer.cpp : Defines the entry point for the console application.
//Призначена програма для вводу, виводу та підрахунку знаків у рядку (тексті)

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
	 *    Функция для подсчета колличества определенного       *
	 *						символа в строке				   *
	 * Ввод: *str1 - адрес строки в которой происходит поиск   *
 	 * *str2 - адрес строки в которой находится искомый символ *
	 * Вывод: count - количество сиволов в строке              *
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
	 *    Функция для ввода строки   *
	 * Ввод: *str - адрес строки     *
	 * Вывод: str - введенная строка *
	 * * * * * * * * * * * * * * * * */
	cout<<"Введіть Ваш рядок:\n";
	cin.getline(str, 255);
	system("cls");
	return str;
}
//----------------------------------------------------------------------
void individualTask(char *str, int length) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *   Функция для выполнения индивидуального задания  *
	 * Ввод: *str - адрес строки                         *
	 * length - длина строки                             *
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
	cout<<"Кількість знаків \"+\" - "<<countOfPluses<<endl;
	cout<<"Кількість знаків \"*\" - "<<countOfMulties<<endl;
	cout<<"Загальна кількість знаків \"+\", \"-\", \"*\" - "
		<<countOfPluses+countOfMulties+countOfMinuses<<endl;
}
//----------------------------------------------------------------------
void individualTaskUsingFunctions(char *str, int length) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *    Функция для выполнения индивидуального задания   *
	 *  с использованием стандартных библиотечных функций  *
	 * Ввод: *str - адрес строки                           *
	 * length - длина строки                               *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	int countOfPluses = 0, countOfMulties = 0, countOfMinuses = 0;
	char plus[1] = {'+'}, multy[1] = {'*'}, minuse[1] = {'-'};
	
	countOfPluses = strtok((char*)str, (char*)plus);
	countOfMulties = strtok((char*)str, (char*)multy);
	countOfMinuses = strtok((char*)str, (char*)minuse);

	cout<<"Кількість знаків \"+\" - "<<countOfPluses<<endl;
	cout<<"Кількість знаків \"*\" - "<<countOfMulties<<endl;
	cout<<"Загальна кількість знаків \"+\", \"-\", \"*\" - "
		<<countOfPluses+countOfMulties+countOfMinuses<<endl;
}
//----------------------------------------------------------------------
void outputOfString(char *str, int length, int choice = 0) {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *                Функция для вывода строки                *
	 * Ввод: *str - адрес строки                               *
	 * length - номер с которого начнется сортировка массива   *
	 * choice - выбор способа вывода                           *
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
			cout<<"\nВведено невірний символ!\n";
	}
}
//----------------------------------------------------------------------
void _tmain(int argc, _TCHAR* argv[]) {
	//демонстрация работы программы

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;
	char str[255], *string;
	
	string = insertOfString(str);

	cout<<"Оберіть варіант виводу тексту:\n";
	cout<<" 1. У консоль\n";
	cout<<" 2. У файл\n";
	cout<<"Ваш вибір: ";
	cin>>choice;

	outputOfString(string, 255, choice);
	cout<<endl<<"Вивід результатів виконання індивідуального завдання\n з використанням власних функцій"<<endl<<endl;
	individualTask(string, 255);
	cout<<endl<<"Вивід результатів виконання індивідуального завдання\n з використанням модифікованої бібліотечної функції"<<endl<<endl;
	individualTaskUsingFunctions(string, 255);

	cout<<endl;
	system("pause");
}