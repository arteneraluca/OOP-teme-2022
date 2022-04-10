#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <cstring>

void Sort::InsertSort(bool ascendent)
{
    int i, key, j;
    for (i = 1; i < this->nr_elem; i++)
    {
        key = this->v[i];
        j = i - 1;
        while (j >= 0 && ((this->v[j] > key && ascendent == true) || (this->v[j] < key && ascendent == false)))
        {
            this->v[j + 1] = this->v[j];
            j = j - 1;
        }
        this->v[j + 1] = key;
    }
}

int partition(int* arr, int low, int high, bool ascendent) 
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot && ascendent == true || arr[j] > pivot && ascendent == false)
        {
            i++;
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    int aux2 = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = aux2;
    return i + 1;
}
void Sort::QuickSort(bool ascendent) 
{
    int pi;
    if (this->low < this->high) //this->low si this->high trebuie setate in constructorul in care dorim sa folosim acest tip de sortare
    {
        int copie1, copie2;
        copie1 = this->low;
        copie2 = this->high;
        pi = partition(this->v, this->low, this->high, ascendent);
        this->high = pi - 1;
        this->low = copie1;
        QuickSort(ascendent);
        this->high = copie2;
        this->low = pi + 1;
        QuickSort(ascendent);
    }
}
void Sort::BubbleSort(bool ascendent)
{
    {
        int i, j;
        for (i = 0; i < this->nr_elem - 1; i++) // Last i elements are already in place            
        {
            for (j = 0; j < this->nr_elem - i - 1; j++)
                if ((this->v[j] > this->v[j + 1] && ascendent == true) || (this->v[j] < this->v[j + 1] && ascendent == false))
                {
                    int aux = this->v[j];
                    this->v[j] = this->v[j + 1];
                    this->v[j + 1] = aux;
                }
        }
    }
}
void Sort::Print()
{
    for (int i = 0; i < this->nr_elem; i++)
        printf("%d ", this->v[i]);
    printf("\n");
}

int  Sort::GetElementsCount()
{
    return this->nr_elem;
}
int  Sort::GetElementFromIndex(int index)
{
    if (index >= 0 && index <= this->nr_elem)
        return this->v[index];
}

Sort::Sort(int nr_elemente, int min_val, int max_val)
{
    time_t t;
    this->nr_elem = nr_elemente;
    this->v = (int*)(malloc(nr_elemente * sizeof(int)));
    srand((unsigned)time(&t));
    for (int i = 0; i < nr_elemente; i++)
        this->v[i] = min_val + rand() % (max_val - min_val + 1);
}

Sort::Sort() : v(new int[6]{ 1,2,3,4,5,6 })
{
    this->nr_elem = 6;
}
Sort::Sort(int* vector, int nr_elemente)
{
    this->low = 0;
    this->high = nr_elemente - 1;
    this->nr_elem = nr_elemente;
    this->v = (int*)(malloc(nr_elemente * sizeof(int)));
    for (int i = 0; i < nr_elemente; i++)
        this->v[i] = vector[i];
}

Sort::Sort(int count, ...)
{
    this->nr_elem = count;
    this->v = (int*)(malloc(count * sizeof(int)));
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++)
        this->v[i] = va_arg(vl, int);
    va_end(vl);
}

Sort::Sort(char* sir)
{
    this->v = (int*)(malloc(0)); //alocam 0 spatiu la inceput pentru a putea realoca intr-o bucla
    char* p;
    char* next_token = NULL;
    p = strtok_s(sir, ",", &next_token);
    int nr = 0;
    while (p != NULL)
    {
        this->v = (int*)(realloc(this->v, (nr + 1) * sizeof(int))); //realocam spatiu pentru vector pe parcurs
        this->v[nr] = atoi(p);
        nr++;
        p = strtok_s(NULL, ",", &next_token);
    }
    this->nr_elem = nr;
}