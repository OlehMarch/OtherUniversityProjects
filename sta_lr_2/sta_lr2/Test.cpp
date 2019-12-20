#include "stdafx.h"

void RunTests(int argc, char** argv)
{
	MainFunction_Test_DateAvarage(argc, argv);
	MainFunction_Test_BelowDiapason(argc, argv);
	MainFunction_Test_OverDiapason(argc, argv);
	MainFunction_Test_DateExists(argc, argv);
	MainFunction_Test_WrongDateFormat(argc, argv);
	MainFunction_Test_WrongDateWords(argc, argv);
	argv[1] = "1";
	MainFunction_Test_NoFile(argc, argv);
	argc = 1;
	MainFunction_TestNoArgs(argc, argv);
}

void MainFunction_TestNoArgs(int argc, char** argv)
{
	assert(MainFunction(argc, argv) == -1);
}

void MainFunction_Test_NoFile(int argc, char** argv)
{
	assert(MainFunction(argc, argv) == -2);
}

void MainFunction_Test_WrongDateFormat(int argc, char** argv)
{
	assert(MainFunction(argc, argv, "1/1/2017") == -3);
}

void MainFunction_Test_WrongDateWords(int argc, char** argv)
{
	assert(MainFunction(argc, argv, "as/as/asdf") == -3);
}

void MainFunction_Test_BelowDiapason(int argc, char** argv)
{
	assert(MainFunction(argc, argv, "01/01/2017") == -4);
}

void MainFunction_Test_OverDiapason(int argc, char** argv)
{
	assert(MainFunction(argc, argv, "01/01/2018") == -4);
}

void MainFunction_Test_DateExists(int argc, char** argv)
{
	assert(MainFunction(argc, argv, "03/05/2017") == 0);
}

void MainFunction_Test_DateAvarage(int argc, char** argv)
{
	assert(MainFunction(argc, argv, "08/04/2017") == 0);
}