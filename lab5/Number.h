#pragma once
class Number
{
private:
	int base;
	char* value;

public:

	Number() = default;
	Number(const char* value, int base); // where base is between 2 and 16

	// add operators and copy / move constructor

	Number(const Number& nr);
	Number(const int nr);

	char operator[](int index);
	Number(Number&& nr);

	Number& operator--();
	Number& operator=(const char* nr1);
	Number& operator--(int val);
	Number& operator +=(Number nr2);

	bool operator<(Number nr2);
	bool operator>(Number nr2);
	bool operator==(Number nr2);
	bool operator<=(Number nr2);
	bool operator>=(Number nr2);

	Number& operator=(const int nr);
	Number& operator=(Number nr1);

	~Number();

	friend Number operator+(Number nr1, Number n2);
	friend Number operator-(Number nr1, Number n2);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

