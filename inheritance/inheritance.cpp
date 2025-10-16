#include <iostream>
using namespace std;

class clsFoo
{
	void priv() {cout << "private" << endl;}

protected:
	void prot() {cout << "proteced" << endl;}


public:
	void pub() {cout << "public" << endl;}

	virtual void Hej()
	{
		cout << " Hej "  << endl;
	}

};

class clsA : public clsFoo
{
public:
	void test()
	{
		pub();	// OK
		prot(); // OK
		// priv(); // ERROR:
	}

	void Hej()
	{
		cout << " hello world "  << endl;
	}

};



class clsB : protected clsFoo
{
public:
	void test2()
	{
		pub();	// OK (derived class can call base's public)
		prot(); // OK
	}
};



int main()
{
	clsA a;  //  : public clsFoo

	//a.pub();

	// // a.prot(); // ERROR 

	// a.Hej();

	// clsB b; // protected clsFoo

	// //b.pub();  // ERROR: pub is protected in class B
	// //b.prot();



	// removing virtual will not change the output???
		// virtual only matters when you use base class pointers or references to call overridden functions in derived classes.

	return 0;
}