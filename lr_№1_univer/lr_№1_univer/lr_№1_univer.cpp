// lr_№1_univer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "cmath"
#include <windows.h>

using namespace std;

void _tmain(int argc, _TCHAR* argv[]) {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, c, d, s, t, u; 
	float x, y;
	
/*вибір введеня змінних*/
	int ToI;
	int def;
	cout<<"Оберіть ручний ввід чи ввід за допомогою функції rand() (1/2): ";
	cin>>ToI;
	switch(ToI) {
		case 1: cout<<endl<<"Введіть координати точки А: ";
			cin>>a>>b;
			cout<<"Введіть координати точки B: ";
			cin>>c>>d;
			cout<<"Введіть s, t, u: ";
			cin>>s>>t>>u;
			cout<<endl<<"Точка А має координати("<<a<<"; "<<b<<");"<<endl;
			cout<<"Точка B має координати("<<c<<"; "<<d<<");"<<endl;
			cout<<"Число s = "<<s<<"; t = "<<t<<"; u = "<<u<<";"<<endl<<endl;
			break;
		case 2: a = rand() % 20 + -10;
			b = rand() % 20 + -10;
			c = rand() % 20 + -10;
			d = rand() % 20 + -10;
			s = rand() % 20 + -10;
			t = rand() % 20 + -10;
			u = rand() % 20 + -10;
			cout<<endl<<"Точка А має координати("<<a<<"; "<<b<<");"<<endl;
			cout<<"Точка B має координати("<<c<<"; "<<d<<");"<<endl;
			cout<<"Число s = "<<s<<"; t = "<<t<<"; u = "<<u<<";"<<endl<<endl;
			break;
		default: cout<<endl<<"Введена невірна цифра чи буква"<<endl<<endl; goto stop;
	}
	
/*Х чи У = 0*/
	char NeZ;
	cout<<"Оберіть \"Х\" чи \"Y\" дорівнює нулю (х/у): ";
	cin>>NeZ;
	switch(NeZ) {
		case 'x': x = 0;
			y = -(s*x + u)/t;
			if (((b > -u) && (d < -u)) || ((b < -u) && (d > -u))) {
				cout<<endl<<"Точки А і В належать різним півплощинам"<<endl<<endl;
			}
			else if (((b > -u) && (d > -u)) || ((b < -u) && (d < -u))) {
				cout<<endl<<"Точки А і В не належать різним півплощинам"<<endl<<endl;
			}
			break;
		case 'y': y = 0;
			x = -(t*y + u)/s;
			if (((a > -u) && (c > -u)) || ((a < -u) && (c < -u))) {
				cout<<endl<<"Точки А і В не належать різним півплощинам"<<endl<<endl;
			}
			else if (((a > -u) && (c < -u)) || ((a < -u) && (c > -u))) {
				cout<<endl<<"Точки А і В належать різним півплощинам"<<endl<<endl;
			}
			break;
		default: cout<<endl<<"Введена невірна буква"<<endl<<endl;
	}

	stop: system("pause");

}