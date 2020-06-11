#include <iostream>
using namespace std;

class Cat
{
private:
    static int numOfCats;//静态数据成员，记录Cat对象的数量

public:
    Cat();
    Cat(const Cat &C);
    ~Cat();
    static void getNumOfCats() { cout << "Object numOfCats=" << numOfCats << endl; }//静态成员函数，显示当前Cat对象的数量
};

int Cat::numOfCats = 0;
Cat::Cat()
{
    cout << "调用构造函数" << endl;
    numOfCats++;
}

Cat::~Cat()
{
    cout << "调用析构函数" << endl;
    numOfCats--;
}

Cat::Cat(const Cat &C)
{
    cout << "调用复制构造函数" << endl;
    numOfCats++;
}

int main()
{
    Cat A;
    Cat::getNumOfCats();
    Cat B(A);
    Cat::getNumOfCats();
    return 0;
}
