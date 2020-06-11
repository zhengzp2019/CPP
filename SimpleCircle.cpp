#include <iostream>
using namespace std;

class SimpleCircle
{
private:
    int *itsRadius;

public:
    SimpleCircle(int *p,int r):itsRadius(p)//构造函数，将半径的值放入new出的对象里
    {
        *itsRadius = r;
    }
    int getRadius()//返回对象值
    {
        return *itsRadius;
    }
    void print()//输出信息
    {
        cout << "圆的半径为：" << *itsRadius << endl;
    }
    ~SimpleCircle()
    {
        delete itsRadius;//手动释放对象内存
    }
};

int main()
{
    int r;
    cout << "输入圆的半径：";
    cin >> r;
    SimpleCircle Cir(new int, r);
    Cir.print();
    return 0;
}
