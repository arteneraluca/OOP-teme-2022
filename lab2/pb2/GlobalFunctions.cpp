#include "GlobalFunctions.h"
#include <string.h>

int cmp_name(Class* ob1, Class* ob2)
{
	return strcmp(ob1->getName(), ob2->getName());
}

int cmp_mathGrade(Class* ob1, Class* ob2)
{
	if (ob1->getMathGrade() < ob2->getMathGrade())
		return -1;
	else if (ob1->getMathGrade() > ob2->getMathGrade())
		return 1;
	return 0;
}

int cmp_englishGrade(Class* ob1, Class* ob2)
{
	if (ob1->getEnglishGrade() < ob2->getEnglishGrade())
		return -1;
	else if (ob1->getEnglishGrade() > ob2->getEnglishGrade())
		return 1;
	return 0;
}

int cmp_historyGrade(Class* ob1, Class* ob2)
{
	if (ob1->getHistoryGrade() < ob2->getHistoryGrade())
		return -1;
	else if (ob1->getHistoryGrade() > ob2->getHistoryGrade())
		return 1;
	return 0;
}

int cmp_averageGrade(Class* ob1, Class* ob2)
{
	if (ob1->CalculateAverageGrade() < ob2->CalculateAverageGrade())
		return -1;
	else if (ob1->CalculateAverageGrade() > ob2->CalculateAverageGrade())
		return 1;
	return 0;
}