#include <iostream>
using namespace std;

class A
{
public :
	int _a;

};

class B : virtual public A
{
public :
	int _b;

};

class C : virtual public A
{
public :
	int _c;

};

class D : public B , public C
{
public :
	int _d;

};


int main(void)
{
	D obj;

	obj._b;
	obj._c;

	// obj._a; // ambiguous  without virtual

	obj._a; // with virtual 


	return 0;
}
