#include <iostream>
using namespace std;

class BaseClass
{
private:
    int a;

public:
    BaseClass(int A) : a(A) { cout << "Calling BaseClass's Constructor" << endl; }
    void fn1();
    void fn2();
    ~BaseClass() { cout << "Calling BaseCLass destructor" << endl; }
};

void BaseClass::fn1()
{
    cout << "calling BaseClass's fn1" << endl;
}
void BaseClass::fn2()
{
    cout << "calling BaseClass's fn2" << endl;
}

class DerivedClass:public BaseClass
{
private:
    int b;

public:
    DerivedClass(int A, int B) : b(B), BaseClass(A) { cout << "calling Derived constructor" << endl; }
    ~DerivedClass() { cout << "calling derived destructor" << endl; }
    void fn1();
    void fn2();
};

void DerivedClass::fn1()
{
    cout << "calling DerivedClass's fn1" << endl;
}

void DerivedClass::fn2()
{
    cout << "calling DerivedClass's fn2" << endl;
}

int main()
{
    DerivedClass *p, d(1, 2);
    p = &d;
    p->fn1();
    p->fn2();
    return 0;
}