//变量的作用域
#include <iostream>
using namespace std;
int x = 5, y = 7;
void myFunction()
{
    int y = 10;
    cout << "x from myFunction:" << x << "\n";
    cout << "y from myFunction:" << y << "\n";
}

int main()
{
    cout << "x from main:" << x << "\n";
    cout << "y from main:" << y << "\n";
    myFunction();
    cout << "Back from myFunction!\n\n";
    cout << "x from main:" << x << "\n";
    cout << "y from main:" << y << "\n";
    return 0;
}