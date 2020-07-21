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

    for (int i = 0; i < MAXN - 1;i++)
    {
        int k = i + 1;
        for (int j = i + 1; j < MAXN;j++)
        {
            if(a[j]>a[k])
            {
                k = j;
            }
        }
        if(a[k]>a[i])
        {
            swap(a[k], a[i]);
        }
    }

    for (int i = 0; i < MAXN;i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}