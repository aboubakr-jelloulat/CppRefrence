#include <iostream>
using namespace std;

class foo
{
	int _nb;

public :

	foo(int num) : _nb(num)
	{

	}

	foo operator+(const foo &other)
	{
		return foo(this->_nb + other._nb);
	}

	friend ostream& operator<<(ostream& os, const foo& obj);

};

ostream& operator<<(ostream& os, const foo& obj)
{
	os << obj._nb;  // Print the internal _nb value
	return os;
}

int main()
{

	foo a(10), b(2);

	cout << a + b << endl;




}