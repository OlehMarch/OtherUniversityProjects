#include "stdafx.h"
#include "struct.h"
//----------------------------------------------------------
void Print(List *u) {
	//функция вывода элементов списка
	List *t = u;
	printf("List:\n");
	while(t) {
		printf("%d\n", t->value);
		t = t->next;
	}
}
//----------------------------------------------------------
void printElementByValueFromBeginig(int iValue, List *u) {
	//функция которая выводит элемент с указаным значением начиная с начала
	int i = 1;
	while(u->value != iValue) {
		i++;
		u = u->next;
	}
	if (u->value == iValue) {
		printf("Sequence number of the element with inserted value is %d", i);
	}
}
//----------------------------------------------------------
void printElementBySequenceNumber(int sequenceNumber, List *u) {
	//функция которая выводит элемент с указаным порядковым номером
	int i = 1;
	while(i != sequenceNumber) {
		i++;
		u = u->next;
	}
	if (i == sequenceNumber) {
		printf("Value of the element with inserted sequence number is %d", u->value);
	}
}
//----------------------------------------------------------
List* addB(int x, List *u) {
	//функция которая добавляет в начало списка новые элементы
	List *t = new List;
	t->next = u;
	t->value = x;
	return t;
}
//----------------------------------------------------------
List* addE(int x, List *u) {
	//функция которая добавляет в конец списка новые элементы
	List *p, *t;
	p = new List;
	p->value = x;
	p->next = NULL;
	if (u == NULL) {
		return p;
	}
	t = u;
	while(t->next) {
		t = t->next;
	}
	t->next = p;
	return u;
}
//----------------------------------------------------------
List* addAfter(int iValue, List *u) {
	//функция которая добавляет элемент после указаного значения
	List *p;
	p = new List;
	while(u->value != iValue) {
		u = u->next;
	}
	if (u->value == iValue) {
		printf("Insert value which will be added: ");
		scanf("%d", &p->value);
		p->next = u->next;
		u->next = p;
	}
	return u;
}
//----------------------------------------------------------
List* addBefore(int iValue, List *u) {
	//функция которая добавляет элемент до указаного значения
	List *p;
	p = new List;
	while(u->next->value != iValue) {
		u = u->next;
	}
	if (u->next->value == iValue) {
		printf("Insert value which will be added: ");
		scanf("%d", &p->value);
		p->next = u->next;
		u->next = p;
	}
	return u;
}
//----------------------------------------------------------
List* delElementByValue(int iValue, List *u) {
	//функция которая удаляет элемент с указаным значением
	while(u->next->value != iValue) {
		u = u->next;
	}
	if (u->next->value == iValue) {
		u->next = u->next->next;
	}
	return u;
}
//----------------------------------------------------------
List* delElementBySequenceNumber(int sequenceNumber, List *u) {
	//функция которая удаляет элемент с указаным порядковым номером
	int i = 1;
	while(i != sequenceNumber-1) {
		i++;
		u = u->next;
	}
	if (i == sequenceNumber-1) {
		u->next = u->next->next;
	}
	return u;
}
//----------------------------------------------------------
List* delFirstElement(List *u) {
	//функция которая удаляет первый элемент
	u = u->next;
	return u;
}
//----------------------------------------------------------
List* delLastElement(List *u) {
	//функция которая удаляет последний элемент
	List *p = u;
	while(p->next->next) {
		p = p->next;
	}
	p->next = NULL;
	return u;
}