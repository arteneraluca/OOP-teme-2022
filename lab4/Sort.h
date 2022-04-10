#pragma once
class Sort
{
    int* v;
    int nr_elem;
    int low, high;
public:
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

    Sort(int nr_elemente, int min_val, int max_val);
    Sort();
    Sort(int* vector, int nr_elemente);
    Sort(int count, ...);
    Sort(char* sir);
};
