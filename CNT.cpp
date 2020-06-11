#include <iostream>
#include <string>
using namespace std;

int Cnt(string s)
{
    int cnt = 0;
    for (char ch : s)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            cnt++;
    }
    return cnt;
}

int main()
{
    string s;
    cout << "请输入一条英文句子：";
    getline(cin, s);
    cout << "该句子中英文字母的个数为：" << Cnt(s) << endl;
    return 0;
}