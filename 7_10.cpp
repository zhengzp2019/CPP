#include <iostream>
using namespace std;

class Object
{
private:
    int weight;

public:
    Object(int w) : weight(w) { cout << "calling Object constructor "<<weight << endl; }
    int getweight() { return weight; }
    ~Object() { cout << "calling Object destructor" << endl; }
};

class Box:public Object
{
private:
    int height;
    int width;

public:
    Box(int h, int wid, int w) : height(h), width(wid), Object(w) { cout << "calling Box constructor "<<height<<" "<<width << endl; }
    int getheight() { return height; }
    int getweight() { return width; }
    ~Box() { cout << "calling Box destructor" << endl; }
};

int main()
{
    Box b(57, 17, 14);
    return 0;
}