#include <iostream>
using namespace std;

int Fibonacci(int n); //求第n位Fibonacci级数

int main()
{
    //int n;
    //cout << "请输入要求第几位Fibonacci级数\n";
    //cin >> n;
    for (int i = 1; i <= 10; i++)
    {//输出前十位的Fibonacci级数
        cout << "第" << i << "位Fibonacci级数为：" << Fibonacci(i) << endl;
    }
    return 0;
}

int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}