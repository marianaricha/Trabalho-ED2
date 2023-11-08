#ifndef SORT_H__
#define SORT_H__

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

#include "metrics.h"
 
template <typename T>
void troca(T* a, T *b)
{

    T* tmp = a;
    a      = b;
    b      = tmp;
}



template<typename T>
void merge(T* array, int start, int end, bool (*compare)(T&, T&), PerformanceMetrics* p)
{
    vector<T> aux(end - start + 1);

    int middle = (start + end) / 2;
    int k   = 0;
    int i  = start;
    int j = middle + 1;

    while (i <= middle && j < end)
    {
        p->n_comp++;
        if (compare(array[i], array[j]))
        {
            aux[k] = array[i];
            p->n_mov++;
            i++;
        }
        else
        {
            aux[k] = array[j];
            p->n_mov++;
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        aux[k] = array[i];
        p->n_mov++;
        i++;
        k++;
    }

    while (j < end)
    {
        aux[k] = array[j];
        p->n_mov++;
        j++;
        k++;
    }

    for (int i = start; i < end; i++)
    {
        array[i] = aux[i - start];
        p->n_mov++;
    }
}

template <typename T>
void mergesort_internal(T* array, int start, int end, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    if( start < end )
    {
        int middle = (start + end) / 2;
        mergesort_internal(array, start, middle, compare, p);
        mergesort_internal(array, middle + 1, end, compare, p);
        merge(array, start, end, compare, p);
    }

}

template <typename T>
void merge_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p, "merge_sort");
    auto t1 = Clock::now();
    mergesort_internal(array, 0, size, compare, &p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    PerformanceMetricsPrint(&p);
}



template <typename T>
int particionamento(T* array, int low, int high, bool (*compare)(T&, T&),PerformanceMetrics *p){
	
	T pivo = array[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++){
        p->n_comp++;
        if(compare(array[j], pivo))
        {
            p->n_mov+=3;
            i++;
			troca(&array[i],&array[j]);
		}
	}
    p->n_mov+=3;
	troca(&array[i+1],&array[high]);
	return i+1;
}

template <typename T>
void quicksort_internal(T* array, int low, int high, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
	if(low < high)
    {
		int middle = particionamento(array,low,high,compare,p);
		quicksort_internal(array,low,middle-1,compare,p);
		quicksort_internal(array,middle+1,high,compare,p);
	}
}

template <typename T>
void quick_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p, "quick_sort");
    auto t1 = Clock::now();
    quicksort_internal<T>(array, 0, size-1, compare, &p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    PerformanceMetricsPrint(&p);
}



template <typename T>
void combsort_internal(T* array, int size, int gap, bool change, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    while (gap != 1 || change == true)
    {
        gap = (gap * 10) / 13;
        if(gap < 1){
            gap = 1;
        }

        change = false;
        for (int i = 0; i < size - gap; i++)
        {
            p->n_comp++;
            if (compare(array[i], array[i + gap]))
            {
                troca(&array[i], &array[i + gap]);
                p->n_mov += 3;
                change = true;
            }
        }
    }
}

template <typename T>
void comb_sort(T* array, int size, bool (*compare)(T&, T&))
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p, "comb_sort");
    auto t1 = Clock::now();
    combsort_internal(array,size,size,true,compare,&p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    PerformanceMetricsPrint(&p);
}

#endif