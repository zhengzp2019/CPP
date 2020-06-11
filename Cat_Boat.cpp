#include <iostream>
using namespace std;
class Cat;
class Boat;

class Cat
{
private:
    int weight;

public:
    Cat(int W);
    Cat(const Cat &C);
    ~Cat();
    int getWeight() { return weight; }
    friend int getTotalWeight(Cat *C, Boat *B);
};

Cat::Cat(int W) : weight(W)
{
}

Cat::~Cat()
{
}

Cat::Cat(const Cat &C) : weight(C.weight)
{
}

class Boat
{
private:
    int weight;

public:
    Boat(int W);
    Boat(const Boat &B);
    ~Boat();
    int getWeight() { return weight; }
    friend int getTotalWeight(Cat *C, Boat *B);
};

Boat::Boat(int W) : weight(W)
{
}

Boat::~Boat()
{
}

Boat::Boat(const Boat &B) : weight(B.weight)
{
}

int getTotalWeight(Cat *C, Boat *B)
{
    return C->weight + B->weight;
}

int main()
{
    Cat C(5);
    Boat B(10);
    cout << "C.weight=" << C.getWeight() << endl;
    cout << "B.weight=" << B.getWeight() << endl;
    cout << "C.weight+B.weight=" << getTotalWeight(&C, &B) << endl;
    return 0;
}
