#include <iostream>
#include <vector>
#include <list>

using namespace std;
#include "container.h"
#include "sort.h"

//Container Base Class
Container::Container() : sort_function(NULL){};
Container::Container(Sort* function) : sort_function(function){};

void Container::set_sort_function(Sort* sort_function)
{
    this->sort_function = sort_function;
    return;
}

//VectorContainer
VectorContainer::VectorContainer() : Container() {};
VectorContainer::VectorContainer(Sort* function) : Container(function) {};
void VectorContainer::add_element(Base* element)
{
    data.push_back(element);
    return;
}
void VectorContainer::print()
{
    for(unsigned int i = 0; i < data.size(); ++i)
    {
        cout << data.at(i)->evaluate() << ' ';
    }
    cout << endl;
    return;
}
void VectorContainer::sort()
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
void VectorContainer::swap(int i, int j)
{
    Base* temp = data.at(i);
    data.at(i) = data.at(j);
    data.at(j) = temp;
    return;
}
Base* VectorContainer::at(int i)
{
    return data.at(i);
}
int VectorContainer::size()
{
    return data.size();
}


//ListContainer
ListContainer::ListContainer() : Container() {};
ListContainer::ListContainer(Sort* function) : Container(function) {};
void ListContainer::add_element(Base* element)
{
    mylist.push_front(element);
    return;
}
void ListContainer::print()
{
    list<Base*>::iterator it;
    for (it = mylist.begin(); it != mylist.end(); ++it)
    {
        cout << (*it)->evaluate() << ' ';
    }
    cout << endl;
    return;
}
void ListContainer::sort()
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
void ListContainer::swap(int i, int j) 
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
    *it2 = temp;
    return;
    }
Base* ListContainer::at(int i)
{
    list<Base*>::iterator it = mylist.begin();
    for(int a = 0; a < i; ++a)
    {
        ++it;
    }
    return *it;
}
int ListContainer::size()
{
    return mylist.size();
}



