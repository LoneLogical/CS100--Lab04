#include <iostream>
#include <vector>
#include <list>

using namespace std;
#include "container.h"


//Container Base Class
Container::Container() : sort_function(NULL){};
Container::Container(Sort* function) : sort_function(function){};

Container::void set_sort_function(Sort* sort_function)
{
    this->sort_function = sort_function;
    return;
}
Container::virtual void add_element(Base* element) = 0;
Container::virtual void print() = 0;
Container::virtual void sort() = 0;
Container::virtual void swap(int i, int j) = 0;
Container::virtual Base* at(int i) = 0;
Container::virtual int size() = 0;

//VectorContainer
VectorContainer::
VectorContainer::VectorContainer(Sort* function) : sort_function(function) {};
VectorContainer::virtual void add_element(Base* element)
{
    data.push_back(element);
    return;
}
VectorContainer::virtual void print()
{
    for(int i = 0; i < data.size(); ++i)
    {
        cout << data.at(i)->evaluate() << ' ';
    }
    cout << endl;
    return;
}
VectorContainer::virtual void sort()
{
    if (sort_function != NULL)
    {
        sort_function->sort(this);
    }
    else {
        cout << "Exception: no sorting algorithm set" << endl;
    }
    return;
}
VectorContainer::virtual void swap(int i, int j)
{
    Base* temp = data.at(i);
    data.at(i) = data.at(j);
    data.at(j) = temp;
    return;
}
VectorContainer::virtual Base* at(int i)
{
    return data.at(i);
}
VectorContainer::virtual int size()
{
    return data.size();
}


//ListContainer
ListContainer::ListContainer() : sort_function(NULL) {};
ListContainer::ListContainer(Sort* function) : sort_function(function) {};
ListContainer::virtual void add_element(Base* element)
{
    mylist.push_front(element);
    return;
}
ListContainer::virtual void print()
{
    list<Base*>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it)
    {
        cout << it->evaluate() << ' ';
    }
    cout << endl;
    return;
}
ListContainer::virtual void sort()
{
    if (sort_function != NULL)
    {
        sort_function->sort(this);
    }
    else {
        cout << "Exception: no sorting algorithm set" << endl;
    }
    return;
}
ListContainer::virtual void swap(int i, int j) 
{
    list<Base*>::iterator it1 = mylist.begin();
    list<Base*>::iterator it2 = mylist.begin();
    for(int a = 0; a < i; ++a)
    {
        ++it1;
    }
    for(int b = 0; b < j; ++b)
    {
    ++it2;
    }
    Base* temp = *it1;
    *it1 = *it2;
    *it2 = *it1;
    return;
    }
ListContainer::virtual Base* at(int i)
{
    list<Base*>::iterator it = mylist.begin();
    for(int a = 0; a < i; ++a)
    {
        ++it;
    }
    return *it;
}
ListContainer::virtual int size()
{
    return mylist.size();
}



