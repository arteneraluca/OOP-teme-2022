#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	Sort ob1(10, 10, 100);
	printf("vectorul neordonat: ");
	ob1.Print();

	ob1.BubbleSort(); //ascendent false default
	printf("vectorul dupa sortare: ");
	ob1.Print();
	printf("-----------------------------------------\n");

	Sort ob2;
	printf("vectorul neordonat: ");
	ob2.Print();

	ob2.InsertSort(); //ascendent false default
	printf("vectorul dupa sortare: ");
	ob2.Print();
	printf("-----------------------------------------\n");

	int v[] = { 1,3,7,6,2 };
	Sort ob3(v, 5);
	printf("vectorul neordonat: ");
	ob3.Print();

	ob3.QuickSort(); //ascendent false default
	printf("vectorul dupa sortare: ");
	ob3.Print();
	printf("-----------------------------------------\n");

	Sort ob4(6, 1, 2, 3, 4, 6, 5);
	printf("vectorul neordonat: ");
	ob4.Print();

	ob4.InsertSort(); //ascendent false default
	printf("vectorul dupa sortare: ");
	ob4.Print();
	printf("-----------------------------------------\n");

	char sir[] = "13,12,14,10,21";
	Sort ob5(sir);
	printf("vectorul neordonat: ");
	ob5.Print();

	ob5.BubbleSort(1); //setam ascendentul true
	printf("vectorul dupa sortare: ");
	ob5.Print();
	printf("-----------------------------------------\n");

	system("pause");
	return 0;
}