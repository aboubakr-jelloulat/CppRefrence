#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Base
{
public:
	// Try with and without 'virtual'
	virtual void sayHej()
	{
		cout << "Hej from Base" << endl;
	}
};

class Derived : public Base
{
public:
	void sayHej()
	{
		cout << "Hej from Derived" << endl;
	}
};

int main()
{
	Base b;
	Derived d;

	Base *ptr1 = &b; // pointer to Base object
	Base *ptr2 = &d; // pointer to Derived object

	cout << "ptr1->sayHej(): ";
	ptr1->sayHej(); // Always prints "Hello from Base"

	cout << "ptr2->sayHej(): ";
	ptr2->sayHej(); // Prints "Hello from Derived" ONLY if 'virtual' is used

	return 0;
}

/*

	Without virtual keyword:
		If you call a function through a base class pointer or reference,
		The base class's version of the function will be called, 
		even if the pointer actually points to a derived object.

*/