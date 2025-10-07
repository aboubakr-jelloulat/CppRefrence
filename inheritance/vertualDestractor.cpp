#include <iostream>
using namespace std;

class Device
{
public:
	Device() 
	{ 
		cout << "Device constructed\n"; 
	}
	// Try removing 'virtual' and see what happens!
	virtual ~Device() 
	{ 
		cout << "Device destroyed\n"; 
	}
};

class Printer : public Device
{
	char *buffer;

public:
	Printer()
	{
		buffer = new char[100];
		cout << "Printer constructed and buffer allocated\n";
	}
	~Printer()
	{
		delete[] buffer;
		cout << "Printer destroyed and buffer deallocated\n";
	}
};

// c++ -std=c++17 vertualDestractor.cpp -o dev && ./dev

void foo()
{
	system("leaks -q dev");
}

int main()
{
	atexit(foo);

	Device *dev = new Printer();
	delete dev;
	return 0;
}
