// lr_�1_univer.cpp : Defines the entry point for the console application.
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
	
/*���� ������� ������*/
	int ToI;
	int def;
	cout<<"������ ������ ��� �� ��� �� ��������� ������� rand() (1/2): ";
	cin>>ToI;
	switch(ToI) {
		case 1: cout<<endl<<"������ ���������� ����� �: ";
			cin>>a>>b;
			cout<<"������ ���������� ����� B: ";
			cin>>c>>d;
			cout<<"������ s, t, u: ";
			cin>>s>>t>>u;
			cout<<endl<<"����� � �� ����������("<<a<<"; "<<b<<");"<<endl;
			cout<<"����� B �� ����������("<<c<<"; "<<d<<");"<<endl;
			cout<<"����� s = "<<s<<"; t = "<<t<<"; u = "<<u<<";"<<endl<<endl;
			break;
		case 2: a = rand() % 20 + -10;
			b = rand() % 20 + -10;
			c = rand() % 20 + -10;
			d = rand() % 20 + -10;
			s = rand() % 20 + -10;
			t = rand() % 20 + -10;
			u = rand() % 20 + -10;
			cout<<endl<<"����� � �� ����������("<<a<<"; "<<b<<");"<<endl;
			cout<<"����� B �� ����������("<<c<<"; "<<d<<");"<<endl;
			cout<<"����� s = "<<s<<"; t = "<<t<<"; u = "<<u<<";"<<endl<<endl;
			break;
		default: cout<<endl<<"������� ������ ����� �� �����"<<endl<<endl; goto stop;
	}
	
/*� �� � = 0*/
	char NeZ;
	cout<<"������ \"�\" �� \"Y\" ������� ���� (�/�): ";
	cin>>NeZ;
	switch(NeZ) {
		case 'x': x = 0;
			y = -(s*x + u)/t;
			if (((b > -u) && (d < -u)) || ((b < -u) && (d > -u))) {
				cout<<endl<<"����� � � � �������� ����� ����������"<<endl<<endl;
			}
			else if (((b > -u) && (d > -u)) || ((b < -u) && (d < -u))) {
				cout<<endl<<"����� � � � �� �������� ����� ����������"<<endl<<endl;
			}
			break;
		case 'y': y = 0;
			x = -(t*y + u)/s;
			if (((a > -u) && (c > -u)) || ((a < -u) && (c < -u))) {
				cout<<endl<<"����� � � � �� �������� ����� ����������"<<endl<<endl;
			}
			else if (((a > -u) && (c < -u)) || ((a < -u) && (c > -u))) {
				cout<<endl<<"����� � � � �������� ����� ����������"<<endl<<endl;
			}
			break;
		default: cout<<endl<<"������� ������ �����"<<endl<<endl;
	}

	stop: system("pause");

}