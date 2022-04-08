#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList obiect;
	obiect.Init();
	int x;
	while (cin >> x && obiect.Add(x) == true);	//citeste pana cand se umple vectorul
	obiect.Sort();
	obiect.Print();
	system("pause");
	return 0;
}