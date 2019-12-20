#pragma once

void RunTests(int argc, char** argv);

void MainFunction_TestNoArgs(int argc, char** argv);
void MainFunction_Test_NoFile(int argc, char** argv);
void MainFunction_Test_WrongDateFormat(int argc, char** argv);
void MainFunction_Test_WrongDateWords(int argc, char** argv);
void MainFunction_Test_BelowDiapason(int argc, char** argv);
void MainFunction_Test_OverDiapason(int argc, char** argv);
void MainFunction_Test_DateExists(int argc, char** argv);
void MainFunction_Test_DateAvarage(int argc, char** argv);