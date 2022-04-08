#include "Class.h"
#include "GlobalFunctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	Class ob1, ob2;
	ob1.setName("Ana");
	ob1.setMathGrade(10);
	ob1.setEnglishGrade(9);
	ob1.setHistoryGrade(7);
	ob1.Print();

	printf("\n");

	ob2.setName("Rex");
	ob2.setMathGrade(6);
	ob2.setEnglishGrade(9);
	ob2.setHistoryGrade(10);
	ob2.Print();

	printf("\n");

	printf("%d\n", cmp_name(&ob1, &ob2));
	printf("%d\n", cmp_mathGrade(&ob1, &ob2));
	printf("%d\n", cmp_englishGrade(&ob1, &ob2));
	printf("%d\n", cmp_historyGrade(&ob1, &ob2));
	printf("%d\n", cmp_averageGrade(&ob1, &ob2));

	system("pause");
	return 0;
}