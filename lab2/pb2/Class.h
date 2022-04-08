#pragma once
class Class
{
	char name[20];
	int MathGrade;
	int EnglishGrade;
	int HistoryGrade;

public:
	void setName(const char* name);
	char* getName();
	void setMathGrade(int MathGrade);
	int getMathGrade();
	void setEnglishGrade(int EnglishGrade);
	int getEnglishGrade();
	void setHistoryGrade(int HistoryGrade);
	int getHistoryGrade();
	float CalculateAverageGrade();
	void Print();

};

