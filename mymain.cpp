//main.cpp
#include "CComplex.cpp"
#include "CTime.cpp"
#include <iostream>
using namespace std;

void TestComplex(); //测试复数类,测试两组数据
void TestC1();
void TestC2();
void TestC3();
void TestTime(); //测试时间类

int main()
{
    while (1)
    {
        int num = 0;
        cout << "请根据如下说明输入指令" << endl;
        cout << "1: 测试复数类" << endl;
        cout << "2: 测试时间类" << endl;
        cout << "3: 程序结束" << endl;
        cout << "请输入指令:" << endl;
        cin >> num;
        switch (num)
        {
        case 1: //测试复数类
            TestComplex();
            break;
        case 2: //ʱ测试时间类
            TestTime();
            break;
        case 3: //程序结束
            return 0;
            break;
        default: //输入出错，强制退出
            exit(0);
        }
    }
    return 0;
}

void TestComplex()
{
    cout << endl;
    TestC1();
    TestC2();
    TestC3();
}

void TestC1()
{
    cout << "第一组测试数据" << endl;
    cout << "第一个复数:";
    CComplex C1;
    C1.setReal(1);
    C1.setImage(2);
    C1.showComplex();
    cout << "第二个复数:";
    CComplex C2;
    C2.setReal(4);
    C2.setImage(3);
    C2.showComplex();
    cout << "加法运算:";
    CComplex C3 = C1 + C2;
    C3.showComplex();
    cout << "减法运算:";
    CComplex C4 = C1 - C2;
    C4.showComplex();
    cout << "乘法运算";
    CComplex C5 = C1 * C2;
    C5.showComplex();
    cout << "除法运算:";
    CComplex C6 = C1 / C2;
    C6.showComplex();
    cout << endl;
}

void TestC2()
{
    cout << "第二组测试数据" << endl;
    cout << "第一个复数:";
    CComplex C1;
    C1.setReal(-3);
    C1.setImage(4);
    C1.showComplex();
    cout << "第二个复数:";
    CComplex C2;
    C2.setReal(-4);
    C2.setImage(2);
    C2.showComplex();
    cout << "加法运算:";
    CComplex C3 = C1 + C2;
    C3.showComplex();
    cout << "减法运算:";
    CComplex C4 = C1 - C2;
    C4.showComplex();
    cout << "乘法运算";
    CComplex C5 = C1 * C2;
    C5.showComplex();
    cout << "除法运算:";
    CComplex C6 = C1 / C2;
    C6.showComplex();
    cout << endl;
}

void TestC3()
{
	cout << "关系操作符重载测试" << endl;
	cout << "第一个复数:";
	CComplex C1;
	C1.setReal(1);
	C1.setImage(2);
	C1.showComplex();
	cout << "第二个复数:";
	CComplex C2;
	C2.setReal(-2);
	C2.setImage(-4);
	C2.showComplex();

	if (C1 > C2)
		cout << "C1 > C2";
	else
		cout << "C1 < C2";
	cout << endl;
	if (C1 == C2)
		cout << "C1 == C2";
	else
		cout << "C1 != C2";
	cout << endl;
	cout << endl;
}

void TestTime()
{
    cout << endl;
    CTime T1; //12:2:30
    T1.setHour(12);
    T1.setMinute(2);
    T1.setSecond(30);
    cout << "T1:";
    T1.displayTime(); //第一个时间
    CTime T2;         //12:2:30
    T2.setHour(12);
    T2.setMinute(2);
    T2.setSecond(30);
    cout << "T2:";
    T2.displayTime(); //第二个时间
    CTime T3;         //2:30:5
    T3.setHour(2);
    T3.setMinute(30);
    T3.setSecond(5);
    cout << "T3:";
    T3.displayTime(); //第三个时间
    CTime T4;         //20:10:3
    T4.setHour(20);
    T4.setMinute(10);
    T4.setSecond(3);
    cout << "T4:";
    T4.displayTime(); //第四个时间

    //测试比较运算法
    //== 
    cout << "== 测试:" << endl;
    (T1 == T2) ? (cout << "T1与T2时间相等" << endl) : (cout << "T1与T2时间不等" << endl);
    (T1 == T3) ? (cout << "T1与T3时间相等" << endl) : (cout << "T1与T3时间不等" << endl);
    cout << endl;
    //>
    cout << "> 测试:" << endl;
    (T1 > T2) ? (cout << "T1>T2" << endl) : (cout << "T1<=T2" << endl);
    (T1 > T3) ? (cout << "T1>T3" << endl) : (cout << "T1<=T3" << endl);
    (T1 > T4) ? (cout << "T1>T4" << endl) : (cout << "T1<=T4" << endl);
    cout << endl;
    //<
    cout << "< 测试:" << endl;
    (T1 < T2) ? (cout << "T1<T2" << endl) : (cout << "T1>=T2" << endl);
    (T1 < T3) ? (cout << "T1<T3" << endl) : (cout << "T1>=T3" << endl);
    (T1 < T4) ? (cout << "T1<T4" << endl) : (cout << "T1>=T4" << endl);
    cout << endl;

    //算数运算符测试
    CTime tmp;
    //+ 测试
    cout << "+ 测试:" << endl;
    cout << "T1:12:2:30,"
         << "T2:12:2:30" << endl
         << "T1+T2:";
    tmp = T1 + T2;
    tmp.displayTime();
    cout << "T1:12:2:30,"
         << "T3:2:30:5" << endl
         << "T1+T3:";
    tmp = T1 + T3;
    tmp.displayTime();
    cout << "T1:12:2:30,"
         << "T4:20:10:3" << endl
         << "T1+T4:";
    tmp = T1 + T4;
    tmp.displayTime();
    cout << endl;

    //-
    cout << "- 测试:" << endl;
    cout << "T1:12:2:30,"
         << "T2:12:2:30" << endl
         << "T1-T2:";
    tmp = T1 - T2;
    tmp.displayTime();
    cout << "T1:12:2:30,"
         << "T3:2:30:5" << endl
         << "T1-T3:";
    tmp = T1 - T3;
    tmp.displayTime();
    cout << "T1:12:2:30,"
         << "T4:20:10:3" << endl
         << "T1-T4:";
    tmp = T1 - T4;
    tmp.displayTime();
    cout << endl;

    //++
    cout << "T++测试:" << endl;
    cout << "T1:12:2:30  "
         << "T1++:";
    tmp = T1;
    tmp++;
    tmp.displayTime();
    cout << "T3:2:30:5  "
         << "T3++:";
    tmp = T3;
    tmp++;
    tmp.displayTime();
    cout << "T4:20:10:3  "
         << "T4++:";
    tmp = T4;
    tmp++;
    tmp.displayTime();
    cout << endl;
    cout << "++T测试:" << endl;
    cout << "T1:12:2:30  "
         << "++T1:";
    tmp = T1;
    ++tmp;
    tmp.displayTime();
    cout << "T3:2:30:5  "
         << "++T3:";
    tmp = T3;
    ++tmp;
    tmp.displayTime();
    cout << "T4:20:10:3  "
         << "++T4:";
    tmp = T4;
    ++tmp;
    tmp.displayTime();
    cout << endl;

    //--
    cout << "T-- 测试:" << endl;
    cout << "T1:12:2:30  "
         << "T1--:";
    tmp = T1;
    tmp--;
    tmp.displayTime();
    cout << "T3:2:30:5  "
         << "T3--:";
    tmp = T3;
    tmp--;
    tmp.displayTime();
    cout << "T4:20:10:3  "
         << "T4--:";
    tmp = T4;
    tmp--;
    tmp.displayTime();
    cout << endl;
    cout << "--T测试:" << endl;
    cout << "T1:12:2:30  "
         << "--T1:";
    tmp = T1;
    --tmp;
    tmp.displayTime();
    cout << "T3:2:30:5  "
         << "--T3:";
    tmp = T3;
    --tmp;
    tmp.displayTime();
    cout << "T4:20:10:3  "
         << "--T4:";
    tmp = T4;
    --tmp;
    tmp.displayTime();
    cout << endl;

    //+=
    cout << "T+=测试:" << endl;
    cout << "T1:12:2:30  "
         << "T1+=11:";
    tmp = T1;
    tmp += 11;
    tmp.displayTime();
    cout << "T3:2:30:5  "
         << "T3+=12:";
    tmp = T3;
    tmp += 12;
    tmp.displayTime();
    cout << "T4:20:10:3  "
         << "T4+=13:";
    tmp = T4;
    tmp += 13;
    tmp.displayTime();
    cout << endl;

    //-=
    cout << "T-=测试:" << endl;
    cout << "T1:12:2:30  "
         << "T1-=11:";
    tmp = T1;
    tmp -= 11;
    tmp.displayTime();
    cout << "T3:2:30:5  "
         << "T3-=12:";
    tmp = T3;
    tmp -= 12;
    tmp.displayTime();
    cout << "T4:20:10:3  "
         << "T4-=13:";
    tmp = T4;
    tmp -= 13;
    tmp.displayTime();
    cout << endl;
}