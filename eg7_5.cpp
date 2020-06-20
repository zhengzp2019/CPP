#include <iostream>
using namespace std;

class Base1
{
public:
    Base1(int i)
    {
        cout << "构造函数Base1 " << i << endl;
    }
    ~Base1()
    {
        cout << "析构函数Base1" << endl;
    }
};

class Base2
{
public:
    Base2(int j)
    {
        cout << "构造函数Base2 " << j << endl;
    }
    ~Base2()
    {
        cout << "析构函数Base2 " << endl;
    }
};

class Base3
{
public:
    Base3()
    {
        cout << "构造函数Base3 *" << endl;
    }
    ~Base3()
    {
        cout << "析构函数Base3" << endl;
    }
};

class Derived : public Base2, public Base1, public Base3
{
private:
    Base1 member1;
    Base2 member2;
    Base3 member3;

public:
    Derived(int a, int b, int c, int d) : Base1(a), member2(d), member1(c), Base2(b)
    {
        cout << "构造函数 Derived" << endl;
    }
    ~Derived() { cout << "析构函数 Derived" << endl; }
};

int main()
{
    Derived obj(1, 2, 3, 4);
    return 0;
}