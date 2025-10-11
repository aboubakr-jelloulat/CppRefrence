/*
			Why You Should NOT Call the Assignment Operator in the Copy Constructor (C++)





	Copy Constructor
		Purpose: Create a new object as a copy of an existing object.

		When Called:
			MyClass b = a;
			MyClass b(a);
			Passing by value to a function.

		Initialization: Initializes the object’s members directly from the source object.

	Assignment Operator
		Purpose: Assign values from one existing object to another already existing object.

		When Called:
			b = a; (after both have already been constructed)

		Assignment: Overwrites the contents of the existing object.


	The Mistake: Calling Assignment in Copy Constructor

		MyClass::MyClass(const MyClass& src) 
		{
			*this = src; // BAD!
			std::cout << "Copy constructor called\n";
		}

		Why is this wrong? 

			Double Work:
				The object is default-initialized, then immediately assigned new values. This is inefficient.

			Undefined Behavior:
				If your object has const or reference members, assignment cannot change them after construction!

			Resource Leaks:
				For classes managing resources (like pointers), this can cause memory leaks or double-free bugs.




	The Right Way: Use Member Initializer List ?



		MyClass::MyClass(const MyClass& src)
		: member1(src.member1),
		member2(src.member2) // ...and so on for all members
		{
			std::cout << "Copy constructor called\n";
		}


		=> This initializes all members directly from the source object, with no unnecessary assignments.




*/

#include <iostream>
using namespace std;


int main(void)
{
	cout << "Why You Should NOT Call the Assignment Operator in the Copy Constructor (C++)" << endl;

}
