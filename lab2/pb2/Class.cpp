#include "Class.h"
#include <stdio.h>
#include <string.h>

void Class::setName(const char* name)
{
	strcpy_s(this->name, 20, name);
}

char* Class::getName()
{
	return this->name;
}

void Class::setMathGrade(int MathGrade)
{
	this->MathGrade = MathGrade;
}

int Class::getMathGrade()
{
	return this->MathGrade;
}

void Class::setEnglishGrade(int EnglishGrade)
{
	this->EnglishGrade = EnglishGrade;
}

int Class::getEnglishGrade()
{
	return this->EnglishGrade;
}

void Class::setHistoryGrade(int HistoryGrade)
{
	this->HistoryGrade = HistoryGrade;
}

int Class::getHistoryGrade()
{
	return this->HistoryGrade;
}

float Class::CalculateAverageGrade()
{
	return (float)(this->MathGrade + this->EnglishGrade + this->HistoryGrade) / 3;
}

void Class::Print()
{
	printf("Name:%s\nMath Grade:%d\nEnglish Grade: %d\nHistory Grade: %d\n", this->name, this->MathGrade, this->EnglishGrade, this->HistoryGrade);
	printf("Average Grade: %.2f\n", this->CalculateAverageGrade());
}