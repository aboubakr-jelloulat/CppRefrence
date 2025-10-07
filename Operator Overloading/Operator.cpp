#include <iostream>
#include "Counter.h"
using namespace std;



class Distance
{
	int feet;
	int inches;

public :
	Distance() : feet(0), inches(0) {}

	Distance(int f, int i) : feet(f), inches(i) {}

	void Print()
	{
		cout << "Feets : " << feet << endl;
		cout << "Inches : " << inches << endl;
	}

	Distance operator+(const Distance& d2) const
	{
		int f = this->feet + d2.feet;
		int i = this->inches + d2.inches;
		return Distance(f, i);
	}

	Distance operator-(const Distance& d2) const
	{
		int f = this->feet - d2.feet;
		int i = this->inches - d2.inches;
		return Distance(f, i);
	}



};


int main(void)
{
    // Counter c1(5);
	// cout << "After : " <<  c1.get_count() << endl;
	// ++c1;
	// cout << "Before : " <<  c1.get_count() << endl;

	// cout << endl;

    // Counter c2(10);
	// cout << "After : " <<  c2.get_count() << endl;
	// c2--;
	// cout << "Before : " <<  c2.get_count() << endl;

	Distance d1(10, 5);

	Distance d2(100, 50);

	Distance d3 = d1 + d2;

	cout << "+ operator : " << endl;
		
	d3.Print();


    return 0;
}
