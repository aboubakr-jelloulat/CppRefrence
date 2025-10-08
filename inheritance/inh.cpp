#include <iostream>
using namespace std;


class clsA
{
public :

	clsA(const string& str)
	{
		cout << "cls A constractor" << " str = " << str << endl;
	}

};

class clsB : public clsA
{
public :

	clsB(string str) : clsA(str)
	{
		cout << "cls B constractor" << endl;
	}

};


int main()
{
	clsB b("hej");


}
