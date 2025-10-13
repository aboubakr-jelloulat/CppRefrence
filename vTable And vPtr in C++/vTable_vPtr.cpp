

/*
	What is vTable?
		The vTable, or Virtual Table, is a table of function pointers that is created by the compiler to support dynamic polymorphism.
		Whenever a class contains a virtual function, the compiler creates a Vtable for that class.
		Each object of the class is then provided with a hidden pointer to this table, known as Vptr.


*/

/*
	What is vPtr (Virtual Pointer)?
		The virtual pointer or _vptr is a hidden pointer that is added by the compiler as a member of the
		class to point to the VTable of that class. For every object of a class containing virtual functions,
		a vptr is added to point to the vTable of that class
		It's important to note that vptr is created only if a class has or inherits a virtual function.



*/

#include <iostream>
using namespace std;

// base class
class Base
{
public:
	virtual void function1()
	{
		cout << "Base function1()" << endl;
	}
	virtual void function2()
	{
		cout << "Base function2()" << endl;
	}
	virtual void function3()
	{
		cout << "Base function3()" << endl;
	}
};

// class derived from Base
class Derived1 : public Base
{
public:
	// overriding function1()
	void function1()
	{
		cout << "Derived1 function1()" << endl;
	}
	// not overriding function2() and function3()
};

// class derived from Derived1
class Derived2 : public Derived1
{
public:
	// again overriding function2()
	void function2()
	{
		cout << "Derived2 function2()" << endl;
	}
	// not overriding function1() and function3()
};


int main()
{
	// defining base class pointers
	Base *ptr1 = new Base();
	Base *ptr2 = new Derived1();
	Base *ptr3 = new Derived2();

	// calling all functions
	ptr1->function1();
	ptr1->function2();
	ptr1->function3();
	ptr2->function1();
	ptr2->function2();
	ptr2->function3();
	ptr3->function1();
	ptr3->function2();
	ptr3->function3();

	// deleting objects
	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}

/* 	Output : 

	Base function1()
	Base function2()
	Base function3()
	Derived1 function1()
	Base function2()
	Base function3()
	Derived1 function1()
	Derived2 function2()
	Base function3()

*/
