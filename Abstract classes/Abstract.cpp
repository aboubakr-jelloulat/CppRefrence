#include <iostream>
using namespace std;

/*
	Abstract classes act as expressions of general concepts from which more specific classes can be derived. 
	You can't create an object of an abstract class type. 
	However, you can use pointers and references to abstract class types.

*/

/*
	You create an abstract class by declaring at least one pure virtual member function. 
	That's a virtual function declared by using the pure specifier (= 0) syntax.

*/

/*
	You cannot create an object from an abstract class directly.

	if your class inherits from an abstract class, it must implement all pure virtual functions.

*/


/*
	A pure virtual method (function):

		Is declared with = 0
		Has no implementation in the base class
		Must be overridden in the derived class
		Makes the class abstract

*/


/*
	What is a “Pure Method”?

	A pure method means a method that has no side effects and always gives the same output for the same input.

	int Add(int a, int b)  
	{
    	return a + b; // No side effects, same result always  => kadir haja wehda
	}


*/


class Account
{

protected :
	double _balance;

public :

	Account();

	Account(double balance) : _balance(balance) {}

	virtual double GetBalance() const = 0;
	
	virtual void PrintBalance()
    {
        std::cout << "Account balance: " << _balance << " USD" << std::endl;
    }

	void	SetBalance(double balance)
	{
		this->_balance = balance;
	}

	virtual ~Account() {}

};

class SavingAccount : public Account
{

public :

	SavingAccount(double balance) : Account(balance) 
	{

	}

	double GetBalance() const override
	{
		return _balance;
	}

	void	PrintBalance() override
	{
		std::cout << "[Savings Account] Current balance: " << _balance << " USD" << std::endl;
	}


};


int main()
{
	// Account acc(100); // 'Account' is an abstract class

	SavingAccount Myaccount(100);

	Myaccount.PrintBalance();

	Myaccount.SetBalance(500);

	std::cout << "Balance retrieved: " << Myaccount.GetBalance() << " USD" << std::endl;

	return 0;
}
