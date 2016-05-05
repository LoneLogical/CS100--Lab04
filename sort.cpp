//sort.cpp
#include <iostream>

using namespace std;
#include "sort.h"

BubbleSort::BubbleSort() {};

BubbleSort::virtual void sort(Container* container)
{
    for (int i = 0; i < container->size(); ++i)
    {
        for (int j = 0; j < container->size() - i - 1; ++j)
        {
            if ( container->at(j)->evaluate() < container->at(j + 1)->evaluate() )
            {
                container->swap(j, j + 1);
            }
        }
    }
    return;
}


SelectionSort::SelectionSort() {};

SelectionSort::virtual void sort(Container* container)
{
    int min;
    for (int i = 0; i < container->size(); ++i)
    {
        min = i;
        for (int j = 0; j < container->size(); ++j)
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


