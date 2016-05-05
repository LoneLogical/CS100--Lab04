#include <iostream>

using namespace std;
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

    VectorContainer* container = new VectorContainer();
    container->add_element(A);
    container->add_element(B);
    container->add_element(C);
    container->add_element(D);

    cout << "Container Before Sort" << endl;
    container->print();

    cout << "Container After Sort" << endl;
    container->set_sort_function(new SelectionSort());
    container->sort();
    container->print();
    return 0;
}
