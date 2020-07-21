//数据生成器
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXN 100 //生成的数据范围
#define NUM 100   //生成的数据数目

int main()
{
    srand(time(NULL));
    //构造方法
    int A;
    //随机生成100个数据
    for (int i = 1; i <= NUM; i++)
    {
        A = rand() % MAXN;
        //B = rand() % MAXN;
        printf("%d\n", A);
    }
    return 0;
}