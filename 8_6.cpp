#include <iostream>
#define PI 3.1415926535
using namespace std;

class Shape
{
private:
public:
    Shape() {}
    virtual void display() {}
    ~Shape() {}
};

class Rectangle : public Shape
{
private:
    int a; //边长

public:
    Rectangle(int A) : a(A) {}
    void display() { cout << "正方形的边长为：" << a << endl; }
    int getPerom() { return 4 * a; }
    int getArea() { return a * a; }
    ~Rectangle() {}
};

class Circle : public Shape
{
private:
    int r; //半径

public:
    Circle(int R) : r(R) {}
    void display() { cout << "圆的半径为：" << r << endl; }
    float getPerom() { return 2 * r * PI; }
    float getArea() { return PI * r * r; }
    ~Circle() {}
};

int main()
{
    Rectangle r(4);
    Circle c(3);
    cout << "正方形面积为：" << r.getArea() << "\n周长为：" << r.getPerom() << endl;
    cout << "圆的面积为：" << c.getArea() << "\n周长为：" << c.getPerom() << endl;
    return 0;
}