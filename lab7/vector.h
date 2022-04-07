#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
bool Compare(T elem1, T elem2) //functia de callback pt sort
{
	return (elem1 > elem2);
}

template <class T>
bool Equal(T elem1, T elem2)
{
	return elem1 == elem2;
}

template <class T>
void Switch(T& elem1, T& elem2)
{
	T aux;
	aux = elem1;
	elem1 = elem2;
	elem2 = aux;
}

template <class T>
class Vector
{
private:
	T *v;
	int nr_elem,nr_max_elem;
public:
	static bool Equal(T elem1, T elem2);
	static bool Compare(T elem1, T elem2);
	 Vector() {
		 nr_elem = 0;
		 nr_max_elem = 3;
		 v = (T*)malloc(nr_max_elem * sizeof(T));
	 }
	 void Resize() {
		 nr_max_elem *= 2;
		 v = (T*)realloc(v,nr_max_elem*sizeof(T));
	 }
	 void Push(const T& element) {
		 if (nr_elem + 1 == nr_max_elem) {
			 printf("am facut resize\n"); Resize();
		 }
		 v[nr_elem++] = element;
		 cout << element << endl;
	 }

	 T& Pop(){ 
		 return v[--nr_elem]; 
	 }

	 void Delete(int index) {
		 if (index < nr_elem && index >= 0)
		 {
			 for (int i = index; i < nr_elem; i++)
				 v[i] = v[i + 1];
			 nr_elem--;
		 }
		 else printf("Nu se poate face delete!\n");
	 }

	 void Insert(int index,T element) {
		 if (index >= nr_elem || index < 0)
			 printf("nu se poate insera\n");
		 else {
			if (nr_elem +1 >= nr_max_elem)Resize();
			for (int i = nr_elem + 1; i > index; i--)
			{
				v[i] = v[i - 1];}
			 v[index] = element;
			 nr_elem++;
		 }
	 }
	 int Count() {
		 return nr_elem;
	 }

	 void Sort(bool(*Compare)(T,T)) {
		 bool verif = 0;
		 if (Compare != nullptr)
			 verif = 1;
		 for (int i = 0; i < nr_elem - 1; i++)
			 for (int j = i + 1; j < nr_elem; j++)
				 if (verif == 1)
				 {
					 if (Compare(v[i], v[j]) == 1)
						 Switch(v[i], v[j]);
				 }
				 else if (v[i] > v[j])
					 Switch(v[i], v[j]);
	 }

	int FirstIndexOf(T element, bool(*Equal)(T, T)) {
		 bool verif = 0;
		 if (Equal != nullptr)
			 verif = 1;
		 for (int i = 0; i < nr_elem; i++)
			 if (verif == 1)
			 {
				 if (Equal(element, v[i]) == 1)
					 return i;
			 }
			 else
				 if (v[i] == element)
					 return i;
		 printf("Elementul nu a fost gasit! ");
		 return -1;
	 }
	void Set(int index, T elem)
	{
		if (index >= 1 && index <= nr_elem)
			v[index] = elem;
	}
	const T& Get(int index) {
		return v[index];
	}
};