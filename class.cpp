#include <iostream>
#include <list>
#include <vector>
using namespace std;

Base::Base() {};
Base::virtual double evaluate() = 0;

Comp1::virtual double evaluate () = 0; 
Comp1::virtual Base* get_lhs () {
    return lhs;
}
Comp1:: virtual void set_lhs(Base* left) {
    lhs = left;
    return;
}
Comp1::virtual Base* get_rhs () {
    return rhs;
}
Comp1::virtual void set_rhs(Base* right) {
    rhs = right;
    return;
}

Comp2::virtual double evaluate() = 0; 
Comp2::virtual Base* get_child() {
    return child;
}
Comp2::virtual void set_child(Base* child) {
    this->child = child;
    return;
}

Mult::virtual double evaluate() {
    return (( get_lhs()->evaluate() ) * ( get_rhs()->evaluate() ));
} 
Mult::Mult(Base* left, Base* right) {
    set_lhs(left);
    set_rhs(right);
    return;
}
        
Add::virtual double evaluate() {
    return (( get_lhs()->evaluate() ) + ( get_rhs()->evaluate() ));
} 
Add::Add(Base* left, Base* right) {
    set_lhs(left);
    set_rhs(right);
    return;
}

Sub::virtual double evaluate() {
    return (( get_lhs()->evaluate() ) - ( get_rhs()->evaluate() ));
}  
Sub::Sub(Base* left, Base* right) {
    set_lhs(left);
    set_rhs(right);
    return;
}

Div::virtual double evaluate() {
    return (( get_lhs()->evaluate() ) / ( get_rhs()->evaluate() ));
}
Div::Div(Base* left, Base* right) {
    set_lhs(left);
    set_rhs(right);
    return;
}
Sgr::virtual double evaluate() {
    double root = get_child()->evaluate();
    return root * root;
}
Sqr::Sqr(Base* child) {
    set_child(child);
    return;
}

Op::virtual double evaluate() {
    return this->value;
}
Op::Op(double value) {
    this->value = value;
}



