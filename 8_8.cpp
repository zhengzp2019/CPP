#include<iostream>
using namespace std;

class BaseClass
{
private:
    
public:
    BaseClass(){}
    virtual void fn1() { cout << "BaseClass::fn1" << endl; }
    void fn2() { cout << "BaseClass::fn2" << endl; }
    ~BaseClass(){}
};

class DerivedClass:public BaseClass
{
private:
    
public:
    DerivedClass(){}
    void fn1() { cout << "Derived::fn1" << endl; }
    void fn2() { cout << "Derived::fn2" << endl; }
    ~DerivedClass(){}
};

int main()
{
    DerivedClass d;
    DerivedClass *p = &d;
    BaseClass *q = &d;
    cout << "通过DerivedClass调用成员函数\n";
    p->fn1();
    p->fn2();
    cout << "通过BaseClass调用成员函数\n";
    q->fn1();
    q->fn2();
    return 0;
}