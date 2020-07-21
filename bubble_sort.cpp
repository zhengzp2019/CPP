#include<iostream>
#include<vector>
#include<algorithm>
#define MAXN 100

using namespace std;
vector<int> a(MAXN);

int main()
{
    for (int i = 0; i < MAXN;i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN - i;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < MAXN;i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}