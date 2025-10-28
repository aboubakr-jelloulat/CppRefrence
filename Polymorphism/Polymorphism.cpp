#include <iostream>
using namespace std;

/*

  NORMAL CASE: Direct object calls (no pointers)

  - We create a Dog object directly.
  - The compiler knows the exact type at compile time.
  - The function call is resolved using STATIC BINDING.
  - No vtable or vptr exists here because there is 
    no virtual function.

*/
namespace DirectObjectCall
{
    class Animal 
    {
    public:
        void speak() { cout << "Animal sound" << endl; }
    };

    class Dog : public Animal 
    {
    public:
        void speak() { cout << "Woof" << endl; }
    };

    void run() 
    {
        Dog d;      // Created directly (stack object)
        d.speak();  // Calls Dog::speak() because type is known at compile time
    }
}


/*

  NON-VIRTUAL CASE: Base pointer without virtual

  - We use a pointer of type Animal* that points to 
    a Dog object.
  - The function 'speak()' is NOT virtual.
  - The call is resolved using the STATIC TYPE 
    (the type of the pointer).
  - Therefore, Animal::speak() is called, even though
    the actual object is a Dog.
  - No vtable or vptr is created.

*/
namespace StaticBinding
{
    class Animal 
    {
    public:
        void speak() { cout << "Animal sound" << endl; }
    };

    class Dog : public Animal 
    {
    public:
        void speak() { cout << "Woof" << endl; }
    };

    void run() 
    {
        Dog* d = new Dog();     // Pointer with static type Dog*
        Animal* a = new Dog();  // Pointer with static type Animal*, dynamic type Dog

        d->speak();  // Calls Dog::speak() (static type = Dog*)
        a->speak();  // Calls Animal::speak() (static type = Animal*, no virtual)
    }
};


/*

  VIRTUAL CASE: Base pointer with virtual function

  - Now 'speak()' is declared as virtual in the base class.
  - The compiler creates a vtable for Animal and Dog.
  - Each object has a hidden vptr that points to its 
    corresponding class's vtable.
  - When we call a->speak(), the program uses the vptr to 
    find the correct function in the vtable at runtime.
  - This is called DYNAMIC BINDING or RUNTIME POLYMORPHISM.

*/
namespace DynamicBinding
{
    class Animal 
    {
    public:
        virtual void speak() { cout << "Animal sound" << endl; }
    };

    class Dog : public Animal 
    {
    public:
        void speak() override { cout << "Woof" << endl; }
    };

    void run() 
    {
        Dog* d = new Dog();     // Pointer with static type Dog*
        Animal* a = new Dog();  // Pointer with static type Animal*, dynamic type Dog

        d->speak();  // Calls Dog::speak() directly
        a->speak();  // Calls Dog::speak() dynamically via vtable lookup
    }
};


int main()
{
    cout << "NORMAL CASE:" << endl;
    DirectObjectCall::run();

    cout << endl << "NON-VIRTUAL CASE (Static Binding):" << endl;
    StaticBinding::run();

    cout << endl << "VIRTUAL CASE (Dynamic Binding):" << endl;
    DynamicBinding::run();

    return 0;
}

