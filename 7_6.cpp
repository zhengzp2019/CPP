#include<iostream>
#include<string>
using namespace std;

class Mammal
{
private:
    string name;
public:
    Mammal() { cout << "默认构造函数Mammal" << endl; }
    Mammal(string n) : name(n) { cout << "构造函数Mammal" << endl; }
    ~Mammal() { cout << "Mammal析构函数" << endl; }
};

class Dog:public Mammal
{
private:
    string name;

public:
    Dog(string n, string m) : name(n), Mammal(m) { cout << "构造函数Dog" << endl; }
    ~Dog() { cout << "Dog类析构函数" << endl; }
};

int main()
{
    Dog d("小明", "狗");
    return 0;
}