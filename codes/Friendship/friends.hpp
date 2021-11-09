#ifndef __friends_hpp
#define __friends_hpp

#include <iostream>

class B;
class A {
private:
	int a;

public:
	A() {
        a = 0;
    }
    void showB(B& x) {
        // Since showB() is friend of B, it can
        // access private members of B
       //  std::cout << "B::b = " << x.b;
    }
	friend class B; // Friend Class 
};

class B {
private:
	int b;

public:
    B() {
        b = 0;
    }

	void showA(A& x) {
		// Since B is friend of A, it can access
		// private members of A.
		std::cout << "A::a=" << x.a;
	}

    friend void
    A::showB(B& x); // Friend function 
};

#endif
