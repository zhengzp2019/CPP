#include <iostream>
#include <cstdio>
#include <string>
#define Male true
#define Female false
using namespace std;

class Date //Date类的定义
{
private: //Date类私有成员变量
    int year, month, day;

public:                                       //Date类外部接口
    Date(int y = 2000, int m = 1, int d = 1); //构造函数
    Date(Date &d);                            //复制构造函数
    ~Date();                                  //析构函数
    int gety() { return year; }
    int getm() { return month; }
    int getd() { return day; }
};

Date::Date(int y /*=2000*/, int m /* =1*/, int d /* = 1*/) : year(y), month(m), day(d)
{
    cout << "调用Date类的构造函数" << endl;
}

Date::Date(Date &d)
{
    year = d.year;
    month = d.month;
    day = d.day;
    cout << "调用Date类的复制构造函数" << endl;
}
Date::~Date()
{
    cout << "调用Date类的析构函数" << endl;
}

class People //组合类People的定义
{
private: //组合类People的私有成员数据
    string num;
    bool sex;
    Date d;
    string ID;

public:                                                                                        //组合类People的外部接口
    People(string nnum = "000", bool ssex = true, Date dd = {2000, 1, 1}, string IID = "000"); //组合类People的构造函数
    People(People &p);                                                                         //组合类People的复制构造函数
    ~People();                                                                                 //组合类People的析构函数
    void Input();                                                                              //录入人员信息                                                                          //录入人员信息
    inline void Display();                                                                     //显示人员信息                                                            //显示人员信息
};

People::People(string nnum /* = "000"*/, bool ssex /* = true*/, Date dd /*(2000,1,1)*/, string IID /*= "000"*/) : num(nnum), sex(ssex), d(dd), ID(IID)
{
    cout << "调用组合类People的构造函数" << endl;
}

People::People(People &p)
{
    num = p.num;
    sex = p.sex;
    d = p.d;
    ID = p.ID;
    cout << "调用组合类People的复制构造函数" << endl;
}

People::~People()
{
    cout << "调用组合类People的析构函数" << endl;
}

void People::Input()
{
    int year, month, day;
    cout << "请输入人员信息：编号(串)、性别(用0、1表示，0表示女，1表示男)、出生日期（y/m/d）、身份证号(串)" << endl;
    cin >> num >> sex;
    scanf("%d/%d/%d", &year, &month, &day);
    cin >> ID;
    Date dd(year, month, day);
    d = dd;
}

void People::Display()
{
    cout << "编号为：" << num << "的信息如下：\n";
    if (sex)
    {
        cout << "性别：Male\t";
    }
    else
    {
        cout << "性别：Female\t";
    }
    printf("出生日期：%d/%d/%d\t", d.gety(), d.getm(), d.getd());
    cout << "身份证号：" << ID << endl;
}

int main()
{
    Date d1, d2(2000, 10, 29);                  //分别用带默认形参值的成员函数和构造函数初始化两个Date对象
    People p1, p2("101", Female, d2, "340322"); //分别用带默认形参值的成员函数和构造函数初始化两个People对象
    p1.Display();
    p2.Display();
    p1.Input(); //输入p1人员信息
    p1.Display();
    People p3(p1);
    p3.Display();
    return 0;
}