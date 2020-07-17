#include <iostream>
#include <cassert>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point();                       //默认构造函数
    Point(int xx, int yy);         //自定义构造函数
    void move(int newX, int newY); //将点坐标输入point对象
    Point(Point &p);
    ~Point();
    void move(int newX, int newY)
    {
        x = newX;
        y = newY;
    }
    int getX() { return x; }
    int getY() { return y; }
};

Point::Point() : x(0), y(0)
{
    cout << "Defult Constructor called." << endl;
}

Point::Point(int xx, int yy) : x(xx), y(yy)
{
    cout << "Constructor Called." << endl;
}

Point::Point(Point &p) : x(p.x), y(p.y)
{
}

Point::~Point()
{
    cout << "Destructor called." << endl;
}

class ArrayOfPoint
{
private:
    int size;
    Point *points;

public:
    ArrayOfPoint(int size);         //生成一个长度为size的point数组
    ArrayOfPoint(ArrayOfPoint &ps); //arrayofpoint的构造函数
    ~ArrayOfPoint();
    Point &element(int index) //输出下标为index的对象
    {
        assert(index >= 0 && index < size); //如果数组越界则停止
        return points[index];
    }
};

ArrayOfPoint::ArrayOfPoint(int size) : size(size)
{
    points = new Point[size];
}

ArrayOfPoint::ArrayOfPoint(ArrayOfPoint &ps) : size(ps.size)
{
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = ps.points[i]; //注意：point类的复制构造函数存在才行
    }
}

ArrayOfPoint::~ArrayOfPoint()
{
    cout << "Delete ..." << endl;
    delete[] points;
}

int main()
{
    int count; //数组长度
    cout << "please enter the counter of point:";
    cin >> count;
    ArrayOfPoint points(count);
    points.element(0).move(5, 0);
    points.element(1).move(15, 20);
    return 0;
}