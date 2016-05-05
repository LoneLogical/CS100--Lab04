//sort.cpp
#include <iostream>

using namespace std;
#include "sort.h"
#include "container.h"

BubbleSort::BubbleSort() {};

void BubbleSort::sort(Container* container)
{
    int flag = 1;
    int size = container->size();
    for (int i = 1; (i <= size) && flag; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if ( container->at(j)->evaluate() > container->at(j + 1)->evaluate() )
            {
                container->swap(j, j + 1);
                flag = 1;
            }
        }
    }
    return;
}


SelectionSort::SelectionSort() {};

void SelectionSort::sort(Container* container)
{
    int min;
    int size = container->size();
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if ( container->at(j)->evaluate() < container->at(min)->evaluate() )
            {
                min = j;
            }
        }
        if (min != i)
        {
            container->swap(i, min);
        }
    }
    return;
}


