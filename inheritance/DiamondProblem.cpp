#include <iostream>
using namespace std;


/*
		Understanding Virtual Inheritance and the Diamond Problem in C++



		. What is the Diamond Problem?
			The Diamond Problem occurs when a class inherits from two classes that both inherit from a common base class. 
			This creates a diamond-shaped inheritance diagram :


					 A
					/ \
					B   C
					\ /
					D


		The Issue :
			Suppose A has some member variable. When D inherits from both B and C, without virtual inheritance, D ends up with two copies of A's members—one via B and one via C. 
			This leads to:

			Ambiguity (compiler can't tell which A you mean)
			Wasted memory
			Potential bugs (modifying one "A" doesn't affect the other)






*/





class A
{
public :
	int value;
    A() : value(0) {}

};

class B : virtual public A
{
public :


};

class C : virtual  public A
{
public :


};

class D : public B , public C
{
public :


	// void setValue(int v) 
	// {
    //     // Ambiguous! Which A's value?
    //     // value = v; // ERROR: ambiguous

    //     B::value = v; // OK
    //     C::value = v + 1; // OK 
    // }


	// With Virtual Inheritance

	void setValue(int v) 
	{
        value = v; // No ambiguity
    }


};



int main(void)
{


	// Diamond Problem Example (Without Virtual Inheritance)

	// {

	// 	D obj;

	// 	obj.setValue(1337);
		
	// 	std::cout << "B::value: " << obj.B::value << std::endl; // 1337
    // 	std::cout << "C::value: " << obj.C::value << std::endl; // 1338

    // 	// std::cout << obj.value << std::endl; // ERROR: ambiguous
	// }


	// using virtual 

	{
		D obj;

		obj.setValue(42);
		std::cout << "A::value: " << obj.value << std::endl; // 42
		std::cout << "B::value: " << obj.B::value << std::endl; // 42
		std::cout << "C::value: " << obj.C::value << std::endl; // 42
	}


	return 0;
}


/*

	What happens?
		D contains two copies of A: one via B, one via C.

		You must specify which path you mean: obj.B::value or obj.C::value.
		If you call a method from A, the compiler won’t know which A to use.


	3. The Solution: Virtual Inheritance 

		C++ provides virtual inheritance to solve this ambiguity.

		When you declare the base class as virtual, 
			C++ ensures that only one shared instance of the base class is present, 
			no matter how many times it is inherited in the chain.



		How to use:

			class B : virtual public A { };
			class C : virtual public A { };

			Now, when D inherits from B and C:

			There is only one copy of A in D.



	Summary

		Without Virtual Inheritance	      	With Virtual Inheritance

		Two copies of A in D	         	Only one copy of A in D
		Ambiguity	       					No ambiguity
		More memory usage					Efficient
		Potential bugs						Safer


*/
