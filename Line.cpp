#include <iostream>
#include <cmath>
using namespace std;

class Point //Point类定义
{
private: //私有成员变量
    int x, y;

public:                                                                                        //外部接口
    Point(int xx = 0, int yy = 0) : x(xx), y(yy) { cout << "调用Point类的构造函数" << endl; }; //构造函数
    Point(Point &p);                                                                           //复制构造函数
    ~Point();                                                                                  //析构函数
    int getX() { return x; }
    int getY() { return y; }
};

Point::Point(Point &p) //复制构造函数的实现
{
    x = p.x;
    y = p.y;
    cout << "调用point类的复制构造函数" << endl;
}

Point::~Point() //析构函数
{
    cout << "调用对象" << '(' << x << ',' << y << ')' << "的析构函数" << endl;
}

class Line //Line类的定义
{
private: //私有数据成员
    Point p1, p2;
    double len;

public:                         //外部接口
    Line(Point xp1, Point xp2); //组合类的构造函数
    Line(Line &l);              //组合类的复制构造函数
    ~Line();                    //组合类的析构函数
    double getLen() { return len; }
};

Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) //组合类的构造函数
{
    cout << "调用组合类Line的构造函数" << endl;
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(x * x + y * y);
}

Line::Line(Line &l) : p1(l.p1), p2(l.p2) //组合类的复制构造函数
{
    cout << "调用组合类Line的复制构造函数" << endl;
    len = l.len;
}
Line::~Line() //组合类的析构函数
{
    cout << "调用组合类Line的析构函数" << endl;
}

int main() //主函数
{
    Point myp1(1, 1), myp2(4, 5); //建立一个Point对象
    Line line(myp1, myp2);        //建立一个Line对象
    Line line2(line);             //利用复制构造函数建立一个新对象
    cout << "Line的长度是：" << line.getLen() << endl;
    cout << "Line2的长度是：" << line2.getLen() << endl;
    return 0;
}