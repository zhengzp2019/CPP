#include <iostream>
using namespace std;

int Factor(int m, int n); //求m,n的最大公约数，m>n
int Muti(int m, int n);   //求m,n的最小公倍数
int main()
{
    int m, n;
    int t;
    cout << "请输入两个整数m,n\n";
    cin >> m >> n;
    if (m < n)
    {
        t = m;
        m = n;
        n = t;
    }
    cout << "m,n的最大公约数为：" << Factor(m, n) << endl;
    cout << "m,n的最小公倍数为：" << Muti(m, n) << endl;
    return 0;
}

int Factor(int m, int n)
{
    int t;
    while ((t = m % n) != 0)
    {
        m = n;
        n = t;
    }
    return n;
}

int Muti(int m, int n)
{
    return m * n / Factor(m, n);
}