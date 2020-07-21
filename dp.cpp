#include <cstdio>
#include <cstdlib>
#include <windows.h>

int main()
{
    int t = 100;
    while (--t)
    {
        system("makedata#.exe>input");
        system("bubble_sort.exe<input> output_my");
        system("select_sort.exe<input> output_other");
        if (system("fc output_my output_other"))
            break;
    }
    if (t == 0)
        printf("correctly\n");
    else
        printf("error\n");
    return 0;

    /*
    *   int t = 1000; //两程序对比次数
    *   while (--t)
    *   {
    *       system("我的程序<输入文件>我的输出文件");
    *       system("正确的程序<输入文件>正确的输出文件");
    *       if (system("fc 我的输出文件 正确的输出文件")) //比较两文件，相同返回0，不同返回1
    *           break;
    *   }  
    *   if (t == 0)
    *   {
    *       printf("你的程序正确\n");
    *   }
    *   else
    *   {
    *       printf("你的程序不正确\n");
    *   }
    *   return 0;
    */
}