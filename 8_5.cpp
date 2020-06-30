#include<iostream>
using namespace std;

class Mammal
{
private:
    
public:
    Mammal() { cout << "calling Mammall's constructor" << endl; }
    virtual void speak() { cout << "calling Mammal's founction speak" << endl; }
    ~Mammal() { cout << "calling Mammal's destructor" << endl; }
};

class Dog:public Mammal
{
private:
    
public:
    Dog() { cout << "calling Dog's constructor" << endl; }
    virtual void speak() { cout << "calling Dog's founction speak" << endl; }
    ~Dog() { cout << "calling Dog's destructor" << endl; }
};

int main()
{
    Dog d;
    d.speak();
    return 0;
}
