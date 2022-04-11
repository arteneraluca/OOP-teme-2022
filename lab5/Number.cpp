#include "Number.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void conversie_int_char(int nr_nou, char* value)
{
	int lungime_sir = 0;
	while (nr_nou)
	{
		value[lungime_sir] = nr_nou % 10 + '0';
		nr_nou /= 10;
		lungime_sir++;
	}
	value[lungime_sir] = '\0';
	_strrev(value);
}

void Number::SwitchBase(int newBase)
{
	int nr_nou = 0, p = 1;
	//conversia in baza 10
	for (int i = strlen(this->value) - 1; i >= 0; i--)
	{
		if (value[i] >= 'A' && value[i] <= 'F')
			nr_nou = p * (value[i] - 55) + nr_nou;
		else
			nr_nou = p * (value[i] - '0') + nr_nou;
		p = p * this->base;
	}
	//conversia in newBase
	char* nr = new char[100];
	int i = 0;
	while (nr_nou >= 1)
	{
		if (nr_nou % newBase >= 10)
			nr[i] = (char)(nr_nou % newBase + 55);
		else
			nr[i] = nr_nou % newBase + '0';
		nr_nou /= newBase;
		i++;
	}
	nr[i] = '\0';
	_strrev(nr);
	this->value = (char*)realloc(value, strlen(nr) + 1);
	if (this->value != nullptr)
	{
		memset(this->value, 0, strlen(nr) + 1);
		memcpy(this->value, nr, strlen(nr) + 1);
	}
	this->base = newBase;
}

Number::Number(const char* value, int base)
{
	this->base = base;
	while (this->base < 2 || this->base >16)
	{
		printf("Dati o baza intre 2 si 16: ");
		scanf_s("%d", &this->base);
	}
	this->value = (char*)malloc(strlen(value) + 1);
	if (this->value != nullptr)
	{
		memset(this->value, 0, strlen(value) + 1);
		strcpy_s(this->value, strlen(value) + 1, value);
	}
	this->base = base;
}

Number::Number(const int nr)
{
	char* tempNumber = (char*)malloc(100);
	if (tempNumber != nullptr)
		_itoa_s(nr, tempNumber, strlen(tempNumber), 10);
	this->base = 10;
	value = new char[strlen(tempNumber) + 1];
	if (tempNumber != nullptr)
		memcpy(value, tempNumber, strlen(tempNumber) + 1);
}

Number::Number(const Number& nr)
{

	this->base = nr.base;
	this->value = (char*)malloc(strlen(nr.value) + 1);
	if (this->value != nullptr)
	{
		memset(this->value, 0, strlen(nr.value) + 1);
		memcpy(this->value, nr.value, strlen(nr.value) + 1);
	}
}

Number::Number(Number&& nr)
{
	this->base = nr.base;
	this->value = (char*)malloc(strlen(nr.value) + 1);
	if (this->value != nullptr)
		strcpy_s(this->value, strlen(nr.value) + 1, nr.value);
	nr.value = nullptr;
	nr.base = 0;
}

Number::~Number()
{
	free(this->value);
	this->base = 0;
}

Number operator+(Number nr1, Number nr2)
{
	int greaterBase = nr1.GetBase() > nr2.GetBase() ? nr1.GetBase() : nr2.GetBase();
	int nr1OldBase = nr1.GetBase();
	int nr2OldBase = nr2.GetBase();
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	char* tempNumber = (char*)(malloc(100));
	conversie_int_char(atoi(nr1.value) + atoi(nr2.value), tempNumber);
	nr1.SwitchBase(nr1OldBase);
	nr2.SwitchBase(nr2OldBase);
	Number nr3(tempNumber, 10);
	nr3.SwitchBase(greaterBase);
	return nr3;
}

Number operator-(Number nr1, Number nr2)
{
	int greaterBase = nr1.GetBase() < nr2.GetBase() ? nr2.GetBase() : nr1.GetBase();
	int oldBase1 = nr1.GetBase();
	int oldBase2 = nr2.GetBase();
	nr1.SwitchBase(10);
	nr2.SwitchBase(10);
	char* tempNumber = (char*)malloc(100);
	if (nr1 < nr2)
		conversie_int_char(atoi(nr2.value) - atoi(nr1.value), tempNumber);
	else
		conversie_int_char(atoi(nr1.value) - atoi(nr2.value), tempNumber);
	nr1.SwitchBase(oldBase1);
	nr2.SwitchBase(oldBase2);
	Number nr3(tempNumber, 10);
	nr3.SwitchBase(greaterBase);
	return nr3;
}

bool Number::operator<(Number nr1)
{
	char* end = nullptr;
	int decimal_nr1 = strtol(nr1.value, &end, nr1.base);
	int decimal_nr2 = strtol(this->value, &end, this->base);
	if (decimal_nr2 < decimal_nr1)
		return true;
	return false;
}

bool Number::operator>(Number nr1)
{
	char* end = nullptr;
	int decimal_nr1 = strtol(nr1.value, &end, nr1.base);
	int decimal_nr2 = strtol(this->value, &end, this->base);
	if (decimal_nr2 > decimal_nr1)
		return true;
	return false;
}

bool Number::operator<=(Number nr1)
{
	char* end = nullptr;
	int decimal_nr1 = strtol(nr1.value, &end, nr1.base);
	int decimal_nr2 = strtol(this->value, &end, this->base);
	if (decimal_nr2 <= decimal_nr1)
		return true;
	return false;
}

bool Number::operator>=(Number nr1)
{
	char* end = nullptr;
	int decimal_nr1 = strtol(nr1.value, &end, nr1.base);
	int decimal_nr2 = strtol(this->value, &end, this->base);
	if (decimal_nr2 >= decimal_nr1)
		return true;
	return false;
}

bool Number::operator==(Number nr1)
{
	char* end = nullptr;
	int decimal_nr1 = strtol(nr1.value, &end, nr1.base);
	int decimal_nr2 = strtol(this->value, &end, this->base);
	if (decimal_nr2 == decimal_nr1)
		return true;
	return false;
}

Number& Number::operator=(Number nr)
{
	this->base = nr.base;
	this->value = (char*)malloc(strlen(nr.value) + 1);
	if (this->value != nullptr)
	{
		memset(this->value, 0, strlen(nr.value) + 1);
		strcpy_s(this->value, strlen(nr.value) + 1, nr.value);
	}
	nr.value = nullptr;
	return *this;
}

Number& Number::operator=(const int nr)
{
	char* tempNumber = (char*)malloc(100);
	if (tempNumber != nullptr)
	{
		if (this->base != 0)
			_itoa_s(nr, tempNumber, strlen(tempNumber), this->base);
		else
		{
			_itoa_s(nr, tempNumber, strlen(tempNumber), 10);
			this->base = 10;
		}
		value = new char[strlen(tempNumber) + 1];
		memcpy(value, tempNumber, strlen(tempNumber) + 1);
		return *this;
	}
}

Number& Number::operator=(const char* nr)
{
	this->value = (char*)realloc(this->value, strlen(nr) + 1);
	if (this->value != nullptr)
		memcpy(this->value, nr, strlen(nr) + 1);
	if (this->base != 10)
		this->SwitchBase(this->base);
	return *this;
}

Number& Number::operator+=(Number nr2)
{
	Number nr3(this->value, this->base);
	nr3 = nr3 + nr2;
	this->value = (char*)realloc(this->value, strlen(nr3.value) + 1);
	if (this->value != nullptr)
		memcpy(this->value, nr3.value, strlen(nr3.value) + 1);
	this->base = nr3.base;
	return *this;
}

char Number::operator[](int index)
{
	return this->value[index];
}

Number& Number::operator--()
{
	strcpy_s(this->value, strlen(this->value), this->value + 1);
	return (*this);
}

Number& Number::operator--(int val)
{
	this->value[strlen(this->value) - 1] = '\0';
	return (*this);
}

int Number::GetDigitsCount()
{
	return strlen(this->value);
}

int Number::GetBase()
{
	return this->base;
}

void Number::Print()
{
	printf("The value is %s and is written in base %d\n", this->value, this->base);
}