#include <iostream>
#include <cstring>

namespace shallow 
{

	class Student
	{
	private:
		char* name;

	public:
		Student(const char* n)
		{
			std::cout << "[Constructor] " << n << std::endl;
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}

		// Default copy constructor (shallow copy)
		// Compiler just copies the pointer, not the data
		// Student(const Student& other) = default;

		void show() const
		{
			std::cout << "Name: " << name << std::endl;
		}

		~Student()
		{
			std::cout << "[Destructor] " << name << std::endl;
		}
	};
	void	Run()
	{


		Student s1("Alice");
		std::cout << "Copying s1 into s2 (shallow copy)" << std::endl;
		Student s2 = s1; // Shallow copy: both share the same pointer!

		std::cout << "\nDisplaying both objects:" << std::endl;
		s1.show();
		s2.show();

	}

	/*
		UNDER THE HOOD (Shallow Copy):
		- s1.name and s2.name point to the SAME memory.
		- Destructor of s1 deletes the memory.
		- Destructor of s2 tries to delete the same memory → DOUBLE DELETE → undefined behavior / crash.

		ADVANTAGES:
		- Fast: only pointer copied.
		- Useful for read-only shared memory or immutable objects.

		DISADVANTAGES:
		- Risk of double-free or dangling pointer.
		- Objects are not independent.
	*/



} 







namespace deep 
{

	class Student
	{
	private:
		char* name;

	public:

		Student(const char* n)
		{
			std::cout << "[Constructor] " << n << std::endl;
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}

		// Deep copy 
		Student(const Student& other)
		{
			std::cout << "[Deep Copy Constructor] " << other.name << std::endl;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}

		void show() const
		{
			std::cout << "Name: " << name << std::endl;
		}

		~Student()
		{
			std::cout << "[Destructor] " << name << std::endl;
			delete[] name;
		}
	};


	/*
		UNDER THE HOOD (Deep Copy):
		- s1.name and s2.name point to DIFFERENT memory blocks.
		- Each destructor deletes its own memory → safe.

		ADVANTAGES:
		- Safe destruction (no double free).

		DISADVANTAGES:
		- Slightly slower: allocate and copy memory.
	*/

	void	Run()
	{
		Student s1("Bob");
		std::cout << "Copying s1 into s2 (deep copy)" << std::endl;
		Student s2 = s1; // Deep copy: new memory allocated

		std::cout << "\nDisplaying both objects:" << std::endl;
		s1.show();
		s2.show();
	}

}


int main(void)
{
	std::cout << "\n\tShallow Copy : \n\n";
	shallow::Run();

	// std::cout << "\n\tDeep Copy : \n\n";
	// deep::Run();

	return 0;
}
