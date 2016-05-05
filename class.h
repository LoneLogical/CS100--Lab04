//class.h
#ifndef CLASS_H
#define CLASS_H

class Base {
	public:
		/* Constructors */
		Base();
		/* Pure Virtual Functions */
		virtual double evaluate() = 0;
};

class Comp1 : public Base {
    private:
        Base* lhs;
        Base* rhs;
    public:
        Comp1(Base* left, Base* right);
        virtual double evaluate () = 0; 
        virtual Base* get_lhs ();
        virtual void set_lhs(Base* left);
        virtual Base* get_rhs ();
        virtual void set_rhs(Base* right);
};

class Comp2 : public Base {
    private:
       Base* child; 
    public:
        Comp2(Base* child);       
        virtual double evaluate() = 0; 
        virtual Base* get_child();
        virtual void set_child(Base* child);
};

class Mult: public Comp1 {
    public:
        virtual double evaluate();
        Mult(Base* left, Base* right);
};

class Add: public Comp1 {
    public:
        virtual double evaluate();
        Add(Base* left, Base* right);
};

class Sub: public Comp1 {
    public:
        virtual double evaluate();
        Sub(Base* left, Base* right);
};

class Div: public Comp1 {
    public:
        virtual double evaluate();
        Div(Base* left, Base* right);
};

class Sqr: public Comp2 {
    public:
        virtual double evaluate();
        Sqr(Base* child);
};

class Op: public Base {
    private: 
        double value;
    public:
        virtual double evaluate();
        Op(double value);
}; 

#endif


