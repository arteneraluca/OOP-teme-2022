#include "Math.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	Math ob;
	printf("add 2 variabile int: %d\n", ob.Add(1, 2));
	printf("add 3 variabile int: %d\n", ob.Add(1, 2, 3));
	printf("add 2 variabile double: %d\n", ob.Add(3.1, 5.1));
	printf("add 3 variabile double: %d\n", ob.Add(7.1, 1.1, 3.1));
	printf("mul 2 variabile int: %d\n", ob.Mul(1, 2));
	printf("mul 3 variabile int: %d\n", ob.Mul(1, 2, 3));
	printf("mul 2 variabile double: %d\n", ob.Mul(3.5, 5.1));
	printf("mul 3 variabile double: %d\n", ob.Mul(7.1, 1.1, 3.1));
	printf("--------------------------------------------------\n");
	printf("add variadic: %d\n", ob.Add(6, 1, 2, 3, 4, 5, 6));
	printf("%s\n", ob.Add("porto", "cala"));

	system("pause");
	return 0;
}