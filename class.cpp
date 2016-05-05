#include <iostream>
using namespace std;

#include "class.h"

Base::Base() {};

Comp1::Comp1(Base* left, Base* right) {
    this->lhs = left;
    this->rhs = right;
}
Base* Comp1::get_lhs () {
    return lhs;
}
void Comp1::set_lhs(Base* left) {
    lhs = left;
    return;
}
Base* Comp1::get_rhs() {
    return rhs;
}
void Comp1::set_rhs(Base* right) {
    rhs = right;
    return;
}

Comp2::Comp2(Base* child) {
    this->child = child;
}
Base* Comp2::get_child() {
    return child;
}
void Comp2::set_child(Base* child) {
    this->child = child;
    return;
}

Mult::Mult(Base* left, Base* right) : Comp1(left, right) {};
double Mult::evaluate() {
    return (( get_lhs()->evaluate() ) * ( get_rhs()->evaluate() ));
} 

Add::Add(Base* left, Base* right) : Comp1(left, right) {}       
double Add::evaluate() {
    return (( get_lhs()->evaluate() ) + ( get_rhs()->evaluate() ));
} 

Sub::Sub(Base* left, Base* right) : Comp1(left, right) {}
double Sub::evaluate() {
    return (( get_lhs()->evaluate() ) - ( get_rhs()->evaluate() ));
}  

Div::Div(Base* left, Base* right) : Comp1(left, right) {}
double Div::evaluate() {
    return (( get_lhs()->evaluate() ) / ( get_rhs()->evaluate() ));
}

Sqr::Sqr(Base* child) : Comp2(child) {}
double Sqr::evaluate() {
    double root = get_child()->evaluate();
    return root * root;
}

Op::Op(double value) {
    this->value = value;
}
double Op::evaluate() {
    return this->value;
}




