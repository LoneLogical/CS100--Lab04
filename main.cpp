#include <iostream>

using namespace std;
#include "class.h"
#include "sort.h"
#include "container.h"


int main() {
    Op* op7 = new Op(7);
    Op* op4 = new Op(4);
    Op* op3 = new Op(3);
    Op* op2 = new Op(2);
    Mult* A = new Mult(op7, op4);
    Add* B = new Add(op3, A);
    Sub* C = new Sub(B, op2);
    Sqr* D = new Sqr(C);

    VectorContainer* container1 = new VectorContainer();
    container1->add_element(A);
    container1->add_element(B);
    container1->add_element(C);
    container1->add_element(D);

    ListContainer* container2 = new ListContainer();
    container2->add_element(A);
    container2->add_element(B);
    container2->add_element(C);
    container2->add_element(D);


    cout << "Container1 Before Sort" << endl;
    container1->print();

    cout << "Container1 After Sort" << endl;
    container1->set_sort_function(new BubbleSort());
    container1->sort();
    container1->print();

    cout << "Container2 Before Sort" << endl;
    container2->print();

    cout << "Container2 After Sort" << endl;
    container2->set_sort_function(new BubbleSort());
    container2->sort();
    container2->print();



    return 0;
}
