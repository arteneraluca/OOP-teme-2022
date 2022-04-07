#include "vector.h"
#include <stdlib.h>

int main()
{
	Vector<int> v1;
	v1.Push(5);
	v1.Push(10);
	v1.Push(6);
	v1.Push(7);
	v1.Insert(2, 20);
	v1.Sort(Compare);
	int n = v1.Count();
	printf("Vectorul sortat este: ");
	for (int i = 0; i < n; i++)
		cout << v1.Get(i) << " ";
	cout << endl;
	v1.Set(2, 90);
	v1.Delete(1);
	n = v1.Count();
	printf("%d\n", v1.Count());
	for (int i = 0; i < n; i++)
		cout << v1.Get(i) << " ";
	cout << endl;
	printf("Prima aparitie a numarului 90 este: %d\n",v1.FirstIndexOf(90, Equal));
	printf("%d\n",v1.FirstIndexOf(76, Equal));
	printf("Ultimul element din vector: %d", v1.Pop());
}