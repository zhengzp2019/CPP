#include <iostream>
using namespace std;

class Point //Point类定义
{
private: //私有成员变量
    int x, y;

public:                                             //外部接口
    Point(int xx = 0, int yy = 0) : x(xx), y(yy){}; //构造函数
    Point(Point &p);                                //复制构造函数
    Point operator++();                             //前置单目运算符重载
    Point operator++(int);                          //后置单目运算符重载
    Point operator--();
    Point operator--(int);
    friend ostream &operator<<(ostream &out, const Point &p);
    ~Point(); //析构函数
    int getX() { return x; }
    int getY() { return y; }
};

Point::Point(Point &p) //复制构造函数的实现
{
    x = p.x;
    y = p.y;
}

Point Point::operator++()
{
    ++this->x;
    ++this->y;
    return *this;
}
Point Point::operator++(int)
{
    Point p = *this;
    ++*this;
    return p;
}

Point Point::operator--()
{
    --this->x;
    --this->y;
    return *this;
}
Point Point::operator--(int)
{
    Point p = *this;
    --*this;
    return p;
}

ostream &operator<<(ostream &out, const Point &p)
{
    out << "(" << p.x << ',' << p.y << ")";
    return out;
}

Point::~Point() //析构函数
{
}

int main()
{
    Point p(0, 0);
    cout << "前置++" << ++p << endl;
    cout << "后置++" << p++ << endl;
    cout << "前置--" << --p << endl;
    cout << "后置--" << p-- << endl;
    cout << "最终的p" << p << endl;
    return 0;
}