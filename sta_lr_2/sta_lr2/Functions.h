#pragma once

using namespace std;

struct DollarRate
{
public:
	DollarRate();

	char* date;
	float* rate;
};

bool Equals(char* val1, char* val2);
int Compare(char* val1, char* val2);
bool IsNumeric(char* value);
void ReplaceDot(char* buff);
int FileProcessing(ifstream *file, char* date, bool isRecursion = false, float* res = 0);
char* GetAnotherDate(char* date, bool isPrevDateToTake);
int MainFunction(int argc, char** argv, char* dateForTest = NULL);