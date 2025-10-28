#include <iostream>
using namespace std;


/*

	How to define an interface in C++:

		* Pure Virtual Functions: An interface is usually a class that only contains pure virtual functions (functions declared but not defined within the class).
		* No Data Members: The interface generally does not have any data members.


*/

/*
	Interface classes should have no data members and only pure virtual functions ?
		* To keep the interface purely as a contract (behavior), not a data holder (state).
		* This makes it easy to separate what an object can do from how it does it.

*/


class IShape
{

public:

	virtual void draw() = 0;  // Pure virtual function
    virtual double area() = 0; //  pure virtual function
    virtual ~IShape() {}
};

/*
	We use 'static const' here because:
		- 'const' makes the value immutable — it cannot be changed after initialization.
		- 'static' means this value is shared by all objects of the class, not duplicated per instance.

	In C++98, only 'static const' integral types (like int, char, etc.) can be initialized
	directly inside the class definition. Non-static members or non-const statics must
	be defined outside the class.

	'inventory_size' must also be a compile-time constant so it can be used
	to declare the fixed-size array '_inventory[inventory_size]'.
 */

class Circle : public IShape 
{
	static const int inventory_size = 4;
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    void draw() override { cout << "Drawing Circle" << endl;}

    double area() override {return 3.14159 * radius * radius;}


};


int main(void)
{

	int *ptr = NULL;

	cout << ptr << endl;
	cout << *ptr << endl;

	return 0;
}