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
		cout << "Printer constructed\n";
	}
	~Printer()
	{
		delete[] buffer;
		cout << "\nPrinter destroyed and buffer deallocated\n";
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


/*
	| Situation                                                | Compiler knows real type?   | Virtual needed? | Result                                   |
| ------------------------------------------------------------ | --------------------------- | --------------- | ---------------------------------------- |
| Object created normally (stack variable)                     | ✅ Yes (`FragTrap s1;`)      | ❌ No           | Both destructors run automatically       |
| Deleted through base pointer (`Device* dev = new Printer()`) | ❌ No (static type = Device) | ✅ Yes          | Only base destructor runs unless virtual |




*/