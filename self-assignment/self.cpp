#include <iostream>
using namespace std;



class Array
{
	int	*arr;
	int _size;

public :
	Array(int size) : _size(size)
	{
		arr = new int[size];

		for (int i = 0; i < size; i++)
            arr[i] = i * 10;
	}

	~Array()
	{
		delete[] arr;
		
	}

	Array& operator=(Array& other)
	{

		delete[]	arr;  	// deleting our own array
		
		this->_size = other._size;

		arr = new int[_size];

		for (int i = 0; i < this->_size; i++)
			arr[i] = other.arr[i];


		return *this;
	}


	void Display()
	{
		for (int i = 0; i < this->_size; i++)
			cout << arr[i] << " ";

		cout << endl;
	}


};


/*
	output : 
	➜  self-assignment g++ -std=c++17 -fsanitize=address  self.cpp && ./a.out 
	-1094795586 -1094795586 -1094795586 -1094795586 -1094795586 -1094795586 -1094795586 -1094795586 -1094795586 -1094795586 

*/




class clsArray
{
	int *data;
	int _size;

public :

	clsArray(int size) : _size(size) 
	{
		this->data = new int[size];

		for (int i = 0; i < this->_size; i++)
			this->data[i] = 10 * i;

	}

	~clsArray() {delete[] this->data ;}

	clsArray& operator=(clsArray &other)
	{
		if (this != &other)
		{

		delete[] this->data;

		this->_size = other._size;

		this->data = new int[this->_size];

		for (int i = 0; i < this->_size; i++)
			this->data[i] = other.data[i];

		}

		return *this;
	}


	void print()
	{
		for (int i = 0; i < this->_size; i++)
			cout << data[i] << " ";
		cout << endl;
	}


};

/*
	output : 

	self-assignment g++ -std=c++17 -fsanitize=address  self.cpp && ./a.out
	0 10 20 30 40 50 60 70 80 90 


*/





int main()
{
	// Without self-assignment protection 

	// Array	arr(10);

	// arr = arr;

	// arr.Display(); 



	// Using self-assignment protection 

	clsArray a(10);

	a = a;

	a.print();



	return 0;
}


