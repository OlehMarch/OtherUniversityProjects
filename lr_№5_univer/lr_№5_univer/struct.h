#pragma once

#include "targetver.h"

#include "stdafx.h"
#include "iostream"
#include <conio.h>
//----------------------------------------------------------
struct List {
	int value;
	List *next;
};
//----------------------------------------------------------
void Print(List *u);
//----------------------------------------------------------
void printElementByValueFromBeginig(int iValue, List *u);
//----------------------------------------------------------
void printElementBySequenceNumber(int sequenceNumber, List *u);
//----------------------------------------------------------
List* addB(int x, List *u);
//----------------------------------------------------------
List* addE(int x, List *u);
//----------------------------------------------------------
List* addAfter(int iValue, List *u);
//----------------------------------------------------------
List* addBefore(int iValue, List *u);
//----------------------------------------------------------
List* delElementByValue(int iValue, List *u);
//----------------------------------------------------------
List* delElementBySequenceNumber(int sequenceNumber, List *u);
//----------------------------------------------------------
List* delFirstElement(List *u);
//----------------------------------------------------------
List* delLastElement(List *u);