#include "stdafx.h"
#define ITOA_BIAS 48

float* res1;
float* res2;

DollarRate::DollarRate()
{
	date = new char[10];
	rate = new float();
}

bool Equals(char* val1, char* val2)
{
	for (int i = 0; i < strlen(val1); i++)
	{
		if (val1[i] != val2[i])
		{
			return false;
		}
	}
	return true;
}

int Compare(char* val1, char* val2)
{
	if (Equals(val1, val2)) return 0;

	char* tmp = new char[4];
	tmp[0] = val1[0];	tmp[1] = val1[1];
	int day1 = atoi(tmp);
	tmp[0] = val2[0];	tmp[1] = val2[1];
	int day2 = atoi(tmp);
	tmp[0] = val1[3];	tmp[1] = val1[4];
	int month1 = atoi(tmp);
	tmp[0] = val2[3];	tmp[1] = val2[4];
	int month2 = atoi(tmp);
	tmp[0] = val1[6];	tmp[1] = val1[7]; 	tmp[2] = val1[8];	tmp[3] = val1[9];
	int year1 = atoi(tmp);
	tmp[0] = val2[6];	tmp[1] = val2[7];	tmp[2] = val2[8];	tmp[3] = val2[9];
	int year2 = atoi(tmp);

	if (year1 > year2)
	{
		return 1;
	}
	else if (year1 < year2)
	{
		return -1;
	}
	else
	{
		if (month1 > month2)
		{
			return 1;
		}
		else if (month1 < month2)
		{
			return -1;
		}
		else
		{
			if (day1 > day2)
			{
				return 1;
			}
			else if (day1 < day2)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}

	return 0;
}

bool IsNumeric(char* value)
{
	char* tmp = new char[4];
	tmp[0] = value[0];
	tmp[1] = value[1];
	int val = atoi(tmp);
	
	if (val == 0) return false;

	tmp[0] = value[3];
	tmp[1] = value[4];
	val = atoi(tmp);

	if (val == 0) return false;

	tmp[0] = value[6];
	tmp[1] = value[7];
	tmp[2] = value[8];
	tmp[3] = value[9];
	val = atoi(tmp);

	if (val == 0) return false;

	return true;
}

void ReplaceDot(char* buff)
{
	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == '.')
		{
			buff[i] = ',';
		}
	}
}

int FileProcessing(ifstream *file, char* date, bool isRecursion, float* res)
{
	DollarRate* rate = new DollarRate();
	char* buff = new char[20];
	bool isMin = false;
	bool isMax = false;

	while (!file->eof())
	{
		file->getline(buff, 20);
		ReplaceDot(buff);
		sscanf(buff, "%s %f", rate->date, rate->rate);

		if (Compare(date, rate->date) == 0)
		{
			if (!isRecursion)
			{
				cout << *rate->rate << endl;
			}
			else
			{
				*res = *rate->rate;
				return 0;
			}

			isMin = false;
			isMax = false;
			break;
		}
		else if (Compare(date, rate->date) == 1)
		{
			isMax = true;
		}
		else
		{
			isMin = true;
		}
	}

	if ((isMin && !isMax) || (!isMin && isMax))
	{
		return -1;
	}
	else if (isMin && isMax)
	{
		char* newDate = new char[10];
		
		if (*res1 == 0)
		{
			newDate = GetAnotherDate(date, true);
			file->seekg(0, ios::beg);
			FileProcessing(file, newDate, true, res1);
		}

		if (*res2 == 0)
		{
			newDate = GetAnotherDate(date, false);
			file->seekg(0, ios::beg);
			FileProcessing(file, newDate, true, res2);

			if (*res1 != -1 && *res2 != -1)
			{
				cout << (*res1 + *res2) / 2 << endl;
				*res1 = -1;
				*res2 = -1;
			}
			
		}
	}

	return 0;
}

char* GetAnotherDate(char* date, bool isPrevDateToTake)
{
	char* newDate = new char[10];
	char* tmp = new char[2];
	tmp[0] = date[0];
	tmp[1] = date[1];
	strncpy(newDate, date, 10);
	int day = atoi(tmp);
	int bias = (isPrevDateToTake) ? -1 : 1;
	day += bias;

	if (day >= 10)
	{
		newDate[0] = day / 10 + ITOA_BIAS;
		newDate[1] = day % 10 + ITOA_BIAS;
	}
	else if (day >= 1 && day <= 9)
	{
		newDate[0] = '0';
		newDate[1] = day + ITOA_BIAS;
	}
	else if (day == 0 || day == 32)
	{
		if (day == 0)
		{
			newDate[0] = '3';
			newDate[1] = '1';
		}
		else
		{
			newDate[0] = '0';
			newDate[1] = '1';
		}
		
		tmp[0] = newDate[3];
		tmp[1] = newDate[4];
		int month = atoi(tmp);
		month += bias;

		if (month >= 10 && month <= 12)
		{
			newDate[3] = month / 10 + ITOA_BIAS;
			newDate[4] = month % 10 + ITOA_BIAS;
		}
		else if (month >= 1 && month <= 9)
		{
			newDate[3] = '0';
			newDate[4] = month + ITOA_BIAS;
		}
		else if (month == 0 || month == 13)
		{
			if (month == 0)
			{
				newDate[3] = '1';
				newDate[4] = '2';
			}
			else
			{
				newDate[3] = '0';
				newDate[4] = '1';
			}

			tmp[0] = newDate[6];
			tmp[1] = newDate[7];
			tmp[2] = newDate[8];
			tmp[3] = newDate[9];
			int year = atoi(tmp);
			year += bias;
		}
	}

	newDate[10] = '\0';
	return newDate;
}

int MainFunction(int argc, char** argv, char* dateForTest)
{
	setlocale(LC_ALL, "rus");

	res1 = new float();
	res2 = new float();

	if (argc < 2)
	{
		cout << "¬ведите параметры:(путь к файлу)" << endl;
		return -1;
	}
	else if (argc == 2)
	{
		ifstream* file = new ifstream(argv[1], ios_base::in);
		char* date = new char[10];

		if (!file->is_open())
		{
			cout << "‘айл не открыт или не найден" << endl;
			return -2;
		}

		if (dateForTest == NULL)
		{
			cout << "¬ведите дату (день/мес€ц/год): ";
			cin >> date;
		}
		else
		{
			date = dateForTest;
		}

		if (strlen(date) < 10 || !IsNumeric(date))
		{
			cout << "¬ведена неверна€ дата" << endl;
			return -3;
		}

		if (FileProcessing(file, date) == -1)
		{
			cout << "¬веденна€ дата находитс€ вне диапазона допустимых значений!" << endl;
			return -4;
		}
	}
	
	if (dateForTest == NULL)
	{
		cout << endl;
		system("pause");
	}
	return 0;
}