//Problema 2
/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	FILE* fp;
	int suma = 0;
	if (fopen_s(&fp, "in.txt", "r") != 0)
		printf("EROARE.Nu am putut deschide fisierul.\n");
	else
	{
		//printf("Am deschis fisierul cu succes.\n");
		char sir[100];
		while (fgets(sir, 100, fp)) //citesc pe rand fiecare nr din fisier
		{
			if (sir[strlen(sir) - 1] == '\n')
				sir[strlen(sir) - 1] = '\0';
			//printf("Am citit din fisier: %s\n", sir);
			int n, p = 1;
			n = strlen(sir);
			while (n > 1) //creez p in functie de nr de cifre ca sa pot contrui fiecare nr
			{
				n--;
				p = p * 10;
			}
			int i, c, nr = 0;
			for (i = 0; i < strlen(sir); i++) //construiesc fiecare nr din fisier
			{
				c = sir[i] - '0';
				nr = nr + c * p;
				p = p / 10;
			}
			//printf("Am obtinut nr: %d\n", nr);
			suma = suma + nr; //aflu suma numerelor din fisier
			p = 1;
			nr = 0;
		}
	}
	fclose(fp);
	printf("Suma numerelor din fisier este: %d\n", suma);
	system("pause");
	return 0;
}
*/

//Problema 3
/*
# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	printf("Introduceti nr de cuvinte din propozitie: ");
	int nrCuv;
	scanf("%d", &nrCuv);
	printf("Introduceti o propozitie: ");
	char cuvant[20], matriceCuv[10][20];
	int counter = 0, total = 0, i, j;
	while (scanf("%s", cuvant)) //citim propozitia
	{
		counter++;
		if (counter >= nrCuv)
			break;
		strcpy(matriceCuv[total], cuvant);
		total++;
	}
	strcpy(matriceCuv[total], cuvant);
	//citesc si ultimul cuv din propozitie (daca l-as citi in while ar intra intr-un loop de citire)
	total++;
	for (i = 0; i < total; i++) //ordonam cuvintele in functie de lungime
	{
		for (j = i + 1; j < total; j++)
			if (strlen(matriceCuv[i]) < strlen(matriceCuv[j]))
				swap(matriceCuv[i], matriceCuv[j]);
	}
	for (i = 0; i < total; i++) //afisam cuvintele
		printf("%s\n", matriceCuv[i]);
	system("pause");
	return 0;
}
*/

//Problema 4

#include <iostream>
using namespace std;

bool isPrime(int n)
{
	for (int tr = 2; tr < n / 2; tr++)
		if ((n % tr) == 0)
			return false;
	return true;
}

int main()
{
	int n;
	std::cout << "Enter a number:";
	std::cin >> n;

	if (isPrime(n))
		std::cout << n << " is prime !";
	else
		std::cout << n << " is NOT prime !";
	return 0;
} 