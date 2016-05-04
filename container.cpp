#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Container {
    protected:
        Sort* sort_function;

    public:
        Container() : sort_function(NULL){};
        Container(Sort* function) : sort_function(function){};

        void set_sort_function(Sort* sort_function);

        virtual void add_element(Base* element) = 0;
        virtual void print() = 0;
        virtual void sort() = 0;
        virtual void swap(int i, int j) = 0;
        virtual Base* at(int i) = 0;
        virtual int size() = 0;
};

class VectorContainer: public Container {
    private:
        vector <Base*> data; 
    public:
        VectorContainer(Sort* function) : sort_function(function) {};
        virtual void add_element(Base* element)
        {
            data.push_back(element);
            return;
        }
        virtual void print()
        {
            for(int i = 0; i < data.size(); ++i)
            {
                cout << data.at(i)->evaluate() << ' ';
            }
            cout << endl;
            return;
        }
        virtual void sort()
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
        virtual void swap(int i, int j)
        {
            Base* temp = data.at(i);
            data.at(i) = data.at(j);
            data.at(j) = temp;
            return;
        }
        virtual Base* at(int i)
        {
            return data.at(i);
        }
        virtual int size()
        {
            return data.size();
        }

};

class ListContainer: public Container {
    private:
        list<Base*> mylist;
    public:
        ListContainer() : sort_function(NULL) {};
        ListContainer(Sort* function) : sort_function(function) {};
        virtual void add_element(Base* element)
        {
            mylist.push_front(element);
            return;
        }
        virtual void print()
        {
            list<Base*>::iterator it;
            for (it = mylist.begin(); it != mylist.end(); ++it)
            {
                cout << it->evaluate() << ' ';
            }
            cout << endl;

            return;
        }
        virtual void sort()
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
        virtual void swap(int i, int j) 
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
        virtual Base* at(int i)
        {
            list<Base*>::iterator it = mylist.begin();
            for(int a = 0; a < i; ++a)
            {
                ++it;
            }
            return *it;
        }
        virtual int size()
        {
            return mylist.size();
        }





};

class Sort {
    public:
        Sort() {};

        virtual void sort(Container* container) = 0;

};

class BubbleSort : public Sort {
    public:
        BubbleSort() {};

        virtual void sort(Container* container)
        {
            for (int i = 0; i < container->size(); ++i)
            {
                for (int j = 0; j < container->size() - i - 1; ++j)
                {
                    if ( container->at(j)->evaluate() < 
                            container->at(j + 1)->evaluate() )
                    {
                        container->swap(j, j + 1);
                    }
                }
            }
            return;
        }
};

class SelectionSort : public Sort {
    public:
        SelectionSort() {};

        virtual void sort(Container* container)
        {
            int min;

            for (int i = 0; i < container->size(); ++i)
            {
                min = i;
                for (int j = 0; j < container->size(); ++j)
                {
                   if ( container->at(j)->evaluate() < 
                           container->at(min)->evaluate() )
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

};

